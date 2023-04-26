#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ito2(int x,int i)
{
    for(;i>0;i--)
    {
        printf("%d",x&1);
        x>>=1;
    }
}
int main()
{
    char a[5000];
    scanf("%s",a);
    int len=strlen(a);
    int num=len/3;
    int last=len%3;
    printf("0001");
    ito2(len,10);
    int x,i=0;
    for(;i<num;i++)
    {
        x=(a[i*3]-'0')*100+(a[i*3+1]-'0')*10+(a[i*3+2]-'0');
        ito2(x,10);
    }
    if(last==2)
    {
        x=(a[i*3]-'0')*10+(a[i*3+1]-'0');
        ito2(x,1+last);
    }
    if(last==1)
    {
        x=a[i*3]-'0';
        ito2(x,last);
    }
    return 0;
}
