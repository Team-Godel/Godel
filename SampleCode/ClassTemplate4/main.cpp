#include "GDL.h"

using namespace std;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    // GDL *Gobj = Gobj->CreateGDLWindow(hInstance, "GDL Application", 350, 100, 640, 480);
    // output(Gobj);
    GDL::msgBox("Hello world", "HELLO WORLD!",MB_OK, NULL, NULL);
    return 0;
}
