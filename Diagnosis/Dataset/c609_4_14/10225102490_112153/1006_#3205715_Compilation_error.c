#include <stdio.h>

int cmp(const void*a, const void*b)//降序排序
{
    return (int*)b - (int*)a;
}

/*typedef struct
{
    int n;
    int val;
} d[62];*/

int power(int n, int m)
{
    int sum = 1;
    for (int i = 1; i <= m; i++)
    {
        sum = sum * n;
    }
    return sum;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int p = 0; p < t; p++)
    {
        char a[111111];
        scanf("%s",a);
        int cnt[62] = {0};
        int i;//共有几位
        //int flag;//标注首位
        for (i = 0; a[i] != '\0'; i++);
        i--;
        int j;
        for (i,j = 0; a[j] != 0; i--,j++)
        {
            int x;
            if (a[j] <= '9' && a[j] >= '0')
            {
                x = a[j] - '0';
            }
            if (a[j] <= 'z' && a[j] >= 'a')
            {
                x = a[j] - 'a' + 10;
            }
            if (a[j] <= 'Z' && a[j] >= 'A')
            {
                x = a[j] - 'A' + 10 + 26;
            }
            //if (i == 0) flag = x;//首位不能为0
            cnt[x] = cnt[x] + powe(10,i);//储存
            
        }
        
        //flag = cnt[flag];//将首位代表的总数标记
        qsort (cnt, cnt + n, cmp);
        
        //首位永远是最大的，第二位是第二大的
        int sum = 0;
        sum = sum + cnt[0];//首位乘以1
        //第二位乘以0
        for (int j = 2; j <= i; j++)//第三位从2开始乘
        {
            sum = sum + cnt[j] * j；
        }
        
        printf("%d",sum);
        
    }
}