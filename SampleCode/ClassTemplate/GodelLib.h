#include <windows.h>

class viewvars {

public:
    static viewvars* CreateTestWindow( HINSTANCE hInstance );
    viewvars() : m_hWnd( 0 ) {}
    ~viewvars();

private:
    static LRESULT CALLBACK WindowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
    static const char * m_pszClassName;
    HWND m_hWnd;

};

const char * viewvars::m_pszClassName = "viewvars";

viewvars * viewvars::CreateTestWindow( HINSTANCE hInst ) {

    WNDCLASS wincl;
    if (!GetClassInfo(hInst, m_pszClassName, &wincl)) {
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
        if (RegisterClass(&wincl) == 0) {
            MessageBox(NULL,"The window class failed to register.","Error",0);
            return 0;
        }
    }

    viewvars * pviewvars = new viewvars;
    HWND hWnd = CreateWindow( m_pszClassName, "Test", WS_VISIBLE | WS_OVERLAPPED, 50, 50, 200, 200, NULL, NULL, hInst, pviewvars );
    if ( hWnd == NULL ) {
        delete pviewvars;
        MessageBox(NULL,"Problem creating the window.","Error",0);
        return 0;
    }

    return pviewvars;

}

 LRESULT CALLBACK viewvars::WindowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam ) {

    switch ( uMsg ) {

        case WM_NCCREATE: {
            CREATESTRUCT * pcs = (CREATESTRUCT*)lParam;
            viewvars * pviewvars = (viewvars*)pcs->lpCreateParams;
            pviewvars->m_hWnd = hwnd;
            SetWindowLongPtr( hwnd, GWLP_USERDATA, (LONG)pcs->lpCreateParams );
            return TRUE;
        }

        case WM_DESTROY: {
            viewvars * pviewvars = (viewvars *)GetWindowLongPtr( hwnd, GWLP_USERDATA );
            if ( pviewvars ) pviewvars->m_hWnd = 0;
            break;
        }

        default:
            return DefWindowProc( hwnd, uMsg, wParam, lParam );

    }

    return 0;

}

viewvars::~viewvars() {
    if ( m_hWnd ) DestroyWindow( m_hWnd );
}
