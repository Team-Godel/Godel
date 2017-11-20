#include <GodelLib.h>


using namespace std;


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    GDL *Gobj = new GDL;    // Create a new instance of GDL

    GDL::CreateTestWindow(hInstance);

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
