#ifndef GDL_H
#define GDL_H

#include <iostream>
#include <string>
#include <tchar.h>
#include <windows.h>

class GDL
{
   public:
     GDL() : m_hWnd(0) {}
     ~GDL();
     static GDL* CreateGDLWindow(HINSTANCE hInstance, LPSTR winTitle, int posWinX, int posWinY, int winWidth, int winHeight);
     static void msgBox(LPCSTR, LPCSTR, UINT, HWND, void*);

   private:
     static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
     static const char *m_pszClassName;
     HWND m_hWnd;
};

const char *GDL::m_pszClassName = "GDL";

GDL *GDL::CreateGDLWindow(HINSTANCE hInst, LPSTR winTitle, int posWinX, int posWinY, int winWidth, int winHeight)
{
    WNDCLASS wincl;

    if(!GetClassInfo(hInst, m_pszClassName, &wincl))
    {
        wincl.style = 0;
        wincl.hInstance = hInst;
        wincl.lpszClassName = m_pszClassName;
        wincl.lpfnWndProc = WindowProc;
        wincl.cbClsExtra = 0;
        wincl.cbWndExtra = 0;
        wincl.hIcon = NULL;
        wincl.hCursor = NULL;
        wincl.hbrBackground = (HBRUSH)(COLOR_BTNFACE+1);
        wincl.lpszMenuName = NULL;

        if (RegisterClass(&wincl) == 0)
        {
            MessageBox(NULL,"The window class failed to register.","Error",0);
            return 0;
        }
    }

    GDL *g_vars = new GDL;
    HWND hWnd = CreateWindow(m_pszClassName, winTitle, WS_VISIBLE | WS_OVERLAPPEDWINDOW, posWinX, posWinY, winWidth, winHeight, NULL, NULL, hInst, g_vars);

    if(hWnd == NULL)
    {
        delete g_vars;
        MessageBox(NULL,"Problem creating the window.","Error",0);
        return 0;
    }

    return g_vars;
}


LRESULT CALLBACK GDL::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_CREATE:
        {
            std::cout << "I am created" << std::endl;
            break;
        }

    case WM_DESTROY:
        {
            std::cout << "I am destroyed" << std::endl;
            break;
        }
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}


GDL::~GDL()   // Destructor
{
   if(m_hWnd)
   {
    DestroyWindow( m_hWnd );
   }
}

void GDL::msgBox(LPCSTR title, LPCSTR msg, UINT flag, HWND windowHandler, void* pointer)
{
    int msgBoxStance = MessageBox(windowHandler, msg, title, flag);
}

int output(GDL*);

int output(GDL* Gobj)
{
    BOOL bRet;
    MSG msg;

    while((bRet = GetMessage(&msg, 0, 0, 0 )))
    {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
    }

    delete Gobj;
    return 0;
}
#endif // GDL_H
