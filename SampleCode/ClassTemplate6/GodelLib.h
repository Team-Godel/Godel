#ifndef GDL_H
#define GDL_H

#include <iostream>
#include <string>
#include <tchar.h>
#include <windows.h>




class GDL
{
   public:
      GDL();
     ~GDL();
     static GDL* createGDLWindow(HINSTANCE hInstance, LPSTR winTitle, int posWinX, int posWinY, int winWidth, int winHeight);
     static void msgBox(LPCSTR, LPCSTR, UINT, HWND, void*);
     static void help(std::string topic);
     static void showCursor(bool onOff);
     static void setCursorPosition(int x, int y);

   private:
     static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
     static const char *m_pszClassName;
     HWND m_hWnd;
};


GDL::GDL()
{

}



const char *GDL::m_pszClassName = "GDL";
WNDCLASS wincl;

GDL *GDL::createGDLWindow(HINSTANCE hInst, LPSTR winTitle, int posWinX, int posWinY, int winWidth, int winHeight)
{
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
            std::cout << "Window succesfully created !" << std::endl;
            break;
        }

    case WM_DESTROY:
        {
            std::cout << "Window succesfully destroyed !" << std::endl;
            break;
        }
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}


void GDL::msgBox(LPCSTR title, LPCSTR txt, UINT flag, HWND windowHandler, void* pointer)
{
    MessageBox(windowHandler, txt, title, flag);
}


const int NBMETHODS = 3;
int iMethod = 0;
std::string method[NBMETHODS] = {"createGDLWindow(HINSTANCE hInst, LPSTR title, int x, int x, int w, int h); \n- Create a window",
                                 "msgBox(LPCSTR title, LPCSTR txt, UINT flag, HWND windowHandler, void* ptr); \n- GUI message box",
                                 "help(std::string topic); \n- Show help"};

const int NBFUNC = 1;
int iFunc = 0;
std::string Func[NBFUNC] = {"gdlUpdate(GDL* Gobj); \n- Main loop of the program"};

void GDL::help(std::string topic)
{
    if(topic == "Methods")
    {
        std::cout << "Methods" << std::endl << std::endl << std::endl;

        for(iMethod = 0; iMethod < NBMETHODS; iMethod ++)
        {
        std::cout << method[iMethod] << std::endl << std::endl;
        }
    }
    else if(topic == "Functions")
    {
        std::cout << "Functions" << std::endl << std::endl << std::endl;

        for(iFunc = 0; iFunc < NBFUNC; iFunc ++)
        {
        std::cout << Func[iFunc] << std::endl << std::endl;
        }
    }
}


void GDL::showCursor(bool onOff)
{
    ShowCursor(onOff);
}


void GDL::setCursorPosition(int x, int y)
{
    SetCursorPos(x, y);
}


GDL::~GDL()   // Destructor
{
   if(m_hWnd)
   {
    DestroyWindow(m_hWnd);
   }
}



int gdlUpdate(GDL*);

int gdlUpdate(GDL* Gobj)
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
