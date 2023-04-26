#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct {
    char s[50];
}string;
int cmp(const void *p1,const void *p2){
    string *a = (string *)p1;
    string *b = (string *)p2;
    return strcmp(a->s,b->s);
}
string a[501];
int fun1(int p,char *s1){
    int j=0;
    for(;j< strlen(s1);j++){
        if(!isalpha(s1[j])){
            strncpy(a[p].s,s1,j);
            a[p].s[j] = 0;
            break;
        }
    }
    p++;
    strcpy(a[p].s,s1+j+1);
    p++;
    return p;
}

int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s1[50];

        int p=0;
        char c;
        while(scanf("%s",s1)){
            if(strstr(s1,",")||strstr(s1,"?")||strstr(s1,"!")||strstr(s1,".")){
                p =fun1(p,s1);
            }
            else{
                strcpy(a[p].s,s1);
                p++;
            }
            c = getchar();
            if(c=='\n'){
                break;
            }
        }
        qsort(a,p,sizeof(string),cmp);
        printf("case #%d:\n",i);
        printf("%s",a[0].s);
        for(int q=1;q<p;q++){
            if(strcmp(a[q].s,a[q-1].s)!=0){
                printf("%s ",a[q].s);
            }
        }
        printf("\n");
    }
    return 0;
}
