#include <stdio.h>
#include <string.h>
int main()
{
    int T,i,j,k,a,r,count,num,m,n;
    int length;
    char s[120];
    scanf("%d",&T);
    getchar();
    for(i = 0;i <T;i ++)
    {
        gets(s);
        length = strlen(s);
        num = 8 * length;
        count = 0;
        for(j = 0; s[j] != '\0';j ++)
        {
            while(s[j])
            {
                s[j] = s[j] &(s[j] - 1);
                count ++;
            }
        }
        m = num;
        n = count;
        do
        {
            r = m % n;
            m = n;
            n = r;
        }
        while(r != 0);
        printf("%d/%d\n",count/m,num/m);
    }
    return 0;
}
