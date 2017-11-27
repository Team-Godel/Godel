#include "GDL.h"

GDL::GDL()
{

}

GDL::~GDL()
{

}

void GDL::setStyle(UINT style)
{
    this->style = style
}

void GDL::setProcess(WNDPROC process)
{
    this->process = process;
}

void GDL::setHandler(HINSTANCE handler)
{
    this->handler = handler
}

void GDL::setIcon(HICON icon)
{
    this->icon = icon;
}

void GDL::setCursor(HCURSOR cursor)
{

}

void GDL::setBackgroundColor(HBRUSH backgroundColor)
{
    this->backgroundColor = backgroundColor;
}

void GDL::setName(LPCTSTR)
{

}

void GDL::setMenuName(LPCTSTR)
{

}
