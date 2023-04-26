#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    int a;
    scanf("%d",&a);
    for (int i=0;i<a;i++)
    {
        char c[100]={'\0'};
        scanf("%s",&c);
        int b=strlen(c);
        int sum;
        for(int j=0;j<b;j++)
        {
            if(c[j]=='-')
                sum=sum-pow(3,b-j-1);
            else if(c[j]=='1')
                sum=sum+pow(3,b-j-1);
            else
                sum=sum;
        }
        printf("case #%d:\n",i);
        printf("%d\n",sum);
    }
    return 0;
}
