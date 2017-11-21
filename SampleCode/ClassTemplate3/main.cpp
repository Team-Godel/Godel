#include <GodelLib.h>



using namespace std;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    GDL *Gobj = new GDL;    // Create a new instance of GDL

    // Create a window with the title "GDL Application" at the position (350,100) in 640X480
    Gobj->CreateGDLWindow(hInstance, "GDL Application", 350, 100, 640, 480);


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
