#include<stdio.h>
#include<stdlib.h>
#define N 101
int diff(int a,int b)
{
    int n=1,i=0,k=0,x,y;
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
    int n,i,j,s[N][2];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {scanf("%d%d",&s[i][0],&s[i][1]);printf("%d\n",diff(s[i][0],s[i][1]));}
    return 0;
}
