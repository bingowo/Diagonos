#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d", &T);
    char s[53];
    long long A=0, B=1;
    int len1, len2;
    for(int i=0; i<T; i++){
        scanf("%s", s);
        A = 0;
        B = 1;
        len1 = strlen(s);
        for(int j=2; j<len1; j++){
            A = A*8+(int)s[j]-48;
            B = B*8;
        }
        printf("case #%d:\n", i);
        printf("%c%c", '0', '.');
        len2 = 0;
        while(A!=0 && len2<3*(len1-2)){
            A *= 10;
            printf("%lld", A/B);
            A = A%B;
            len2++;
        }
        printf("%c", '\n');
    }
    return 0;
}
