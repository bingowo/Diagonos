#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char table[]="01";
char dd[65]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
void reverse(char s[])
{
    for(int i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        char c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}
void cal(char s[],char ans[])
{
    char t[10];int k;
    for(int i=0;i<strlen(s);i++)
    {
        int a=(int)s[i];
        k=0;
        do
        {
            t[k]=table[a%2];a=a/2;k++;
        }while(a!=0);
        while(k<8)
        {
            t[k]='0';k++;
        }
        t[8]='\0';
        reverse(t);
        strcat(ans,t);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    char s[110];
    for(int cas=0;cas<T;cas++)
    {
        scanf("%s",s);
        printf("case #%d:\n",cas);
        char ans[1100]={};
        cal(s,ans);
        int len=strlen(ans);
        while(len%6!=0)
        {
            ans[len]='0';len++;
        }
        ans[len]='\0';
        int cnt=0;int mm=0;
        for(int i=0;i<len;i+=6)
        {
            cnt=0;
            for(int j=i;j<i+6;j++)
            {
                cnt=cnt*2+(ans[j]-'0');
            }
            printf("%c",dd[cnt]);mm++;
        }
        while(mm%4!=0)
        {
            mm++;printf("=");
        }
        printf("\n");
    }
    return 0;
}
