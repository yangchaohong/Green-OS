#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;
int main()
{
	cout<<"��������\n";
	system("ping www.microsoft.com");
	system("ping www.google.cn");
	system("ping www.csdn.net");
st:
	system("cls");
	cout<<"��ӭ����Green OS 2.1���İ棡\n";
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
					cout<<"���Ѿ���¼��"<<endl;
					login=1;
					logfl=1;
					break;
				}
			if(logfl==0)
				cout<<"û������û���"<<endl;
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
					cout<<"Green OS 1.0����Green Hat 1.0!\n";
				else if(r==1)
					cout<<"����ñ��\n";
				else if(r==2)
					system("cls");
				else
					cout<<"��ʽ��!\n";
			}
			if(ty=="about")
			{
				com=1;
				cout<<"AbuzzHarbor9999\n";
				Sleep(5000);
				cout<<"������2019/11/24\n";
				Sleep(5000);
				cout<<"�����˳��������档\n";
				Sleep(5000);
				cout<<"2019 ���\n";
				Sleep(5000);
				system("cls");
			}
			if(ty=="help")
			{
				com=1;
				cout<<"exit -�˳���\n";
				cout<<"reboot -������\n";
				cout<<"cls -������\n";
				cout<<"shutdown -�ػ���\n";
				cout<<"egg -�Ҳ�������㡣\n";
				cout<<"help -������\n";
				cout<<"about -�����������\n";
			}
			if(com==0)
				cout<<"û��������\n";
		}
	}
	system("pause");
	return 0;
}

