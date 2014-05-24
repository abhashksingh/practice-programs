#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

void stringtoIntArr(string str, vector<int> & vec);
string itoa(int a);
bool compareVectors(vector<int>& a,vector<int> &b); //if number represented by a is greater than number represented by b
bool compareVectorsEqual(vector<int>& a,vector<int> &b); //if number represented by a is equal to number represented by b
vector<int> addVectors(vector<int> &a ,vector<int> &b);
vector<int> subtractVectors(vector<int> &a ,vector<int> &b);// a-b always a>b

class Operand
{
	//private:
	//string strval;
	public :
	bool isNeg ;
	void printNumber()
	{
		//cout<<strval<<endl;
		if(isNeg){cout<<"-";}
		int i = arrayRep.size()-1;
		while(i>=0)
		{
			if(i!=arrayRep.size()-1)
			{
				if(arrayRep[i]>= 10 && arrayRep[i]<100)
				{
					cout<<0;
				}
				else if(arrayRep[i]> 0 && arrayRep[i]<10)
				{
					cout<<00;
				}
			}
			cout<<arrayRep[i];
			i--;
		}
		cout<<endl;
	}
	vector<int> arrayRep;//six digits in one element of array
	//public :
	Operand (vector<int> a)
	{
		string str="";
		for(int i=0;i<a.size();i++)
		{
			arrayRep.push_back(a[i]);
			str+=itoa(a[i]);
		}
	}

	Operand(string inp)
	{
		//strval = inp;
		if(inp[0]=='-')
		{
			isNeg=true;
		}
		else
		{
			isNeg=false;
		}
		stringtoIntArr(inp,arrayRep);
		//int arrlengthrequired = (length/6) +1;
		//arrayRep.reserve(arrlengthrequired);
		
	}

	Operand()
	{
		//strval = "";
	}

	Operand Add(Operand &a , Operand &b) //addition of two positive numbers
	{
		Operand t1;
		vector<int> s;
		int carry =0;
		int lengtha = a.arrayRep.size(),i=0;
		int lengthb = b.arrayRep.size(),j=0;
		while(i<lengtha && j<lengthb)
		{
			int sum = a.arrayRep[i]+b.arrayRep[j] + carry;
			cerr<<"sum of"<<a.arrayRep[i]<<" and "<<b.arrayRep[i] << "is "<<sum<<endl;
			carry = sum/1000;
			s.push_back(sum%1000);
			i++,j++;
		}
		if(j>=lengthb && i<lengtha)
		{
			while(i<lengtha)
			{
				int sum = a.arrayRep[i]+ carry;
				carry = sum/1000;
				s.push_back(sum%1000);
				i++;
			}
		}
		else if(j<lengthb && i>=lengtha)
		{
			while(j<lengthb)
			{
				int sum = b.arrayRep[j]+ carry;
				carry = sum/1000;
				s.push_back(sum%1000);
				j++;
			}
		}
		t1 = Operand(s);
		if(!a.isNeg && !b.isNeg)
		{
			t1.isNeg = false;
		}
		else if(a.isNeg && b.isNeg)
		{
			t1.isNeg = true;
		}
		return t1;
	}

	Operand Multiply(Operand &a , Operand &b)//multiplication of two positive numbers
	{
		vector<int> s;
		int carry =0,product=0;
		int lengtha = a.arrayRep.size(),i=0;
		int lengthb = b.arrayRep.size(),j=0;
		//multiplying a.arrayRep[0] with everything in b first
		carry=0;
		for(j=0;j<lengthb;j++)
		{
			product = a.arrayRep[i]*b.arrayRep[j] + carry;
			carry = product/1000;
			product = product%1000;
			s.push_back(product);
		}
		if(carry>0)
		{
			s.push_back(carry);
		}
		Operand t1(s);
		s.clear();
		for(i=1;i<lengtha;i++)
		{
			s.clear();
			carry=0;
			for(j=0;j<lengthb;j++)
			{
				product = a.arrayRep[i]*b.arrayRep[j]*pow(1000,i) + carry;
				carry = product/1000;
				product = product%1000;
				s.push_back(product);
			}
			if(carry>0)
			{
				s.push_back(carry);
			}
			Operand t2(s);
			t1 = t1.Add(t1,t2);
		}
		if(a.isNeg && b.isNeg)
		{t1.isNeg = false;}
		else if(!a.isNeg && !b.isNeg)
		{t1.isNeg = false;}
		else
		{t1.isNeg = true;}
		return t1;
	}

	Operand Subtract(Operand &a , Operand &b)
	{
		Operand t1;
		vector<int> s;
		if(CompareEqual(a,b))
		{
			s.push_back(0);
			t1 = Operand(s);
		}
		else if(Compare(a,b))
		{
			
		}
		else
		{
			
		}
		return t1;
	}
	
	bool CompareEqual(Operand &a , Operand &b) //if a==b
	{
		if(a.isNeg == b.isNeg)
		{
			return compareVectorsEqual(a.arrayRep , b.arrayRep);
		}
		else
		{
			return false;
		}
	}
	
	bool Comapare(Operand &a , Operand &b) // if a > b
	{
		if(a.isNeg && !b.isNeg) //a negative b positive
		{
			return false;
		}
		else if(!a.isNeg && b.isNeg ) // a positive b negative
		{
			return true;
		}
		else // both positive or both negative
		{
			
		}
	}
};

int main()
{
	int ch;
	string inp1,inp2;
	getline(cin,inp1);
	getline(cin,inp2);
	//quit
	//cin.ignore();
	Operand op1(inp1);
	Operand op2(inp2);
	Operand op3;
	op3 = op3.Add(op1,op2);
	//cout<<inp2<<endl;
	//cout<<op2.arrayRep[1]<<op2.arrayRep[0];
	cout<<op3.arrayRep[2]<<op3.arrayRep[1]<<op3.arrayRep[0]<<endl;
	op3.printNumber();
	getline(cin,inp1);
	getline(cin,inp2);
	/*cout<<inp1<<endl;
	cout<<inp2<<endl;*/
	op1 = Operand(inp1);
	op2 = Operand(inp2);
	//cout<<op1.arrayRep[0]<<endl;
	//cout<<op2.arrayRep[0]<<endl;
	op3 = op3.Multiply(op1,op2);
	op3.printNumber();
}

void stringtoIntArr(string inp, vector<int> & vec)
{
	if(inp[0]=='-')
	{
		inp = inp.substr(1,inp.length()-1);
	}
	int length = inp.size();
	
	if(length<=3)
	{
		vec.push_back(atoi(inp.c_str()));
	}
	else
	{
		int start = length - 3;
		while(start>=0)
		{
			vec.push_back(atoi(inp.substr(start,3).c_str()));
			start = start -3;
		}
		if(start < 0 && start> -3)//negative start mean in this range
		{
			start = start+3;
			vec.push_back(atoi(inp.substr(0,start).c_str()));
		}
	}
}

bool compareVectors(vector<int>& a,vector<int> &b) //if number represented by a is greater than number represented by b
{
	if(a.size() > b.size())
	{
		return true;
	}
	else if(a.size() < b.size())
	{
		return false;
	}
	else
	{
		
	}
}

bool compareVectorsEqual(vector<int>& a,vector<int> &b)//if number represented by a is equal to number represented by b
{
	if(a.size() != b.size())
	{
		return false;
	}
	else
	{
		for(int i=0;i < a.size();i++)
		{
			if(a[i]!=b[i]) return false;
		}
	}
	return true;
}

vector<int> addVectors(vector<int> &a ,vector<int> &b)
{
	
}

//this function seems useless now
string itoa(int a)
{
	string ret="";
	bool isNeg = false;
	if(a<0)
	{
		isNeg = true;
		a = (-a);
	}
	int t;
	while(a>0)
	{
		t = a%10;
		a = a/10;
		switch(t)
		{
			case 0:
				ret+='0';
				break;
			case 1:
				ret+='1';
				break;
			case 2:
				ret+='2';
				break;
			case 3:
				ret+='3';
				break;
			case 4:
				ret+='4';
				break;
			case 5:
				ret+='5';
				break;
			case 6:
				ret+='6';
				break;
			case 7:
				ret+='7';
				break;
			case 8:
				ret+='8';
				break;
			case 9:
				ret+='9';
				break;
		}
	}

	if(isNeg)
	{
		ret = "-"+ret;
	}
	return ret;
}
