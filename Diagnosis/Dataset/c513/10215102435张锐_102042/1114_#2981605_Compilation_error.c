#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int a=0,b=0,c=0;
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
    return 0;
}
