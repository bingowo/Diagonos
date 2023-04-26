#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct {
    long long int number;
    char b[20];
}num;
int cmp(const void *p1,const void *p2){
    num * a1 = (num *)p1;
    num * b1 = (num *)p2;
    if(a1->number!=b1->number){
        return a1->number < b1->number?1:-1;
        }
    else{
        return atol(a1->b) > atol(b1->b)?1:-1;
    }
    
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;
        scanf("%d",&N);
        num a[N];
        for(int j=0;j<N;j++){
            scanf("%s",a[j].b);
            if(isdigit(a[j].b[0])){
                a[j].number = a[j].b[0]-'0';
            }else{
                a[j].number = a[j].b[1]-'0';
            }
        }
        qsort(a,N, sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int p=0;p<N;p++){
            printf("%s%c",a[p].b,p==N-1?'\n':' ');
        }
    }

    return 0;
}