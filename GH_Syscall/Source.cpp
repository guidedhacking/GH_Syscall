#include <iostream>
#include "gh_syscall.h"

using namespace std;

int main()
{
	MEMORY_BASIC_INFORMATION mbi{ 0 };
	SIZE_T retLen = 0;
	ScQueryVirtualMemory( HANDLE( -1 ), (PVOID) Sleep, MemoryBasicInformation, (PVOID) &mbi, sizeof( mbi ), &retLen );

	if ( retLen )
	{
		cout << "Sleep is on page 0x" << mbi.BaseAddress << endl;
	}

	getchar();

	return 0;
}