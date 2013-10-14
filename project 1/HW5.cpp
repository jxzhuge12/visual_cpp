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
	switch (message)
	{
	case WM_LBUTTONDOWN:
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &PtStr);
		SetMapMode(hDC, MM_TEXT);
		TextOut(hDC, 0, 0, NULL, NULL);

		hPen = CreatePen(
			PS_SOLID,
			0,
			RGB(255, 0, 0)
			);
		hBrush = CreateSolidBrush(RGB(0,255,0));
		POINT lpPoints[5];
		lpPoints[0].x = 181;
		lpPoints[0].y = 221;
		lpPoints[1].x = 212;
		lpPoints[1].y = 195;
		lpPoints[2].x = 201;
		lpPoints[2].y = 159;
		lpPoints[3].x = 161;
		lpPoints[3].y = 159;
		lpPoints[4].x = 150;
		lpPoints[4].y = 195;
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Polygon(hDC,lpPoints,5);

		hBrush = CreateSolidBrush(RGB(255, 255, 0));
		lpPoints[0].x = 181;
		lpPoints[0].y = 100;
		lpPoints[1].x = 161;
		lpPoints[1].y = 159;
		lpPoints[2].x = 201;
		lpPoints[2].y = 159;
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Polygon(hDC, lpPoints, 3);

		hBrush = CreateSolidBrush(RGB(0, 255, 255));
		lpPoints[0].x = 181;
		lpPoints[0].y = 100;
		lpPoints[1].x = 161;
		lpPoints[1].y = 159;
		lpPoints[2].x = 100;
		lpPoints[2].y = 159;
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Polygon(hDC, lpPoints, 3);

		hBrush = CreateSolidBrush(RGB(100, 100, 100));
		lpPoints[0].x = 181;
		lpPoints[0].y = 100;
		lpPoints[1].x = 201;
		lpPoints[1].y = 159;
		lpPoints[2].x = 262;
		lpPoints[2].y = 159;
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Polygon(hDC, lpPoints, 3);

		hBrush = CreateSolidBrush(RGB(150, 100, 50));
		lpPoints[0].x = 100;
		lpPoints[0].y = 159;
		lpPoints[1].x = 150;
		lpPoints[1].y = 195;
		lpPoints[2].x = 161;
		lpPoints[2].y = 159;
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Polygon(hDC, lpPoints, 3);

		hBrush = CreateSolidBrush(RGB(95, 205, 190));
		lpPoints[0].x = 262;
		lpPoints[0].y = 159;
		lpPoints[1].x = 201;
		lpPoints[1].y = 159;
		lpPoints[2].x = 212;
		lpPoints[2].y = 195;
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Polygon(hDC, lpPoints, 3);

		hBrush = CreateSolidBrush(RGB(54, 165, 130));
		lpPoints[0].x = 100;
		lpPoints[0].y = 159;
		lpPoints[1].x = 131;
		lpPoints[1].y = 254;
		lpPoints[2].x = 150;
		lpPoints[2].y = 195;
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Polygon(hDC, lpPoints, 3);

		hBrush = CreateSolidBrush(RGB(123, 56, 150));
		lpPoints[0].x = 131;
		lpPoints[0].y = 254;
		lpPoints[1].x = 150;
		lpPoints[1].y = 195;
		lpPoints[2].x = 181;
		lpPoints[2].y = 218;
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Polygon(hDC, lpPoints, 3);

		hBrush = CreateSolidBrush(RGB(90, 124, 30));
		lpPoints[0].x = 131;
		lpPoints[0].y = 254;
		lpPoints[1].x = 231;
		lpPoints[1].y = 254;
		lpPoints[2].x = 181;
		lpPoints[2].y = 218;
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Polygon(hDC, lpPoints, 3);

		hBrush = CreateSolidBrush(RGB(195, 45, 40));
		lpPoints[0].x = 181;
		lpPoints[0].y = 218;
		lpPoints[1].x = 212;
		lpPoints[1].y = 195;
		lpPoints[2].x = 231;
		lpPoints[2].y = 254;
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Polygon(hDC, lpPoints, 3);

		hBrush = CreateSolidBrush(RGB(143, 135, 130));
		lpPoints[0].x = 231;
		lpPoints[0].y = 254;
		lpPoints[1].x = 212;
		lpPoints[1].y = 195;
		lpPoints[2].x = 262;
		lpPoints[2].y = 159;
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Polygon(hDC, lpPoints, 3);

		hPen = CreatePen(
			PS_SOLID,
			3,
			(0, 0, 130)
			);
		lpPoints[0].x = 181;
		lpPoints[0].y = 100;
		lpPoints[1].x = 131;
		lpPoints[1].y = 254;
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Polyline(hDC, lpPoints, 2);

		hPen = CreatePen(
			PS_SOLID,
			3,
			RGB(143, 0, 100)
			);
		lpPoints[0].x = 181;
		lpPoints[0].y = 100;
		lpPoints[1].x = 231;
		lpPoints[1].y = 254;
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Polyline(hDC, lpPoints, 2);

		hPen = CreatePen(
			PS_SOLID,
			3,
			RGB(0, 135, 130)
			);
		lpPoints[0].x = 100;
		lpPoints[0].y = 159;
		lpPoints[1].x = 262;
		lpPoints[1].y = 159;
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Polyline(hDC, lpPoints, 2);

		hPen = CreatePen(
			PS_SOLID,
			3,
			RGB(103, 0, 0)
			);
		lpPoints[0].x = 100;
		lpPoints[0].y = 159;
		lpPoints[1].x = 231;
		lpPoints[1].y = 254;
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Polyline(hDC, lpPoints, 2);

		hPen = CreatePen(
			PS_SOLID,
			3,
			RGB(0, 0, 0)
			);
		lpPoints[0].x = 262;
		lpPoints[0].y = 159;
		lpPoints[1].x = 131;
		lpPoints[1].y = 254;
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);
		Polyline(hDC, lpPoints, 2);

		//lpPoints[0].x = 181;
		//lpPoints[0].y = 100;
		//lpPoints[1].x = 100;
		//lpPoints[1].y = 159;
		//lpPoints[2].x = 131;
		//lpPoints[2].y = 254;
		//lpPoints[3].x = 231;
		//lpPoints[3].y = 254;
		//lpPoints[4].x = 262;
		//lpPoints[4].y = 159;
		//SelectObject(hDC, hPen);
		//Polygon(hDC,lpPoints,5);

		//hBrush = (HBRUSH) GetStockObject(DKGRAY_BRUSH);
		//SelectObject(hDC, hBrush);
		//RoundRect(hDC, 50, 120, 100, 200, 15, 15);
		EndPaint(hWnd, &PtStr);
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