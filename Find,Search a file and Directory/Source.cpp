#include<Windows.h>
#include<iostream>
using namespace std;
int main()
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFindFile;
	LPCWSTR file = L"*.cpp";
	hFindFile = FindFirstFile(file, &FindFileData);
	if (INVALID_HANDLE_VALUE == hFindFile)
	{
		cout << "Error in Finding File" << endl;
		cout << "Error - " << GetLastError() << endl;
	}
	else
	{
		cout << "File Found" << endl;
		wcout << "File Name - " << FindFileData.cFileName << endl;
		wcout << "File Size - " << FindFileData.nFileSizeLow << endl;

	}
	while (FindNextFile(hFindFile, &FindFileData))
	{
		wcout << "File Name -" << FindFileData.cFileName << endl;
	}

	FindClose(hFindFile);
	system("PAUSE");
	return 0;

}