#include<iostream>
#include<cstring>
#include<climits>
#define MAX 256
using namespace std;
//  function that takes as input the given string(str),
//  its length(n), set of characters(s), its size(m), 
//  reference to window's start index, reference to 
//  window's end index
void minlengthwindow(char input[], char chars[], int &start, int &finish)  
{  
int shouldfind[MAX] = {0,};  
int hasfound[MAX] = {0,};  
int cnt = 0;  
int minwindow = INT_MAX;  
  
int charlen = strlen(chars);  
for (int i=0; i< charlen; i++)  
shouldfind[chars[i]] += 1;  
  
int iplen = strlen(input);  
start = 0;  
finish = iplen;  
int j = 0;  
  
for (int i=0; i< iplen; i++)  
{  
if (!shouldfind[input[i]])  
 continue;  
hasfound[input[i]] += 1;  
  
if (shouldfind[input[i]] >= hasfound[input[i]])  
 cnt++;       
  
if (cnt == charlen)  
{  
 while (shouldfind[input[j]] == 0 || hasfound[input[j]] > shouldfind[input[j]])  
 {    
  if (hasfound[input[j]] > shouldfind[input[j]])  
           hasfound[input[j]]--;  
        j++;  
 }  
 if (minwindow > (i - j +1))  
 {  
  minwindow = i - j +1;  
  finish = i;  
  start = j;  
 }  
}  
}  
cout << start << "  " << finish << endl;  
}  
//  function to print the output
//  if match is not found, start and end is -1
void print(char *a,int x,int y){
    if(x==-1 && y==-1){
        cout<<"Match Not Found"<<endl;
        return;
    }
    cout<<"Start Index = "<<x<<endl;
    cout<<"End Index = "<<y<<endl;
    cout<<"Found Window = ";
    for(int i=x;i<=y;i++){
        cout<<a[i];
    }
}
//  main function to test the algorithm
int main(){
    char *str="coder";
    char *s="iamredoc";
    int n=strlen(str);
    int m=strlen(s);
    int start,finish;
    minlengthwindow(str,s,start,finish);
    //print(str,start,finish);
    return 0;
}

