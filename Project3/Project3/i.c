#include "windows.h"
#include "iostream"
#include <stdio.h>
#include <stdlib.h>
#include "winbase.h"
#include "sysinfoapi.h"
#include "fileapi.h"
#include "winnt.h"
#include <cassert>

using namespace std;

volatile int n; 

DWORD WINAPI Add(LPVOID iNum)
{
	cout << "Thread is started." << endl;
	n += (int)iNum;
	cout << "Thread is finished." << endl;

	return 0;
}


int main()
{
	int inc = 10;
	HANDLE hThread; // дескриптор потока
	DWORD IDThread; // идентификатор потока

	cout << "n = " << n << endl;

	hThread = CreateThread(NULL, 0, Add, (void*)inc, 0, &IDThread);
	if (hThread == NULL)
		return GetLastError();

	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);

	cout << "n = " << n << endl;

	return 0;	
}