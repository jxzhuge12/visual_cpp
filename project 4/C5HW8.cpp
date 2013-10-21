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
	LPCWSTR poem = L"欲穷千里目更上一层楼";
	TEXTMETRIC tm;
	int X = 0;
	int Y = 20;
	int R = 120;
	HFONT hF;
	int i;

	switch (message){
	case WM_PAINT:
			hDC = BeginPaint(hWnd, &ps);
			SetTextColor(hDC, RGB(0, 0, 0));
		for (i = 0; i < 10; i++){
			LPCWSTR output = &poem[i];
			Y = Y + 2;
			hF = CreateFont(
				60 - i * 4,
				20,
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
			TextOut(hDC, X, Y, output, 1);
			GetTextMetrics(hDC, &tm);
			DeleteObject(hF);
			X = X + tm.tmMaxCharWidth;
		}
		Y = 90;
		X = 0;
		for (i = 0; i < 10; i++){
			LPCWSTR output = &poem[i];
			Y = Y - 2;
			hF = CreateFont(
				24 + i * 4,
				20,
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
			TextOut(hDC, X, Y, output, 1);
			GetTextMetrics(hDC, &tm);
			DeleteObject(hF);
			X = X + tm.tmMaxCharWidth;
		}
		X = 0;
		for (i = 0; i < 5; i++){
			LPCWSTR output = &poem[i];
			Y = 160 + (4 - i) * (4 - i) / 2;
			hF = CreateFont(
				40 - (4 - i) * (4 - i),
				20,
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
			SetTextColor(hDC, RGB(230 - 25.5 * i, 230 - 25.5 * i, 230 - 25.5 * i));
			TextOut(hDC, X, Y, output, 1);
			GetTextMetrics(hDC, &tm);
			DeleteObject(hF);
			X = X + tm.tmMaxCharWidth;
		}
		for (i = 5; i < 10; i++){
			LPCWSTR output = &poem[i];
			Y = 160 + (5 - i) * (5 - i) / 2;
			hF = CreateFont(
				40 - (5 - i) * (5 - i),
				20,
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
			SetTextColor(hDC, RGB(230 - 25.5 * i, 230 - 25.5 * i, 230 - 25.5 * i));
			TextOut(hDC, X, Y, output, 1);
			GetTextMetrics(hDC, &tm);
			DeleteObject(hF);
			X = X + tm.tmMaxCharWidth;
		}
		X = 0;
		for (i = 0; i < 10; i++){
			LPCWSTR output = &poem[i];
			Y = 270 - i * i / 2;
			hF = CreateFont(
				10 + i * i,
				20,
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
			TextOut(hDC, X, Y, output, 1);
			GetTextMetrics(hDC, &tm);
			DeleteObject(hF);
			X = X + tm.tmMaxCharWidth;
		}
		X = 0;
		for (i = 0; i < 10; i++){
			LPCWSTR output = &poem[i];
			Y = 380 - 40 * sin(3.1415 * i / 5);
			hF = CreateFont(
				40,
				20,
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
			SetTextColor(hDC, RGB(230 - 25.5 * i, 230 - 25.5 * i, 230 - 25.5 * i));
			TextOut(hDC, X, Y, output, 1);
			GetTextMetrics(hDC, &tm);
			DeleteObject(hF);
			X = X + tm.tmMaxCharWidth;
		}
		X = 0;
		for (i = 0; i < 10; i++){
			LPCWSTR output = &poem[i];
			Y = 500 - 40 * cos(3.1415 * i / 5);
			hF = CreateFont(
				40,
				20,
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
			TextOut(hDC, X, Y, output, 1);
			GetTextMetrics(hDC, &tm);
			DeleteObject(hF);
			X = X + tm.tmMaxCharWidth;
		}
		for (i = 0; i < 10; i++){
			LPCWSTR output = &poem[i];
			X = 700 - R * cos(3.1415926 * i / 10);
			Y = 150 - R * sin(3.1415926 * i / 10);
			hF = CreateFont(
				40 - 3 * i,
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
			TextOut(hDC, X, Y, output, 1);
			GetTextMetrics(hDC, &tm);
			DeleteObject(hF);
		}
		for (i = 0; i < 10; i++){
			LPCWSTR output = &poem[i];
			X = 700 - R * cos(3.1415926 * (i - 5) / 5);
			Y = 350 + R * sin(3.1415926 * i / 5);
			hF = CreateFont(
				40,
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
			TextOut(hDC, X, Y, output, 1);
			GetTextMetrics(hDC, &tm);
			DeleteObject(hF);
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
	TCHAR szTitle [] = L"文字显示";
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