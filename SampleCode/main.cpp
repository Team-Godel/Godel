#include <windows.h>


HINSTANCE instance;

LRESULT CALLBACK procedureFenetrePrincipale(HWND, UINT, WPARAM, LPARAM);

int WinMain (HINSTANCE cetteInstance, HINSTANCE precedenteInstance, LPSTR lignesDeCommande, int modeDAffichage)
{
    HWND fenetrePrincipale;  // The window
    MSG message;   // Events
    WNDCLASS classeFenetre;  // The class of the window

    instance = cetteInstance;

    classeFenetre.style = 0;
    classeFenetre.lpfnWndProc = procedureFenetrePrincipale;
    classeFenetre.cbClsExtra = 0;
    classeFenetre.cbWndExtra = 0;
    classeFenetre.hInstance = NULL;
    classeFenetre.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    classeFenetre.hCursor = LoadCursor(NULL, IDC_ARROW);
    classeFenetre.hbrBackground = (HBRUSH)(1 + COLOR_BTNFACE);
    classeFenetre.lpszMenuName = NULL;
    classeFenetre.lpszClassName = "classeF";

    if(!RegisterClass(&classeFenetre)) return FALSE;

    fenetrePrincipale = CreateWindow("classeF", "Windows API Test", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, cetteInstance, NULL);   // Create a window in 640 X 480

    ShowWindow(fenetrePrincipale, modeDAffichage);   // display the window
    UpdateWindow(fenetrePrincipale);  // update the state of the window


    while (GetMessage(&message, NULL, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return 0;
}


LRESULT CALLBACK procedureFenetrePrincipale(HWND fenetrePrincipale, UINT message, WPARAM wParam, LPARAM lParam)
{
    static int posLineX = 100, posLineY = 50, widthY = 50;   // posLineX determine

    switch (message)   // events
    {



        case WM_DESTROY:   // Exit the program
        {
            PostQuitMessage(0);
         break;
        }

        default:
        {
            return DefWindowProc(fenetrePrincipale, message, wParam, lParam);
         break;
        }

    }
}

