#include<stdio.h>

long trans(char s[]);
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        char s[1000];
        scanf("%s",&s);
        printf("case #%d:\n%ld\n",i,trans(s));
    }
}

long trans(char s[])
{
    int a[1000],i=0,j=0;
    long ans=0;
    while(s[i]!='\0')
    {
        if (s[i]=='1')
            a[i]=1;
        else if (s[i]=='0')
            a[i]=0;
        else 
            a[i]=-1;
        i++;
    }
    while(j<i)
    {
        ans=ans*3+a[j];
        j++;
    }
    return ans;
}
