#include <stdio.h>
#include <stdlib.h>

int a[10001];
int cmpA(const void*c,const void*d){
    return *(int *)c-*(int *)d;
}
int cmpD(const void*c,const void*d){
    return *(int *)d-*(int *)c;
}

int main(){
    int i,j,temp;
    for(i=0;i<10000;i++) a[i]='\0';
    char order;
    scanf("%c",&order);
    for(i=0;(getchar())!=EOF;i++) scanf("%d",&a[i]);

    for(i=1;a[i]!='\0';i++){
        for(j=0;j<i;j++){
            if(a[j]==a[i]){
                for(temp=i+1;a[temp]!='\0';temp++) a[temp-1]=a[temp];
                a[temp-1]='\0';
            }}}
    for(i=0;a[i]!='\0';i++);
    if(order=='A') qsort(a, i, sizeof(int), cmpA);
    else if(order=='D') qsort(a, i, sizeof(int), cmpD);
    for(i=0;a[i+1]!='\0';i++) printf("%d ",a[i]);
    printf("%d",a[i]);
}