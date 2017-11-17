#include <windows.h>
#include <iostream>
#include <string>
#include "GodelLib.h"

namespace Godel
{
	Godel::Godel(LPCTSTR windowName,
			     int defaultHorizontalPosition = CW_USEDEFAULT, 
			     int defaultVerticalPosition = CW_USEDEFAULT, 
			     int width = CW_USEDEFAULT,  
			     int height = CW_USEDEFAULT, 
			     LPCTSTR className = "MainWClass",
			     DWORD windowStyles = WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL, 
			     HWND parentWindow = (HWND) NULL, 
			     HMENU classMenuUsed = (HMENU) NULL, 
			     HINSTANCE instanceHandle = this.hinst, 
			     DWORD extendedStyles = 0,
			     LPVOID windowCreationData = NULL);
	{
		hwndMain = CreateWindowEx(extendedStyles,
								  className,
								  windowName,
								  windowStyles,
								  defaultHorizontalPosition,
								  defaultVerticalPosition,
								  width,
								  height,
								  parentWindow,
								  classMenuUsed,
								  instanceHandle,
								  windowCreationData);
		if (!hwndMain)
		{
    		return FALSE;  	                       
		} else {
			ShowWindow(this.hwndMain, SW_SHOWDEFAULT); 
			UpdateWindow(this.hwndMain); 
		}
	}
}
