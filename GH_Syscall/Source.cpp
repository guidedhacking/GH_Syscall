#include <iostream>
#include "gh_syscall.h"
#include "nt_defs.h"
#include "syscall_defs.h"

using namespace std;

int main()
{
	MEMORY_BASIC_INFORMATION mbi{ 0 };
	SIZE_T retLen = 0;
	ScQueryVirtualMemory( HANDLE( -1 ), (PVOID) Sleep, MemoryBasicInformation, (PVOID) &mbi, sizeof( mbi ), &retLen );

	HANDLE hProc = nullptr;
	OBJECT_ATTRIBUTES oa{ 0 };
	oa.Length = sizeof( oa );
	CLIENT_ID ci{ 0 };
	DWORD dwPID = GetCurrentProcessId();
	ci.UniqueProcess = (void*)dwPID;
	NTSTATUS ntStatus = ScOpenProcess(&hProc, PROCESS_ALL_ACCESS, &oa, &ci);

	if ( ntStatus )
	{
		cout << "Failed to open process..." << endl;
	}

	if ( retLen )
	{
		cout << "Sleep is on page 0x" << mbi.BaseAddress << endl;
	}

	ntStatus = ScClose( hProc );

	getchar();

	return 0;
}