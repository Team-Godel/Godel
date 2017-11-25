#include <GodelLib.h>


using namespace std;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    bool on = true;

    GDL *Gobj = new GDL;
    GDL *Gobj2 = new GDL;    // Create a new instance of GDL

    Gobj->help("Methods");
    Gobj->createGDLWindow(hInstance, "GDL Application", 350, 100, 640, 480);

    Gobj->showCursor(on);
    Gobj->setCursorPosition(500,500);


    gdlUpdate(Gobj);

    return 0;
}
