#include <stdio.h>

int main()
{
    int T,i,j,n,k;
    char s[16];
    scanf("%d",&T);
    for(i = 0;i < T;i ++)
    {
        j = 0;
        n = 0;
        scanf("%s",s);
        while(s[j] != '\0')
        {
            if(s[j] == '-')
                s[j] = -1;
            else
            {
                s[j] -= '0';
            }
            n = n * 2 + s[j];
            j++;
        }
        printf("case #%d:\n%d",i,n);
    }

    return 0;
}
