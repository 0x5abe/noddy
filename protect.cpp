#include <Windows.h>
#include <iostream>
#include "tlhelp32.h"

#define IMPORT_COUNT 151

struct Import {
    DWORD address;
    std::string moduleName;
    std::string importName;
};

BOOL APIENTRY DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved) {
    const Import imports[IMPORT_COUNT] = {
        {0x001c5000, "advapi32.dll", "RegSetValueExA"},
        {0x001c5004, "advapi32.dll", "RegQueryValueExA"},
        {0x001c5008, "advapi32.dll", "RegFlushKey"},
        {0x001c500c, "advapi32.dll", "RegOpenKeyExA"},
        {0x001c5010, "advapi32.dll", "RegCreateKeyExA"},
        {0x001c5014, "advapi32.dll", "RegCloseKey"},
        {0x001c501c, "comctl32.dll", "InitCommonControls"},
        {0x001c5024, "ddraw.dll", "DirectDrawCreate"},
        {0x001c502c, "dinput8.dll", "DirectInput8Create"},
        {0x001c5034, "dsound.dll", "DirectSoundCreate"},
        {0x001c503c, "gdi32.dll", "CreateBrushIndirect"},
        {0x001c5040, "gdi32.dll", "StretchDIBits"},
        {0x001c5044, "gdi32.dll", "CreateFontA"},
        {0x001c5048, "gdi32.dll", "GetStockObject"},
        {0x001c504c, "gdi32.dll", "CreatePen"},
        {0x001c5054, "kernel32.dll", "OutputDebugStringA"},
        {0x001c5058, "kernel32.dll", "MultiByteToWideChar"},
        {0x001c505c, "kernel32.dll", "GetVersionExA"},
        {0x001c5060, "kernel32.dll", "LoadLibraryA"},
        {0x001c5064, "kernel32.dll", "Sleep"},
        {0x001c5068, "kernel32.dll", "LCMapStringA"},
        {0x001c506c, "kernel32.dll", "CreateFileW"},
        {0x001c5070, "kernel32.dll", "CreateFileA"},
        {0x001c5074, "kernel32.dll", "FlushFileBuffers"},
        {0x001c5078, "kernel32.dll", "SetStdHandle"},
        {0x001c507c, "kernel32.dll", "GetTimeZoneInformation"},
        {0x001c5080, "kernel32.dll", "RaiseException"},
        {0x001c5084, "kernel32.dll", "InterlockedExchange"},
        {0x001c5088, "kernel32.dll", "GetCPInfo"},
        {0x001c508c, "kernel32.dll", "GetOEMCP"},
        {0x001c5090, "kernel32.dll", "GetACP"},
        {0x001c5094, "kernel32.dll", "GetStringTypeW"},
        {0x001c5098, "kernel32.dll", "GetStringTypeA"},
        {0x001c509c, "kernel32.dll", "IsBadCodePtr"},
        {0x001c50a0, "kernel32.dll", "IsBadReadPtr"},
        {0x001c50a4, "kernel32.dll", "SetUnhandledExceptionFilter"},
        {0x001c50a8, "kernel32.dll", "GetFileAttributesA"},
        {0x001c50ac, "kernel32.dll", "VirtualQuery"},
        {0x001c50b0, "kernel32.dll", "GetTickCount"},
        {0x001c50b4, "kernel32.dll", "VirtualProtect"},
        {0x001c50b8, "kernel32.dll", "ReadFile"},
        {0x001c50bc, "kernel32.dll", "SetFilePointer"},
        {0x001c50c0, "kernel32.dll", "CloseHandle"},
        {0x001c50c4, "kernel32.dll", "GetFileType"},
        {0x001c50c8, "kernel32.dll", "SetHandleCount"},
        {0x001c50cc, "kernel32.dll", "GetEnvironmentStringsW"},
        {0x001c50d0, "kernel32.dll", "WideCharToMultiByte"},
        {0x001c50d4, "kernel32.dll", "FreeEnvironmentStringsW"},
        {0x001c50d8, "kernel32.dll", "GetEnvironmentStrings"},
        {0x001c50dc, "kernel32.dll", "FreeEnvironmentStringsA"},
        {0x001c50e0, "kernel32.dll", "UnhandledExceptionFilter"},
        {0x001c50e4, "kernel32.dll", "GetStdHandle"},
        {0x001c50e8, "kernel32.dll", "WriteFile"},
        {0x001c50ec, "kernel32.dll", "HeapSize"},
        {0x001c50f0, "kernel32.dll", "GetModuleFileNameA"},
        {0x001c50f4, "kernel32.dll", "GetSystemTimeAsFileTime"},
        {0x001c50f8, "kernel32.dll", "GetCurrentProcessId"},
        {0x001c50fc, "kernel32.dll", "GetCurrentThreadId"},
        {0x001c5100, "kernel32.dll", "QueryPerformanceCounter"},
        {0x001c5104, "kernel32.dll", "IsBadWritePtr"},
        {0x001c5108, "kernel32.dll", "VirtualAlloc"},
        {0x001c510c, "kernel32.dll", "VirtualFree"},
        {0x001c5110, "kernel32.dll", "HeapCreate"},
        {0x001c5114, "kernel32.dll", "HeapDestroy"},
        {0x001c5118, "kernel32.dll", "GetCommandLineA"},
        {0x001c511c, "kernel32.dll", "GetDriveTypeA"},
        {0x001c5120, "kernel32.dll", "GetUserDefaultLangID"},
        {0x001c5124, "kernel32.dll", "LCMapStringW"},
        {0x001c5128, "kernel32.dll", "WaitForSingleObject"},
        {0x001c512c, "kernel32.dll", "GetExitCodeProcess"},
        {0x001c5130, "kernel32.dll", "SetConsoleCtrlHandler"},
        {0x001c5134, "kernel32.dll", "CreateProcessA"},
        {0x001c5138, "kernel32.dll", "RemoveDirectoryA"},
        {0x001c513c, "kernel32.dll", "GetSystemInfo"},
        {0x001c5140, "kernel32.dll", "SetCurrentDirectoryA"},
        {0x001c5144, "kernel32.dll", "GetCurrentDirectoryA"},
        {0x001c5148, "kernel32.dll", "DeleteFileA"},
        {0x001c514c, "kernel32.dll", "CompareStringW"},
        {0x001c5150, "kernel32.dll", "CompareStringA"},
        {0x001c5154, "kernel32.dll", "SetEnvironmentVariableA"},
        {0x001c5158, "kernel32.dll", "SetEndOfFile"},
        {0x001c515c, "kernel32.dll", "HeapFree"},
        {0x001c5160, "kernel32.dll", "RtlUnwind"},
        {0x001c5164, "kernel32.dll", "HeapAlloc"},
        {0x001c5168, "kernel32.dll", "ExitProcess"},
        {0x001c516c, "ntdll.dll", "RtlReAllocateHeap"},
        {0x001c5170, "kernel32.dll", "GetModuleHandleA"},
        {0x001c5174, "kernel32.dll", "GetStartupInfoA"},
        {0x001c5178, "kernel32.dll", "FindClose"},
        {0x001c517c, "kernel32.dll", "FileTimeToSystemTime"},
        {0x001c5180, "kernel32.dll", "FileTimeToLocalFileTime"},
        {0x001c5184, "kernel32.dll", "GetLastError"},
        {0x001c5188, "kernel32.dll", "FindFirstFileA"},
        {0x001c518c, "kernel32.dll", "FindNextFileA"},
        {0x001c5190, "kernel32.dll", "GetProcAddress"},
        {0x001c5194, "kernel32.dll", "TerminateProcess"},
        {0x001c5198, "kernel32.dll", "GetCurrentProcess"},
        {0x001c519c, "kernel32.dll", "CreateDirectoryA"},
        {0x001c51a0, "kernel32.dll", "GetLocaleInfoA"},
        {0x001c51a8, "user32.dll", "LoadIconA"},
        {0x001c51ac, "user32.dll", "ScreenToClient"},
        {0x001c51b0, "user32.dll", "GetCursorPos"},
        {0x001c51b4, "user32.dll", "GetSysColor"},
        {0x001c51b8, "user32.dll", "GetDC"},
        {0x001c51bc, "user32.dll", "ReleaseDC"},
        {0x001c51c0, "user32.dll", "AppendMenuA"},
        {0x001c51c4, "user32.dll", "CheckMenuItem"},
        {0x001c51c8, "user32.dll", "EnableMenuItem"},
        {0x001c51cc, "user32.dll", "ClientToScreen"},
        {0x001c51d0, "user32.dll", "TrackPopupMenu"},
        {0x001c51d4, "user32.dll", "LoadMenuA"},
        {0x001c51d8, "user32.dll", "GetSubMenu"},
        {0x001c51dc, "user32.dll", "InvalidateRect"},
        {0x001c51e0, "user32.dll", "GetClientRect"},
        {0x001c51e4, "user32.dll", "GetWindowLongA"},
        {0x001c51e8, "user32.dll", "EndDialog"},
        {0x001c51ec, "user32.dll", "SetWindowTextA"},
        {0x001c51f0, "user32.dll", "GetWindowTextA"},
        {0x001c51f4, "user32.dll", "CallWindowProcA"},
        {0x001c51f8, "user32.dll", "CreateDialogParamA"},
        {0x001c51fc, "user32.dll", "GetDlgItem"},
        {0x001c5200, "user32.dll", "LoadCursorA"},
        {0x001c5204, "user32.dll", "RegisterClassA"},
        {0x001c5208, "user32.dll", "CreateWindowExA"},
        {0x001c520c, "user32.dll", "GetSystemMetrics"},
        {0x001c5210, "user32.dll", "SetWindowLongA"},
        {0x001c5214, "user32.dll", "UpdateWindow"},
        {0x001c5218, "user32.dll", "SetFocus"},
        {0x001c521c, "user32.dll", "SetWindowPos"},
        {0x001c5220, "user32.dll", "PostQuitMessage"},
        {0x001c5224, "user32.dll", "GetWindowRect"},
        {0x001c5228, "user32.dll", "ClipCursor"},
        {0x001c522c, "user32.dll", "DefWindowProcA"},
        {0x001c5230, "user32.dll", "SendMessageA"},
        {0x001c5234, "user32.dll", "DispatchMessageA"},
        {0x001c5238, "user32.dll", "TranslateMessage"},
        {0x001c523c, "user32.dll", "PeekMessageA"},
        {0x001c5240, "user32.dll", "GetMessageA"},
        {0x001c5244, "user32.dll", "ShowWindow"},
        {0x001c5248, "user32.dll", "MessageBoxA"},
        {0x001c524c, "user32.dll", "GetKeyNameTextA"},
        {0x001c5250, "user32.dll", "ShowCursor"},
        {0x001c5258, "winmm.dll", "timeKillEvent"},
        {0x001c525c, "winmm.dll", "timeSetEvent"},
        {0x001c5260, "winmm.dll", "sndPlaySoundA"},
        {0x001c5268, "d3d9.dll", "Direct3DCreate9"},
        {0x001c5270, "d3dx9_27.dll", "D3DXMatrixMultiply"},
        {0x001c5274, "d3dx9_27.dll", "D3DXCompileShaderFromResourceA"},
        {0x001c527c, "combase.dll", "CoUninitialize"},
        {0x001c5280, "ole32.dll", "CoInitialize"},
        {0x001c5284, "combase.dll", "CoCreateInstance"}
    };

    HANDLE curProcessSnapshot;
    MODULEENTRY32 noddyModule;
    DWORD oldProtection;
    HMODULE curModuleHdl;
    FARPROC curImportFunctionAddress;

    noddyModule.dwSize = sizeof(MODULEENTRY32);

    switch (dwReason) {
        case DLL_PROCESS_ATTACH:
            while (true) {
                curProcessSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, NULL);
                if (curProcessSnapshot) {
                    break;
                }
            }
            while (true) {
                BOOL result = Module32First(curProcessSnapshot, &noddyModule);
                if (result) {
                    break;
                }
            }

            VirtualProtect(noddyModule.modBaseAddr, noddyModule.modBaseSize, PAGE_EXECUTE_READWRITE, &oldProtection);

            for (unsigned int i = 0; i < IMPORT_COUNT; i++) {
                while (true) {
                    curModuleHdl = GetModuleHandle(imports[i].moduleName.c_str());
                    if (curModuleHdl) {
                        break;
                    }
                }
                while (true) {
                    curImportFunctionAddress = GetProcAddress(curModuleHdl, imports[i].importName.c_str());
                    if (curImportFunctionAddress) {
                        break;
                    }
                }
                *(FARPROC*)((DWORD)noddyModule.modBaseAddr+imports[i].address) = curImportFunctionAddress;
            }
            break;
    }
    return true;
}

extern "C" void DummyExport() {
    return;
}