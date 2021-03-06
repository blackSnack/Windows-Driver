#include "pch.h"
#include <stdio.h>
#include <tchar.h> 
#include <windows.h>

// 主函数
int _tmain(int argc,_TCHAR* argv[])
{
	// 打开符号（设备句柄）
	HANDLE hDevice = CreateFile(L"\\\\.\\MTRead", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hDevice == INVALID_HANDLE_VALUE)
	{
		printf("Failed To Obtain Device Handle!");
		return -1;
	}

	// 创建一个缓冲区进行读写
	UCHAR buffer[10];
	ULONG size;
	// 从设备中读取数据
	BOOL result = ReadFile(hDevice, buffer, 10, &size, NULL);
	if (result)
	{
		// 打印到控制台
		printf("Read %d bytes : ", size);
		for (int i = 0; i < (int)size; i++)
		{
			printf("%02X ", buffer[i]);
		}
		printf("\n");
	}
	// 关闭设备句柄
	CloseHandle(hDevice);
	system("pause");
	return 0;
}

