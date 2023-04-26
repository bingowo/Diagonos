#include <stdio.h>
#include <stdlib.h>
int main()
{
    char input[10000];
    scanf("%s",input);
    int sign1=1,sign2=1,a=0,b=0,i=0;
    if(input[0]=='0'){a=0;b=0;}
    if(input[0]=='-'){sign1=-1;i++;}
    if(input[i]=='i')a=1;//解决了i和-i的问题！
    for(;input[i]!='-'&&input[i]!='+'&&input[i]!='i'&&i<strlen(input);i++)
    {
        a=a*10+input[i]-'0';
    }
    a=a*sign1;
    if(input[i]=='i'){b=a;a=0;}
    else if(input[strlen(input)-2]=='-'&&input[strlen(input)-1]=='i')b=-1;
    else if(input[strlen(input)-2]=='+'&&input[strlen(input)-1]=='i')b=1;
    else
    {
        if(input[i]=='-')sign2=-1;
        i++;
        for(;i<strlen(input)&&input[i]!='i';i++)
        {
            b=b*10+input[i]-'0';
        }
        b=b*sign2;
    }
    int qr=0,qi=0,r=0;
    int res[10000];i=0;
    if(a==0&&b==0){res[i]=0;printf("0");}
    else
    {
        while(a!=0||b!=0)
        {
            if(abs(a%2)!=abs(b%2)){res[i++]=1;r=1;}
            else {res[i++]=0;r=0;}
            qi=(r-a-b)/2;
            qr=(r+b-a)/2;
            a=qr;b=qi;
        }
        if(i==1)printf("%d",res[0]);
        else
        {
            for(i=i-1;i>=0;i--)
            {
                printf("%d",res[i]);
            }
        }
    }
    
     return 0;
}
