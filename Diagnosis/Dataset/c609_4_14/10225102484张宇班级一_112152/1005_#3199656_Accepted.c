#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   char a[100];
        scanf("%s",a);
    printf("case #%d:\n",i);
     int x=0;
    for(int i=0;a[i]!=0;i++)
    {
    if(a[i]=='-')
        x=x*3+(-1);
    else x=x*3+a[i]-'0';
    }
    printf("%d\n",x);
    }
    return 0;
}
