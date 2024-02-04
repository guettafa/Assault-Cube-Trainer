#pragma once

#include <Windows.h>
#include <string>

namespace Process {

	/*
		Used to return a handle
		of the target process
	*/
	BOOL AttachProc(DWORD pid);
	/*
		Used to return the process ID
		of the target process
	*/
	DWORD GetProcId(const std::wstring &procName);
}
