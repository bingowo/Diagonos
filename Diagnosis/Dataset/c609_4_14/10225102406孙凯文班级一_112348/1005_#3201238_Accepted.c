#include<stdio.h>
int main()
{
    int t,i,sum=0,j,w=1;
    char a[50];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%s",a);
        for(j=0;a[j]!='\0';j++);
        j--;
        for(;j>-1;j--)
        {
            if(a[j]=='-') sum=sum-w;
            if(a[j]=='1') sum=sum+w;
            w=w*3;
        }
        printf("case #%d:\n%d\n",i,sum);
    sum=0;
    w=1;
    }
    return 0;
}