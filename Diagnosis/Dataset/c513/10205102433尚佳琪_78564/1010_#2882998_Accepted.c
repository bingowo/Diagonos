#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void cl(int a,int n)
{
   // int len=n-1;
    int b[n];
    for(int i=0;i<n;i++)
    {
        //printf("%d",a&1);
        b[i]=a&1;
        a=a>>1;
    }
    for(int i=n-1;i>=0;i--)
        printf("%d",b[i]);
   // printf("%s",b);
   // printf("\n");
}
int main()
{
    char a[505];
    scanf("%s",a);
    int len=strlen(a);
    printf("0001");
    cl(len,10);
    for(int j=0;j<len;j+=3)
    {
        int temp=0;
        int temp2=0;
        temp2=len-j;
        if(temp2!=1&&temp2!=2)
            temp2=3;
        for(int i=j;i<j+temp2;i++)
        {
            temp=temp*10+a[i]-'0';
           // printf("\n%d\n",temp);
        }
        cl(temp,temp2*3+1);
    }

    return 0;
}
