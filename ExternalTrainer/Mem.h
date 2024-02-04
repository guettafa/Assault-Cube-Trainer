#pragma once
#include <Windows.h>

namespace Memory {

	template<typename T>
	void Read(void);

	template<typename T>
	void Write(HANDLE hProcess, T stuff);
}


