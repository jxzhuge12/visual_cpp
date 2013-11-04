#include<windows.h>
#include<tchar.h>
#include<malloc.h>
#include<stdlib.h>

BOOLEAN InitWindowClass(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);



POINT* lpPoints = (POINT*) malloc(sizeof(POINT) * 100);
int able = 100;
int size = 0;

void isfull(int size){
	int i;
	if (size == able - 1){
		POINT* temp = (POINT*) malloc(sizeof(POINT) * able * 2);
		able = able * 2;
		for (i = 0; i < size; i++){
			temp[i].x = lpPoints[i].x;
			temp[i].y = lpPoints[i].y;
		}
		free(lpPoints);
		lpPoints = temp;
	}
}

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
	WORD X, Y;
	PAINTSTRUCT ps;
	static int i = 2;
	RECT clientRect;
	HFONT hF;
	wchar_t istr[32];
	HPEN hPen;
	LPCWSTR poem = L"以下数字表示已有的点的数量。由于使用了数据结构，所以没有点数上限。如果VS有内存限制，则会在足够多的点后发生错误。";

	switch (message){
	case WM_CREATE:
		break;
	case WM_MOUSEMOVE:
		X = LOWORD(lParam);
		Y = HIWORD(lParam);
		if (i == 1){
			lpPoints[size].x = X;
			lpPoints[size].y = Y;
			size++;
			isfull(size);
		}
		InvalidateRect(hWnd, NULL, false);
		break;
	case WM_LBUTTONDOWN:
		i = 1;
		break;
	case WM_LBUTTONUP:
		i = 2;
		break;
	case WM_SIZE:
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &clientRect);
		hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));

		Polyline(hDC, lpPoints, size);
		if (i == 2){
			POINT be[2];
			be[0].x = lpPoints[0].x;
			be[0].y = lpPoints[0].y;
			be[1].x = lpPoints[size - 1].x;
			be[1].y = lpPoints[size - 1].y;
			Polyline(hDC, be, 2);
		}
		hF = CreateFont(
			0,
			0,
			0,
			0,
			FW_NORMAL,
			0,
			0,
			0,
			GB2312_CHARSET,
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
			DEFAULT_PITCH,
			L"宋体"
			);
		SelectObject(hDC, hF);
		TextOut(hDC, 0, 0, poem, 57);
		_itow_s(size, istr, 10);
		TextOut(hDC, 0, 20, istr, wcslen(istr));
		DeleteObject(hF);
		DeleteObject(hPen);
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
	TCHAR szWindowClass [] = L"窗口";
	TCHAR szTitle [] = L"绘图";
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