#include <stdio.h>
#include <string.h>
struct RLE{
    char c;
    int count;
};

int main() {
    struct RLE r[501];
    int T;
    char s[501];
    scanf("%d",&T);
    getchar();
    for(int t=0;t<T;t++)
    {
        gets(s);
        int len= strlen(s);
        r[0].c=s[0];
        for(int i=0;i<501;i++)
        {
            r[i].count=1;
        }
        int j=0;
        for(int i=1;i<len;i++)
        {
            if(s[i]==s[i-1])
            {
                if(r[j].count==255) {
                    j++;
                    r[j].c = s[i];
                }
                r[j].count++;
            }
            else if(s[i] != s[i-1])
            {
                j++;
                r[j].c=s[i];
            }
        }
        printf("case #%d:\n",t);
        for(int i=0;i<=j;i++)
        {
            printf("%d%c",r[i].count,r[i].c);
        }
        printf("\n");
    }
    return 0;
}
