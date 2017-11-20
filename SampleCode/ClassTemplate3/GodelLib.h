#include <windows.h>



class GDL
{
   public:
     static GDL *CreateTestWindow(HINSTANCE hInstance);
     GDL() : m_hWnd(0) {}
     ~GDL();

   private:
     static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
     static const char *m_pszClassName;
     HWND m_hWnd;
};


const char *GDL::m_pszClassName = "GDL";

GDL *GDL::CreateTestWindow(HINSTANCE hInst)
{
    WNDCLASS wincl;

    if(!GetClassInfo(hInst, m_pszClassName, &wincl))
    {
        wincl.style = 0;
        wincl.hInstance = hInst;
        wincl.lpszClassName = m_pszClassName;
        wincl.lpfnWndProc = WindowProc;
        wincl.cbClsExtra = 0;
        wincl.cbWndExtra = 0;
        wincl.hIcon = NULL;
        wincl.hCursor = NULL;
        wincl.hbrBackground = (HBRUSH)(COLOR_BTNFACE+1);
        wincl.lpszMenuName = NULL;

        if (RegisterClass(&wincl) == 0)
        {
            MessageBox(NULL,"The window class failed to register.","Error",0);
            return 0;
        }
    }

    GDL *g_vars = new GDL;
    HWND hWnd = CreateWindow(m_pszClassName, NULL, WS_VISIBLE | WS_OVERLAPPED, 50, 50, 200, 200, NULL, NULL, hInst, g_vars);

    if(hWnd == NULL)
    {
        delete g_vars;
        MessageBox(NULL,"Problem creating the window.","Error",0);
        return 0;
    }

    return g_vars;
}


LRESULT CALLBACK GDL::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_DESTROY:
        {
            GDL *g_vars = (GDL *)GetWindowLongPtr(hwnd, GWLP_USERDATA);

            if(g_vars)
            {
              g_vars->m_hWnd = 0;
            }
            break;
        }

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}


GDL::~GDL()   // Destructor
{
   if(m_hWnd)
   {
    DestroyWindow( m_hWnd );
   }
}
