#include<stdio.h>
#include<string.h>
int trans(int x)
{

    int i=0;
    while(x)
    {
        x=x/2;
        i++;
    }
    return i;
}
int cnt(int x,int y)
{
    int cnt=0;
    int N=trans(x);
    int M=trans(y);
    if(M>N){
    	N=M;
	}
    for(int i=0; i<N; i++)
    {
        if(((x>>i)&1)!=((y>>i)&1))
        {
            cnt++;
        }

    }
    return cnt;
} 
int main()
    {
        int T;
        scanf("%d",&T);
		while(T){
			int a,b;
			scanf("%d %d",&a,&b);
			printf("%d\n",cnt(a,b));
			T--; 
		} 
        return 0;
    }