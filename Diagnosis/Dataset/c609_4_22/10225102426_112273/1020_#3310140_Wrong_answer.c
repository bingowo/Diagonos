#include<stdio.h>
#include<string.h>

int check_number(char *a)
{
    int len,i,num = 0,check = 0;
    len = strlen(a);
    for(i = 0; i < len; i++){
        if((a[i] >= '0') && (a[i] <= '9')){
           num = num * 10 + (a[i] - '0');
           check = 1;
        }
        if(check == 0) num = -1;
    }
    return num;
}

int strnumcmp(const void *a, const void *b)
{
    int s1, s2;
    char *str1, *str2;
    str1 = (char *)a;
    str2 = (char *)b;
    s1 = check_number(str1);
    s2 = check_number(str2);
    if(s1 == s2){
        return strcmp(str1, str2);
    }
    else{
        if(s1 > s2) return 1;
        else return -1;
    }

}

int main()
{
    char str[101][31];
    int cnt = 0, i = 0;
    while(scanf("%s", &str[cnt]) != EOF){
        cnt++;
    }
    qsort(str, cnt, sizeof(str[0]), strnumcmp);
    for(i = 0; i < cnt - 1; i++){
        printf("%s ", str[i]);
    }
    printf("%s\n", str[i]);
    return 0;
}
