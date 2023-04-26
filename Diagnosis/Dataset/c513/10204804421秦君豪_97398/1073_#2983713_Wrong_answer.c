#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>


typedef long long int lli;

void chartoint9(char *a,int *b,int len)
{
    int l=18;
    for(int i=0;i<len;i++)
    {
        b[l-len+i]=a[i]-'0';
    }
}

lli minus (int* y,int *x)
{
    int i=0;
    while (*(y+i)==0) i++;
    
}
int main(void)
{
    char a[19],b[19];
    memset(a,0,19);
    memset(b,0,19);
    int x[18]={0},y[18]={0};

    scanf("%s %s",a,b);
    int len1=strlen(a);
    int len2=strlen(b);
    chartoint9(a,x,len1);
    chartoint9(b,y,len2);
    lli ans=minus(y,x);//显示9的数的个数
    return 0;

}
