#include<windows.h>
#include<tchar.h>
#include"resource.h"

BOOLEAN InitWindowClass(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE hInst;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	MSG msg;
	hInst = hInstance;
	if (!InitWindowClass(hInstance, nCmdShow)){
		MessageBox(NULL, L"创建窗口失败！", _T("创建窗口"), NULL);
		return 1;
	}
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	HDC hDC;
	PAINTSTRUCT ps;
	static HDC hMemDC;
	static HBITMAP hBitmap;
	static BITMAP bitmap;
	static int X, Y;
	static int up = 0, down = 0;
	static int graphheight, graphwidth;
	static double distance = 5;
	static RECT clientRect;
	RECT temp;
	switch (message)
	{
	case WM_CREATE:
		hDC = GetDC(hWnd);
		hMemDC = CreateCompatibleDC(hDC);
		hBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
		SelectObject(hMemDC, hBitmap);
		GetObject(hBitmap, sizeof(BITMAP), &bitmap);
		ReleaseDC(hWnd, hDC);
		GetClientRect(hWnd, &clientRect);
		graphwidth = (clientRect.right - clientRect.left) / 4;
		graphheight = (clientRect.bottom - clientRect.top) / 4;
		X = (clientRect.right - clientRect.left) * 3 / 8;
		Y = (clientRect.bottom - clientRect.top) * 3 / 8;
		break;
	case WM_KEYDOWN:
		{
			switch (wParam){
			case VK_UP:
				up++;
				InvalidateRect(hWnd, NULL, true);
				break;
			case VK_DOWN:
				down++;
				InvalidateRect(hWnd, NULL, true);
				break;
			}
		}
		break;
	case WM_LBUTTONDOWN:
		up++;
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_RBUTTONDOWN:
		down++;
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_SIZE:
		GetClientRect(hWnd, &temp);
		graphwidth = (temp.right - temp.left) / 4;
		graphheight = (temp.bottom - temp.top) / 4;
		X = (temp.right - temp.left) * 3 / 8;
		Y = (temp.bottom - temp.top) * 3 / 8;
		distance = distance * (temp.bottom - temp.top) / (clientRect.bottom - clientRect.top);
		GetClientRect(hWnd, &clientRect);
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_PAINT:
		GetClientRect(hWnd, &clientRect);
		if ((int)(Y + (down - up) * distance) <= 0){
			hDC = BeginPaint(hWnd, &ps);
			StretchBlt(hDC, X, (int) (Y + (down - up) * distance), graphwidth, graphheight, hMemDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
			EndPaint(hWnd, &ps);
			down++;
			MessageBox(hWnd, L"不能再向上移动了！", L"错误", MB_OK);
			break;
		}
		else if ((int)(Y + graphheight + (down - up) * distance) >= (clientRect.bottom - clientRect.top)){
			hDC = BeginPaint(hWnd, &ps);
			StretchBlt(hDC, X, (int) (Y + (down - up) * distance), graphwidth, graphheight, hMemDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
			EndPaint(hWnd, &ps);
			up++;
			MessageBox(hWnd, L"不能再向下移动了！", L"错误", MB_OK);
			break;
		}
		else{
			hDC = BeginPaint(hWnd, &ps);
			StretchBlt(hDC, X, (int) (Y + (down - up) * distance), graphwidth, graphheight, hMemDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
			EndPaint(hWnd, &ps);
			break;
		}
	case WM_DESTROY:
		DeleteObject(hBitmap);
		ReleaseDC(hWnd, hMemDC);
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
	TCHAR szWindowClass [] = L"窗口示例";
	TCHAR szTitle [] = L"GRAPH";
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