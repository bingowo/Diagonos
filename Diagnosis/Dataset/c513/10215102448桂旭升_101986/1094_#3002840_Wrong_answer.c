#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int d[121] = {0};
typedef struct {
	char sign;
    char s[121];
} SCORE;
int cmp(const void *a, const void *b){
    int lena, lenb; SCORE *pa = (SCORE *)a, *pb = (SCORE *)b;
    lena = strlen(pa -> s); lenb = strlen(pb -> s);
    if(pa -> sign != pb -> sign)return pa -> sign == 1 ? 1:-1;
    else if(pa -> sign == pb -> sign && pa -> sign == 1){
        if(lena != lenb)return lena > lenb ? 1:-1;
        else return strcmp(pa -> s, pb -> s);
    }
    else if(pa -> sign == pb -> sign && pa -> sign == -1){
        if(lena != lenb)return lena < lenb ? 1:-1;
        else return strcmp(pb -> s, pa -> s);
    }
}
void add(char s1[], char s2[]){
    int d1[121] = {0}, d2[121] = {0}, len1 = strlen(s1), len2 = strlen(s2);
    int i, j;
    j = 120;
    for(i = len1-1; i >= 0; i--){
        d1[j--] = s1[i]-'0';
    }
    j = 120;
    for(i = len2-1; i >= 0; i--){
        d2[j--] = s2[i]-'0';
    }
    for(j = 120; j >= 0; j--){
        d[j] = d1[j]+d2[j];
        d[j-1] += d[j]/10;
        d[j] %= 10;
    }
}
void reduce(char s1[], char s2[]){
    int d1[121] = {0}, d2[121] = {0}, len1 = strlen(s1), len2 = strlen(s2);
    int i, j;
    j = 120;
    for(i = len1-1; i >= 0; i--){
        d1[j--] = s1[i]-'0';
    }
    j = 120;
    for(i = len2-1; i >= 0; i--){
        d2[j--] = s2[i]-'0';
    }
    for(j = 120; j >= 0; j--){
        d[j] = d1[j]-d2[j];
        if(d[j] < 0){
            d[j-1]--; d[j] += 10;
        }
    }
}
SCORE* Input(int n)
{
    SCORE *a = (SCORE*)malloc(sizeof(SCORE)*n);
    int i, j = 0, len;
    for(i = 0; i < n; i++){
        scanf("%s", a[i].s); len = strlen(a[i].s);
        if(a[i].s[0] == '-'){
            a[i].sign = -1;
            for(i = 0; i < len; i++)a[i].s[i] = a[i].s[i+1];
        }
        else a[i].sign = 1;
    }
    return a;
}
int main(){
    int k, n, i, j = 0;
    SCORE *A = NULL; 
    scanf("%d", &n);
    A = Input(n);
    qsort(A, n, sizeof(SCORE), cmp);
    
    if(A[0].sign != A[n-1].sign){
        add(A[0].s, A[n-1].s);
        if(A[0].sign == -1)printf("-");
        while(d[j] == 0)j++;
        for(; j < 121; j++){
            printf("%d", d[j]);
        }
    }
    else{
        if(A[0].sign == -1){
            reduce(A[0].s, A[n-1].s);
        }
        else{//printf("%s %s\n", A[0].s, A[n-1].s);
            reduce(A[n-1].s, A[0].s);
        }
        while(d[j] == 0)j++;
        for(; j < 121; j++){
            printf("%d", d[j]);
        }
    }
    system("pause");
	return 0;
}