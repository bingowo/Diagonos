#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char a[50]={0};
        int b,c=0,sum=0;
        scanf("%s",&a);
        b=strlen(a);
        for(int k=b-1;k>-1;k--) /*从位权最低的数开始遍历*/
        {
            if(a[k]=='-')
            {
                sum+=-1*pow(3,c);
            }
            else if(a[k]=='0')
            {
                sum+=0;
            }
            else
            {
                sum+=pow(3,c);
            }
            c++;/*c为次方，每次循环＋1*/
        }
        printf("case #%d:\n%d\n",i,sum);
    }
    return 0;
}
