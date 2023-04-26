#include <stdio.h>

int main()
{
    int T,i,j,k,a,r,count,num,m,n;
    char s[120],t[8];
    scanf("%d",&T);
    for(i = 0;i <T;i ++)
    {
        scanf("%s",s);
        count = 0,num = 0;
        for(j = 0; s[j] != '\0';j ++)
        {
            a = (int)s[j];
            k = 0;
            while(k < 8)
            {
                t[k++] =a% 2;
                a /= 2;
            }
            for(k =0 ;k < 8;k ++)
            {
                count += (t[k] == 0) ?0:1;
                num ++;
            }
        }
        m = count;
        n = num;
        do
        {
            r = n % m;
            n = m;
            m = r;
        }
        while(r != 0);
        printf("%d/%d\n",count/n,num/n);
    }
    return 0;
}
