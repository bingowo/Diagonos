#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void reverse(char *s){
    int lo = 0, hi = strlen(s) - 1;
    while(lo <= hi){
        char temp = s[lo];
        s[lo++] = s[hi];
        s[hi--] = temp;
    }
}

int find(char *s, char *s_t){
    char stemp[strlen(s)], s_temp[strlen(s_t)];
    strcpy(stemp, s), strcpy(s_temp, s_t);
    reverse(stemp), reverse(s_temp);
    return (strlen(stemp) - (strstr(stemp, s_temp) - stemp)) - strlen(s_temp);
}

int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        char s1[81], s2[81], s[81];
        scanf("%s%s%s", s1, s2, s);
        int lens1 = strlen(s1), lens2 = strlen(s2);
        printf("case #%d:\n", i);
        if (strstr(s, s1) == NULL || strstr(s, s2) == NULL){
            printf("0\n"); break;
        }
        int fs1 = strstr(s, s1) - s + strlen(s1) - 1;
        int fs2 = strstr(s, s2) - s + strlen(s2) - 1;

        int ls1 = find(s, s1);
        int ls2 = find(s, s2);

        if (ls1 > 10000 || ls2 > 10000){
            printf("0\n"); break;
        }

        int res1 = abs(ls1 - fs2) - 1;
        int res2 = abs(ls2 - fs1) - 1;
        int res = res1 > res2? res1: res2;
        printf("%d\n", res);
    }
    return 0;
}