#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void minus(int* e1, int* e2) {
    for(int j = 0; j < 500; j++) {
        e1[j] = e1[j] - e2[j];
    }
    for(int j = 0; j < 499; j++) {
        if(e1[j] < 0) {
            e1[j] = e1[j] + 10;
            e1[j+1]--;
        }
    }
}

void print(int *e) {
    int k;
    for(k =499; k >=0; k--) {
        if(e[k] != 0) break;
    }
    for(; k>=0; k--) {
        printf("%d", e[k]);
    }
    printf("\n");
}

int main() {
    while(1) {
        char a[500] = { "0" };
        char b[500] = { "0" };
        int c[500] = { 0 };
        int d[500] = { 0 };

        if(scanf("%s", a) != EOF) {
            scanf("%s", b);
            for(int i = 0; i < strlen(a); i++) {
                c[i] = a[strlen(a) - i - 1] - '0';
            }
            for(int i = 0; i < strlen(b); i++) {
                d[i] = b[strlen(b) - i - 1] - '0';
            }
            if(strlen(a) > strlen(b)) {
                minus(c, d);
                print(c);
            } else if(strlen(a) < strlen(b)) {
                minus(d, c);
                print(d);
            } else {
                int flag = 0;
                for(int i = 499; i >= 0; i--) {
                    if(a[i] > b[i]) {
                        flag = 1;
                        break;
                    } else if(a[i] < b[i]) {
                        flag = -1;
                        break;
                    }
                }
                if(flag == 1) {
                    minus(c, d);
                    print(c);
                } else if(flag == -1) {
                    minus(d, c);
                    print(d);
                } else if(flag == 0) {
                    printf("0\n");
                }
            }
        } else {
            break;
        }
    }

    return 0;
}
