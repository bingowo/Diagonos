#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count_alp(char *s){
    int count=0;
    for(int i=65; i<91; i++) 
        if(strchr(s,(char)i)) count++;
    return count;
}
int cmp1(const void *a, const void *b){
    char *s1=*(char**)a, *s2=*(char**)b;
    int num1=count_alp(s1), num2=count_alp(s2);
    if(num1!=num2) return num2-num1;
    else return strcmp(s1,s2); 
}
int main(){
    int T, N;
    scanf("%d", &T);
    char **s;
    for(int k=0; k<T; k++){
        scanf("%d", &N);
        s = (char**)malloc(sizeof(char*)*N);
        for(int i=0; i<N; i++){
            s[i] = (char*)malloc(sizeof(char)*21);
            scanf("%s", s[i]);
        }
        qsort(s,N,sizeof(s[0]),cmp1);
        printf("case #%d:\n", k);
        for(int i=0; i<N; i++) printf("%s\n", s[i]);
        for(int i=0; i<N; i++) free(s[i]);
        free(s);
    }
    return 0;
}