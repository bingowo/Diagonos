#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 123

int reduction(int a,int b)//化简
{
    int temp;
    int a1=a;
    int b1=b;
    while(a%b)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    a1/=b;
    b1/=b;
    printf("%d/%d",b1,a1);
    return 0;
}

int density(char *A)
{
    int len=strlen(A);
    int num=0;
    for(int i=0;i<len;i++)
    {
        char temp=A[i];
        while(temp)
        {
            temp=temp&(temp-1);//消去最末位1
            num++;
        }
        reduction(len*8,num);
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        char a[MAXN]={'\0'};
        char c;
        int j=0;
        while((c=getchar())!='\n')
        a[j++]=c;
        density(a);
    }
    return 0;
}