#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char s[20];
}string;
int cmp(const void *p1,const void *p2){
    char a= *(char *)p1;
    char b= *(char *)p2;
    return a-b;
}
int cmp1(const void *p1,const void *p2){
    string *a= (string *)p1;
    string *b = (string *)p2;
    int i =0;
    while (a->s[i++]==b->s[i++]);
    return a->s[i] - b->s[i];
}
int main() {
    int T;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++){
        char s[20];
        char a[26];
        scanf("%s",s);
        qsort(s, strlen(s), sizeof(char),cmp);
        a[0] = s[0];
        int p=1;
        for(int j=1;j< strlen(s);j++){
            if(s[j]!=s[j-1]){
                a[p++] =s[j];
            }
        }
        a[p] = 0;
        string b[150]={0};
        int i=0;
        for(int d=1;d<= strlen(a);d++){
            for(int q=0;q< strlen(a)-d+1;q++){
                int m =0;
                for(;m<d;m++){
                    b[i].s[m] = a[q+m];
                }
                b[i].s[m] = 0;
                i++;
            }
        }
        qsort(b, strlen(s)*(strlen(s)+1)/2,sizeof(string),cmp1);
        printf("case #%d:\n",i);
        for(int m=0;m< i;m++){
            printf("%s\n",b[m].s);
        }
    }

    return 0;
}
