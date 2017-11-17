#include <windows.h>
#include <iostream>
#include <string>

#ifndef NULL
#define NULL 0
#endif
#ifndef GODELLIB_H_INCLUDED
#define GODELLIB_H_INCLUDED

namespace Godel
{
	class Godel
	{
	public:
		Godel(DWORD extendedStyles,
			  LPCTSTR className,
			  LPCTSTR windowName,
			  DWORD windowStyles, 
			  int defaultHorizontalPosition, 
			  int defaultVerticalPosition, 
			  int width,  
			  int height, 
			  HWND parentWindow, 
			  HMENU classMenuUsed, 
			  HINSTANCE instanceHandle, 
			  LPVOID windowCreationData);
		~Godel();
		HINSTANCE hinst;
		HWND hwndMain;
	};
}

#endif // GODELLIB_H_INCLUDED
