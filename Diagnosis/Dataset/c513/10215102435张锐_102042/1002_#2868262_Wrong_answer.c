#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int power(int base,int n)
{
    int i,p;
    p=1;
    for(i=1;i<=n;i++)
        p=p*base;
    return p;
}
void read(int i)
{
    char s[61];
    scanf("%s",&s);
    int len=strlen(s);
    int temp[61]={0};
    temp[0]=1;
    int num=1;
    for(int i=1;i<strlen(s);i++)
    {
        for(int j=0;j<i;j++)
        {
            if(s[i]==s[j])
            {
                temp[i]=temp[j];
                break;
            }
            else if(j==i-1&&num==1)
            {
                temp[i]=0;
                num=2;
            }
            else if(j==i-1&&num!=1)
            {
                temp[i]=num;
                num++;
            }
        }
    }
    if(num==1) num=2;
    long long int min=0;
    for(int i=0;i<len;i++)
    {
        min+=temp[i]*power(num,len-i-1);
    }
    printf("case #%d:\n%lld\n",i,min);
}
int main()
{
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        read(i);
    }
    return 0;
}

