#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    int i;//循环t次数
    int res=0;
    scanf("%d",&t);
    char test[10000];
    for(i=0;i<t;i++)
    {
        res=0;
        scanf("%s",&test);
        int j=strlen(test);
        int k;
        for(k=0;k<j;k++)
        {
            if(test[k]=='-')
                res=res*3-1;
            else
                res=res*3+test[k]-'0';

        }

        printf("case #%d:\n",i);
        printf("%d\n",res);
    }
    return 0;
}
