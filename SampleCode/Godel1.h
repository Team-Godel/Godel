#include <windows.h>
#include <iostream>
#include <vector>
#include <string>

#ifndef GODELLIB_H_INCLUDED
#define GODELLIB_H_INCLUDED

namespace Godel
{
	class Godel
	{
	public:
		int constructor();
		int destroyer();
		LRESULT CALLBACK mainFunctionProcedure(HWND, UINT, WPARAM, LPARAM);
	protected:
		HINSTANCE hInstance;
		HINSTANCE hPrevInstance;
		PWSTR pCmdLine;
		int nCmdShow;
		HWND gWindow;
		MSG message;
		WNDCLASS gWindowClass;
	};

	int Godel::constructor()
	{
		gWindowClass.style = 0;
		gWindowClass.lpfnWndProc = (WNDPROC)&mainFunctionProcedure;
		gWindowClass.cbClsExtra = 0;
		gWindowClass.cbWndExtra = 0;
		gWindowClass.hInstance = NULL;
		gWindowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		gWindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		gWindowClass.hbrBackground = (HBRUSH)(1 + COLOR_BTNFACE);
		gWindowClass.lpszMenuName = NULL;
		gWindowClass.lpszClassName = "gWindowClass";
		if(!RegisterClass(&gWindowClass)) 
		{
			return FALSE;
		} else {
			gWindow = CreateWindow( "gWindowClass", 
									"gWindows API Test", 
									WS_OVERLAPPEDWINDOW, 
									CW_USEDEFAULT, 
									CW_USEDEFAULT, 
									640, 
									480, 
									NULL, 
									NULL, 
									hInstance, 
									NULL);
			ShowWindow(gWindow, nCmdShow);
			UpdateWindow(gWindow);
			while (GetMessage(&message, NULL, 0, 0))
			{
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
		}
		return 0;
	}

	int Godel::destroyer()
	{
		return 0;
	}

	LRESULT CALLBACK Godel::mainFunctionProcedure(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
	{
	    switch (msg)
	    {
              case WM_DESTROY:
	            PostQuitMessage(0);
	            return 0;
	       break;
            
              default:
	            return DefWindowProc(gWindow, msg, wParam, lParam);
	       break;
	    }
        }
    }

}

#endif