#pragma once

#include <Windows.h>
#include <string>

namespace Game {
	
	typedef struct {
		HANDLE hdlProcess;
		DWORD dwProcessId;
		std::wstring wstrClientName;
		uintptr_t moduleAddress;
	} Client;
}

inline namespace Offsets {
	namespace Player {


		// Add the moduleBaseAddrs just before
		constexpr uintptr_t entityList = 0x18AC04;
		constexpr uintptr_t localEntityPlayerPtr = 0x18AC00;

		// Player info
		constexpr uintptr_t strName = 0x205;
		constexpr uintptr_t intHealth = 0xEC;
		constexpr uintptr_t intArmor = 0xF0;

		// View Angles
		constexpr uintptr_t flViewAngleX = 0x34; // MAX 360
		constexpr uintptr_t flViewAngleY = 0x38;// MAX 90
		constexpr uintptr_t intFieldOfView = 0x334;

		// Positions

		// Head positions
		constexpr uintptr_t flHeadPosX = 0x4;
		constexpr uintptr_t flHeadPosY = 0x8;
		constexpr uintptr_t flHeadPosZ = 0xC;

		// Body positions
		constexpr uintptr_t flPosX = 0x0;
		constexpr uintptr_t flPosY = 0x0;
		constexpr uintptr_t flPosZ = 0x0;
	}
	namespace Gun {

		constexpr uintptr_t intAmmo = 0x150;
	}
}
