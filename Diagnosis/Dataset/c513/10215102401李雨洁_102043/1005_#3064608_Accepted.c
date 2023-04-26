#include <stdio.h>
#include <string.h>
int main()
{
    char s[52],s2[152];
    int T; scanf("%d",&T);
    for(int m = 0; m < T; m++)
    {
        int j,t,k=0;
        scanf("%s",s);
        memset(s2,0,sizeof(s2));
        int len = strlen(s);
        for(int i = len - 1 ; i > 1 ; i--)
        {
            int num = s[i] - '0';
            for(j = 0 ; j < k || num != 0;j++)
            {
                t = 10 * num + (j < k ? s2[j]-'0' : 0);
                s2[j] = t / 8 + '0';
                num = t % 8;
            }
            k = j;
        }
        printf("case #%d:\n0.%s\n",m,s2);
    }
    return 0;
}
