#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct S
{
    char c;
    int x1;
    int x2;
}mm;
int main()
{
    mm s[20]={{'0',0,0},{'1',1,0},{'2',-1,1},{'3',0,1},{'4',0,-2},{'5',1,-2},{'6',-1,-1},{'7',0,-1},{'8',2,2},{'9',3,2},{'A',1,3},{'B',2,3},{'C',2,0},{'D',3,0},{'E',1,1},{'F',2,1}};
    char x[50];
    scanf("%s",x);
    long long a=0,b=0;
    for(int i=2;i<strlen(x);i++)
    {
        int m;
        if(x[i]>='0' && x[i]<='9') m=x[i]-'0';
        if(x[i]>='A' && x[i]<='F') m=x[i]-'0'-7;
        a=a*(-4)+s[m].x1;
        b=b*(-4)+s[m].x2;
    }
    if(a==0 && b==0) printf("%d",0);
    if(a!=0) printf("%lld",a);
    if(b!=0)
    {
        if(b>0 && a!=0)
        {
            printf("+");
        }
        if(b!=1 && b!=-1) printf("%lld",b);
        if(b==-1) printf("-");
        printf("i");
    }
    return 0;
}

