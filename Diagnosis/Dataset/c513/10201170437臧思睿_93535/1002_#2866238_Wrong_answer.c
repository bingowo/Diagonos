#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long int ll;
char std[65]="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int stdi[65];

int R(char *s,int len)//计算输入的是几进制数 顺便标记每个符号对应的数值
{
    int i,j,r=0;
    for(i=0;i<65;i++)
    {
        stdi[i]=-1;
    }
    for(i=0;i<len;i++)
    {
        for(j=0;j<65;j++)
        {
            if(*(s+i)==std[j]&&stdi[j]==-1)
            {
                stdi[j]=r;
                r++;
            }
        }
    }
    return(r);
}
int main()
{
    int i,j,t=0,T;
    scanf("%d\n",&T);
    while(t++<T)
    {
        char s[100];
        scanf("%s",s);
        s[strlen(s)]='\0';
        int num=R(s,strlen(s));
        for(i=0;i<65;i++)
        {
            if(stdi[i]==0){stdi[i]=1;}
            else if(stdi[i]==1){stdi[i]=0;}
        }
        ll sum=0;
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]<='9'&&s[i]>='0')
                {sum+=stdi[s[i]-'0']*pow(num,strlen(s)-i-1);}
            if(s[i]<='z'&&s[i]>='a')
                {sum+=stdi[s[i]-'a'+10]*pow(num,strlen(s)-i-1);}
            if(s[i]<='Z'&&s[i]>='A')
                {sum+=stdi[s[i]-'A'+36]*pow(num,strlen(s)-i-1);}
        }
        if(num==1)
        {
            sum=0;
            for(i=0;i<strlen(s);i++)
            {
                sum+=pow(2,strlen(s)-i-1);
            }
        }
        printf("case #%d:\n%lld\n",t-1,sum);
    }
}
