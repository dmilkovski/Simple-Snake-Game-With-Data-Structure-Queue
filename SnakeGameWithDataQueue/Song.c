#define _CRT_NO_SECURE_WARNIGS
#include<Windows.h>

void PlaySong ()
{
	int C = 261;
	int Cis = 277;
	int D = 293;
	int Dis = 311;
	int E = 329;
	int F = 349;
	int Fis = 369;
	int G = 391;
	int Gis = 415;
	int A = 440;
	int Ais = 466;
	int H = 493;
	int Takt = 1700;

	Beep(E * 2, Takt / 4);
	Beep(H * 1, Takt / 8);
	Beep(C * 2, Takt / 8);
	Beep(D * 2, Takt / 4);
	Beep(C * 2, Takt / 8);
	Beep(H * 1, Takt / 8);
	Beep(A * 1, Takt / 4);
	Beep(A * 1, Takt / 8);
	Beep(C * 2, Takt / 8);
	Beep(E * 2, Takt / 8);
	Beep(E * 2, Takt / 8);
	Beep(D * 2, Takt / 8);
	Beep(C * 2, Takt / 8);
	Beep(H * 1, Takt / 2.5);
	Beep(C * 2, Takt / 8);
	Beep(D * 2, Takt / 4);
	Beep(E * 2, Takt / 4);
	Beep(C * 2, Takt / 4);
	Beep(A * 1, Takt / 4);
	Beep(A * 1, Takt / 4);
	Sleep(Takt / (8 / 3));
	Beep(D * 2, Takt / 3.25);
	Beep(F * 2, Takt / 8);
	Beep(A * 2, Takt / 8);
	Beep(A * 2, Takt / 8);
	Beep(G * 2, Takt / 8);
	Beep(F * 2, Takt / 8);
	Beep(E * 2, Takt / 3);
	Beep(C * 2, Takt / 8);
	Beep(E * 2, Takt / 8);
	Beep(E * 2, Takt / 8);
	Beep(D * 2, Takt / 8);
	Beep(C * 2, Takt / 8);
	Beep(H * 1, Takt / 4);
	Beep(H * 1, Takt / 8);
	Beep(C * 2, Takt / 8);
	Beep(D * 2, Takt / 4);
	Beep(E * 2, Takt / 4);
	Beep(C * 2, Takt / 4);
	Beep(A * 1, Takt / 4);
	Beep(A * 1, Takt / 4);
}