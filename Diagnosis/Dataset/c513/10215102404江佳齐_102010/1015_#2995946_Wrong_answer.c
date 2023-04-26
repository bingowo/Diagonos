#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void Readnumber(char s[],int a[])
{
    int i,ct=0;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]==',') ct++;
    }
    ct++;
    for(i=0;s[i]!='\0';i++)
    {
        if(isdigit(s[i]))
        {
            a[26-ct]=a[26-ct]*10+s[i]-'0';
            if(s[i+1]==',') ct--;

        }
    }
}
void ADD(int a[],int b[],int c[])
{
    int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    int i,carry=0;
    for(i=25;i>=0;i--)
    {
        c[i]=(a[i]+b[i]+carry)%prime[i];
        carry=(a[i]+b[i]+carry)/prime[i];
    }
}
void output(int c[])
{
    int i=0;
    while(c[i]==0) i++;
    for(;i<25;i++)
        printf("%d,",c[i]);
    printf("%d\n",c[i]);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        char s[100];
        int a[26]={0},b[26]={0},c[26]={0};
        scanf("%s",s);
        Readnumber(s,a);
        scanf("%s",s);
        Readnumber(s,b);
        ADD(a,b,c);
        output(c);
    }
    return 0;
}
