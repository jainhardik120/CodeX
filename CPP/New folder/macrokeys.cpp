#include<windows.h>
#include <iostream>

int main(){
    // mouse_event(MOUSEEVENTF_MOVE, 100,100,0,0);
    // LPINPUT inputs[1];
    // SendInput(sizeof(inputs)/sizeof(inputs[0]), inputs, sizeof(inputs))
    // BlockInput(true);
    INPUT inputs[1] = {};
    ZeroMemory(inputs, sizeof(inputs));

    inputs[0].type = INPUT_MOUSE;
    inputs[0].mi.dx = 9000;
    inputs[0].mi.dy = 90;
    inputs[0].mi.dwFlags = MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE;
   
    // inputs[1].type = INPUT_KEYBOARD;
    // inputs[1].ki.wVk = 0x44;

    // inputs[2].type = INPUT_KEYBOARD;
    // inputs[2].ki.wVk = 0x44;
    // inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

    // inputs[3].type = INPUT_KEYBOARD;
    // inputs[3].ki.wVk = VK_LWIN;
    // inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;

    UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
    // Sleep(5000);
    // BlockInput(false);
    // HWND info = GetActiveWindow();
    // std::cout<< info;
    // std::cout << GetKeyState(VK_CAPITAL);
    return 0;
}