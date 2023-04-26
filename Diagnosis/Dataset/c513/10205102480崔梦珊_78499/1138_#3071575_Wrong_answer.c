#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int alpha[200];
    for(int i=0;i<200;i++)
    {
        if(i>='A'&&i<='F')
        {
            alpha[i]=i-'A'+10;
        }
        if(i>='0'&&i<='9')
        {
            alpha[i]=i-'0';
        }
    }
    char s[33];
    int a,b;
    char ans[33]={0};
    scanf("%d %s %d",&a,s,&b);
    int q[33];
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='a'&&s[i]<='f')
        {
            s[i]=s[i]-'a'+'A';
        }
    }
    int temp0=0;
    for(int i=0;i<strlen(s);i++)
    {
        temp0=temp0*a+alpha[s[i]];
    }
    int temp=temp0;
    int cnt=0;
    while(temp/b!=0)
    {
        int tempp=temp%b;
        if(tempp<='9') ans[cnt]=tempp+'0';
        else ans[cnt]=tempp-10+'A';
        temp=temp/b;
        cnt++;
    }
    int tempp=temp&b;
    if(tempp<='9') ans[cnt]=tempp+'0';
    else ans[cnt]=tempp-10+'A';
    for(int i=strlen(ans)-1;i>=0;i--)
    {
        printf("%c",ans[i]);
    }

}
