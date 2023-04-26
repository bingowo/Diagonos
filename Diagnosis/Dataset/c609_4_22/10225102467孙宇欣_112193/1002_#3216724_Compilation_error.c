#include <stdio.h>

int binary (int n, int s[])
{
    int a[32];
    int i, j = 0;
    for (i = 0; n > 0; i++)
    {
        a[i] = n%2;
        n = n/2;
    }
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
    int f = 0;
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
                if (s[j，则跳出循环
                {
                    break;
                }
                else 
                {
                    x = s[j];
                    cont++;
                }
            }
        
            if (ans < cont)
            {
                ans = cont;
            }
        }
        printf("case #%d:\n%d\n",f,ans+1);
        f++;
    }
    return 0;
}