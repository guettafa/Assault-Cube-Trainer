#pragma once
#include <Windows.h>

namespace Memory {

	template<typename T>
	inline BOOL Read(HANDLE hProc, LPCVOID addressToRead, T saveDataIn) {
		return ReadProcessMemory(hProc, addressToRead, &saveDataIn, sizeof(T), NULL);
	}

	template<typename T>
	inline BOOL Write(HANDLE hProc, LPVOID addressToModify, T dataToWrite) {
		return WriteProcessMemory(
			hProc,
			addressToModify,
			&dataToWrite,
			sizeof(T),
			NULL);
	}
}


