#include <stdio.h>
#include <stdlib.h>
int n,t;
int count;
void zou(int p,int m)
{
    if(m==0){if(p==t)count++;return;}
    if(p==1)zou(2,m-1);
    else if(p==n)zou(n-1,m-1);
    else{zou(p-1,m-1);zou(p+1,m-1);}

}
void jisuan()
{
    int p,m;
    count=0;
    scanf("%d %d %d %d",&n,&p,&m,&t);
     zou(p,m);
    printf("%d\n",count);
    return 0;
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan();
}
