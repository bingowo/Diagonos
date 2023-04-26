#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char s[30];
    while(scanf("%s",s)!=EOF)
    {
        char a[42][42];
    for(int i=0;i<41;i++)
    {for(int j=0;j<41;j++)
        a[i][j]='.';
        a[i][41]='\0';}
    for(int i=0;i<41;i++)
    {
        a[i][20]='|';
        a[20][i]='-';
    }
    a[0][20]='^';
    a[20][40]='>';

        int l=5,c3=0,c2=0,c1=0,c0=0,flag=1,c=0;
        while(s[l]!='\0')
        {
            if(s[l]=='-') {flag=-1;}
            else if(s[l]=='+') {flag=1;}
            else if(s[l]>='0'&&s[l]<='9')
            {c=c*10+s[l]-48;
             if(s[l+1]=='\0') {c0=c*flag;c=0;}
             }
            else if(s[l]=='x')
           {
            if(s[l+1]=='^')
            {
                if(s[l+2]=='2') {if(c!=0) c2=c*flag;else c2=flag;}
                else if(s[l+2]=='3') {if(c!=0) c3=c*flag;else c3=flag;}
                l+=2;
            }
            else {if(c!=0) c1=c*flag;else c1=flag;}
            c=0;
           }
           l++;
        }
        //printf("%d %d %d %d\n",c3,c2,c1,c0);
        for(int k=-20;k<=20;k++)
        {
            int y;
            y=c3*pow(k,3)+c2*pow(k,2)+c1*k+c0;
            if(y<=20&&y>=-20) a[20-y][20+k]='*';
        }
        for(int i=0;i<41;i++)
            printf("%s\n",a[i]);
        printf("\n");

    }



    return 0;
}
