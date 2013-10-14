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

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	HDC hDC;
	PAINTSTRUCT PtStr;
	HBRUSH hBrush;
	HPEN hPen;
	LPCTSTR str;
	static int i = 0;
	switch (message)
	{
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &PtStr);

		hPen = CreatePen(PS_SOLID,
		1,
		RGB(100, 100, 100)
		);
		SelectObject(hDC, hPen);
		Ellipse(hDC, 100, 100, 500, 500); //画外圆轮廓

		hPen = CreatePen(PS_SOLID,
			1,
			RGB(255, 255, 0)
			);
		hBrush = CreateSolidBrush(RGB(255, 255, 0));
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Pie(hDC, 100, 100, 500, 500, 300 - (int) (200 * sin(3.14 * i / 300)), 300 - (int) (200 * cos(3.14 * i / 300)), 300 - (int) (200 * sin(3.14 * (i + 100) / 300)), 300 - (int) (200 * cos(3.14 * (i + 100) / 300)));

		hPen = CreatePen(PS_SOLID,
			1,
			RGB(255, 0, 0)
			);
		hBrush = CreateSolidBrush(RGB(255, 0, 0));
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Pie(hDC, 100, 100, 500, 500, 300 - (int) (200 * sin(3.14 * (i + 200) / 300)), 300 - (int) (200 * cos(3.14 * (i + 200) / 300)), 300 - (int) (200 * sin(3.14 * (i + 300) / 300)), 300 - (int) (200 * cos(3.14 * (i + 300) / 300)));

		hPen = CreatePen(PS_SOLID,
			1,
			RGB(0, 0, 255)
			);
		hBrush = CreateSolidBrush(RGB(0, 0, 255));
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Pie(hDC, 100, 100, 500, 500, 300 - (int) (200 * sin(3.14 * (i + 400) / 300)), 300 - (int) (200 * cos(3.14 * (i + 400) / 300)), 300 - (int) (200 * sin(3.14 * (i + 500) / 300)), 300 - (int) (200 * cos(3.14 * (i + 500) / 300)));

		EndPaint(hWnd, &PtStr);
		i++;
		Sleep(100);
		InvalidateRect(hWnd, NULL, true);
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
	TCHAR szWindowClass [] = L"窗口示例";
	TCHAR szTitle [] = L"映射模式及填充示例图";
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