#ifndef GDL_H
#define GDL_H


#include <Windows.h>
#include <string>

#define DEFAULT_WIDTH 640
#define DEFAULT_HEIGHT 480
#define TITLE "GDL Application"
#define CLASS "gdlWindow"

using namespace std;


typedef struct
{
	LPSTR Tipo;
	LPSTR Texto;
	HANDLE CtrlHWND;
	DWORD ID;
	INT Alto;
	INT Ancho;
	INT PosX;
	INT PosY;
	DWORD Estilo;
}   CONTROL, *PCONTROL;



class GDL
{
  private:
	HWND hwnd;
	HINSTANCE hInstance;
	WNDCLASSEX wincl;
	PCONTROL Control;
	HBRUSH PincelStatic;

	void init();
	LRESULT WndProc(HWND, UINT, WPARAM, LPARAM);


static LRESULT CALLBACK WinProcInicial(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	 if (Msg == WM_NCCREATE)
	 {
		LPCREATESTRUCT CreateStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);

		void * lpCreateParam = CreateStruct->lpCreateParams;

		GDL * EstaVentana = reinterpret_cast<GDL*>(lpCreateParam);

		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(EstaVentana));

		SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&GDL::WinProcRedir));
	 }

    return DefWindowProc(hWnd, Msg, wParam, lParam);
}


static LRESULT CALLBACK WinProcRedir(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	LONG_PTR UserData = GetWindowLongPtr(hWnd, GWLP_USERDATA);

	GDL * EstaVentana = reinterpret_cast<GDL*>(UserData);

	return EstaVentana->WndProc(hWnd, Msg, wParam, lParam);
}


  public:
    GDL(HINSTANCE hInst);
    void update(); // Iniciar la aplicación
};



GDL::GDL(HINSTANCE hInst)
{
	hInstance = hInst;
	init();
}


void GDL::init()
{
	wincl.hInstance = hInstance;
	wincl.lpszClassName = CLASS;
	wincl.hbrBackground = NULL;
	wincl.lpfnWndProc = &GDL::WinProcInicial;
	wincl.style = CS_DBLCLKS;
	wincl.cbSize = sizeof(WNDCLASSEX);
	wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL;
	wincl.cbClsExtra = NULL;
	wincl.cbWndExtra = NULL;

	RegisterClassEx(&wincl);

	hwnd = CreateWindowEx(NULL, CLASS, TITLE, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, DEFAULT_WIDTH, DEFAULT_HEIGHT, NULL, (HMENU) NULL, hInstance, (LPVOID)this);
}


LRESULT GDL::WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch(Msg)
	{
        case WM_DESTROY:
            PostQuitMessage(0);
		break;

        default:
            return DefWindowProc(hWnd, Msg, wParam, lParam);
	}
	return 0;
}


void GDL::update()
{
	MSG mensaje;
	ShowWindow(hwnd, SW_SHOWDEFAULT);
	UpdateWindow(hwnd);

    while (GetMessage(&mensaje, hwnd, NULL, NULL) == TRUE)
    {
		TranslateMessage(&mensaje);
		DispatchMessage(&mensaje);
	}
}


#endif // GDL_H
