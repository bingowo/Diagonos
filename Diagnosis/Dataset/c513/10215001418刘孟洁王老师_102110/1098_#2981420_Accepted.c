#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cas,i,j;
    char s[107];
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        scanf("%s",s);
        int len = strlen(s);
        int ad[4] = {0};
        int tot[4] = {0};
        int lamp[4] = {0};
        for(j = 0; j < len; j++)
        {
            tot[j%4]++;//用余数的值来记录彩灯的顺序；每次加一的意思就是加上这个位置本该有的灯的数量；
            switch(s[j])
            {
                case 'R':lamp[0]++;ad[0] = j%4;break;//有这个颜色的灯就加一；
                case 'B':lamp[1]++;ad[1] = j%4;break;
                case 'Y':lamp[2]++;ad[2] = j%4;break;
                case 'G':lamp[3]++;ad[3] = j%4;break;
            }
        }
        printf("case #%d:\n%d %d %d %d\n",i,tot[ad[0]]-lamp[0],tot[ad[1]]-lamp[1],tot[ad[2]]-lamp[2],tot[ad[3]]-lamp[3]);
    }
    return 0;
}