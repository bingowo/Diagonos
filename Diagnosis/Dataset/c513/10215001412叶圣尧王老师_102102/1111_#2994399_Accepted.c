#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char s[20];getchar();getchar();getchar();getchar();getchar();
    while(scanf("%s",s)!=EOF)
    {
        char y[42][42]={'\0'};int i,j;
        int a[4]={0};
        for(i=0;i<strlen(s);i++)
        {
            int k;
            if(s[i]=='-')
            {
                k=0;
                for(j=i+1;j<strlen(s)&&isdigit(s[j]);j++)
                    k=k*10+s[j]-'0';
                if(k==0)k=1;
                if(j==strlen(s)){a[0]=k*-1;break;}
                else if(s[j+1]!='^'){a[1]=k*-1;i=j;}
                else {a[s[j+2]-'0']=k*-1;i=j+2;}
            }
            else if(s[i]!='x')
            {
                k=0;
                if(isdigit(s[i]))j=i;
                else j=i+1;
                for(;j<strlen(s)&&isdigit(s[j]);j++)
                    k=k*10+s[j]-'0';
                if(k==0)k=1;
                if(j==strlen(s)&&isdigit(s[j-1])){if(s[0]=='0')a[0]=0;else a[0]=k;break;}
                else if(j==strlen(s)&&!isdigit(s[j-1])){a[1]=k;break;}
                else if(s[j+1]!='^'){a[1]=k;i=j;}
                else {a[s[j+2]-'0']=k;i=j+2;}
            }
            else
            {
                if(s[i+1]!='^')a[1]=1;
                else {a[s[i+2]-'0']=1;i+=2;}
            }
        }
        for(i=0;i<41;i++)
        {
            for(j=0;j<41;j++)
            {
                if(i==0&&j==20)y[i][j]='^';
                else if(i==20&&j==40)y[i][j]='>';
                else if(i==20&&j!=20)y[i][j]='-';
                else if(i==20&&j==20)y[i][j]='+';
                else if(j==20)y[i][j]='|';
                else y[i][j]='.';
            }
        }
        for(i=-20;i<=20;i++)
        {
            int t=a[0]+a[1]*i+a[2]*i*i+a[3]*i*i*i;
            if(t>=-20&&t<=20)y[20-t][i+20]='*';
        }
        for(i=0;i<41;i++)printf("%s\n",y[i]);putchar('\n');
        getchar();getchar();getchar();getchar();getchar();getchar();
    }
}
