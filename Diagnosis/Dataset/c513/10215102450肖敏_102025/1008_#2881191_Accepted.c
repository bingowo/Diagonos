#include <stdio.h>

int main()
{
    int T,i,j,k,count;
    int a,b;
    int s[32],t[32];
    scanf("%d",&T);
    for(i = 0;i < T;i ++)
    {
        scanf("%d %d",&a,&b);
        j = 0,k = 0,count = 0;
        while(a != 0)
        {
            s[j++] = a % 2;
            a /= 2;
        }
        while(b != 0)
        {
            t[k++] = b % 2;
            b /= 2;
        }
        while(j <k)
            s[j ++] = 0;
        while(k < j)
            t[k ++] = 0;
        for(int e = 0;e < k;e ++)
        {
            if(s[e] != t[e])
                count ++;
        }
        printf("%d\n",count);
    }

    return 0;
}
