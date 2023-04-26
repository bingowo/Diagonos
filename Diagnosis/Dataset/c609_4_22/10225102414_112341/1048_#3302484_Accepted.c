#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

void Cal(char *F1, char *F2)
{
    int l = strlen(F2), i, carry = 0, cal;
    char F3[N];memset(F3, '0', N);
    for (i = 0;i < l;i++){
        if (F1[i] == '\0') cal = F2[i] - '0' + carry;
        else cal = F1[i] + F2[i] - 2 * '0' + carry;
        F3[i] += cal % 10;
        carry = cal / 10;
    }
    if (carry > 0) F3[i++] += carry;
    F3[i] = '\0';
    strcpy(F1, F2);strcpy(F2, F3);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0;i < T;i++){
        int n, l;
        char F1[N] = "0", F2[N] = "1";
        scanf("%d", &n);
        for (int j = 0;j < n - 1;j++) Cal(F1, F2);
        printf("case #%d:\n", i);
        if (n == 0){
            printf("0\n");
            continue;
        }
        for (l = strlen(F2) - 1;l >= 0;l--) printf("%c", F2[l]);
        printf("\n");
    }
    return 0;
}
