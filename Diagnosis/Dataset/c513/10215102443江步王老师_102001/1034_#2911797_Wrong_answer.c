#include<stdio.h>
#include<stdlib.h>


int cmp(const void *_a, const void *_b);

double f[26];

int main()
{
    int T;
    int i,j;
    char ch;
    scanf("%d",&T);
    for (i=0;i<T;i++){
        char s[100];
        for (j=0;j<26;j++){//输入字母频率
            scanf("%lf",&f[j]);
        }
        getchar();
        j=0;
        while ((ch=getchar()) != EOF && ch != '\n'){//输入字符串
            s[j]=ch;
            j++;
        }
        qsort(s,j,sizeof(char),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }
    return 0;
}

int cmp(const void *_a, const void *_b)
{
    char *a = (char *)_a;
    char *b = (char *)_b;
    if (*a == *b || abs(*a-*b)==32){//两个字符相同时(区分大小写)
        if (*a == *b){
            return -1;
        }
        else if (*b < *a){
            return -1;
        }
        return 1;
    }
    else if (*a >= 'a' && *a <= 'z' && *b >= 'a' && *b <= 'z'){//都为小写
        if (f[*a-'a'] < f[*b-'a']){
            return 1;
        }
        else {
            return -1;
        }
    }
    else if (*a >= 'A' && *a <= 'Z' && *b >= 'a' && *b <= 'z'){//a为大写，b为小写
        if (f[*a-'A'] < f[*b-'a']){
            return 1;
        }
        else {
            return -1;
        }
    }
    else if (*a >= 'a' && *a <= 'z' && *b >= 'A' && *b <= 'Z'){//a为小写，b为大写
        if (f[*a-'a'] < f[*b-'A']){
            return 1;
        }
        else {
            return -1;
        }
    }
    else {//都为大写
        if (f[*a-'A'] < f[*b-'A']){
            return 1;
        }
        else {
            return -1;
        }
    }
}