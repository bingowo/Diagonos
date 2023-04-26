#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
    int a;
    int num=0;
    scanf("%d",&a);
    double sum=0;
    for(int i=0;i<a;i++)
    {
        char k[60];
        scanf("%s",k);
        int len=strlen(k);
        for(int m=2;m<len;m++)
        {
            sum=sum+(k[m]-'0')*pow(8,len-m-3);
        }
        printf("%f\n",sum);
    }
    return 0;
}