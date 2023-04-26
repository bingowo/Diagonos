#include <stdio.h>
#include <stdlib.h>

int Encrypt(int *keych, int *key, int length) {
    keych[0] = key[0];
    int i, j = 0, k = 0, flag;
    for (i = 0; i < length; i++) {
        flag = 1;
        for (k = 0; k < j + 1; k++) {
            if (key[i] == keych[k])
                flag = 0;
        }
        if (flag) {
            j = j + 1;
            keych[j] = key[i];
        }
    }
    return j + 1;
}

int cmpA(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int cmpD(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

void myprint(int *p, int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", p[i]);
    printf("\n");
}

int main() {
    int key[100];
    int keych[100];
    int length = 0;
    char command;
    scanf("%c", &command);
    while (1) {
        scanf("%d", &key[length]);
        char c = getchar();
        length++;
        if (c == '\n') {
            break;
        }
    }
    int len = Encrypt(keych, key, length);
    if (command == 'A') {
        qsort(keych, len, sizeof(int), cmpA);
        myprint(keych, len);
    } else if (command == 'D') {
        qsort(keych, len, sizeof(int), cmpD);
        myprint(keych, len);
    }
    return 0;
}