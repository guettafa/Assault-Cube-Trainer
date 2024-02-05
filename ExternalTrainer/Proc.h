#pragma once

#include <Windows.h>
#include <string>

namespace Process {

	/*
		Used to return a handle
		of the target process
	*/
	HANDLE AttachProc(DWORD procId);
	/*
		Used to return the process ID
		of the target process
	*/
	DWORD GetProcId(const std::wstring &procName);
	uintptr_t GetModuleBaseAddrs(const std::wstring &moduleName, DWORD procId);
}
