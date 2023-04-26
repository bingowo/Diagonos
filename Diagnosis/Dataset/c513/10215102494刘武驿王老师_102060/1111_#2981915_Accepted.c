#include <stdio.h>
#include <string.h>
int main()
{
    char F[40], dot[41][41];
    int check=0;
    check=scanf("%s",F);
    while(check!=EOF)
    {
        int i, j, sig=1, l=strlen(F), a3=0, a2=0, a1=0, a0=0, num=1;
        for(i=0; i<41; i++)
            for(j=0; j<41; j++)
            {
                if(i==20)
                {
                    if(j==20) dot[i][j]='+';
                    else if(j==40) dot[i][j]='>';
                    else dot[i][j]='-';
                }
                else if(j==20)
                {
                    if(i==0) dot[i][j]='^';
                    else if(i==20) dot[i][j]='+';
                    else dot[i][j]='|';
                }
                else dot[i][j]='.';
            }
        for(i=5; i<l;)
        {
            if(F[i]=='-') {sig=-1; num*=-1; i++;}
            else if(F[i]=='+') {sig=1; i++;}
            else if(F[i]=='x')
            {
                if(F[++i]=='^')
                {
                    i++;
                    if(F[i]=='3') {a3=num; a0=0; i++;}
                    else if(F[i]=='2') {a2=num; a0=0; i++;}
                }
                else {a1=num; a0=0;}
            }
            else
            {
                num=F[i++]-'0';
                if(F[i]>='0'&&F[i]<='9')
                {
                    num*=10;
                    num+=F[i]-'0';
                    i++;
                }
                num*=sig;
                a0=num;
            }
        }
        for(i=-20; i<21; i++)
        {
            num=a3*i*i*i+a2*i*i+a1*i+a0;
            if(num>-21 && num<21) dot[20-num][i+20]='*';
        }
        for(i=0; i<41; i++)
        {
            for(j=0; j<41; j++) printf("%c",dot[i][j]);
            printf("\n");
        }
        check=scanf("%s",F);
        if(check!=EOF) printf("\n");
        else break;
    }
    return 0;
}