#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
    int cas,i,j,k,m,b,n,x,tmp,d,len,base;
    long long si[10007];
    char ss[10007];
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        memset(si,0,sizeof(si));
        len = 0;
        scanf("%s%d%d",ss,&b,&n);
        x = pow(10,n);//用取余数的方法减小数字；
        len = strlen(ss);
        for(k = 0,base = 0; k < len; k++)
        {
            base  = base*10 + ss[k]-'0';
            si[k] = ss[k] - '0';
        }
        base %= x;
        for(k = 0; k <= (len-1)/2; k++)
        {
            d = si[k];
            si[k] = si[len-1-k];
            si[len-1-k] = d;
        }
        for(j = 2; j <= b; j++)
            for(k = 0; k < len; k++)si[k] = si[k] * base % x;
            m = 0;
            for(k = 0; k < len; k++)
            {
                tmp = si[k] + m;
                si[k] = tmp%10%x;//记住取余数法则
                m = tmp/10;
            }
            while(m)
            {
                si[len] = m%10%x;
                m /= 10;
                len++;
            }
        printf("case #%d:\n",i);
        for(j = n-1; j >= 0; j--)printf("%d",si[j]);//保留n位，从n-1位开始输出；
        printf("\n");
    }
    return 0;
}