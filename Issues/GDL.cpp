#include "GDL.h"

GDL::GDL(LPSTR name, int posWinX, int posWinY, int winWidth, int winHeight)
{
    WNDCLASS windowStructure;

    if(!GetClassInfo(this->windowInstance, name, &windowStructure))
    {
        // If the window instance is not defined in the current class, set it
        if(!(this->windowInstance != 0))
            this->windowInstance = (HINSTANCE)GetModuleHandle(NULL);

        windowStructure.lpszClassName = name;
        windowStructure.style = 0;
        windowStructure.hInstance = this->windowInstance;
        windowStructure.lpfnWndProc = WindowProc;
        windowStructure.cbClsExtra = 0;
        windowStructure.cbWndExtra = 0;
        windowStructure.hIcon = NULL;
        windowStructure.hCursor = NULL;
        windowStructure.hbrBackground = (HBRUSH)(COLOR_BTNFACE+1);
        windowStructure.lpszMenuName = NULL;

        if (RegisterClass(&windowStructure) == 0)
        {
            MessageBox(NULL,"The window class failed to register.","Error",0);
            delete this;
        }
    }

    HWND windowHandler = CreateWindow(m_pszClassName, const_cast<char *>(this->windowName.c_str()), WS_VISIBLE | WS_OVERLAPPEDWINDOW, posWinX, posWinY, winWidth, winHeight, NULL, NULL, this->windowInstance, this);

    if(windowHandler == NULL)
    {
        delete this;
        MessageBox(NULL,"Problem creating the window.","Error",0);
    }
}

const char *GDL::m_pszClassName = "GDL";

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
}

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

// ...

// A partir de aca el codigo experimental

// ...

/*
void setName(std::string name)
{
    if(!this->name)
        this->name = name;
    if((this->name) && (this->name != name)
        this->name = name;
}
*/

