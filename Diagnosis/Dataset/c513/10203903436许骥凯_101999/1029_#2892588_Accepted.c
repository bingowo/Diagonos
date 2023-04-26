#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int compare(const void *p1, const void *p2){
    char c1 = *(char*)p1, c2 = *(char*)p2;
    return c1 > c2? 1: -1;
}
int main(){
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i != n; i++){
        char string[200] = {0}, c;
        char alpha[200] = {0};
        int slen = 0, alen = 0;
        while ((c = getchar()) != '\n'){
            string[slen++] = c;
            if (isalpha(c)) alpha[alen++] = c;
        }
        string[slen] = 0, alpha[alen] = 0;
        qsort(alpha, alen, sizeof(alpha[0]), compare);    
        printf("case #%d:\n", i);
        for (int j = 0, k = 0; j != slen; j++){
            if (isalpha(string[j])) printf("%c", alpha[k++]);
            else printf("%c", string[j]);
        }
        printf("\n");
    }
    return 0;
}