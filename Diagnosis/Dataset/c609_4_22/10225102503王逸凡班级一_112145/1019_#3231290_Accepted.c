#include <stdio.h>
#include <stdlib.h>

int cmp (const void *a,const void *b){
    int p = *(int *)a;
    int q = *(int *)b;
    int w1=0,w2=0;
    if (p<0){
        p=-p;
    }
    if (q<0){
        q=-q;
    }
    do{
        p/=10;
        w1++;
    }while(p>0);
    do{
        q/=10;
        w2++;
    }while(q>0);
    if (w1>w2){
        return -1;
    }else if(w1<w2){
        return 1;
    }else{
        return (*(int*)a)-(*(int*)b);
    }

}
int a[50000000];
int main()
{

    int i=0;
    while(scanf("%d",&a[i])!=EOF){
        i++;
    }
    qsort(a,i,sizeof(int),cmp);
    int j=0;
    for(j=0;j<i;j++){
        printf("%d ",a[j]);
    }
    return 0;
}
