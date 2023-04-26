#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char*a, char *b) {
    if((strlen(b)>strlen(a))||(strlen(a)==strlen(b) && strcmp(b, a)>0)){
        char *t = (char*)malloc(501*sizeof(char));
        strcpy(t, a);   strcpy(a, b);  strcpy(b, t);
        free(t);
        return -1;
    }
    return 1;
}

void set(char* s, int* a) {
    int len = strlen(s);
    for(int i=0; i<len; ++i)
        a[i] = s[len-1-i] - '0';
}

int main()
{
    char n1[501], n2[501];
    while(scanf("%s %s",n1,n2) != EOF) {
        int sign = compare(n1, n2);
        int i, a[500] = {0}, b[500] = {0};
        set(n1, a); set(n2, b);
        for(i=0; i<strlen(n1); ++i) {
            if(a[i] < b[i]) {
                a[i] += 10;
                int k = i + 1;
                while(a[k] == 0) a[k++] = 9;
                --a[k];
            }
            a[i] -= b[i];
        }
        i = 499;
        while(i>=0 && a[i] == 0) --i;
        if(sign == -1) printf("-");
        if(i < 0) printf("0");
        else for(; i>=0; --i) printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}
