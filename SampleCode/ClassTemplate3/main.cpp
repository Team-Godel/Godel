#include <GodelLib.h>


using namespace std;


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    GDL *Gobj = new GDL;    // Create a new instance of GDL

    Gobj->CreateGDLWindow(hInstance, 640, 480); // Create a window in 640X480

    BOOL bRet;
    MSG msg;   

    while((bRet = GetMessage(&msg, 0, 0, 0 )))
    {
            TranslateMessage(&msg);  // Traduction of keyboard's codes
            DispatchMessage(&msg);   // Send the messages (events to the CALL BACK function)
    }

    delete Gobj;   // Destroye the instance GDL

    return 0;
}
