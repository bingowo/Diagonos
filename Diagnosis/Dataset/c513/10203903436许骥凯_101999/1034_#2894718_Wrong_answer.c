#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
double table[26];

int compare(const void *p1, const void *p2){
    char c1 = *(char*)p1, c2 = *(char*)p2;
    
    if (fabs(table[toupper(c1)-'A'] - table[toupper(c2)-'A']) < 1e-4) return (c1 > c2)? -1: 1;
    return (table[toupper(c1)-'A'] > table[toupper(c2)-'A'])? -1: 1;
}
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; i++){
        for (int j = 0; j != 26 && scanf("%lf", &table[j]); j++);
        getchar();
        char temp[101];
        scanf("%s", temp);
        qsort(temp, strlen(temp), sizeof(temp[0]), compare);
        printf("case #%d:\n%s\n", i, temp);
    }
    return 0;
}