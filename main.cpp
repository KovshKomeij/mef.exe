#include <windows.h>
#include <cstdlib>

int main(){
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	PlaySound(TEXT("mef.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	HDC hdc = GetDC(0);
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);

	while(1){
		POINT cursor;
		GetCursorPos(&cursor);

		DrawIcon(hdc, cursor.x, cursor.y, LoadIcon(NULL, IDI_ERROR));
		DrawIcon(hdc, rand() % w, rand() % h, LoadIcon(NULL, IDI_WARNING));
		BitBlt(hdc, rand() % w, rand() % h, rand() % w, rand() % h, hdc, rand() % w, rand() % h, NOTSRCCOPY);
		StretchBlt(hdc, 50, 50, w - 100, h - 100, hdc, 0, 0, w, h, SRCCOPY);
		Sleep(100);
	}

	return 0;
}