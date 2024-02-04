
#include <iostream>
#include "Proc.h"

int main()
{
	printf("pid: %d\n", Process::GetProcId(L"ac_client.exe"));
}
