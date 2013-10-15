#include<windows.h>
#include<tchar.h>
#include<math.h>

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
	static int temp = 0;
	RECT clientRect;
	HBRUSH hBrush;
	HPEN hPen;

	switch (message){
	case WM_CREATE:
		SetTimer(hWnd, 9999, 1000, NULL);
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &clientRect);
		if (temp % 3 == 0){
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
		}
		else if (temp % 3 == 1){
			hBrush = CreateSolidBrush(RGB(0, 255, 0));
			hPen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));
		}
		else{
			hBrush = CreateSolidBrush(RGB(0, 0, 255));
			hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
		}
		SelectObject(hDC, hBrush);
		SelectObject(hDC, hPen);
		Rectangle(hDC, 0, 0, clientRect.right, clientRect.bottom);
		temp++;
		DeleteObject(hBrush);
		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		if (wParam = 9999)
			InvalidateRect(hWnd, NULL, true);
		break;
	case WM_SIZE:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &clientRect);
		if (temp % 3 == 1){
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
		}
		else if (temp % 3 == 2){
			hBrush = CreateSolidBrush(RGB(0, 255, 0));
			hPen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));
		}
		else{
			hBrush = CreateSolidBrush(RGB(0, 0, 255));
			hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
		}
		SelectObject(hDC, hBrush);
		SelectObject(hDC, hPen);
		Rectangle(hDC, 0, 0, clientRect.right, clientRect.bottom);
		DeleteObject(hBrush);
		EndPaint(hWnd, &ps);
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
	TCHAR szWindowClass[] = L"窗口";
	TCHAR szTitle[] = L"屏幕闪烁";
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
		CW_USEDEFAULT,CW_USEDEFAULT,
		CW_USEDEFAULT,CW_USEDEFAULT,
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