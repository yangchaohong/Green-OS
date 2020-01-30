#include <bits/stdc++.h>
#include <Windows.h>
#include <conio.h>
using namespace std;
int main()
{
re:
	cout<<"Starting\n";
	system("ping www.microsoft.com");
	system("ping www.google.com");
	system("ping www.csdn.net");
st:
	ifstream userin("users.inf");
	system("cls");
	cout<<"Welcome to Green OS 3.0.1 English Edition!\n";
	cout<<"Warning: BETA version!\n";
	bool login=0;
	string user[100],username;
	int usernum=0;
	while(userin>>user[usernum++]);
	while(1)
	{
		if(login==0)
		{
			bool logfl=0;
			cout<<"login:";
			cin>>username;
			getchar();
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
			const string usf=username+"data";
			bool com=0;
			char c='$';
			if(username=="root")
				c='#';
			cout<<username<<' '<<c<<' ';
			string ty;
			getline(cin,ty);
			if(ty=="reboot")
			{
				com=1;
				goto re;
			}
			else if(ty=="exit"||ty=="reboot")
			{
				com=1;
				system("cls");
				goto st;
			}
			else if(ty=="cls")
			{
				com=1;
				system("cls");
			}
			else if(ty=="shutdown")
			{
				com=1;
				return 0;
			}
			else if(ty=="egg")
			{
				com=1;
				int r;
				srand(time(NULL));
				r=rand()%5;
				if(r==0)
					cout<<"Green OS 1.0 named Green Hat 1.0!\n";
				else if(r==1)
					cout<<"Big green hat!\n";
				else if(r==2)
					system("cls");
				else if(r==3)
					cout<<"BETA!!!\n";
				else
				{
					cout<<"Error: Big crash!\nYou need to reboot!\n";
					cout<<"Press anykey to reboot\n";
					getch();
					cout<<"HaHaHa!!!\n";
					Sleep(10000);
					system("cls");
				}
			}
			else if(ty=="about")
			{
				com=1;
				cout<<"AbuzzHarbor9999\n";
				Sleep(5000);
				cout<<"Build 2019/11/24\n";
				Sleep(5000);
				cout<<"Developing this program is purely fun.\n";
				Sleep(5000);
				cout<<"2019 Yang Chaohong\n";
				Sleep(5000);
				system("cls");
			}
			else if(ty.find("user")!=string::npos)
			{
				if(ty.find("-v")!=string::npos)
				{
					freopen(usf.c_str(),"r",stdin);
					char t;
					while(t=getch())
						cout<<t;
					fclose(stdin);
				}
			}
			else if(ty=="help")
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
				cout<<"No such order!\n";
		}
	}
	system("pause");
	return 0;
}

