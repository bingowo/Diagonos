#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char l[21];
    int num;
    int alb[26];
}con;
int cmp(const void *p1,const void *p2){
    con *a= (con*)p1;
    con *b= (con*)p2;
    if(a->num < b->num){
        return 1;
    }else if(a->num > b->num){
        return -1;
    }else{
        return strcmp(a->l,b->l);
    }
}
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        con a[n];
        for(int j=0;j<n;j++){
            a[j].num =0;
            for(int q=0;q<26;q++){
                a[j].alb[q] = 0;
            }
            scanf("%s",a[j].l);
            for(int p=0;p< strlen(a[j].l);p++){
                if(a[j].alb[p]==0){
                    a[j].alb[p]=1;
                    a[j].num ++;
                }
            }
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int c=0;c<n;c++){
            printf("%s\n",a[c].l);
        }
    }
    return 0;
}
