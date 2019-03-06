#pragma once
#include <Windows.h>
#include <functional>
#include <vector>

// so you create your all your defs and all that jazz
// and then jump to the bottom of this file and create
// "ezCall" (tm) defines to one line these bad boys

typedef enum _MEMORY_INFORMATION_CLASS {
	MemoryBasicInformation
} MEMORY_INFORMATION_CLASS;

using fnNtQueryVirtualMemory = NTSTATUS( NTAPI* )(HANDLE ProcessHandle, PVOID BaseAddress, MEMORY_INFORMATION_CLASS MemoryInformationClass, PVOID MemoryInformation, SIZE_T MemoryInformationLength, PSIZE_T ReturnLength);

class TSyscall
{
	static void* pCodeLoc;
public:

	template<class T>
	static std::function<T> GetInvoke( const char* sFunction, T* pAddress = nullptr );
};

template<class T>
std::function<T> TSyscall::GetInvoke( const char* sFunction, T * pAddress )
{
	if ( !pCodeLoc )
	{
		pCodeLoc = VirtualAlloc( nullptr, 0x1000, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE ); // if you really want to be sneaky you can scan for a code cave
#ifdef _WIN64
		BYTE cb[] = { 0x4C, 0x8B, 0xD1, 0xB8, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x05, 0xC3 };
		memcpy( pCodeLoc, cb, ARRAYSIZE( cb ) );
#endif
	}

	auto pStub = (DWORD*) GetProcAddress( GetModuleHandle( "ntdll.dll" ), sFunction ); // sneakier ways to do this too
#ifdef _WIN64
	memcpy( (DWORD*) pCodeLoc + 1, pStub + 1, sizeof( DWORD ) );
#else
	memcpy( pCodeLoc, pStub, 15 );
#endif
	return std::function<T>( (T*) pCodeLoc );
}

#define _sc(t, s) TSyscall::GetInvoke(s, (t)nullptr)

// use the define above to create an ezCall (tm) define like below.
#define ScQueryVirtualMemory _sc(fnNtQueryVirtualMemory, "NtQueryVirtualMemory")
