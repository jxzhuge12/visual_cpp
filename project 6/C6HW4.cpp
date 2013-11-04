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

static HCURSOR hCursor;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	HDC hDC;
	WORD x, y;
	PAINTSTRUCT ps;
	static int i = 0;
	RECT clientRect;
	HFONT hF;
	HBRUSH hBrush;
	HPEN hPen;
	LPCWSTR text1 = L"LEFT BUTTON";
	LPCWSTR text2 = L"RIGHT BUTTON";

	switch (message){
	case WM_CREATE:
		break;
	case WM_MOUSEMOVE:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		GetClientRect(hWnd, &clientRect);
		if (x >= clientRect.right / 5 && x <= clientRect.right * 2 / 5 && y >= 0 && y <= clientRect.bottom){
			hCursor = LoadCursor(NULL, IDC_CROSS);
			SetCursor(hCursor);
		}
		else if (x >= clientRect.right * 2 / 5 && x <= clientRect.right * 3 / 5 && y >= 0 && y <= clientRect.bottom){
			hCursor = LoadCursor(NULL, IDC_SIZENESW);
			SetCursor(hCursor);
		}
		else if (x >= clientRect.right * 3 / 5 && x <= clientRect.right * 4 / 5 && y >= 0 && y <= clientRect.bottom){
			hCursor = LoadCursor(NULL, IDC_SIZENS);
			SetCursor(hCursor);
		}
		else if (x >= clientRect.right * 4 / 5 && x <= clientRect.right && y >= 0 && y <= clientRect.bottom){
			hCursor = LoadCursor(NULL, IDC_WAIT);
			SetCursor(hCursor);
		}
		else{
			hCursor = LoadCursor(NULL, IDC_ARROW);
			SetCursor(hCursor);
		}
		break;
	case WM_LBUTTONDOWN:
		i = 1;
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_RBUTTONDOWN:
		i = 2;
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_SIZE:
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &clientRect);
		hBrush = CreateSolidBrush(RGB(255, 0, 0));
		hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		SelectObject(hDC, hBrush);
		SelectObject(hDC, hPen);
		Rectangle(hDC, 0, 0, clientRect.right, clientRect.bottom);
		hBrush = CreateSolidBrush(RGB(255, 255, 0));
		hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 0));
		SelectObject(hDC, hBrush);
		SelectObject(hDC, hPen);
		Rectangle(hDC, 0, 0, clientRect.right * 4 / 5, clientRect.bottom);
		hBrush = CreateSolidBrush(RGB(0, 0, 255));
		hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		SelectObject(hDC, hBrush);
		SelectObject(hDC, hPen);
		Rectangle(hDC, 0, 0, clientRect.right * 3 / 5, clientRect.bottom);
		hBrush = CreateSolidBrush(RGB(0, 255, 0));
		hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		SelectObject(hDC, hBrush);
		SelectObject(hDC, hPen);
		Rectangle(hDC, 0, 0, clientRect.right * 2 / 5, clientRect.bottom);
		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
		SelectObject(hDC, hBrush);
		SelectObject(hDC, hPen);
		Rectangle(hDC, 0, 0, clientRect.right / 5, clientRect.bottom);
		DeleteObject(hPen);
		DeleteObject(hBrush);
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
		SetTextColor(hDC, RGB(0, 0, 0));
		SelectObject(hDC, hF);
		if (i == 1){
			TextOut(hDC, 0, 0, text1, 11);
		}
		else if (i == 2){
			TextOut(hDC, 0, 0, text2, 12);
		}
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
	TCHAR szTitle [] = L"文字显示";
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = 0;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = hCursor;
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