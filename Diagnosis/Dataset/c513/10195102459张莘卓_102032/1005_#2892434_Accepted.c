#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;  scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        char s[60];
        scanf("%s",s);
        int i = strlen(s)-1;
        int num[160] = {0}, end = 1;
        while(s[i] != '.') {
            num[0] += s[i--] - '0';
            int k = 0, mod = 0;
            while(k<end || mod) {
                mod = mod*10 + num[k];
                num[k++] = mod / 8;
                mod %= 8;
            }
            end = k;
        }
        printf("case #%d:\n0.",j);
        for(int k=1; k<end; ++k)
            printf("%d",num[k]);
        printf("\n");
    }
    return 0;
}
