#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int cmp (const void*a, const void *b)
{
    return *(int*)b - *(int*)a;//降序排序
}

int main()
{
    int T;
    scanf("%d",&T);
    printf("t=%d\n",T);
    for (int p = 0; p < T; p++)
    {
        char a[63] = {0};//存放输入字符
        int integer[62] = {0};//将字符转换为数字存放
        int s[63] = {0};//存放一共出现了多少个字符
        int l = 1;//共有多少字符

        //输入a
        scanf("%s",a+1);//将字符输入a
        printf("%s",a+1);
        printf("\n");
        
        printf("str=%d\n",str);
        l = strlen(a)-1;
        //l--;//此时l为字符数
        printf("l=%d\n",l);

        //确定进制
        //int x;
        for (int i = 1; i <= l; i++)//记录每个字符出现次数，从而确定进制
        {
            //printf("a=%d ",a[l]);
            if (a[i] >= '0' && a[i] <= '9')
            {
                s[a[i]-'0']++;
            }
            if (a[i] >= 'a' && a[i] <= 'z')
            {
                s[a[i] - 'a' + 10]++;
            }
            if (a[i] >= 'A' && a[i] <= 'Z')
            {
                s[a[i] - 'A' + 10 + 26]++;
            }
        }
        int jinzhi = 0;
        for (int i = 0; i <= 63; i++)
        {
            printf("s=%d ",s[i]);
            if (s[i] != 0) jinzhi++;
        }
        printf("\n");
        printf("jinzhi=%d\n",jinzhi);
        //计算每个字符的出现位置
        int jishu = l - 1;//第1位级数为0，第二位为1
        for (int i = 1; i <= 63; i++)
        {
            if (a[i] >= '0' && a[i] <= '9')
            {
                integer[a[i] - '0'] = pow(jinzhi,jishu) + integer[a[i] - '0'];
                jishu--;
            }
            if (a[i] >= 'a' && a[i] <= 'z')
            {
                integer[a[i] - 'a' + 10] = pow(jinzhi,jishu) + integer[a[i] - 'a' + 10];
                jishu--;
            }
            if (a[i] >= 'A' && a[i] <= 'Z')
            {
                integer[a[i] - 'A' + 10 + 26] = pow(jinzhi,jishu) + integer[a[i] - 'A' + 10 + 26];
                jishu--;
            }
        }

        //将每个字符所代表的级数和从大到小排序
        qsort(integer,63,sizeof(int),cmp);
        for (int i = 0; i <= 62; i++)
        {
            printf("integer=%d ",integer[i]);

        }
        printf("\n");

        //赋予数字
        int ans = 0;
        ans = integer[0] * 1 + ans;
        ans = integer[1] * 0 + ans;
        for (int i = 2; i <=63; i++)
        {
            ans = integer[i] * i  + ans;
        }

        printf("case #%d:\n%d\n",p,ans);
    }
    return 0;
}
