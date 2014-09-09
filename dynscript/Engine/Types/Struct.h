#pragma once

namespace Script
{
	void FORCEINLINE RegisterDefaultStructs(asIScriptEngine *Engine)
	{
		using namespace std;

		// MEMPAGE
		AS_BEGIN_STRUCT(MEMPAGE)
			AS_STRUCT_ADD(MEMORY_BASIC_INFORMATION, mbi)
			AS_STRUCT_ACCESS(string,                info, STR_GET(info), STR_SET(info))
		AS_END_STRUCT()

		// MEMMAP
		AS_BEGIN_STRUCT(MEMMAP)
			AS_STRUCT_ADD(int,            count)
			AS_ADD_STRUCT_ARRAY(MEMPAGE&, page,
			-> MEMPAGE*
			{
				if (Index > (asUINT)Obj->count)
					return nullptr;

				return &Obj->page[Index];
			})
		AS_END_STRUCT()

		// BRIDGEBP
		AS_BEGIN_STRUCT(BRIDGEBP)
			AS_STRUCT_ADD(BPXTYPE,   type)
			AS_STRUCT_ADD(ptr,       addr)
			AS_STRUCT_ADD(bool,      enabled)
			AS_STRUCT_ADD(bool,      singleshoot)
			AS_STRUCT_ADD(bool,      active)
			AS_STRUCT_ACCESS(string, name, STR_GET(name), STR_SET(name))
			AS_STRUCT_ACCESS(string, mod,  STR_GET(mod),  STR_SET(mod))
			AS_STRUCT_ADD(word,      slot)
		AS_END_STRUCT()

		// BPMAP
		AS_BEGIN_STRUCT(BPMAP)
			AS_STRUCT_ADD(int,          count)
			AS_ADD_STRUCT_ARRAY(BPMAP&, bp,
			-> BRIDGEBP*
			{
				if (Index > (asUINT)Obj->count)
				return nullptr;

				return &Obj->bp[Index];
			})
		AS_END_STRUCT()

		// FUNCTION
		AS_BEGIN_STRUCT(FUNCTION)
			AS_STRUCT_ADD(ptr, start)
			AS_STRUCT_ADD(ptr, end)
		AS_END_STRUCT()

		// LOOP
		AS_BEGIN_STRUCT(LOOP)
			AS_STRUCT_ADD(int, depth)
			AS_STRUCT_ADD(ptr, start)
			AS_STRUCT_ADD(ptr, end)
		AS_END_STRUCT()

		// ADDRINFO
		AS_BEGIN_STRUCT(ADDRINFO)
			AS_STRUCT_ADD(int,       flags)
			AS_STRUCT_ACCESS(string, module,  STR_GET(module),  STR_SET(module))
			AS_STRUCT_ACCESS(string, label,   STR_GET(label),   STR_SET(label))
			AS_STRUCT_ACCESS(string, comment, STR_GET(comment), STR_SET(comment))
			AS_STRUCT_ADD(bool,      isbookmark)
			AS_STRUCT_ADD(FUNCTION,  function)
			AS_STRUCT_ADD(LOOP,      loop)
		AS_END_STRUCT()

		// SYMBOLINFO
		AS_BEGIN_STRUCT(SYMBOLINFO)
			AS_STRUCT_ADD(ptr,       addr)
			AS_STRUCT_ACCESS(string, decoratedSymbol,   STR_GET(decoratedSymbol),   { assert(false); })
			AS_STRUCT_ACCESS(string, undecoratedSymbol, STR_GET(undecoratedSymbol), { assert(false); })
		AS_END_STRUCT()

		// SYMBOLMODULEINFO
		AS_BEGIN_STRUCT(SYMBOLMODULEINFO)
			AS_STRUCT_ADD(ptr,       base)
			AS_STRUCT_ACCESS(string, name, STR_GET(name), STR_SET(name))
		AS_END_STRUCT()

#if 0
		// SYMBOLCBINFO !!TODO!!
		AS_BEGIN_STRUCT(SYMBOLCBINFO)
			AS_STRUCT_ADD(ptr, base)
			AS_STRUCT_ADD(ptr, cbSymbolEnum)
			AS_STRUCT_ADD(ptr, user)
		AS_END_STRUCT()
#endif

		// FLAGS
		AS_BEGIN_STRUCT(FLAGS)
			AS_STRUCT_ADD(bool, c)
			AS_STRUCT_ADD(bool, p)
			AS_STRUCT_ADD(bool, a)
			AS_STRUCT_ADD(bool, z)
			AS_STRUCT_ADD(bool, s)
			AS_STRUCT_ADD(bool, t)
			AS_STRUCT_ADD(bool, i)
			AS_STRUCT_ADD(bool, d)
			AS_STRUCT_ADD(bool, o)
		AS_END_STRUCT()

		// REGDUMP
		AS_BEGIN_STRUCT(REGDUMP)
			AS_STRUCT_ADD(ptr,   cax)
			AS_STRUCT_ADD(ptr,   ccx)
			AS_STRUCT_ADD(ptr,   cdx)
			AS_STRUCT_ADD(ptr,   cbx)
			AS_STRUCT_ADD(ptr,   csp)
			AS_STRUCT_ADD(ptr,   cbp)
			AS_STRUCT_ADD(ptr,   csi)
			AS_STRUCT_ADD(ptr,   cdi)
#ifdef _WIN64
			AS_STRUCT_ADD(ptr,   r8)
			AS_STRUCT_ADD(ptr,   r9)
			AS_STRUCT_ADD(ptr,   r10)
			AS_STRUCT_ADD(ptr,   r11)
			AS_STRUCT_ADD(ptr,   r12)
			AS_STRUCT_ADD(ptr,   r13)
			AS_STRUCT_ADD(ptr,   r14)
			AS_STRUCT_ADD(ptr,   r15)
#endif
			AS_STRUCT_ADD(ptr,   cip)
			AS_STRUCT_ADD(uint,  eflags)
			AS_STRUCT_ADD(FLAGS, flags)
			AS_STRUCT_ADD(word,  gs)
			AS_STRUCT_ADD(word,  fs)
			AS_STRUCT_ADD(word,  es)
			AS_STRUCT_ADD(word,  ds)
			AS_STRUCT_ADD(word,  cs)
			AS_STRUCT_ADD(word,  ss)
			AS_STRUCT_ADD(ptr,   dr0)
			AS_STRUCT_ADD(ptr,   dr1)
			AS_STRUCT_ADD(ptr,   dr2)
			AS_STRUCT_ADD(ptr,   dr3)
			AS_STRUCT_ADD(ptr,   dr6)
			AS_STRUCT_ADD(ptr,   dr7)
		AS_END_STRUCT()

		// DISASM_ARG
		AS_BEGIN_STRUCT(DISASM_ARG)
			AS_STRUCT_ADD(DISASM_ARGTYPE, type)
			AS_STRUCT_ADD(SEGMENTREG, segment)
			AS_STRUCT_ACCESS(string,  mnemonic, STR_GET(mnemonic), STR_SET(mnemonic))
			AS_STRUCT_ADD(ptr,        constant)
			AS_STRUCT_ADD(ptr,        value)
			AS_STRUCT_ADD(ptr,        memvalue)
		AS_END_STRUCT()

		// DISASM_INSTR
		AS_BEGIN_STRUCT(DISASM_INSTR)
			AS_STRUCT_ACCESS(string,         instruction, STR_GET(instruction), STR_SET(instruction))
			AS_STRUCT_ADD(DISASM_INSTRTYPE,  type)
			AS_STRUCT_ADD(int,               argcount)
			AS_STRUCT_ADD(int,               instr_size)
			AS_ADD_STRUCT_ARRAY(DISASM_ARG&, arg,
			-> DISASM_ARG*
			{
				if (Index > ARRAYSIZE(Obj->arg))
					return nullptr;

				return &Obj->arg[Index];
			})
		AS_END_STRUCT()
	}

	void FORCEINLINE RegisterWindowsStructs(asIScriptEngine *Engine)
	{
		// MEMORY_BASIC_INFORMATION
		AS_BEGIN_STRUCT(MEMORY_BASIC_INFORMATION)
			AS_STRUCT_ADD(ptr,   BaseAddress)
			AS_STRUCT_ADD(ptr,   AllocationBase)
			AS_STRUCT_ADD(dword, AllocationProtect)
			AS_STRUCT_ADD(ptr,   RegionSize)
			AS_STRUCT_ADD(dword, State)
			AS_STRUCT_ADD(dword, Protect)
			AS_STRUCT_ADD(dword, Type)
		AS_END_STRUCT()

		// EXCEPTION_RECORD
		AS_BEGIN_STRUCT(EXCEPTION_RECORD)
			AS_STRUCT_ADD(dword,     ExceptionCode)
			AS_STRUCT_ADD(dword,     ExceptionFlags)
			AS_ADD_STRUCT_ACCESS_MOD(EXCEPTION_RECORD, ExceptionRecord, "&", { return Obj->ExceptionRecord; }, { Obj->ExceptionRecord = &Val; })
			AS_STRUCT_ADD(ptr,       ExceptionAddress)
			AS_STRUCT_ADD(dword,     NumberParameters)
			AS_ADD_STRUCT_ARRAY(ptr, ExceptionInformation,
			-> ULONG_PTR
			{
				if (Index > ARRAYSIZE(Obj->ExceptionInformation))
					return 0;

				return Obj->ExceptionInformation[Index];
			})
		AS_END_STRUCT()

		// CREATE_THREAD_DEBUG_INFO
		AS_BEGIN_STRUCT(CREATE_THREAD_DEBUG_INFO)
			AS_STRUCT_ADD(handle, hThread)
			AS_STRUCT_ADD(ptr,    lpThreadLocalBase)
			AS_STRUCT_ADD(ptr,    lpStartAddress)
		AS_END_STRUCT()

		// CREATE_PROCESS_DEBUG_INFO
		AS_BEGIN_STRUCT(CREATE_PROCESS_DEBUG_INFO)
			AS_STRUCT_ADD(handle, hFile)
			AS_STRUCT_ADD(handle, hProcess)
			AS_STRUCT_ADD(handle, hThread)
			AS_STRUCT_ADD(ptr,    lpBaseOfImage)
			AS_STRUCT_ADD(dword,  dwDebugInfoFileOffset)
			AS_STRUCT_ADD(dword,  nDebugInfoSize)
			AS_STRUCT_ADD(ptr,    lpThreadLocalBase)
			AS_STRUCT_ADD(ptr,    lpStartAddress)
			AS_STRUCT_ADD(ptr,    lpImageName)
			AS_STRUCT_ADD(word,   fUnicode)
		AS_END_STRUCT()

		// LOAD_DLL_DEBUG_INFO
		AS_BEGIN_STRUCT(LOAD_DLL_DEBUG_INFO)
			AS_STRUCT_ADD(handle, hFile)
			AS_STRUCT_ADD(ptr,    lpBaseOfDll)
			AS_STRUCT_ADD(dword,  dwDebugInfoFileOffset)
			AS_STRUCT_ADD(dword,  nDebugInfoSize)
			AS_STRUCT_ADD(ptr,    lpImageName)
			AS_STRUCT_ADD(word,   fUnicode)
		AS_END_STRUCT()
	}
}