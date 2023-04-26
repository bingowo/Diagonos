#include<stdio.h>
int main()
{
    char s=getchar();
    int i=0,n,a[101],b[1001]={0};
    while(scanf("%d",&n)==1)
    {
        a[i]=n;
        b[n]=1;
        i++;
        
    }
    for(int ii=0;ii<1001;ii++)
    {
        pintf("%d",b[ii]);
    }
}