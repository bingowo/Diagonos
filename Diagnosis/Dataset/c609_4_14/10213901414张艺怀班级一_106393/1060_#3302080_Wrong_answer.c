#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// min is for the minimum of dict order

int reverse(char s[], int len, int i)
{
    for (; i < len-1; i++) {
        if (s[i+1] < s[i]) return i;
    }
    return -1;
}

// void adjust(int status[], )

int main()
{
    char s[120] = {0};
    int status[120] = {0};
    scanf("%s", s);
    int len = strlen(s);

    int R = reverse(s, len, 0);
    int k = (R == -1) ? len-1 : R+1;
    for (int i = 0; i < k; i++) {
        if (i+1 != (R == -1) ? len-1 : R) {
            for (int j = i+1; j <= k; j++) {
                if (s[j] > s[i]) {
                    status[i]++;
                }
            }
        }
        else {
            if (s[i+1] > s[i]) status[i]++;
        }
    }
    int v = R;
    while (R != -1) {
        int R1 = reverse(s, len, R+1);
        if (R1 != -1) {
            for (int i = R+1; i < R1; i++) {
                if (i+1 != R1) {
                    for (int j = i+1; j < R1; j++) {
                        if (s[j] > s[i]) {
                            status[i]++;
                        }
                    }
                }
                else {
                    if (s[i+1] > s[i]) status[i]++;
                }
            }
        }
        if (R1 != -1) v = R1;
        R = R1;
    }
    if (v < len-1) {
        for (; v < len-1; v++) {
            if (s[v+1] > s[v]) status[v]++;
        }
    }
    for (int i = 0; i < len; i++) {
        if (status[i]) printf("%c", s[i]);
        printf("%c", s[i]);
    }
    return 0;
}
