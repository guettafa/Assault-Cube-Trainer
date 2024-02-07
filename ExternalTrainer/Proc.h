#pragma once

#include <Windows.h>
#include <TlHelp32.h>
#include <string>
#include <iostream>


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

	/*
		Used to return the module base
		address of the target process
	*/
	uintptr_t GetModuleBaseAddrs(const std::wstring &moduleName, DWORD procId);
}
