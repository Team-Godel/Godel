#include <windows.h>


HINSTANCE instance;     // instance of the program

LRESULT CALLBACK procedureFenetrePrincipale(HWND, UINT, WPARAM, LPARAM);
             
             //Instance of the prog    // Always equal to NULL                             // Display mode
int WinMain (HINSTANCE cetteInstance, HINSTANCE precedenteInstance, LPSTR lignesDeCommande, int modeDAffichage)
{
    HWND fenetrePrincipale;   
    MSG message;    // Events
    WNDCLASS classeFenetre;  // The class of the window

    instance = cetteInstance;

    classeFenetre.style = 0;   // Window's style
    classeFenetre.lpfnWndProc = procedureFenetrePrincipale;     // Define the CALLBACK function (Line 46)
    classeFenetre.cbClsExtra = 0;   // Number of bytes following the structure. (Useless, Always equal to 0)
    classeFenetre.cbWndExtra = 0;   // Same but following the instance (Always equal to 0)
    classeFenetre.hInstance = NULL;  // Define the instance of the window
    classeFenetre.hIcon = LoadIcon(NULL, IDI_APPLICATION);  // Define the icon to use for the window
    classeFenetre.hCursor = LoadCursor(NULL, IDC_ARROW);   // Define the default cursor to use in this window 
    classeFenetre.hbrBackground = (HBRUSH)(1 + COLOR_BTNFACE);  // The Default background color in the window
    classeFenetre.lpszMenuName = NULL;   // Define the associated menu to this window (Here none, equal to NULL)
    classeFenetre.lpszClassName = "classeF";   // The name of the class

    if(!RegisterClass(&classeFenetre)) return FALSE;    // Save the window

    fenetrePrincipale = CreateWindow("classeF", "Windows API Test", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, cetteInstance, NULL);  // Create a window in 640 X 480

    ShowWindow(fenetrePrincipale, modeDAffichage);  // Display window
    UpdateWindow(fenetrePrincipale);   // Update the state of the window


    while (GetMessage(&message, NULL, 0, 0))  // Recovers the events of all the windows of the instance in "message"
    {
        TranslateMessage(&message);  // Traduction of the event
        DispatchMessage(&message);   // Send the message to the window
    }

    return 0;
}


LRESULT CALLBACK procedureFenetrePrincipale(HWND fenetrePrincipale, UINT message, WPARAM wParam, LPARAM lParam)    // CALLBACK function treat all the events in the window
{
    switch (message)   // Events
    {
        case WM_CREATE:
                SetMenu(fenetrePrincipale, LoadMenu(instance, "ID_MENU"));  // Associate the menu with the window
        return 0;

        case WM_DESTROY:
            PostQuitMessage(0);   // Exit the window
            return 0;

        default:
            return DefWindowProc(fenetrePrincipale, message, wParam, lParam);   // If there is no message, return the windows default procedur
    }
}

