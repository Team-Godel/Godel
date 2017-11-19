#include "GodelLib.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    viewvars * pviewvars = viewvars::CreateTestWindow( hInstance );
    if ( pviewvars == 0 ) return 0;

    BOOL bRet;
    MSG msg;

    while( (bRet = GetMessage( &msg, 0, 0, 0 )) != 0)
    {
        if (bRet == -1)
        {
            // handle the error and possibly exit
        }
        else
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    delete pviewvars;

    return 0;
}
