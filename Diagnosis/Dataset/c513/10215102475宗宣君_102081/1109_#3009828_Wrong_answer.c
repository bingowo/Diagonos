#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int T,i,j;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        int a[9],num = 0;
        for(j = 0;j<9;j++)
            {scanf("%d",&a[j]);
            if(a[j]==0&&num==j) num++;
            }
        //printf("%d ",num);
        printf("case #%d:\n",i);
        if(num==j) printf("0");
        else
        {for(j = 0;j<9;j++)
        {
            if(a[j]==0);
            else if(a[j] == 1)
            {
                if(j==7) printf("+x");
                else if(j==8) printf("+1");
                else if(j==num) printf("x^%d",8-num);
                else printf("+x^%d",8-j);
            }
            else if(a[j]==-1)
            {
                if(j==7) printf("-x");
                else if(j==8) printf("-1");
                else if(j==num) printf("-x^%d",8-num);
                else printf("-x^%d",8-j);
            }
            else{
                char flag = a[j]>0?'+':'-';
                int p = abs(a[j]);
                if(j==7) printf("%c%dx",flag,p);
                else if(j==8) printf("%c%d",flag,p);
                else if(j==num) printf("%c%dx^%d",flag,p,8-num);
                else printf("%c%dx^%d",flag,p,8-j);
            }

        }}
        printf("\n");

    }
    return 0;
}
