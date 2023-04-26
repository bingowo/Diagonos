# include <stdio.h>
# include<stdlib.h>

int main()
{
    int T;// T组问题
    scanf("%d",&T);
    int j,i; 
    for (i = 0; i < T; i++)
    {
        long long int n;// 每个问题下的值
        scanf("%d",&n);
        int b[100];
        for (j = 0; j < 100; j++)
        {
            b[j]=-1;// 数组b用来存放二进制数，并且初始化为-1；
        }
        int remain=n;
        int r;
        for (j = 0; j < 100 && remain > 0; j++)
        {
            r = remain%2;
            remain = ( remain-r )/2;
            b[j] = r;
        }//转换为二进制存放在数组b中
        int max=1;
        for (j = 0; j < 100 && b[j] != -1 ; j++)
        {
            int k,count = 1;
            for (k = j+1; k < 100 && b[k] != -1; k++)
            {
                if (b[k-1] != b[k] && b[k] != -1)
                {
                    count++;
                }
                else
                {
                    break;
                }
                if (count > max)
                {
                    max = count;
                }
            }

        }
        printf("case #%d:\n%d",i,max);
    }
    return 0;
}
