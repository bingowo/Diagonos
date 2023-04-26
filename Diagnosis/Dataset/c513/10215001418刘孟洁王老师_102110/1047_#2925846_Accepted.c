#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct{char ch;int num;}RLE;

int main()
{
    int n,i,j,x,m;
    RLE r[507];
    char s[507];
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%s",s);
        x = 0;
        j = 0;
        while(j < strlen(s))
        {
            r[x].ch = s[j];
            for(m = j+1,r[x].num = 1; s[m] == s[j]; r[x].num++,m++);
            if(r[x].num > 255)
            {
                int numm = r[x].num;
                while(numm > 255)
                {
                   numm = numm-255;
                   r[x].num = 255;
                   r[x].ch = s[j];
                   x++;
                }
                r[x].num = numm;
                r[x].ch = s[j];
            }
            x++;
            j = m;
        }
        printf("case #%d:\n",i);
        for(j = 0; j < x; j++)printf("%d%c",r[j].num,r[j].ch);
        printf("\n");
    }
    return 0;
}
