#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
        char c[100]={'\0'};
        scanf("%s",&c);
        int b=strlen(c);
        double sum=0;
        int point=b;
        for(int j=0;j<b;j++)
        {
            if(c[j]=='.')
                point=j;
        }
        for(int j=0;j<b;j++)
        {
            if(c[j]=='2')
                sum=sum-pow(3,point-j-1);
            else if(c[j]=='1')
                sum=sum+pow(3,point-j-1);
        }
        printf("%lf\n",sum);
    return 0;
}
