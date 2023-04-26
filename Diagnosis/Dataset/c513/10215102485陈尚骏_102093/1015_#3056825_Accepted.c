#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};

void read(char*a,int*b)
{
    int n=strlen(a),t=25,ans=0;
    for(int i=0;i<26;i++)
    {
        b[i]=0;
    }
    char s[3];
    for(int i=n-1;i>=0;)
    {
        for(int j=0;j<3;j++)
        {
            s[j]='0';
        }
        int k=2;
        while(a[i]!=','&&i>=0)
        {
            s[k--]=a[i--];
        }
        i--;
        ans=(s[1]-'0')*10+(s[2]-'0');
        b[t--]=ans;
    }
}

void add(int*a,int*b,int*c)
{
    int i=25,cry=0;
    for(int i=0;i<26;i++)
    {
        c[i]=0;
    }
    while(i>=0)
    {
        c[i]=(a[i]+b[i]+cry)%prime[i];
        cry=(a[i]+b[i]+cry)/prime[i];
        i--;
    }
    c[i]=cry;
}

void out(int*a)
{
    int i=0;
    while(!a[i])
    {
        i++;
        if(i==26)
        {
            printf("0\n");
            break;
        }
    }
    while(i<26)
    {
        printf("%d%c",a[i],i==25?'\n':',');
        i++;
    }
}

int main()
{
    int T,a[26]={0},b[26]={0},ans[26]={0};
    char s[100];
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%s",s);
        read(s,a);
        scanf("%s",s);
        read(s,b);
        add(a,b,ans);
        printf("case #%d:\n",i);
        out(ans);
    }
    return 0;
}
