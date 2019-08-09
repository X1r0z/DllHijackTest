// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 头文件
#include <Windows.h>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 导出函数
#pragma comment(linker, "/EXPORT:SignWith3Des=_AheadLib_SignWith3Des,@26")
#pragma comment(linker, "/EXPORT:StartWachat=_AheadLib_StartWachat,@27")
#pragma comment(linker, "/EXPORT:___ASSERT=_AheadLib___ASSERT,@30")
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 原函数地址指针
PVOID pfn__4IMVQQEngine__QAEAAV0_ABV0__Z;
PVOID pfn___FIMVQQEngine__QAEXXZ;
PVOID pfn_AddExtraMem_TXBugReport__YAHKI_Z;
PVOID pfn_AddExtraMem_TXBugReport__YAHPAXI_Z;
PVOID pfn_AddIgnoreHookCheckModule_TXBugReport__YAXPB_W_Z;
PVOID pfn_AddReleaseMonitorPoint_TXBugReport__YAXPAJ_Z;
PVOID pfn_DoBugReport_TXBugReport__YAJPAU_EXCEPTION_POINTERS__PB_W_Z;
PVOID pfn_GetBugReportFlag_TXBugReport__YAKXZ;
PVOID pfn_GetBugReportInfo_TXBugReport__YAPAUtagBugReportInfo_1_XZ;
PVOID pfn_GetCustomFiltFunc_TXBugReport__YAP6AHPAU_EXCEPTION_POINTERS___ZXZ;
PVOID pfn_InitBugReport_TXBugReport__YAXPB_W000GGKHHKKP6GHPAUtagBugReportInfo_1_PBD200PAPAXPAKPAX_Z_Z;
PVOID pfn_InitBugReportEx_TXBugReport__YAXPB_W000GGKHHKKP6GHPAUtagBugReportInfo_1_PBD200PAPAXPAKPAX_ZH_Z;
PVOID pfn_RaiseSelfFatalException_TXBugReport__YAXW4SelfException_1__Z;
PVOID pfn_RecordCallStackIfNeed_TXBugReport__YAXPAJ_Z;
PVOID pfn_SetBugReportFlag_TXBugReport__YAHK_Z;
PVOID pfn_SetBugReportPath_TXBugReport__YAHPB_W_Z;
PVOID pfn_SetBugReportUin_TXBugReport__YAXKH_Z;
PVOID pfn_SetCustomFiltFunc_TXBugReport__YAXP6AHPAU_EXCEPTION_POINTERS___Z_Z;
PVOID pfn_SetExtInfo_TXBugReport__YAHKKPB_W_Z;
PVOID pfn_SetExtRptFilePath_TXBugReport__YAHPB_W0_Z;
PVOID pfn_SetLogFileMd5Dir_TXBugReport__YAHPB_W00_Z;
PVOID pfn_UninitBugReport_TXBugReport__YAXXZ;
PVOID pfn_ValidateBugReport_TXBugReport__YAXXZ;
PVOID pfnSignWith3Des;
PVOID pfnStartWachat;
PVOID pfn__ASSERT;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 宏定义
#define EXTERNC extern "C"
#define NAKED __declspec(naked)
#define EXPORT __declspec(dllexport)

#define ALCPP EXPORT NAKED
#define ALSTD EXTERNC EXPORT NAKED void __stdcall
#define ALCFAST EXTERNC EXPORT NAKED void __fastcall
#define ALCDECL EXTERNC NAKED void __cdecl
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// AheadLib 命名空间
namespace AheadLib
{
	HMODULE m_hModule = NULL;	// 原始模块句柄
	DWORD m_dwReturn[30] = { 0 };	// 原始函数返回地址


	// 获取原始函数地址
	FARPROC WINAPI GetAddress(PCSTR pszProcName)
	{
		FARPROC fpAddress;
		CHAR szProcName[16];
		TCHAR tzTemp[MAX_PATH];

		fpAddress = GetProcAddress(m_hModule, pszProcName);
		if (fpAddress == NULL)
		{
			if (HIWORD(pszProcName) == 0)
			{
				wsprintfA(szProcName, "%d", pszProcName);
				pszProcName = szProcName;
			}

			wsprintf(tzTemp, TEXT("无法找到函数 %hs，程序无法正常运行。"), pszProcName);
			MessageBox(NULL, tzTemp, TEXT("AheadLib"), MB_ICONSTOP);
			ExitProcess(-2);
		}

		return fpAddress;
	}

	// 初始化原始函数地址指针
	inline VOID WINAPI InitializeAddresses()
	{
		pfn__4IMVQQEngine__QAEAAV0_ABV0__Z = GetAddress("??4IMVQQEngine@@QAEAAV0@ABV0@@Z");
		pfn___FIMVQQEngine__QAEXXZ = GetAddress("??_FIMVQQEngine@@QAEXXZ");
		pfn_AddExtraMem_TXBugReport__YAHKI_Z = GetAddress("?AddExtraMem@TXBugReport@@YAHKI@Z");
		pfn_AddExtraMem_TXBugReport__YAHPAXI_Z = GetAddress("?AddExtraMem@TXBugReport@@YAHPAXI@Z");
		pfn_AddIgnoreHookCheckModule_TXBugReport__YAXPB_W_Z = GetAddress("?AddIgnoreHookCheckModule@TXBugReport@@YAXPB_W@Z");
		pfn_AddReleaseMonitorPoint_TXBugReport__YAXPAJ_Z = GetAddress("?AddReleaseMonitorPoint@TXBugReport@@YAXPAJ@Z");
		pfn_DoBugReport_TXBugReport__YAJPAU_EXCEPTION_POINTERS__PB_W_Z = GetAddress("?DoBugReport@TXBugReport@@YAJPAU_EXCEPTION_POINTERS@@PB_W@Z");
		pfn_GetBugReportFlag_TXBugReport__YAKXZ = GetAddress("?GetBugReportFlag@TXBugReport@@YAKXZ");
		pfn_GetBugReportInfo_TXBugReport__YAPAUtagBugReportInfo_1_XZ = GetAddress("?GetBugReportInfo@TXBugReport@@YAPAUtagBugReportInfo@1@XZ");
		pfn_GetCustomFiltFunc_TXBugReport__YAP6AHPAU_EXCEPTION_POINTERS___ZXZ = GetAddress("?GetCustomFiltFunc@TXBugReport@@YAP6AHPAU_EXCEPTION_POINTERS@@@ZXZ");
		pfn_InitBugReport_TXBugReport__YAXPB_W000GGKHHKKP6GHPAUtagBugReportInfo_1_PBD200PAPAXPAKPAX_Z_Z = GetAddress("?InitBugReport@TXBugReport@@YAXPB_W000GGKHHKKP6GHPAUtagBugReportInfo@1@PBD200PAPAXPAKPAX@Z@Z");
		pfn_InitBugReportEx_TXBugReport__YAXPB_W000GGKHHKKP6GHPAUtagBugReportInfo_1_PBD200PAPAXPAKPAX_ZH_Z = GetAddress("?InitBugReportEx@TXBugReport@@YAXPB_W000GGKHHKKP6GHPAUtagBugReportInfo@1@PBD200PAPAXPAKPAX@ZH@Z");
		pfn_RaiseSelfFatalException_TXBugReport__YAXW4SelfException_1__Z = GetAddress("?RaiseSelfFatalException@TXBugReport@@YAXW4SelfException@1@@Z");
		pfn_RecordCallStackIfNeed_TXBugReport__YAXPAJ_Z = GetAddress("?RecordCallStackIfNeed@TXBugReport@@YAXPAJ@Z");
		pfn_SetBugReportFlag_TXBugReport__YAHK_Z = GetAddress("?SetBugReportFlag@TXBugReport@@YAHK@Z");
		pfn_SetBugReportPath_TXBugReport__YAHPB_W_Z = GetAddress("?SetBugReportPath@TXBugReport@@YAHPB_W@Z");
		pfn_SetBugReportUin_TXBugReport__YAXKH_Z = GetAddress("?SetBugReportUin@TXBugReport@@YAXKH@Z");
		pfn_SetCustomFiltFunc_TXBugReport__YAXP6AHPAU_EXCEPTION_POINTERS___Z_Z = GetAddress("?SetCustomFiltFunc@TXBugReport@@YAXP6AHPAU_EXCEPTION_POINTERS@@@Z@Z");
		pfn_SetExtInfo_TXBugReport__YAHKKPB_W_Z = GetAddress("?SetExtInfo@TXBugReport@@YAHKKPB_W@Z");
		pfn_SetExtRptFilePath_TXBugReport__YAHPB_W0_Z = GetAddress("?SetExtRptFilePath@TXBugReport@@YAHPB_W0@Z");
		pfn_SetLogFileMd5Dir_TXBugReport__YAHPB_W00_Z = GetAddress("?SetLogFileMd5Dir@TXBugReport@@YAHPB_W00@Z");
		pfn_UninitBugReport_TXBugReport__YAXXZ = GetAddress("?UninitBugReport@TXBugReport@@YAXXZ");
		pfn_ValidateBugReport_TXBugReport__YAXXZ = GetAddress("?ValidateBugReport@TXBugReport@@YAXXZ");
		pfnSignWith3Des = GetAddress("SignWith3Des");
		pfnStartWachat = GetAddress("StartWachat");
		pfn__ASSERT = GetAddress("__ASSERT");
	}

	// 加载原始模块
	inline BOOL WINAPI Load()
	{
		TCHAR tzPath[MAX_PATH];
		TCHAR tzTemp[MAX_PATH * 2];

		lstrcpy(tzPath, TEXT("WeChatWinOrg.dll"));
		m_hModule = LoadLibrary(tzPath);
		if (m_hModule == NULL)
		{
			wsprintf(tzTemp, TEXT("无法加载 %s，程序无法正常运行。"), tzPath);
			MessageBox(NULL, tzTemp, TEXT("AheadLib"), MB_ICONSTOP);
		}
		else
		{
			InitializeAddresses();
		}

		return (m_hModule != NULL);
	}

	// 释放原始模块
	inline VOID WINAPI Free()
	{
		if (m_hModule)
		{
			FreeLibrary(m_hModule);
		}
	}
}
using namespace AheadLib;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 入口函数
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, PVOID pvReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		STARTUPINFO si = { sizeof(si) };
		PROCESS_INFORMATION pi;
		CreateProcess(TEXT("C:\\Windows\\System32\\calc.exe"), NULL, NULL, NULL, false, 0, NULL, NULL, &si, &pi);
		DisableThreadLibraryCalls(hModule);

		return Load();
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		Free();
	}

	return TRUE;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 导出函数
ALCDECL AheadLib_SignWith3Des(void)
{
	__asm JMP pfnSignWith3Des;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 导出函数
ALCDECL AheadLib_StartWachat(void)
{
	__asm JMP pfnStartWachat;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 导出函数
ALCDECL AheadLib___ASSERT(void)
{
	__asm JMP pfn__ASSERT;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma comment(linker, "/EXPORT:??_FIMVQQEngine@@QAEXXZ=WeChatWinOrg.??_FIMVQQEngine@@QAEXXZ,@2")
#pragma comment(linker, "/EXPORT:?pfPostBugReport@TXBugReport@@3P6AXXZA=WeChatWinOrg.?pfPostBugReport@TXBugReport@@3P6AXXZA,@24")
#pragma comment(linker, "/EXPORT:?pfPreBugReport@TXBugReport@@3P6AXXZA=WeChatWinOrg.?pfPreBugReport@TXBugReport@@3P6AXXZA,@25")
#pragma comment(linker, "/EXPORT:_TlsGetData@12=WeChatWinOrg._TlsGetData@12,@28")
#pragma comment(linker, "/EXPORT:_TlsStoreData@12=WeChatWinOrg._TlsStoreData@12,@29")
class EXPORT IMVQQEngine
{
public: class IMVQQEngine& operator=(class IMVQQEngine const&);
};
ALCPP class IMVQQEngine& IMVQQEngine::operator=(class IMVQQEngine const&)
{
	__asm JMP pfn__4IMVQQEngine__QAEAAV0_ABV0__Z;
}
namespace TXBugReport
{
	ALCPP int __cdecl AddExtraMem(unsigned long, unsigned int)
	{
		__asm JMP pfn_AddExtraMem_TXBugReport__YAHKI_Z;
	}
	ALCPP int __cdecl AddExtraMem(void*, unsigned int)
	{
		__asm JMP pfn_AddExtraMem_TXBugReport__YAHPAXI_Z;
	}
	ALCPP void __cdecl AddIgnoreHookCheckModule(wchar_t const*)
	{
		__asm JMP pfn_AddIgnoreHookCheckModule_TXBugReport__YAXPB_W_Z;
	}
	ALCPP void __cdecl AddReleaseMonitorPoint(long*)
	{
		__asm JMP pfn_AddReleaseMonitorPoint_TXBugReport__YAXPAJ_Z;
	}
	ALCPP long __cdecl DoBugReport(struct _EXCEPTION_POINTERS*, wchar_t const*)
	{
		__asm JMP pfn_DoBugReport_TXBugReport__YAJPAU_EXCEPTION_POINTERS__PB_W_Z;
	}
	ALCPP unsigned long __cdecl GetBugReportFlag(void)
	{
		__asm JMP pfn_GetBugReportFlag_TXBugReport__YAKXZ;
	}
	ALCPP struct tagBugReportInfo* __cdecl GetBugReportInfo(void)
	{
		__asm JMP pfn_GetBugReportInfo_TXBugReport__YAPAUtagBugReportInfo_1_XZ;
	}
	ALCPP int(__cdecl* __cdecl GetCustomFiltFunc(void))(struct _EXCEPTION_POINTERS*)
	{
		__asm JMP pfn_GetCustomFiltFunc_TXBugReport__YAP6AHPAU_EXCEPTION_POINTERS___ZXZ;
	}
	ALCPP void __cdecl InitBugReport(wchar_t const*, wchar_t const*, wchar_t const*, wchar_t const*, unsigned short, unsigned short, unsigned long, int, int, unsigned long, unsigned long, int(__stdcall*)(struct tagBugReportInfo*, char const*, char const*, wchar_t const*, wchar_t const*, void**, unsigned long*, void*))
	{
		__asm JMP pfn_InitBugReport_TXBugReport__YAXPB_W000GGKHHKKP6GHPAUtagBugReportInfo_1_PBD200PAPAXPAKPAX_Z_Z;
	}
	ALCPP void __cdecl InitBugReportEx(wchar_t const*, wchar_t const*, wchar_t const*, wchar_t const*, unsigned short, unsigned short, unsigned long, int, int, unsigned long, unsigned long, int(__stdcall*)(struct tagBugReportInfo*, char const*, char const*, wchar_t const*, wchar_t const*, void**, unsigned long*, void*), int)
	{
		__asm JMP pfn_InitBugReportEx_TXBugReport__YAXPB_W000GGKHHKKP6GHPAUtagBugReportInfo_1_PBD200PAPAXPAKPAX_ZH_Z;
	}
	ALCPP void __cdecl RaiseSelfFatalException(enum SelfException)
	{
		__asm JMP pfn_RaiseSelfFatalException_TXBugReport__YAXW4SelfException_1__Z;
	}
	ALCPP void __cdecl RecordCallStackIfNeed(long*)
	{
		__asm JMP pfn_RecordCallStackIfNeed_TXBugReport__YAXPAJ_Z;
	}
	ALCPP int __cdecl SetBugReportFlag(unsigned long)
	{
		__asm JMP pfn_SetBugReportFlag_TXBugReport__YAHK_Z;
	}
	ALCPP int __cdecl SetBugReportPath(wchar_t const*)
	{
		__asm JMP pfn_SetBugReportPath_TXBugReport__YAHPB_W_Z;
	}
	ALCPP void __cdecl SetBugReportUin(unsigned long, int)
	{
		__asm JMP pfn_SetBugReportUin_TXBugReport__YAXKH_Z;
	}
	ALCPP void __cdecl SetCustomFiltFunc(int(__cdecl*)(struct _EXCEPTION_POINTERS*))
	{
		__asm JMP pfn_SetCustomFiltFunc_TXBugReport__YAXP6AHPAU_EXCEPTION_POINTERS___Z_Z;
	}
	ALCPP int __cdecl SetExtInfo(unsigned long, unsigned long, wchar_t const*)
	{
		__asm JMP pfn_SetExtInfo_TXBugReport__YAHKKPB_W_Z;
	}
	ALCPP int __cdecl SetExtRptFilePath(wchar_t const*, wchar_t const*)
	{
		__asm JMP pfn_SetExtRptFilePath_TXBugReport__YAHPB_W0_Z;
	}
	ALCPP int __cdecl SetLogFileMd5Dir(wchar_t const*, wchar_t const*, wchar_t const*)
	{
		__asm JMP pfn_SetLogFileMd5Dir_TXBugReport__YAHPB_W00_Z;
	}
	ALCPP void __cdecl UninitBugReport(void)
	{
		__asm JMP pfn_UninitBugReport_TXBugReport__YAXXZ;
	}
	ALCPP void __cdecl ValidateBugReport(void)
	{
		__asm JMP pfn_ValidateBugReport_TXBugReport__YAXXZ;
	}
}
