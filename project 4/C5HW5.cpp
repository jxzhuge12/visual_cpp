#include<windows.h>
#include<tchar.h>
#include<math.h>

BOOLEAN InitWindowClass(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	MSG msg;
	if (!InitWindowClass(hInstance, nCmdShow)){
		MessageBox(NULL, L"��������ʧ�ܣ�", _T("��������"), NULL);
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
	LPCWSTR poem = L"�ޱ���ľ�����£�����������������";
	TEXTMETRIC tm;
	int X = 0;
	static int Y = 0;
	HFONT hF;
	int i;

	switch (message){
	case WM_CREATE:
		SetTimer(hWnd, 9999, 1000, NULL);
		break;
	case WM_PAINT:
		if (temp == 0){
			hDC = BeginPaint(hWnd, &ps);
			SetTextColor(hDC, RGB(255 / 4 * temp, 255 / 4 * temp, 255 / 4 * temp));
			SetBkColor(hDC, RGB(255, 0, 0));
			for (i = 0; i < 16; i++){
				LPCWSTR output = &poem[i];
				hF = CreateFont(
					32 / 15 * i + 8,
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
					L"����"
					);
				SelectObject(hDC, hF);
				TextOut(hDC, X, Y, output, 1);
				GetTextMetrics(hDC, &tm);
				DeleteObject(hF);
				X = X + tm.tmMaxCharWidth;
			}
			X = 0;
			Y = tm.tmHeight;
		}
		else if (temp == 1){
			hDC = BeginPaint(hWnd, &ps);
			SetTextColor(hDC, RGB(255 / 4 * temp, 255 / 4 * temp, 255 / 4 * temp));
			SetBkColor(hDC, RGB(255, 0, 0));
			for (i = 0; i < 16; i++){
				LPCWSTR output = &poem[i];
				hF = CreateFont(
					32 / 15 * i + 8,
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
					L"����"
					);
				SelectObject(hDC, hF);
				TextOut(hDC, X, Y, output, 1);
				GetTextMetrics(hDC, &tm);
				DeleteObject(hF);
				X = X + tm.tmMaxCharWidth;
			}
			X = 0;
			Y = Y + tm.tmHeight;
		}
		else if (temp == 2){
			hDC = BeginPaint(hWnd, &ps);
			SetTextColor(hDC, RGB(255 / 4 * temp, 255 / 4 * temp, 255 / 4 * temp));
			SetBkColor(hDC, RGB(255, 0, 0));
			for (i = 0; i < 16; i++){
				LPCWSTR output = &poem[i];
				hF = CreateFont(
					32 / 15 * i + 8,
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
					L"������"
					);
				SelectObject(hDC, hF);
				TextOut(hDC, X, Y, output, 1);
				GetTextMetrics(hDC, &tm);
				DeleteObject(hF);
				X = X + tm.tmMaxCharWidth;
			}
			X = 0;
			Y = Y + tm.tmHeight;
		}
		else if (temp == 3){
			hDC = BeginPaint(hWnd, &ps);
			SetTextColor(hDC, RGB(255 / 4 * temp, 255 / 4 * temp, 255 / 4 * temp));
			SetBkColor(hDC, RGB(255, 0, 0));
			for (i = 0; i < 16; i++){
				LPCWSTR output = &poem[i];
				hF = CreateFont(
					32 / 15 * i + 8,
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
					L"����"
					);
				SelectObject(hDC, hF);
				TextOut(hDC, X, Y, output, 1);
				GetTextMetrics(hDC, &tm);
				DeleteObject(hF);
				X = X + tm.tmMaxCharWidth;
			}
			X = 0;
			Y = Y + tm.tmHeight;
		}
		else if (temp == 4){
			hDC = BeginPaint(hWnd, &ps);
			SetTextColor(hDC, RGB(255 / 4 * temp, 255 / 4 * temp, 255 / 4 * temp));
			SetBkColor(hDC, RGB(255, 0, 0));
			for (i = 0; i < 16; i++){
				LPCWSTR output = &poem[i];
				hF = CreateFont(
					32 / 15 * i + 8,
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
					L"��Բ"
					);
				SelectObject(hDC, hF);
				TextOut(hDC, X, Y, output, 1);
				GetTextMetrics(hDC, &tm);
				DeleteObject(hF);
				X = X + tm.tmMaxCharWidth;
			}
			X = 0;
			Y = 0;
		}

		temp = (temp + 1) % 5;
		break;
	case WM_TIMER:
		if (wParam = 9999)
			InvalidateRect(hWnd, NULL, true);
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
	TCHAR szWindowClass [] = L"����";
	TCHAR szTitle [] = L"������˸";
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