/* *************************************
*
* @Author         Noxaean
* @Email          noxaean@gmail.com
* @Description  
* @Created        2017-01-10 13:26:49
* @Last Modified  2017-01-10 15:54:09
*
* ****************************************/
#include <windows.h>

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE PrevInstance,
		LPSTR lpCmdLine, int nCmdShow){
	//MessageBox (NULL, TEXT("hello world"), TEXT("HELLOMSG"),4);
//	HDC hdc;
//	HWND hwnd;
//	COLORREF clo;
//	TCHAR szBuffer[] = TEXT("hehe");
//
//	hwnd = GetDesktopWindow();
//	hdc = GetWindowDC(hwnd);
//	SetBkMode(hdc,TRANSPARENT);
//
//	clo = SetTextColor(hdc,RGB(255,0,0));
//	TextOut(hdc,0,0,szBuffer,lstrlen(szBuffer));
//
//	SetTextColor(hdc,RGB(0,255,0));
//	TextOut(hdc,0,20,szBuffer,lstrlen(szBuffer));
//	SetBkMode(hdc,OPAQUE);
//	SetTextColor(hdc,RGB(0,0,255));
//	TextOut(hdc,0,40,szBuffer,lstrlen(szBuffer));
//	SetTextColor(hdc,clo);
//	ReleaseDC(hwnd,hdc);
//	Sleep(5000);
//	

	HDC hSrcDc,hMemDc;
	hSrcDc = CreateDC("DISPLAY",NULL,NULL,NULL);
	hMemDc = CreateCompatibleDC(hSrcDc);
	int xScrn,yScrn;
	xScrn = GetDeviceCaps(hSrcDc,HORZRES);
	yScrn = GetDeviceCaps(hSrcDc,VERTRES);
	HBITMAP hBitmap,hOldBitmap;
	hBitmap = CreateCompatibleBitmap(hSrcDc,100,60);
	hOldBitmap = (HBITMAP)SelectObject(hMemDc,hBitmap);
	BitBlt(hMemDc,0,0,100,60,hSrcDc,100,100,SRCCOPY);
	hBitmap = (HBITMAP)SelectObject(hMemDc,hOldBitmap);
	OpenClipboard(NULL);
	EmptyClipboard();
	SetClipboardData(CF_BITMAP,hBitmap);

	Sleep(5000);
	CloseClipboard();
	
	DeleteDC(hMemDc);
	DeleteDC(hSrcDc);
	DeleteObject(hBitmap);

	return 0;
}
//end
//end2
