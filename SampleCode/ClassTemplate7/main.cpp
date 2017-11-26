#include "GDL.h"

using namespace std;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    bool on = true;
    GDL *Gobj = new GDL(hInstance, "GDL Application", 350, 100, 640, 480);
    Gobj->help("Methods");
    Gobj->showCursor(on);
    Gobj->setCursorPosition(500,500);
    gdlUpdate(Gobj);
    return 0;
}
