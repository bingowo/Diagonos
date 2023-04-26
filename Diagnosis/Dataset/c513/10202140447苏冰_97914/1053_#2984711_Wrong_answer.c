#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
    char s[200];
    char t[30];
    char ans[30];
    while(1)
    {
        gets(s);
        if(strcmp(s,"END")==0)
        {
            printf("%s",ans);
            break;
        }
        int k=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]==',') break;
            t[k++]=s[i];
        }
        t[k++]='\0';
        if(strcmp(t,"$GPRMC")==0)
        {
            int cnt=0;int flag=0;
            for(int i=0;i<strlen(s);i++)
            {
                if(s[i]==',') cnt++;
                if(cnt==2)
                {
                    if(s[i+1]=='A') flag=1;
                    else flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                int xx=s[1]^s[2];
                for(int i=3;s[i]!='*';i++)
                {
                    xx=xx^s[i];
                }
                xx=xx%65536;
                char ch1=s[strlen(s)-1];
                char ch2=s[strlen(s)-2];
                int x=0;
                if(isdigit(ch1)) x+=ch1-'0';
                else x+=ch1-'A'+10;
                if(isdigit(ch2)) x+=16*(ch2-'0');
                else x+=16*(ch2-'A'+10);
                if(xx==x)
                {
                    int t1=(s[7]-'0')*10+(s[8]-'0')+8;
                    int t2=(s[9]-'0')*10+(s[10]-'0');
                    int t3=(s[11]-'0')*10+(s[12]-'0');
                    ans[0]=t1/10+'0';
                    ans[1]=t1%10+'0';
                    ans[2]=':';
                    ans[3]=t2/10+'0';
                    ans[4]=t2%10+'0';
                    ans[5]=':';
                    ans[6]=t3/10+'0';
                    ans[7]=t3%10+'0';
                    ans[8]='\0';
                }
            }
        }
    }
    return 0;
}

