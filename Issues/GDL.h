#ifndef __GDL_H_INCLUDED__
#define __GDL_H_INCLUDED__

#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <string>

class GDL
{
public:
    GDL(LPSTR name, int posWinX, int posWinY, int winWidth, int winHeight);
    ~GDL();

    // ...

    /*
    void setHandler(HWND);
    void setName(std::string);
    */

    // ...

    static void msgBox(LPCSTR, LPCSTR, UINT, HWND, void*);
    static void help(std::string topic);
    static void showCursor(bool onOff);
    static void setCursorPosition(int x, int y);

private:

    // ...
    HWND classHandler;
    HINSTANCE windowInstance;
    std::string windowName;

    // ...

    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    static const char *m_pszClassName;
};

int gdlUpdate(GDL*);

#endif // __GDL_H_INCLUDED__
