#pragma once
#include <windows.h>

using namespace std;

class KeyboardManager {
public:
	KeyboardManager();
	~KeyboardManager();
	static LRESULT CALLBACK WindowProc(_In_ HWND   hwnd,
		_In_ UINT   uMsg,
		_In_ WPARAM wParam,
		_In_ LPARAM lParam
	);
};

