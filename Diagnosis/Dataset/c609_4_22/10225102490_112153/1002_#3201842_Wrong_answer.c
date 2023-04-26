#include <stdio.h>

int binary (int n, int s[])//用二进制表示存储在s中,返回共有多少位（-1）
{
    int a[32];
    int i, j = 0;//表示a的最大下标
    for (i = 0; n > 0; i++)
    {
        a[i] = n%2;
        n = n/2;
    }
    //for (int i = 0; i<3; i++)
    //{
      //  printf("%d",a[i]);
    //}
    //printf("i:%d\n",i);
    int ans = i;
    i--;
    for (i,j; i >=0; i--, j++)
    {
        s[j] = a[i];
    }
    return ans;
}

int main()
{
    int t;
    int f = 0;//输出格式
    scanf("%d",&t);
    while (t--)
    {
        int n;
        int s[32];
        scanf("%d",&n);
        int l = binary(n,s);//共有l位
        //printf("l:%d\n",l);
        /*for (int i =0; i<l;i++)
        {
            printf("%d",s[i]);
        }*/
        int i, j;//i为前置位，j为最后位
        int ans = 0;
        int cont = 0;
        for (i = 0; i < l; i++)
        {
            cont = 0;
            int x = s[i];//前置位的数字
            for (j = i+1; j < l; j++)
            {
                if (s[j] == x)//如果前置位等于后置位，则跳出循环
                {
                    break;
                }
                else //如果前置位和后置位不相等，则x往后顺延一位，同时cont加一
                {
                    x = s[j];
                    cont++;
                }
            }
            //printf("cont:%d",cont);
            if (ans < cont)
            {
                ans = cont;
            }
                //选取大的那个
        }
        printf("case #%d\n%d\n",f,ans+1);
        f++;
    }
    return 0;
}
