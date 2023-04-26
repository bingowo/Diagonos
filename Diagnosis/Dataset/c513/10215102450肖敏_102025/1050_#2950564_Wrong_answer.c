#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    getchar();
    for (int i = 0; i < T; i++) {
        char s[81], s1[81], s2[81];

        gets(s1);
        gets(s2);
        gets(s);
        int l = strlen(s), l1 = strlen(s1), l2 = strlen(s2);
        int x1,x2;
        int k = 0;
        for (int j = 0; j < l; j++) {
            if (k == 0 && s[j] == s1[k]) {
                k++;
                {
                    if(k == l1)
                    {
                        x1 = j;
                        break;
                    }
                }
                continue;
            }
            else if(k>0 && s[j] == s1[k])
            {
                k++;
                if(k == l1)
                {
                    x1 = j;
                    break;
                }
                continue;
            }
            k =0;
        }
        int y=l2-1;
        for (int j = l-1; j >=0; j--) {
            if (y == l2-1 && s[j] == s2[y]) {
                y--;
                if(y == -1)
                {
                   x2=j;
                   break;
                }
                continue;
            }
            else if(y<l2-1 && s[j] == s2[y])
            {
                y--;
                if(y == -1)
                 {
                    x2 = j;
                    break;
                 }
                continue;
            }
            y =l2-1;
        }
        printf("case #%d:\n%d\n",i,x2-x1-1);
    }
    return 0;
}
