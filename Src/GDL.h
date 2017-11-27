#ifndef GDL_H
#define GDL_H

#include <iostream>
#include <string>
#include <tchar.h>
#include <windows.h>

#include "GDL.cpp"

class GDL
{
public:
    GDL();
    ~GDL();
    void setStyle(UINT);
    void setProcess(WNDPROC);
    void setHandler(HINSTANCE);
    void setIcon(HICON);
    void setCursor(HCURSOR);
    void setBackgroundColor(HBRUSH);
    void setName(LPCTSTR);
    void setMenuName(LPCTSTR);
private:
    UINT style;
    WNDPROC process;
    HINSTANCE handler;
    HICON icon;
    HCURSOR cursor;
    HBRUSH backgroundColor;
    LPCTSTR Name;
    LPCTSTR menuName;

    // Checkers
    // Aqui va un vector estatico con todos los nombres de clases asignados, para tener un control
    // mejor sobre ese elemento, cada vez que se instancia uno se a;ade al array solo y solo si
    // no hay nombre repetido
};

#endif // GDL_H
