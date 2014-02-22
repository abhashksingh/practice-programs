#include <iostream>
#include <map>
using namespace std;

map <char,int> mymap;
void populateMapping();

int main()
{
	populateMapping();
	string a,b;
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		int aCount[62]={0},bCount[62]={0},ret=0;
		getline(cin,a);
		getline(cin,b);
		for(int i=0;i<a.length();i++)
		{
			aCount[mymap[a[i]]]++;
		}
		for(int i=0;i<b.length();i++)
		{
			bCount[mymap[b[i]]]++;
		}
		for(int i=0;i<62;i++)
		{
			ret+=min(aCount[i],bCount[i]);
		}
		cout<<ret<<endl;
	}
}


void populateMapping()
{
	mymap['a'] = 0;
	mymap['b'] = 1;
	mymap['c'] = 2;
	mymap['d'] = 3;
	mymap['e'] = 4;
	mymap['f'] = 5;
	mymap['g'] = 6;
	mymap['h'] = 7;
	mymap['i'] = 8;
	mymap['j'] = 9;
	mymap['k'] = 10;
	mymap['l'] = 11;
	mymap['m'] = 12;
	mymap['n'] = 13;
	mymap['o'] = 14;
	mymap['p'] = 15;
	mymap['q'] = 16;
	mymap['r'] = 17;
	mymap['s'] = 18;
	mymap['t'] = 19;
	mymap['u'] = 20;
	mymap['v'] = 21;
	mymap['w'] = 22;
	mymap['x'] = 23;
	mymap['y'] = 24;
	mymap['z'] = 25;
	mymap['A'] = 26;
	mymap['B'] = 27;
	mymap['C'] = 28;
	mymap['D'] = 29;
	mymap['E'] = 30;
	mymap['F'] = 31;
	mymap['G'] = 32;
	mymap['H'] = 33;
	mymap['I'] = 34;
	mymap['J'] = 35;
	mymap['K'] = 36;
	mymap['L'] = 37;
	mymap['M'] = 38;
	mymap['N'] = 39;
	mymap['O'] = 40;
	mymap['P'] = 41;
	mymap['Q'] = 42;
	mymap['R'] = 43;
	mymap['S'] = 44;
	mymap['T'] = 45;
	mymap['U'] = 46;
	mymap['V'] = 47;
	mymap['W'] = 48;
	mymap['X'] = 49;
	mymap['Y'] = 50;
	mymap['Z'] = 51;
	mymap['0'] = 52;
	mymap['1'] = 53;
	mymap['2'] = 54;
	mymap['3'] = 55;
	mymap['4'] = 56;
	mymap['5'] = 57;
	mymap['6'] = 58;
	mymap['7'] = 59;
	mymap['8'] = 60;
	mymap['9'] = 61;
}
