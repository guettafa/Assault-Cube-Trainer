
#include "Proc.h"
#include <TlHelp32.h>
#include <iostream>

HANDLE Process::AttachProc(DWORD procId) {
	return OpenProcess(
		PROCESS_ALL_ACCESS,
		FALSE,
		procId);
}

DWORD Process::GetProcId(const std::wstring &procName) {

	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hSnap == INVALID_HANDLE_VALUE) {

		printf("%s\n", GetLastError());
		exit(EXIT_FAILURE);
	}

	// To store process information
	PROCESSENTRY32 procInfo;
	procInfo.dwSize = sizeof(PROCESSENTRY32); // declare sa taille
	
	for (register size_t i = 0; i < procInfo.dwSize; i++) {
	
		// Look for the next process ( to iterate through the process list )
		Process32Next(hSnap, &procInfo);

		// Compare the name of the process we are 
		// looking for with the process in the loop
		if (!procName.compare(procInfo.szExeFile)) {

			// Ferme le snapshot handle et retourne le processId du process qu'on veut trouver
			CloseHandle(hSnap);
			return procInfo.th32ProcessID;
		}
	}
	// Nothing found ;(
	CloseHandle(hSnap);
	exit(EXIT_FAILURE);
}

uintptr_t Process::GetModuleBaseAddrs(const std::wstring& moduleName, DWORD procId) {
												// For 32 bits modules  /  For 64 bits too 
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, procId);

	if (hSnap == INVALID_HANDLE_VALUE) {

		printf("%s\n", GetLastError());
		exit(EXIT_FAILURE);
	}

	// To store process information
	MODULEENTRY32 moduleInfo;
	moduleInfo.dwSize = sizeof(MODULEENTRY32); // declare sa taille

	Module32First(hSnap, &moduleInfo);
	if (!moduleName.compare(moduleInfo.szModule)) {
		CloseHandle(hSnap);
		return reinterpret_cast<uintptr_t>(moduleInfo.modBaseAddr);
	}

	for (register size_t i = 0; i < moduleInfo.dwSize; i++) {

		// Look for the next process ( to iterate through the process list )
		Module32Next(hSnap, &moduleInfo);

		// Compare the name of the process we are 
		// looking for with the process in the loop
		if (!moduleName.compare(moduleInfo.szModule)) {

			// Ferme le snapshot handle et retourne le processId du process qu'on veut trouver
			CloseHandle(hSnap);
			return reinterpret_cast<uintptr_t> (moduleInfo.modBaseAddr);
		}
	}
	// Nothing found ;(
	CloseHandle(hSnap);
	exit(EXIT_FAILURE);
}