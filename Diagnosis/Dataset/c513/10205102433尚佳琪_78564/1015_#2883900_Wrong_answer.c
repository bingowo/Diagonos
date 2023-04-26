#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
void Readnumber(char s[],int a[])
{
    int n=25;
    int len=strlen(s);
    for(int i=len-1;i>=0;i--)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            if(s[i-1]<='9'&&s[i-1]>='0')
            {
                a[n--]=(s[i-1]-'0')*10+s[i]-'0';
                i--;
            }
            else a[n--]=s[i]-'0';
        }
    }
}
void ADD(int a[],int b[],int c[])
{
    int i,cnt=0;
    for(i=25;i>=0;i--)
    {
        c[i]=(a[i]+b[i]+cnt)%prime[i];
        cnt=(a[i]+b[i]+cnt)/prime[i];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[100];
        int a[26]={0},b[26]={0},c[26]={0};
        scanf("%s",s);
        Readnumber(s,a);
        scanf("%s",s);
        Readnumber(s,b);
        ADD(a,b,c);
        printf("case #%d:\n",i);
        int temp=0;
        while(c[temp]==0)
        {
            temp++;
            if(temp==25)
                break;
        }
        if(temp==25)
            printf("0");
        else
        {
            for(int i=temp;i<25;i++)
                printf("%d,",c[i]);
            printf("%d\n",c[25]);
        }
    }
    return 0;
}
