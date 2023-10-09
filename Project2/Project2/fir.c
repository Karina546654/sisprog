#include "windows.h"
#include "iostream"
#include <stdio.h>
#include <stdlib.h>
#include "winbase.h"
#include "sysinfoapi.h"
#include "fileapi.h"
#include "winnt.h"
#include <cassert>

int main() {
	

	setlocale(0, "");
	char q[256];
	DWORD s = 256;
	GetComputerNameA(q, &s);
	printf("%s\n", q);


	setlocale(0, "");
	char qu[256];
	UINT su = 256;
	GetSystemDirectoryA(qu, su);
	printf("%s\n", qu);


	setlocale(0, "");
	char q1[256];
	UINT s1 = 256;
	GetWindowsDirectoryA(q1, s1);
	printf("%s\n", q1);


	setlocale(0, "");
	char q2[256];
	LPSTR s2 = q2;
	DWORD q3 = 256;
	GetTempPathA(q3, s2);
	printf("%s\n", q2);



	//std::system("ver");


	return 0;

}