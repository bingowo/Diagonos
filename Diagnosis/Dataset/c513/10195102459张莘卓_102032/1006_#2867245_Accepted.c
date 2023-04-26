#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0; t<T; ++t) {
        char s[100];
        scanf("%s",s);
        int num = 0;
        for(int i=0; s[i]; ++i) {
            int p = s[i]=='-' ? -1 : s[i]-'0';
            num = num * 3 + p;
        }
        printf("case #%d:\n%d\n",t, num);
    }
    return 0;
}
