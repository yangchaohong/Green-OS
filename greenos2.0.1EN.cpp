#include <bits/stdc++.h>
using namespace std;
int main()
{
st:
	cout<<"Welcome to Green OS 2.0 English Edition!\n";
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
			char c='$';
			if(username=="root")
				c='#';
			cout<<username<<' '<<c<<' ';
			string ty;
			cin>>ty;
			if(ty=="exit"||ty=="reboot")
			{
				system("cls");
				goto st;
			}
			if(ty=="cls")
				system("cls");
		}
	}
	system("pause");
	return 0;
}

