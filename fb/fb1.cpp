#include<iostream>
using namespace std;
int CanPlaceKingInPosition(int pos[],int MaxIndex,int NewCol);
int solver(int pos[], int N, int K);

int main()
{
	int T,N,K;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N;
		cin>>K;
		int pos[K];
		for(int j=0;j<K;j++)
			cin>>pos[j];

			
	}
}

int CanPlaceKingInPosition(int pos[],int MaxIndex,int NewCol){
    for(int i=0;i<MaxIndex-1;i++)
        if(pos[i]==NewCol)
            return 0;
    //MaxIndex is the index of the above row of the new king, so we have to check attacking conditions

    if (abs(pos[MaxIndex-1]-NewCol)<=1)
       return 0;
    return 1;
}

int solver(int pos[], int N, int K){      
    int result=0;
    if (K>N) //termination condition
        return result;
    if (K==N-1) //last row
        return IsOnlyPossibleColAGoodOne(pos,N,N-1);
    for (int i=0;i<N;i++){ //for each column if we can place the king in it, move one step forward
        if (CanPlaceKingInPosion(pos,K,i)){
            pos[K]=i;  //add new king
            result+=solver(pos,N,K+1);  
        }
    }
    return result;
}s
