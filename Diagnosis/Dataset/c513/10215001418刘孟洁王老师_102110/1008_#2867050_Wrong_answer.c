#include<stdio.h>
#include<stdlib.h>
#define N 101
int diff(int a,int b)
{
    int n=1,i=0,k,x,y;
    while(i<32)
    {
        x=a&n;y=b&n;
        if(x!=0&&y!=0||x==0&&y==0)i++;
        else k++,i++;
       a>>=1;b>>=1;
    }
return k;}
int main()
{
    int n,s[N][2],i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d%d",&s[i][0],&s[i][1]);
    for(i=0;i<n;i++)printf("%d\n",diff(s[i][0],s[i][1]));
    return 0;
}
