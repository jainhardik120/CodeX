#include <iostream>
#include <Windows.h>

using namespace std;

void sendKeyCombo(WORD key1, WORD key2)
{
    // Set up the input events for the key combination
    INPUT inputEvents[1];
    ZeroMemory(inputEvents, sizeof(inputEvents));

    inputEvents[0].type = INPUT_KEYBOARD;
    inputEvents[0].ki.wVk = key1;

    inputEvents[1].type = INPUT_KEYBOARD;
    inputEvents[1].ki.wVk = key1;
    inputEvents[1].ki.dwFlags = KEYEVENTF_KEYUP;

    // inputEvents[2].type = INPUT_KEYBOARD;
    // inputEvents[2].ki.wVk = 0;
    // inputEvents[2].ki.wScan = key2;
    // inputEvents[2].ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;

    // inputEvents[3].type = INPUT_KEYBOARD;
    // inputEvents[3].ki.wVk = 0;
    // inputEvents[3].ki.wScan = key1;
    // inputEvents[3].ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;

    // Send the input events to Windows
    SendInput(2, inputEvents, sizeof(INPUT));
}

int main()
{
    // Prompt the user to enter a string
    // cout << "Enter a string to simulate keyboard input: ";
    // string input;
    // getline(cin, input);

    // // Convert the string to a wchar_t array
    // const wchar_t* keys = new wchar_t[input.length() + 1];
    // mbstowcs((wchar_t*)keys, input.c_str(), input.length() + 1);

    // // Simulate pressing each key in the string
    // INPUT* inputBuffer = new INPUT[input.length() * 2];
    // ZeroMemory(inputBuffer, sizeof(INPUT) * input.length() * 2);

    // int inputIndex = 0;
    // for (int i = 0; i < input.length(); i++)
    // {
    //     // Set up the key down event
    //     inputBuffer[inputIndex].type = INPUT_KEYBOARD;
    //     inputBuffer[inputIndex].ki.wVk = 0;
    //     inputBuffer[inputIndex].ki.wScan = keys[i];
    //     inputBuffer[inputIndex].ki.dwFlags = KEYEVENTF_UNICODE;

    //     // Set up the key up event
    //     inputIndex++;
    //     inputBuffer[inputIndex].type = INPUT_KEYBOARD;
    //     inputBuffer[inputIndex].ki.wVk = 0;
    //     inputBuffer[inputIndex].ki.wScan = keys[i];
    //     inputBuffer[inputIndex].ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;

    //     inputIndex++;
    // }

    // // Send the input events to Windows
    // SendInput(inputIndex, inputBuffer, sizeof(INPUT));

    // // Clean up memory
    // delete[] keys;
    // delete[] inputBuffer;

    // Sleep(5000);


    sendKeyCombo(VK_LWIN, VK_SPACE); // Simulate pressing Ctrl+Alt
    // sendKeyCombo(VK_DELETE, 0); // Simulate pressing Delete key
    // sendKeyCombo(VK_DELETE, KEYEVENTF_KEYUP); // Simulate releasing Delete key
    // sendKeyCombo(VK_CONTROL, VK_MENU | KEYEVENTF_KEYUP); // Simulate releasing Ctrl+Alt


    return 0;
}
