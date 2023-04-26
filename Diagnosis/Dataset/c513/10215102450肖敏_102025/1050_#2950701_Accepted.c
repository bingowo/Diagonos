#include <stdio.h>
#include <string.h>

int Index(char s[], char t[]) {
    int l = strlen(s), l1 = strlen(t);
    int x1;
    int k = 0;
    for (int j = 0; j < l; j++) {
        if (k == 0 && s[j] == t[k]) {
            k++;
            {
                if (k == l1) {
                    x1 = j;
                    break;
                }
            }
            continue;
        } else if (k > 0 && s[j] == t[k]) {
            k++;
            if (k == l1) {
                x1 = j;
                break;
            }
            continue;
        }
        k = 0;
    }
    if(k==0)
        return -1;
    return x1;
}

int Index2(char s[], char t[]) {
    int l = strlen(s), l1 = strlen(t);
    int x2;
    int y = l1 - 1;
    for (int j = l - 1; j >= 0; j--) {
        if (y == l1 - 1 && s[j] == t[y]) {
            y--;
            if (y == -1) {
                x2 = j;
                break;
            }
            continue;
        } else if (y < l1 - 1 && s[j] == t[y]) {
            y--;
            if (y == -1) {
                x2 = j;
                break;
            }
            continue;
        }
        y = l1 - 1;
    }
    if(y==l1-1)
        return -1;
    return x2;
}

int main() {
    int T;
    scanf("%d", &T);
    getchar();
    for (int i = 0; i < T; i++) {
        char s[81], s1[81], s2[81];

        gets(s1);
        gets(s2);
        gets(s);
        int x;
        int a1,a2,b1,b2;
        a1= Index(s,s1);
        a2= Index2(s,s1);
        b1= Index(s,s2);
        b2= Index2(s,s2);
        if(a1 == -1 || a2 == -1 || b1 ==-1 || b2==-1)
            x=0;
        else if(b2 > a1)
            x= b2-a1-1;
        else if(a2 > b1)
            x= a2-b1-1;
        else if(a1 == b1)
            x =0;


        printf("case #%d:\n%d\n", i, x);
    }
    return 0;
}
