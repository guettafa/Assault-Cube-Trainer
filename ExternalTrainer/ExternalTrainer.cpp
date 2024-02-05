
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
	
	int healthValue = 200;
	uintptr_t healthAddrs = 0x0082F644;


	printf("%zX\n", client.moduleAddress);
	printf("%d\n", client.dwProcessId);
	printf("Read: %d\n", Memory::Read<int>(client.hdlProcess, reinterpret_cast<LPCVOID>(healthAddrs), healthValue));
	printf("Write: %d\n", Memory::Write<int>(client.hdlProcess, reinterpret_cast<LPVOID>(healthAddrs), healthValue));
	

}
