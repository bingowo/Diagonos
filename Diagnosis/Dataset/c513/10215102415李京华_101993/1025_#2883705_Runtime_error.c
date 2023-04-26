#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int difNum(char *a){
    int flag[128] = {0};
    int ret = 0;
    for (int i = 0; i < strlen(a); i++){
        if (!flag[a[i]]){   //第一次出现
            flag[a[i]] == 1;
            ret++;
        }
    }
    return ret;
}

int cmp(const void *_a, const void *_b){
    char *a = (char *)_a;
    char *b = (char *)_b;
    int anum = difNum(a);
    int bnum = difNum(b);
    if (anum != bnum)
        return bnum - anum;
    return strcmp(a, b);
}

int main(){
    int t, T;
    scanf("%d", &T);
    for (t = 0; t < T; t++){
        int n;
        scanf("%d", &n);
        char a[n];

        int i;
        for (i = 0; i < n; i++)
            scanf("%s", a[i]);
        
        qsort(a, n, sizeof(a[0]), cmp);

        //输出
        printf("case #%d:\n", t);
        for (i = 0; i < n; i++)
            printf("%s\n", a[i]);
    }
    return 0;
}