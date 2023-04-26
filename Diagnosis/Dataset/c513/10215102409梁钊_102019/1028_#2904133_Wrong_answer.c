#include<stdio.h>
#include<stdlib.h>

int acmp(const void* x,const void* y){
	int* a = (int*) x ;
	int* b = (int*) y ;
    return a-b >= 0 ? 1 : -1 ;
}

int dcmp(const void* x,const void* y){
	int* a = (int*) x ;
	int* b = (int*) y ;
    return b-a >= 0 ? 1 : -1 ;
}

int main()
{
    char t[1]={'A'};
    scanf("%s",&t);
    getchar();
    int n[1000] ; int i=0;
    while(scanf("%d",&n[i++]) != EOF ) ;
    int len = i ;
    if(t[0]=='A') qsort(n,i,sizeof(n[0]),acmp);
    else qsort(n,i,sizeof(n[0]),dcmp);
    i = 0 ;
    while(i<len){
        if(n[i]==n[i+1]){
            int idx = i+1 ;
            for(int j=idx;j!=len-1;j++) n[idx+j]=n[idx+j+1] ;
            len-- ;
        }
        i++ ;
    }
    for(int i=0;i!=len;i++){
        printf("%d",n[i]);
    }
}
