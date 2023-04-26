#include <stdio.h>
#include <stdlib.h>

int main()
{
    char n[505];
    scanf("%s",n);
    int len=strlen(n);
    //printf("%d\n",len);
    int a[505]={0};
    int i=0;
    while(len!=0)
    {
        a[i]=len%2;
        len=len/2;
        i++;
    }


    printf("0001");
    for(int i=9;i>=0;i--)
    {
        printf("%d",a[i]);
    }
    return 0;
}
