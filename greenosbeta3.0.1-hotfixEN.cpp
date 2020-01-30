#include <bits/stdc++.h>
#include <Windows.h>
#include <conio.h>
using namespace std;
string read(const char *path)
{
	string a;
	char szTest[1000];
	FILE *fp;
	if((fp=fopen(path,"r"))==NULL)
		cout<<"File Error!\n";
	while(!feof(fp))  
    {  
        memset(szTest, 0, sizeof(szTest));  
        fgets(szTest, sizeof(szTest) - 1, fp); // 包含了\n  
        a+=szTest;
        a+="\\n";
    }
	fclose(fp);
	return a;
}
/*void fwi(int p, char *path) {
	FILE *fp;
	if ((fp = fopen(path, "wb")) == NULL) {
		cout << "File Error!" << endl;
		exit(0);
	}

	if (fwrite(p, sizeof(int), 1, fp) != 1) {
		cout << "Write Error." << endl;
	}
	fclose(fp);
}*/
//感谢CSDN博主「shansusu」https://blog.csdn.net/shansusu/article/details/44780873
int main()
{
re:
	system("cls");
	cout<<"Starting\n";
	bool login=0;
	string user[100],username;
	int usernum=0;
	string usf;
	string userd;
	size_t fp;
//	system("ping www.microsoft.com");
//	system("ping www.google.com");
//	system("ping www.csdn.net");
st:
	ifstream userin("users.inf");
	system("cls");
	cout<<"Welcome to Green OS 3.0.1 English Edition!\n";
	cout<<"Warning: BETA version!\n";
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
			else
			{
				usf=username+".dat";
			}
		}
		else
		{
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
					system("cls");
					cout<<"Error: Big crash!\nYou need to reboot!\n";
					cout<<"Press anykey to reboot.\n";
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
				cout<<"Build 2019/11/27\n";
				Sleep(5000);
				cout<<"Developing this program is purely fun.\n";
				Sleep(5000);
				cout<<"2019 Yang Chaohong\n";
				Sleep(5000);
				cout<<"Follow the GPL agreement.\n";
				Sleep(5000);
				system("cls");
			}
			else if(ty.find("user ")!=string::npos)
			{
				com=1;
				if(ty.find(" -v")!=string::npos||ty.find(" /v")!=string::npos)
				{
					const char *path=usf.c_str();
					cout<<read(path)<<endl;
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
				cout<<"user -About the user.";
			}
			if(com==0)
				cout<<"No such command!\n";
		}
	}
	system("pause");
	return 0;
}

