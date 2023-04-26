#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int count_1(int m);

int main()
{
    int T;
    scanf("%d", &T);
    int cnt = 0;
    while(cnt < T)
    {
        int N;
        scanf("%d", &N);
        int **nums;
        nums = (int **)malloc(sizeof(int) *10000);
        for(int i = 0;i < 10000;i++)
        {
            nums[i] = (int *)malloc(sizeof(int) *10000);
        }
        for(int i = 0;i < N;i++)
        {
            scanf("%d",&nums[i][0]);//数据已经完成输入
        }
        //利用二维数组，第一维储存原始数据，
        for(int j = 0;j < N; j++)
        {
            nums[j][1] = count_1(nums[j][0]);
        }//第二维来储存1的数目
        for(int j = 0;j < N;j++)
        {
          printf("%d\n", nums[j][1]);
        }

        int total = N * (N - 1) / 2;
        int cntt = 0;
        while(cntt < total)
        {
            int m = 0;
            int n = 1;
            if(nums[m][1] > nums[n][1])
            {
                n++;
            }
            while(nums[m][1] < nums[n][1] && n < N)
            {
                int t = nums[m][1];
                nums[m][1] = nums[n][1];
                nums[n][1] = t;
                int p = nums[m][0];
                nums[m][0] = nums[n][0];
                nums[n][0] = p;
                n++;
                m++;
            }
            if((nums[m][1] == nums[n][1]) && nums[m][0] > nums[n][0])
            {
                int t = nums[m][1];
                nums[m][1] = nums[n][1];
                nums[n][1] = t;
                int p = nums[m][0];
                nums[m][0] = nums[n][0];
                nums[n][0] = p;
                n++;
                m++;
            }
            cntt++;
        }
        printf("case #%d:\n", cnt);
        for(int i = 0;i < N;i++)
        {
            printf("%d ", nums[i][0]);
        }
        printf("\n");
        cnt++;
    }
}

int count_1(int m)
{
    int sum =0;
    int etr = 0;
    int s1[64];
    if(m < 0)
    {
        m = -m;
        if(m % 2 != 0) etr = 1;
        for(int i = 0;i < 64;i++)
        {
            s1[i] = m % 2;
            m = m / 2;
        }
        for(int j = 0;j < 64;j++)
        {
            if(s1[j] == 0) sum++;
        }
        sum = sum + etr;
    }
    if(m > 0)
    {
        for(int k = 0;k < 64;k++)
        {
            s1[k] = m % 2;
            m = m / 2;
        }
        for(int x = 0;x < 64;x++)
        {
            if(s1[x] == 1) sum++;
        }
    }
    return sum;
}

