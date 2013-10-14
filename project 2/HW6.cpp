#include<windows.h>
#include<tchar.h>
#include<math.h>
#include<malloc.h>

typedef struct pointdef{
	int x;
	int y;
}DEFPOINT;

int showtime = 100;
DEFPOINT *point = (DEFPOINT *) malloc(4 * showtime * sizeof(DEFPOINT));

BOOLEAN InitWindowClass(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	MSG msg;
	if (!InitWindowClass(hInstance, nCmdShow)){
		MessageBox(NULL, L"创建窗口失败！", _T("创建窗口"), NULL);
		return 1;
	}

	int j;
	for (j = 0; j < 4 * showtime; j++){
		point[j].x = 300 + 100 * 3.14 * j / 2 / showtime;
		point[j].y = 300 - (int) (sin(3.14 * j / 2 / showtime) * 100);
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
	int r;
	switch (message)
	{
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &PtStr);

		
		if (i < showtime){
			hPen = CreatePen(
				PS_SOLID,
				0,
				RGB(255, 0, 0)
				);
			r = 20 + 40 * i / showtime;
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hDC, hBrush);
			SelectObject(hDC, hPen);
			Ellipse(hDC, point[i].x - r, point[i].y - r, point[i].x + r, point[i].y + r);
		}
		else if (i < 2 * showtime){
			hPen = CreatePen(
				PS_SOLID,
				0,
				RGB(0, 255, 0)
				);
			r = 20 + 40 * (i - showtime) / showtime;
			hBrush = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hDC, hBrush);
			SelectObject(hDC, hPen);
			Ellipse(hDC, point[i].x - r, point[i].y - r, point[i].x + r, point[i].y + r);
		}
		else if (i < 3 * showtime){
			hPen = CreatePen(
				PS_SOLID,
				0,
				RGB(0, 0, 255)
				);
			r = 20 + 40 * (i - 2 * showtime) / showtime;
			hBrush = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hDC, hBrush);
			SelectObject(hDC, hPen);
			Ellipse(hDC, point[i].x - r, point[i].y - r, point[i].x + r, point[i].y + r);
		}
		else if (i < 4 * showtime){
			hPen = CreatePen(
				PS_SOLID,
				0,
				RGB(255, 255, 0)
				);
			r = 20 + 40 * (i - 3 * showtime) / showtime;
			hBrush = CreateSolidBrush(RGB(255, 255, 0));
			SelectObject(hDC, hBrush);
			SelectObject(hDC, hPen);
			Ellipse(hDC, point[i].x - r, point[i].y - r, point[i].x + r, point[i].y + r);
		}

		i++;
		EndPaint(hWnd, &PtStr);
		Sleep(25);
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