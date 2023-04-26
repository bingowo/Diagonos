#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) return 0;
        else
        {
            double temp=n*log10(n);
            temp=temp-(int)temp;
            temp=pow(10,temp);
            printf("%d\n",(int)temp);
        }
    }
}
