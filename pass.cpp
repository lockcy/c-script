#define _XOPEN_SOURCE
#include<unistd.h>
#include<iostream>
#include<fstream>
using namespace std;
int main(void)
{
	char* encryption;
	int temp=0;
	char* salt,*cryptpass;
	cout<<"please input the cryptpass from shadow file"<<endl;
	cin>>cryptpass;
	cout<<"please input the salt value!"<<endl;
	cin>>salt;
	ifstream infile;
	infile.open("dictionary.txt",ios::in);
	if(!infile)
	{
		cerr<<"open dictionary error!"<<endl;
		exit(1);
	}
	string pass;
	while(getline(infile,pass))
	{
		encryption=crypt(pass,salt);
		if(encryption==cryptpass)
		{
			cout<<"[+] succeed to find the password,password:"<<pass<<endl;
			temp=1;
			break;
		}
	}
	infile.close();
	if(temp=0)
	{
		cout<<"not found password!"<<endl;
	}
	
	
	return 0;
}
