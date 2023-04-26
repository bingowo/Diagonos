#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    char s[50];
    for(int i=0;i<T;i++)
    {
        scanf("%s",&s);
        int n=strlen(s);
        //printf("%d\n",n);
        long double res=0;
        long double flag=1;
        for(int j=2;j<n;j++)
        {
            flag*=0.125;
            res=(s[j]-'0')*flag+res;
            //printf("%lf %lf\n",flag,res);
            //printf("%lf\n",res);
        }
        printf("case #%d:\n",i);
        printf("%lf\n",res);
    }
    return 0;
}
