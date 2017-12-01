#include <GodelLib.h>


using namespace std;

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	GDL *Gobj = new GDL(hInstance, "GDL Application", DEFAULT_POS, DEFAULT_POS, 640, 480);  // Create a window

    Gobj->showCursor(0);  // Disable the cursor

	Gobj->update();  // Update the state of the window

	return 0;
}
