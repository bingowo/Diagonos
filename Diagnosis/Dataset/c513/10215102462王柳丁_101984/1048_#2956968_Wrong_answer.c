#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void read(char *a,int *res);
void mul(char *a,char *b);
int main()
{
	char a[101],b[101];
	while(scanf("%s%s",a,b)==2)
    {
        mul(a,b);
    }
	return 0;
}
void read(char *a,int *res)//记录系数和幂
{
    int k=0;
    while(k<strlen(a))
    {
        int sign=1,coe=0,pow=0;
        if(a[k]=='-'){sign=-1;k++;}
        if(a[k]=='+'){sign=1;k++;}
        while(isdigit(a[k])){coe=coe*10+a[k++]-'0';}
        if(coe==0)coe=1;
        if(a[k]!='x'){res[0]=coe*sign;return;}else k++;
        if(a[k]=='^')k++;
        while(isdigit(a[k])){pow=pow*10+a[k++]-'0';}
        if(pow==0)pow=1;
        res[pow]=coe;
    }
}
void mul(char *a,char *b)
{
    int result[10000]={0};
    int m[51]={0};int n[51]={0};
    read(a,m);
    read(b,n);
    int i=0,j=0;
    for(;i<50;i++)
    {
        for(;j<50;j++)
        {
            result[i+j]=m[i]*n[j];
        }
    }
    int x=1;
    for(i=99;i>=0;i--)
    {
        if(result[i])
        {
            (x=1)?printf("%d",result[i]):printf(" %d",result[i]);
            x=0;
        }
    }
    printf("\n");
}
