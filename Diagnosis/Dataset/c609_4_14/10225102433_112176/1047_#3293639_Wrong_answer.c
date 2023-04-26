#include <stdio.h>
#include <math.h>
#include <string.h>

int tmp[100000];
int a,n;
int cnt = 1;

void BIGplus(int num)
{
    int t = 0;
    for(int i = 0;i < cnt || t;i++)
    {
        t += tmp[i]*num;
        if(i < cnt) tmp[i] = t%10;
        else tmp[cnt++] = t%10;
        t /= 10;
    }
}

int main()
{
    int T;scanf("%d",&T);
    for(int i = 0;i < T;i++){
        printf("case #%d:\n",i);
        scanf("%d %d",&a,&n);
        if(n == 0) printf("1\n");
        else
        {
            tmp[0] = a;n--;
            while(n--)
            {
                BIGplus(a);
            }
            for(int j = cnt-1;j >= 0;j--) printf("%d",tmp[j]);
            printf("\n");
            memset(tmp,0,sizeof(tmp));
            cnt = 0;
        }
    }
    return 0;
}