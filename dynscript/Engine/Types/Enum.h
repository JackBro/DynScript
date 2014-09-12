#pragma once

namespace Script
{
	void FORCEINLINE RegisterDefaultEnums(asIScriptEngine *Engine)
	{
		// DBGSTATE
		AS_BEGIN_ENUM(DBGSTATE)
			AS_ADD_ENUM(initialized)
			AS_ADD_ENUM(paused)
			AS_ADD_ENUM(running)
			AS_ADD_ENUM(stopped)
		AS_END_ENUM()

		// SEGMENTREG
		AS_BEGIN_ENUM(SEGMENTREG)
			AS_ADD_ENUM(SEG_DEFAULT)
			AS_ADD_ENUM(SEG_ES)
			AS_ADD_ENUM(SEG_DS)
			AS_ADD_ENUM(SEG_FS)
			AS_ADD_ENUM(SEG_GS)
			AS_ADD_ENUM(SEG_CS)
			AS_ADD_ENUM(SEG_SS)
		AS_END_ENUM()

		// ADDRINFOFLAGS
		AS_BEGIN_ENUM(ADDRINFOFLAGS)
			AS_ADD_ENUM(flagmodule)
			AS_ADD_ENUM(flaglabel)
			AS_ADD_ENUM(flagcomment)
			AS_ADD_ENUM(flagbookmark)
			AS_ADD_ENUM(flagfunction)
			AS_ADD_ENUM(flagloop)
		AS_END_ENUM()

		// BPXTYPE
		AS_BEGIN_ENUM(BPXTYPE)
			AS_ADD_ENUM(bp_none)
			AS_ADD_ENUM(bp_normal)
			AS_ADD_ENUM(bp_hardware)
			AS_ADD_ENUM(bp_memory)
		AS_END_ENUM()

		// FUNCTYPE
		AS_BEGIN_ENUM(FUNCTYPE)
			AS_ADD_ENUM(FUNC_NONE)
			AS_ADD_ENUM(FUNC_BEGIN)
			AS_ADD_ENUM(FUNC_MIDDLE)
			AS_ADD_ENUM(FUNC_END)
			AS_ADD_ENUM(FUNC_SINGLE)
		AS_END_ENUM()

		// LOOPTYPE
		AS_BEGIN_ENUM(LOOPTYPE)
			AS_ADD_ENUM(LOOP_NONE)
			AS_ADD_ENUM(LOOP_BEGIN)
			AS_ADD_ENUM(LOOP_MIDDLE)
			AS_ADD_ENUM(LOOP_ENTRY)
			AS_ADD_ENUM(LOOP_END)
		AS_END_ENUM()

		// DBGMSG

		// SCRIPTLINETYPE
		AS_BEGIN_ENUM(SCRIPTLINETYPE)
			AS_ADD_ENUM(linecommand)
			AS_ADD_ENUM(linebranch)
			AS_ADD_ENUM(linelabel)
			AS_ADD_ENUM(linecomment)
			AS_ADD_ENUM(lineempty)
		AS_END_ENUM()

		// SCRIPTBRANCHTYPE
		AS_BEGIN_ENUM(SCRIPTBRANCHTYPE)
			AS_ADD_ENUM(scriptnobranch)
			AS_ADD_ENUM(scriptjmp)
			AS_ADD_ENUM(scriptjnejnz)
			AS_ADD_ENUM(scriptjejz)
			AS_ADD_ENUM(scriptjbjl)
			AS_ADD_ENUM(scriptjajg)
			AS_ADD_ENUM(scriptjbejle)
			AS_ADD_ENUM(scriptjaejge)
			AS_ADD_ENUM(scriptcall)
		AS_END_ENUM()

		// DISASM_INSTRTYPE
		AS_BEGIN_ENUM(DISASM_INSTRTYPE)
			AS_ADD_ENUM(instr_normal)
			AS_ADD_ENUM(instr_branch)
			AS_ADD_ENUM(instr_stack)
		AS_END_ENUM()

		// DISASM_ARGTYPE
		AS_BEGIN_ENUM(DISASM_ARGTYPE)
			AS_ADD_ENUM(arg_normal)
			AS_ADD_ENUM(arg_memory)
		AS_END_ENUM()

		// DISASM_ARGTYPE
		AS_BEGIN_ENUM(STRING_TYPE)
			AS_ADD_ENUM(str_none)
			AS_ADD_ENUM(str_ascii)
			AS_ADD_ENUM(str_unicode)
		AS_END_ENUM()

		// THREADPRIORITY
		// THREADWAITREASON

		// DISASM_ARGTYPE
		AS_BEGIN_ENUM(MEMORY_SIZE)
			AS_ADD_ENUM(size_byte)
			AS_ADD_ENUM(size_word)
			AS_ADD_ENUM(size_dword)
			AS_ADD_ENUM(size_qword)
		AS_END_ENUM()
	}
}