#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct T{
    char s[31];
    int n;//string number
};
int cmp(const void * a, const void * b);
void input(char s[],struct T t[],int n);
int main() {
    struct T t[100];
    char str[31];

    int n = 0;
    char c;
    while(scanf("%s",&str) != EOF){
        input(str,t,n);
        n++;
    }
    qsort(t,n,sizeof(struct T),cmp);
    for(int i = 0;i < n;i++){
        printf("%s ",t[i].s);
    }
	return 0;
}
int cmp(const void * a, const void * b){
    int n1 = ((struct T *)a) -> n;
    int n2 = ((struct T *)b) -> n;
    char s1[31];
    char s2[31];
    strcpy(s1,((struct T *)a) -> s);
    strcpy(s1,((struct T *)a) -> s);
    if(n1 != n2) return n1 - n2;
    else return strcmp(s1,s2);
}

void input(char s[],struct T t[],int n){
    strcpy(t[n].s,s);
    char num[9];
    int nn = 0;
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] >= '0' && s[i] <= '9') {num[nn] = s[i];nn++;}
        i++;
    }
    if(nn == 1 && num[0] == '0') t[n].n = 0;
    else{
        int number = atoi(num);
        if(number == 0) t[n].n = -1;
        else t[n].n = number;
    }
}
