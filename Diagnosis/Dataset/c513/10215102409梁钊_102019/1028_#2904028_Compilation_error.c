#include<stdio.h>

int* clear(int* n,int idx,int num)
{
    for(int i=0;i!=num;i++){
        n[idx+i] = n[idx+i+1] ;
    }
    return n ;
}
int acmp(int x,int y){
    return x>y ;
}

int dcmp(int x,int y){
    return x<y ;
}

int main()
{
    char t={'A'};
    scanf("%s",&t);
    getchar();
    int n[1000] ; int i=0;
    while(scanf("%d",&n[i++]) != EOF ) ;
    int len = i ;
    if(t[0]=='A') qsort(n,i,sizeof(n[0]),acmp);
    else qsort(n,i,sizeof(n[0]),dcmp);
    i = 0 ;
    while(i++!=len){
        if(n[i]==n[i+1]){
            n = clear(n,i+1,len-i-2) ;
            len-- ;
        }
    }
    for(int i=0;i!=len;i++){
        printf("%d",n[i]);
    }
}
