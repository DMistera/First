#include "KeyboardManager.h"
#include <iostream>



KeyboardManager::KeyboardManager()
{
}


KeyboardManager::~KeyboardManager()
{
}

LRESULT CALLBACK KeyboardManager::WindowProc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	cout << "Got message";
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
