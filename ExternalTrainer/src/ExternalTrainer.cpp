
#include <iostream>
#include "Proc.h"
#include "Mem.h"
#include "Game.h"

int main()
{									
	Game::Client client;  // Mettre L pour unicode

	client.wstrClientName.append(L"ac_client.exe");
	client.dwProcessId = Process::GetProcId(client.wstrClientName);
	client.hdlProcess = Process::AttachProc(client.dwProcessId);
	client.moduleAddress = Process::GetModuleBaseAddrs(client.wstrClientName, client.dwProcessId);

	uintptr_t localPlayer = Memory::Read<uintptr_t>(client.hdlProcess, client.moduleAddress + Player::localEntityPlayerPtr);
	uintptr_t healthAddrs = localPlayer + Player::intHealth;

	int healthValue = 240;

	printf("%X\n", healthAddrs);
	printf("%zX\n", client.moduleAddress);
	printf("%d\n", client.dwProcessId);
	Memory::Write<int>(client.hdlProcess,  healthAddrs, healthValue);
	//printf("Write: %d\n", Memory::Write<int>(client.hdlProcess, healthAddrs, healthValue));
	

}
