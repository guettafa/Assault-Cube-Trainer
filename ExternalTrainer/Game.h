#pragma once

#include <Windows.h>
#include <string>

namespace Offsets {

	namespace Player {

		// Player info
		constexpr uintptr_t strName = 0x205;
		constexpr uintptr_t intHealth = 0xEC;
		constexpr uintptr_t intArmor = 0xF0;

		// View Angles
		constexpr uintptr_t flViewAngleX = 0x34; // MAX 360
		constexpr uintptr_t flViewAngleY = 0x38;// MAX 90

		// Positions
		constexpr uintptr_t flPosX = 0x0;
		constexpr uintptr_t flPosY = 0x0;
		constexpr uintptr_t flPosZ = 0x0;

	}

	namespace Gun{
		
		constexpr uintptr_t intAmmo = 0x150;
	}
}

namespace Game {
	
	typedef struct {

		HANDLE hdlProcess;
		DWORD dwProcessId;
		std::wstring wstrClientName;
		uintptr_t moduleAddress;
	} Client;
}
