#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int check(int a[],int len)
{   int tot=0;
    for(int i=0;i<len;i++)
        tot+=a[i];
    if(tot%9==0)
        return 0;
    else
        return 1;

}
void slo(int a[],int len)
{
    while(1)
    {
         a[0]++;
        int loc=0;
        while(a[loc]>=10&&loc<len)
        {
            a[loc]-=10;a[loc+1]++;loc++;
            if(loc==len)
                len++;
        }
        for(int i=0;i<len;i++)
        {
            if(a[i]==9)
            {
                a[i+1]++;
                for(int j=i;j>=0;j--)
                    a[j]=0;
                if(i==len-1)
                    len++;
                while(a[i]>=10)
                {
                    a[i+1]++;
                    a[i]-=10;
                    i++;
                    if(i==len)
                        len++;
                }
            }
        }
        if (check(a,len))
        {
            for (int i=len-1;i>=0;i--)
                printf("%d",a[i]);
            break;
        }
    }
    return;

}
int main()
{
    char s[101];int len,id=0,a[105]={0};
    scanf("%s",s);len=strlen(s);
    for(int i=strlen(s)-1;i>=0;i--)
        a[id++]=s[i]-'0';
    if(len==1)
    {
        if(a[0]<=7)
            printf("%d",a[0]+1);
        else
        printf("10");
    }
    else
    {
        slo(a,len);
    }
}
