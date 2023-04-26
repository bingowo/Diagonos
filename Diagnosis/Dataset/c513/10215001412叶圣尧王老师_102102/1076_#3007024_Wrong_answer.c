#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int T,i;scanf("%d",&T);char s[101];
    for(int t=0;t<T;t++)
    {
        scanf("%s",s);int d[3]={0};
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]=='{')
            {
                if(i==0){d[2]++;continue;}
                if(s[i-1]=='{')break;
                else if(s[i-1]=='[')break;
                else if(s[i-1]==']'&&(d[0]!=0||d[1]!=0||d[2]!=0))break;
                else if(s[i-1]==')'&&(d[0]!=0||d[1]!=0||d[2]!=0))break;
                d[2]++;
            }
            else if(s[i]=='[')
            {
                if(i==0){d[1]++;continue;}
                if(s[i-1]=='[')break;
                else if(s[i-1]=='(')break;
                else if(s[i-1]=='}'&&(d[0]!=0||d[1]!=0||d[2]!=0))break;
                else if(s[i-1]==')'&&(d[0]!=0||d[1]!=0||d[2]!=0))break;
                d[1]++;
            }
            else if(s[i]=='(')
            {
                if(i==0){d[0]++;continue;}
                if(s[i-1]=='{')break;
                else if(s[i-1]=='(')break;
                else if(s[i-1]==']'&&(d[0]!=0||d[1]!=0||d[2]!=0))break;
                else if(s[i-1]=='}'&&(d[0]!=0||d[1]!=0||d[2]!=0))break;
                d[0]++;
            }
            else if(s[i]=='}')
            {
                d[2]--;
                if(i==0)continue;
                if(s[i-1]==')')break;
                else if(s[i-1]=='}')break;
                else if(s[i-1]=='[')break;
                else if(s[i-1]=='(')break;
            }
            else if(s[i]==']')
            {
                d[1]--;
                if(i==0)continue;
                if(s[i-1]==']')break;
                else if(s[i-1]=='}')break;
                else if(s[i-1]=='(')break;
                else if(s[i-1]=='{')break;
            }
            else
            {
                d[0]--;
                if(i==0)continue;
                if(s[i-1]==')')break;
                else if(s[i-1]==']')break;
                else if(s[i-1]=='[')break;
                else if(s[i-1]=='{')break;
            }

        }
        if(i>=strlen(s)&&d[0]==0&&d[1]==0&d[2]==0)printf("Yes\n");
        else printf("No\n");
    }
}