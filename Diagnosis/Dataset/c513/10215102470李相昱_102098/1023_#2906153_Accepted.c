#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct {
    int num;
    char alb[31];
}str;
int cmp(const void *p1,const void *p2){
    str *a = (str *)p1;
    str *b = (str *)p2;
    if((a->num) > (b->num)){
        return 1;
    }else if((a->num) < (b->num)){
        return -1;
    }else{
        return strcmp(a->alb,b->alb);
    }
}
int main() {
    str a[110];
    int i=0;
    while(scanf("%s",a[i++].alb)!=EOF){
        int j=0;
        a[i-1].num = 0;
        for(;!(isdigit(a[i-1].alb[j]))&&j< strlen(a[i-1].alb);j++);
        if(j == strlen(a[i-1].alb)){
            a[i-1].num = -1;
        }
        while (isdigit(a[i-1].alb[j])){
            a[i-1].num = a[i-1].num *10 +  (a[i-1].alb[j] - '0');
            j++;
        }
    }
    qsort(a,i-1, sizeof(a[0]),cmp);
    for(int p=0;p<i-1;p++){
        printf("%s%c",a[p].alb,p==i-2?'\n':' ');
    }
    return 0;
}
