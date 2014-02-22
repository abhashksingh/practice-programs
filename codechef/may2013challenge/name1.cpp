#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream> 
#include <cstring>

using namespace std;

bool isChild(string parent,string children);
void change(int **a,char b);

int main()
{
	int t,i=0;
	cin>>t;
	char a;
	scanf("%c",&a);
	string parent,children="",str;
	for(int j=0;j<t;j++)
	{
		children="";
		getline(cin,parent);
		int numChild;
		cin>>numChild;
		scanf("%c",&a);
		for(i=0;i<numChild;i++)
		{
			getline(cin,str);
			//scanf("%c",&a);
			children.append(str);
		}
		if(isChild(parent,children))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
		//cout<<parent<<"     "<<children<<endl;
	}
return 0;
}

bool isChild(string parent,string children)
{
	bool ret=true;
	int i=0;
	int* pArr = new int[27];
	int* cArr = new int[27];
	for(i=0;i<27;i++)
	{
		pArr[i]=0;
		cArr[i]=0;
	}
	for(i=0;i<parent.length();i++)
	{
		change(&pArr,parent[i]);
	}
	for(i=0;i<children.length();i++)
	{
		change(&cArr,children[i]);
	}
	for(i=0;i<27;i++)
	{
		if(cArr[i]>pArr[i])
		{
			ret=false;
			break;
		}
	}
return ret;
}

void change(int **a,char b)
{
	int *arr=*a;
	switch(b)
	{
		case 'a':
			arr[0]++;
			break;
		case 'b':
			arr[1]++;
			break;
		case 'c':
			arr[2]++;
			break;
		case 'd':
			arr[3]++;
			break;
		case 'e':
			arr[4]++;
			break;
		case 'f':
			arr[5]++;
			break;
		case 'g':
			arr[6]++;
			break;
		case 'h':
			arr[7]++;
			break;
		case 'i':
			arr[8]++;
			break;
		case 'j':
			arr[9]++;
			break;
		case 'k':
			arr[10]++;
			break;
		case 'l':
			arr[11]++;
			break;
		case 'm':
			arr[12]++;
			break;
		case 'n':
			arr[13]++;
			break;
		case 'o':
			arr[14]++;
			break;
		case 'p':
			arr[15]++;
			break;
		case 'q':
			arr[16]++;
			break;
		case 'r':
			arr[17]++;
			break;
		case 's':
			arr[18]++;
			break;
		case 't':
			arr[19]++;
			break;
		case 'u':
			arr[20]++;
			break;
		case 'v':
			arr[21]++;
			break;
		case 'w':
			arr[22]++;
			break;
		case 'x':
			arr[23]++;
			break;
		case 'y':
			arr[24]++;
			break;
		case 'z':
			arr[25]++;
			break;
		default:
			arr[26]++;
			break;
	}
}

