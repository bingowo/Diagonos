#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f(char s[],int a[])
{
        int len=strlen(s);
        for(int i=0;i<len;)
        {
            int sign=1,xishu=0,mi=0;
            if(s[i]=='+') i++;
            else if(s[i]=='-') sign=-1,i++;
            while(s[i]>='0'&&s[i]<='9') xishu=xishu*10+s[i]-'0',i++;
            if(xishu==0) xishu=1;
            if(s[i]!='x') {a[0]=xishu*sign;return;}
            else i++;
            if(s[i]=='^') i++;
            while(s[i]>='0'&&s[i]<='9') mi=mi*10+s[i]-'0',i++;
            if(mi==0) mi=1;
            a[mi]=sign*xishu;
        }
}


int main()
{
    char s1[101],s2[101];
    while(scanf("%s%s",s1,s2)==2)
    {
        int a1[50]={0},a2[50]={0},b[100]={0};
        f(s1,a1);
        f(s2,a2);
        for(int i=0;i<50;i++)
            for(int j=0;j<50;j++)
               b[i+j]+=a1[i]*a2[j];
        for(int i=99;i>=0;i--)
        {
            if(b[i])
            {
                printf("%d%c",b[i],i==0?'\n':' ');
            }
            if(i==0&&b[i]==0) printf("\n");
        }
    }
    return 0;
}
