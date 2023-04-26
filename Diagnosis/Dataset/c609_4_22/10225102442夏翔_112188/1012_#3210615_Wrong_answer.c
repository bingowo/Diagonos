#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d", &T);
    char s[53];
    int len1;
    double sum;
    for(int i=0; i<T; i++){
        scanf("%s", s);
        sum = 0;
        len1 = strlen(s);
        for(int j=len1-1; j>1; j--){
            sum = sum/8+(int)s[j]-48;
        }
        sum /= 8;
        printf("case #%d:\n", i);
        printf("%.150g\n", sum);
    }
    return 0;
}
