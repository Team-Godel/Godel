#include <iostream>
#include <GodelLib.h>


using namespace std;


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    GDL *g_vars = GDL::CreateTestWindow(hInstance);

    BOOL bRet;
    MSG msg;

    while((bRet = GetMessage(&msg, 0, 0, 0 )))
    {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
    }

    delete g_vars;

    return 0;
}
