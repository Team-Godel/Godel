#include <GodelLib.h>


using namespace std;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    GDL *Gobj = new GDL;    // Create a new instance of GDL

    Gobj->help("Functions");    // Try commands: "Methods", "Functions"

    gdlUpdate(Gobj);

    return 0;
}
