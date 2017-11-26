#include "GDL.h"

using namespace std;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    GDL *Gobj = new GDL("It has been repaired!", 350, 100, 640, 480);
    gdlUpdate(Gobj);
    return 0;
}
