#include<stdio.h>
#include<stdlib.h>
#define N 101
int diff(int a,int b)
{
    unsigned n=1;int i,k,x,y;
    while(i<=32)
    {
        x=a&n;y=b&n;
        if(x!=0&&y!=0||x==0&&y==0)i++;
        else {i++;k++;}
        n<<=1;
    }
return k;}
int main()
{
    int n,s[N][2],i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d%d",&s[i][0],&s[i][1]);
    for(j=0;j<n;j++)printf("%d\n",diff(s[j][0],s[j][0]));
    return 0;
}