#include "pch.h"
#include <Windows.h>



HHOOK hHook = NULL;

extern "C" __declspec(dllexport) LRESULT __stdcall HookCallback(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0)
    {
        if (wParam == WM_LBUTTONDOWN)
        {
            POINT point = ((MSLLHOOKSTRUCT*)lParam)->pt;
            HWND window = WindowFromPoint(point);
            WCHAR className[256];
            GetClassNameW(window, className, sizeof(className));
            if (wcscmp(className, L"Button") == 0)
            {
                WCHAR windowText[256];
                GetWindowTextW(window, windowText, sizeof(windowText));
                if (wcscmp(windowText, L"Print") == 0)
                {
                    MessageBoxW(NULL, L"МОЛЯ УВЕРЕТЕ СЕ, ЧЕ НЯМА ОСТАНАЛИ ДОКУМЕНТИ СЛЕД ИЗВЪРШВАНЕ НА ОПЕРАЦИЯТА!", L"ВНИМАНИЕ!", MB_ICONINFORMATION | MB_OK);
                }
            }
        }
    }
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

DWORD __stdcall HookThread(LPVOID lpParameter)
{
    hHook = SetWindowsHookEx(WH_MOUSE_LL, HookCallback, NULL, 0);
    if (hHook == NULL)
    {
        MessageBox(NULL, L"Failed to set hook!", L"Error", MB_ICONERROR | MB_OK);
        return 1;
    }

    MSG message;
    while (GetMessage(&message, NULL, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    UnhookWindowsHookEx(hHook);
    return 0;
}

int __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, 0, HookThread, NULL, 0, NULL);
        break;
    case DLL_PROCESS_DETACH:
        UnhookWindowsHookEx(hHook);
        break;
    }
    return TRUE;
}
