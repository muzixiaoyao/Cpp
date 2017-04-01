#include "stdafx.h"
#include <windows.h>
#include <iostream>

int main(int argc, char* argv[])
{
	using namespace std;
	
	if (argc < 4)
	{
		cout << "error：ifconfig [interface] [ip address] [netmask] [gateway]"<<endl;
		cout << "exp:"<<endl<<"  "<<"ifconfig 本地连接 192.168.1.1 255.255.255.0 192.168.1.254";
		getchar();
		exit(0);
	}
	char temp[500];    //修改后的IP
	sprintf(temp, "/c netsh interface ip set address name=\"%s\" source=static addr=%s mask=%s gateway=%s", argv[1],argv[2],argv[3],argv[4]);
	HINSTANCE hresult = ShellExecuteA(NULL, "open", "cmd.exe", temp, NULL, SW_HIDE);    //启动cmd
	int nRes = (int)hresult;
	if (nRes>32)
		printf("设置成功");
	else
		printf("设置失败,error:%d", nRes);
	Sleep(1000);
	return 0;
}
