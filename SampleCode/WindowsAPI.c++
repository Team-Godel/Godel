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
    classeFenetre.cbClsExtra = 0;
    classeFenetre.cbWndExtra = 0;
    classeFenetre.hInstance = NULL;
    classeFenetre.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    classeFenetre.hCursor = LoadCursor(NULL, IDC_ARROW);
    classeFenetre.hbrBackground = (HBRUSH)(1 + COLOR_BTNFACE);
    classeFenetre.lpszMenuName = NULL;
    classeFenetre.lpszClassName = "classeF";

    if(!RegisterClass(&classeFenetre)) return FALSE;

    fenetrePrincipale = CreateWindow("classeF", "Windows API Test", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, cetteInstance, NULL);  // Create a window in 640 X 480

    ShowWindow(fenetrePrincipale, modeDAffichage);  // Display window
    UpdateWindow(fenetrePrincipale);   // Update the state of the window


    while (GetMessage(&message, NULL, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return 0;
}


LRESULT CALLBACK procedureFenetrePrincipale(HWND fenetrePrincipale, UINT message, WPARAM wParam, LPARAM lParam)    // CALLBACK function treat all the events in the window
{
    switch (message)   // Events
    {
        case WM_CREATE:
                SetMenu(fenetrePrincipale, LoadMenu(instance, "ID_MENU"));
        return 0;

        case WM_DESTROY:
            PostQuitMessage(0);   // Exit the window
            return 0;

        default:
            return DefWindowProc(fenetrePrincipale, message, wParam, lParam);
    }
}

