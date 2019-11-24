#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;
int main()
{
	cout<<"正在启动\n";
	system("ping www.microsoft.com");
	system("ping www.google.cn");
	system("ping www.csdn.net");
st:
	system("cls");
	cout<<"欢迎来到Green OS 2.1中文版！\n";
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
					cout<<"你已经登录！"<<endl;
					login=1;
					logfl=1;
					break;
				}
			if(logfl==0)
				cout<<"没有这个用户！"<<endl;
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
				com=1;system("cls");}
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
					cout<<"Green OS 1.0叫做Green Hat 1.0!\n";
				else if(r==1)
					cout<<"大绿帽！\n";
				else if(r==2)
					system("cls");
				else
					cout<<"正式版!\n";
			}
			if(ty=="about")
			{
				com=1;
				cout<<"AbuzzHarbor9999\n";
				Sleep(5000);
				cout<<"编译于2019/11/24\n";
				Sleep(5000);
				cout<<"开发此程序纯属好玩。\n";
				Sleep(5000);
				cout<<"2019 杨巢鸿\n";
				Sleep(5000);
				system("cls");
			}
			if(ty=="help")
			{
				com=1;
				cout<<"exit -退出。\n";
				cout<<"reboot -重启。\n";
				cout<<"cls -清屏。\n";
				cout<<"shutdown -关机。\n";
				cout<<"egg -我不会告诉你。\n";
				cout<<"help -帮助。\n";
				cout<<"about -关于这个程序\n";
			}
			if(com==0)
				cout<<"没有这个命令！\n";
		}
	}
	system("pause");
	return 0;
}

