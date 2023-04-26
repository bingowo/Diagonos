# include <stdio.h>
# include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int j,i; 
    for (i = 0; i < T; i++)
    {   int count_a = 0,count_b = 0;
        long long int a,b;// 每个问题下的值
        scanf("%d%d",&a,&b);
        int a1[20],b1[20];
        for (j = 0; j < 20; j++)
        {
            a1[j] = -1;
            b1[j] = -1;// 数组用来存放二进制数，并且初始化为-1；
        }
        int remain_a = a,remain_b = b;
        int r;
        if (a == 0)
        {
            a1[0] = 0;
        }
        if (b == 0)
        {
            b1[0] = 0;
        }
        for (j = 0; j < 20 && remain_a > 0; j++)
        {
            r = remain_a%2;
            remain_a = ( remain_a-r )/2;
            a1[j] = r;
        }
        for (j = 0; j < 20 && remain_b > 0; j++)
        {
            r = remain_b%2;
            remain_b = ( remain_b-r )/2;
            b1[j] = r;
        }
        int count = 0;
        for (j = 0; j < 20; j++)
        {
            if (a1[j] != b1[j])
            {
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}