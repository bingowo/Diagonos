#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    for (int i = 0; i < T; i++) {
        char s[100];
        gets(s);
        int j = 0;
        int result=0,k;
       
        for (int e = strlen(s) - 1; e > 1; e--) {
            int n = s[e] - '0';
            result=result+n;
            result*=8;
        }
        printf("case #%d:\n0.", i);
      printf("%d.", result);
        printf("\n");
    }
    return 0;
}
