#include<windows.h>
#include<tchar.h>
#include <stdio.h>   
#include <stdlib.h>    
#include<commdlg.h>
#include"resource.h"

OPENFILENAME ofn;
CHOOSECOLOR chc;
CHOOSEFONT chf;
HINSTANCE hInst;

BOOL  OpenFileDialog(HWND hWnd)
{
	TCHAR szFile[MAX_PATH];       // buffer for file name
	// Initialize OPENFILENAME
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = szFile;
	//
	// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
	// use the contents of szFile to initialize itself.
	//
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = TEXT("All Files (*.*)\0*.*\0\0");
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	return GetOpenFileName((LPOPENFILENAME) &ofn);
}

BOOL  SaveFileDialog(HWND hWnd)
{
	TCHAR szFile[MAX_PATH];       // buffer for file name
	// Initialize OPENFILENAME
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = szFile;
	//
	// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
	// use the contents of szFile to initialize itself.
	//
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = TEXT("All Files (*.*)\0*.*\0\0");
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_SHOWHELP | OFN_OVERWRITEPROMPT;
	return GetSaveFileName((LPOPENFILENAME) &ofn);
}

BOOLEAN InitWindowClass(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	MSG msg;
	hInst = hInstance;
	if (!InitWindowClass(hInstance, nCmdShow)){
		MessageBox(NULL, L"��������ʧ�ܣ�", _T("��������"), NULL);
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
	static char szFilter [] = "All Files (*.*)\0*.*\0\0";
	static char lpstrFileName [] = "";
	static COLORREF clref[16] = { 0x00ff0000 };

	switch (message)
	{
	case WM_CREATE:
		chc.lStructSize = sizeof(CHOOSECOLOR);	//�ṹ��С
		chc.hwndOwner = hWnd;			//�����ھ��
		chc.rgbResult = 0;			//�趨Ĭ����ɫ
		chc.lpCustColors = clref;		//�û��Զ�����ɫ�����ָ��
		chc.Flags = 0;				//��־
		chc.lCustData = 0;
		chc.lpfnHook = NULL;			//���Ӻ���ָ��
		chc.lpTemplateName = NULL;

		chf.lStructSize = sizeof(CHOOSEFONT);	//�ṹ��С
		chf.hwndOwner = hWnd;				//�����ھ��
		chf.Flags = CF_BOTH | CF_TTONLY | CF_EFFECTS;//ͨ�öԻ�������
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDM_OPEN:
			OpenFileDialog(hWnd);
			break;
		case IDM_SAVEAS:
			SaveFileDialog(hWnd);
			break;
		case IDM_FONT:
			ChooseFont(&chf);	
			break;
		case IDM_COLOR:
			ChooseColor(&chc);
			break;
		default:
			break;
		}
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
	TCHAR szWindowClass [] = L"ͨ�öԻ�����ʾʵ������";
	TCHAR szTitle [] = L"ͨ�öԻ�����ʾʵ������";
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = 0;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName = L"MENU";
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