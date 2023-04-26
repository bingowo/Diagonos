#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int value(char *a){
    int num=-1;
    for(int i=0; i<strlen(a); i++){
        if(a[i]>='0'&&a[i]<='9'){
            if(num==-1) num = (int)a[i]-48;
            else num = num*10+(int)a[i]-48;
        }
    }
    return num;
}
int strnumcmp(char *s1, char *s2){
    int num1=value(s1), num2 = value(s2);
    if(num1>num2) return 1;
    else if(num1<num2) return -1;
    else return strcmp(s1,s2);
}
int cmp(const void *a, const void *b){
    return strnumcmp(*(char**)a,*(char**)b);
}
int main(){
    char **s;
    s = (char**)malloc(sizeof(char*)*100);
    s[0] = (char*)malloc(sizeof(char)*31);
    int count=0;
    while(scanf("%s", s[count])!=EOF){
        count++;
        s[count] = (char*)malloc(sizeof(char)*31);
    }
    qsort(s,count,sizeof(s[0]),cmp);
    for(int i=0; i<count-1; i++) printf("%s ", s[i]);
    printf("%s", s[count-1]);
    for(int i=0; i<=count; i++) free(s[i]);
    free(s);
    return 0;
}