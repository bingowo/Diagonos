#include<stdio.h>
#include <stdlib.h>
int cmp1(const void *a, void *b);
int cmp2(const void *a, void *b);
int main(){
    char T;
    scanf("%c",&T);
    int m[1000];
    int i=0;
    while(scanf("%d",&m[i])!=EOF){i++;}
    int n[1000];
    if(T=='A'){qsort(m,i+1,sizeof(int),cmp1);}
    if(T=='D'){qsort(m,i+1,sizeof(int),cmp2);}
    n[0]=m[0];
    int k=0;
    for(int j=1;j<i;j++){
        if(m[j]!=n[k]){
            n[k]=m[j];
            k++;
        }
    }
    for(int t=0;t<k;t++){
        printf("%d",n[t]);
    }
    return 0;

	}
int cmp1(const void *a, void *b){
    int m=*(int*)a;
    int n=*(int*)b;
    return m-n;
    }
int cmp2(const void *a, void *b){
    int m=*(int*)a;
    int n=*(int*)b;
    return n-m;
    }
