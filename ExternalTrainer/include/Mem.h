#pragma once
#include <Windows.h>

namespace Memory {

	// Thx Anas
	template<typename T>
	inline T Read(HANDLE hProc, uintptr_t source) {
		T destination;
		ReadProcessMemory(hProc, reinterpret_cast<LPCVOID>(source), &destination, sizeof(T), NULL);
		return destination;
	}

	template<typename T>
	inline VOID Write(HANDLE hProc, int32_t addressToModify, T dataToWrite) {
		WriteProcessMemory(
			hProc,
			reinterpret_cast<LPVOID>(addressToModify),
			&dataToWrite,
			sizeof(T),
			NULL);
	}
	
}


