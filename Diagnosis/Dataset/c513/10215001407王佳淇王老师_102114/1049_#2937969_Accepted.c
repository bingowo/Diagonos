#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int cmp(const void* a, const void* b) {
    char* c = (char*)a;
    char* d = (char*)b;
    int x = strcmp(c, d);
    if (x > 0) return 1;
    if (x < 0) return  -1;
    else return 0;
}
int main() {
    int T;
    scanf("%d",&T);
    getchar();
    for (int v = 0; v < T; v++) {
        char c[500];
        char str[500][500] = { 0 };
       gets(c);
        int i = 0, j = 0, k = 0;
        for (; c[i]; i++)
            if (isalpha(c[i])) str[j][k++] = c[i]; 
            else 
            {
                if (strlen(str[j]) == 0) continue;
                str[j++][k] = '\0';
                k = 0; 
            }
        printf("case #%d:\n", v);
        if (j == 0) printf("%s\n", str[0]);
        else
        {
            qsort(str, j, sizeof(str[0]), cmp);  
            printf("%s", str[0]);
            for (int f = 1; f < j; f++)
                if (strcmp(str[f], str[f - 1]) != 0) printf(" %s", str[f]);
            printf("\n");
        }
    }
    return 0;
}