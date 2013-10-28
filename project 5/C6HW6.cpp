#include<windows.h> 
#include<tchar.h>

BOOLEAN InitWindowClass(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	MSG msg;
	if (!InitWindowClass(hInstance, nCmdShow)){
		MessageBox(NULL, L"创建窗口失败！", _T("创建窗口"), NULL);
		return 1;
	}
	while (GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	HDC hDC;
	PAINTSTRUCT ps;
	static int X1 = 50;
	static int Y1 = 50;
	static int X2 = 200;
	static int Y2 = 200;
	HPEN hPen;
	static int i = 0;

	switch (message){
	case WM_CHAR:
		
		
		break;
	case WM_KEYDOWN:
		{
			switch (wParam)
			{
			case VK_CONTROL:
				i = 1;
				InvalidateRect(hWnd, NULL, true);
				break;
			case VK_SHIFT:
				i = 2;
				InvalidateRect(hWnd, NULL, true);
				break;
			case VK_RIGHT:
				X2 += 10;
				InvalidateRect(hWnd, NULL, true);
				break;
			case VK_DOWN:
				Y2 += 10;
				InvalidateRect(hWnd, NULL, true);
				break;
			case VK_HOME:
				X1 -= 10;
				X2 -= 10;
				InvalidateRect(hWnd, NULL, true);
				break;
			case VK_END:
				X1 += 10;
				X2 += 10;
				InvalidateRect(hWnd, NULL, true);
				break;
			case VK_PRIOR:
				Y1 -= 10;
				Y2 -= 10;
				InvalidateRect(hWnd, NULL, true);
				break;
			case VK_NEXT:
				Y1 += 10;
				Y2 += 10;
				InvalidateRect(hWnd, NULL, true);
				break;
			}   
		}
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		if (i == 1){
			hPen = (HPEN) GetStockObject(BLACK_PEN);
			SelectObject(hDC, hPen);
			Arc(hDC, X1, Y1, X2, Y2, 0, 0, 0, 0);
		}
		else if (i == 2){
			hPen = (HPEN) GetStockObject(BLACK_PEN);
			SelectObject(hDC, hPen);
			Rectangle(hDC, X1, Y1, X2, Y2);
		}
		break;
	case WM_SIZE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}

BOOLEAN InitWindowClass(HINSTANCE hInstance, int nCmdShow){
	WNDCLASSEX wcex;
	HWND hWnd;
	TCHAR szWindowClass [] = L"窗口";
	TCHAR szTitle [] = L"画图";
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = 0;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	if (!RegisterClassEx(&wcex))
		return FALSE;
	hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
		);
	if (!hWnd)
		return FALSE;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}