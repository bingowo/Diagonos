#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF)
    {
        int len=strlen(s);
        int ans[41][41]={0};
        int a=0,b=0,c=0,d=0;int p=0;
        for(int i=4;i<len;i++)
        {
            if(s[i]=='x')
            {
                int j;int t=1;
                for(j=i-1;;j--) if(!isdigit(s[j])) break;
                if(s[j]=='-') t=-1;
                int temp=0;int bo=1;
                if(j==i-1&&s[i-1]!='-') temp=1,bo=0;
                if(j==i-1&&s[i-1]=='-') temp=-1,bo=0;
                else
                {
                    j++;
                    while(isdigit(s[j])) temp=temp*10+(s[j++]-'0');
                }
                if(s[i+1]=='^')
                {
                    if(s[i+2]=='3'&&bo==1) a=temp*t;
                    if(s[i+2]=='3'&&bo==0) a=temp;
                    if(s[i+2]=='2'&&bo==1) b=temp*t;
                    if(s[i+2]=='2'&&bo==0) b=temp;
                }
                else c=temp*t;
            }
            if(i==len-1&&isdigit(s[i])&&s[i-1]!='^')
            {
                int j;int t=1;
                for(j=i-1;;j--) if(!isdigit(s[j])) break;
                if(s[j]=='-') t=-1;
                int temp=0;
                {
                    j++;
                    while(isdigit(s[j])) temp=temp*10+(s[j++]-'0');
                }
                d=temp*t;
            }
        }
        for(int x=-20;x<=20;x++)
        {
            int f=a*x*x*x+b*x*x+c*x+d;
            if(f<=20&&f>=-20) ans[20-f][x+20]=1;
        }
        for(int y=0;y<41;y++)
        {
            for(int x=0;x<41;x++)
            {
                if(ans[y][x]==1) printf("*");
                else if(y==0&&x==20) printf("^");
                else if(y==20&&x==40) printf(">");
                else if(y==20&&x==20) printf("+");
                else if(x==20) printf("|");
                else if(y==20) printf("-");
                else printf(".");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
