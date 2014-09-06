#include "../stdafx.h"

namespace Script
{
namespace Dbg
{
	void Init(asIScriptEngine *Engine)
	{
		// Register all debugger variables and functions
		Engine->SetDefaultNamespace("Dbg");

		//
		// VARIABLES
		//
		VERIFY(Engine->RegisterGlobalProperty("const int PluginHandle", &pluginHandle));
		VERIFY(Engine->RegisterGlobalProperty("const handle ProcessHandle", &pluginHandle));

		//
		// FUNCTIONS
		//
		VERIFY(Engine->RegisterGlobalFunction("ptr ValFromString(string &in Value)", asFUNCTION(asValFromString), asCALL_CDECL));

		VERIFY(Engine->RegisterGlobalFunction("bool MemWrite(ptr Address, ptr Buffer, uint Size, uint &out BytesWritten = 0)", asFUNCTION(asMemWrite), asCALL_CDECL));
		VERIFY(Engine->RegisterGlobalFunction("bool MemRead(ptr Address, ptr Buffer, uint Size, uint &out BytesRead = 0)", asFUNCTION(asMemRead), asCALL_CDECL));
		VERIFY(Engine->RegisterGlobalFunction("bool MemFill(ptr Address, byte Value, uint Size)", asFUNCTION(asMemFill), asCALL_CDECL));
		VERIFY(Engine->RegisterGlobalFunction("ptr MemGetPageSize(ptr Base)", asFUNCTION(asMemGetPageSize), asCALL_CDECL));
		VERIFY(Engine->RegisterGlobalFunction("ptr MemGetBaseAddr(ptr Address, uint &out Size = 0)", asFUNCTION(asMemGetBaseAddr), asCALL_CDECL));
		VERIFY(Engine->RegisterGlobalFunction("bool CmdExec(string &in Cmd)", asFUNCTION(asCmdExec), asCALL_CDECL));
		VERIFY(Engine->RegisterGlobalFunction("bool CmdExecDirect(string &in Cmd)", asFUNCTION(asCmdExecDirect), asCALL_CDECL));
		//VERIFY(Engine->RegisterGlobalFunction("bool MemMap(........)", asFUNCTION(asMemMap), asCALL_CDECL));
		VERIFY(Engine->RegisterGlobalFunction("bool IsValidExpression(string &in Expression)", asFUNCTION(asIsValidExpression), asCALL_CDECL));
		VERIFY(Engine->RegisterGlobalFunction("bool IsDebugging()", asFUNCTION(asIsDebugging), asCALL_CDECL));
		VERIFY(Engine->RegisterGlobalFunction("bool IsJumpGoingToExecute(ptr Address)", asFUNCTION(asIsJumpGoingToExecute), asCALL_CDECL));
	}

	ULONG_PTR asValFromString(std::string &Value)
	{
		return (ULONG_PTR)DbgValFromString(Value.c_str());
	}

	bool asMemWrite(PVOID Address, PVOID Buffer, asUINT Size, asUINT *BytesWritten)
	{
		if (DbgMemWrite((duint)Address, (PUCHAR)Buffer, Size))
		{
			if (BytesWritten)
				*BytesWritten = Size;

			return true;
		}

		if (BytesWritten)
			*BytesWritten = 0;

		return false;
	}

	bool asMemRead(PVOID Address, PVOID Buffer, asUINT Size, asUINT *BytesRead)
	{
		if (DbgMemRead((duint)Address, (PUCHAR)Buffer, Size))
		{
			if (BytesRead)
				*BytesRead = Size;

			return true;
		}

		if (BytesRead)
			*BytesRead = 0;

		return false;
	}

	bool asMemFill(PVOID Address, asBYTE Value, asUINT Size)
	{
		asBYTE buffer[512];
		memset(buffer, Value, min(Size, sizeof(buffer)));

		for (; Size > 0;)
		{
			if (!asMemWrite(Address, buffer, min(Size, sizeof(buffer)), nullptr))
				return false;

			Size -= min(Size, sizeof(buffer));
		}

		return true;
	}

	ULONG_PTR asMemGetPageSize(ULONG_PTR Base)
	{
		return DbgMemGetPageSize(Base);
	}

	ULONG_PTR asMemGetBaseAddr(ULONG_PTR Address, asUINT *Size)
	{
		duint retSize	= 0;
		ULONG_PTR base	= DbgMemFindBaseAddr(Address, &retSize);

		if (*Size)
			*Size = retSize;

		return base;
	}

	bool asCmdExec(std::string &Cmd)
	{
		return DbgCmdExec(Cmd.c_str());
	}

	bool asCmdExecDirect(std::string &Cmd)
	{
		return DbgCmdExecDirect(Cmd.c_str());
	}

// 	bool asMemMap(/*....*/)
// 	{
// 		return false;
// 	}

	bool asIsValidExpression(std::string &Expression)
	{
		return DbgIsValidExpression(Expression.c_str());
	}

	bool asIsDebugging()
	{
		return DbgIsDebugging();
	}

	bool asIsJumpGoingToExecute(ULONG_PTR Address)
	{
		return DbgIsJumpGoingToExecute(Address);
	}
}
}