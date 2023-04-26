#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number(char *str){
    int a[26] = {0};
    for(int i = 0;i < strlen(str);i++){
        a[str[i] - 'A']++;
    }
    int num = 0;
    for(int i = 0;i < 26;i++){
        if(a[i] != 0)num++;
    }
    return num;
}

int cmp(const void *a,const void *b){
    char *a1,*b1;
    a1 = (char*)a;
    b1 = (char*)b;
    int a2 = number(a1),b2 = number(b1);
    if(a2 == b2)return strcmp(a1,b1);
    else{
        return b2 - a2;
    }
}


int main()
{
    int T;
    scanf("%d",&T);
    int n;
    char s[100][21];
    for(int i = 0;i < T;i++){
        scanf("%d",&n);
        for(int j = 0;j < n;j++){
            scanf("%s",s[j]);
        }
        qsort(s,n,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int j = 0;j < n;j++){
            printf("%s\n",s[j]);
        }
    }
    return 0;
}
