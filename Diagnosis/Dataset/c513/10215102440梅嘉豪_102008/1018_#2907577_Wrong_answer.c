#include <stdio.h>
#include <string.h>
void read(char *s,int *a);
int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
int main()
{
    char s[200];
    int a[26]={0};
    scanf("%s",s);
    // printf("%s\n",s);
    read(s,a);
    // for(int i=0;i<26;i++)   printf("%d ",a[i]);
    unsigned long long weight=1,ans=0;
    for(int i=25;i>=0;i--)
    {
        ans=ans+a[i]*weight;
        weight=weight*prime[i];
    }
    printf("%llu",ans);
}
void read(char *s,int *a)
{
    char t[2]={'0'};
    int j=1,k=25;
    for(int i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]==',')   continue;
        else
        {
            t[j]=s[i];
            j--;
            if(s[i-1]==','||i==0)
            {
                // printf("%d %d\n",t[0],t[1]);
                a[k]=10*(t[0]-'0')+(t[1]-'0');
                k--;
                j=1;
                t[0]='0';t[1]='0';
            }
        }
    }
}
