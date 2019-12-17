#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;
void getSystemName()
{
	std::string vname;
	//���ж��Ƿ�Ϊwin8.1��win10
	typedef void(__stdcall*NTPROC)(DWORD*, DWORD*, DWORD*);
	HINSTANCE hinst = LoadLibrary("ntdll.dll");
	DWORD dwMajor, dwMinor, dwBuildNumber;
	NTPROC proc = (NTPROC)GetProcAddress(hinst, "RtlGetNtVersionNumbers"); 
	proc(&dwMajor, &dwMinor, &dwBuildNumber); 
	if (dwMajor == 6 && dwMinor == 3)	//win 8.1
	{
		vname = "Microsoft Windows 8.1";
		return;
	}
	if (dwMajor == 10 && dwMinor == 0)	//win 10
	{
		vname = "Microsoft Windows 10";
		return;
	}
	//�����жϲ���Win Server����Ϊ���˻�δ������ϵͳ�Ļ��ӣ���ʱ������
 
 
 
	//�ж�win8.1���µİ汾
	SYSTEM_INFO info;                //��SYSTEM_INFO�ṹ�ж�64λAMD������  
	GetSystemInfo(&info);            //����GetSystemInfo�������ṹ  
	OSVERSIONINFOEX os;
	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	#pragma warning(disable:4996)
	if (GetVersionEx((OSVERSIONINFO *)&os))
	{
 
		//������ݰ汾��Ϣ�жϲ���ϵͳ����  
		switch (os.dwMajorVersion)
		{                        //�ж����汾��  
		case 4:
			switch (os.dwMinorVersion)
			{                //�жϴΰ汾��  
			case 0:
				if (os.dwPlatformId == VER_PLATFORM_WIN32_NT)
					vname ="Microsoft Windows NT 4.0";  //1996��7�·���  
				else if (os.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
					vname = "Microsoft Windows 95";
				break;
			case 10:
				vname ="Microsoft Windows 98";
				break;
			case 90:
				vname = "Microsoft Windows Me";
				break;
			}
			break;
		case 5:
			switch (os.dwMinorVersion)
			{               //�ٱȽ�dwMinorVersion��ֵ  
			case 0:
				vname = "Microsoft Windows 2000";    //1999��12�·���  
				break;
			case 1:
				vname = "Microsoft Windows XP";      //2001��8�·���  
				break;
			case 2:
				if (os.wProductType == VER_NT_WORKSTATION &&
					info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
					vname = "Microsoft Windows XP Professional x64 Edition";
				else if (GetSystemMetrics(SM_SERVERR2) == 0)
					vname = "Microsoft Windows Server 2003";   //2003��3�·���  
				else if (GetSystemMetrics(SM_SERVERR2) != 0)
					vname = "Microsoft Windows Server 2003 R2";
				break;
			}
			break;
		case 6:
			switch (os.dwMinorVersion)
			{
			case 0:
				if (os.wProductType == VER_NT_WORKSTATION)
					vname = "Microsoft Windows Vista";
				else
					vname = "Microsoft Windows Server 2008";   //�������汾  
				break;
			case 1:
				if (os.wProductType == VER_NT_WORKSTATION)
					vname = "Microsoft Windows 7";
				else
					vname = "Microsoft Windows Server 2008 R2";
				break;
			case 2:
				if (os.wProductType == VER_NT_WORKSTATION)
					vname = "Microsoft Windows 8";
				else
					vname = "Microsoft Windows Server 2012";
				break;
			}
			break;
		default:
			vname = "δ֪����ϵͳ";
		}
		if(vname!="Microsoft Windows 10"&&vname!="Microsoft Windows 8.1")
			cout<<"You better upgrade your operating system for a better experience.\n";
	}
}
//CSDN������IT1995��https://blog.csdn.net/qq78442761/article/details/64440535
/*******************************************************************************
 * ȫ������̨����
 * ȡ�����������߿�
 ******************************************************************************/
void full_screen()
{   
    HWND hwnd = GetForegroundWindow();
    int cx = GetSystemMetrics(SM_CXSCREEN);            /* ��Ļ��� ���� */
    int cy = GetSystemMetrics(SM_CYSCREEN);            /* ��Ļ�߶� ���� */

    LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE);   /* ��ȡ������Ϣ */
    /* ���ô�����Ϣ ��� ȡ�����������߿� */
    SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);

    SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}
//��лCSDN������linuxwuj�� https://blog.csdn.net/linuxwuj/article/details/81165885
int main()
{
	getSystemName();
	full_screen(); 
	cout<<"Starting\n";
//	system("ping www.microsoft.com");
//	system("ping www.google.com");
//	system("ping www.csdn.net");
st:
//	system("cls");
	cout<<"Welcome to Green OS 2.2.2 English Edition!\n";
	bool login=0;
	string user[100]= {"root","user"},username;
	int usernum=2;
	while(1)
	{
		if(login==0)
		{
			bool logfl=0;
			cout<<"login:";
			cin>>username;
			for(int i=0; i<usernum; i++)
				if(user[i]==username)
				{
					system("cls");
					cout<<"You've already logged!"<<endl;
					login=1;
					logfl=1;
					break;
				}
			if(logfl==0)
				cout<<"No such user!"<<endl;
		}
		else
		{
			bool com=0;
			char c='$';
			if(username=="root")
				c='#';
			cout<<username<<' '<<c<<' ';
			string ty;
			cin>>ty;
			if(ty=="exit"||ty=="reboot")
			{
				com=1;
				system("cls");
				goto st;
			}
			if(ty=="cls")
			{
				com=1;
				system("cls");
			}
			if(ty=="shutdown")
			{
				com=1;
				return 0;
			}
			if(ty=="egg")
			{
				com=1;
				int r;
				srand(time(NULL));
				r=rand()%4;
				if(r==0)
					cout<<"Green OS 1.0 named Green Hat 1.0!\n";
				else if(r==1)
					cout<<"Big green hat!\n";
				else if(r==2)
					system("cls");
				else
					cout<<"Formal edition!!!\n";
			}
			if(ty=="about")
			{
				com=1;
				cout<<"AbuzzHarbor9999\n";
				Sleep(5000);
				cout<<"Build 2019/12/17\n";
				Sleep(5000);
				cout<<"Developing this program is purely fun.\n";
				Sleep(5000);
				cout<<"2019 Yang Chaohong\n";
				Sleep(5000);
				cout<<"Follow the GPL Protocol.\n";
				Sleep(5000);
				cout<<"Christmas is coming!";
				system("cls");
			}
			if(ty=="help")
			{
				com=1;
				cout<<"exit -Drop out.\n";
				cout<<"reboot -Reboot.\n";
				cout<<"cls -Clear screen.\n";
				cout<<"shutdown -Shutdown.\n";
				cout<<"egg -I will not tell you.\n";
				cout<<"help -Help\n";
				cout<<"about -About this program.\n";
			}
			if(com==0)
				cout<<"No such cammand!\n";
		}
	}
	system("pause");
	return 0;
}

