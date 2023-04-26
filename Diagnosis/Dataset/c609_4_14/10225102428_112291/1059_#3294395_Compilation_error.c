#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void zheng(char s[102]){
    
    return a;
}
int cmp(const void a,const void b){
    return strcmp(a,b);
}
int main(){
    int n;
    scanf("%d",&n);
    double s[102][102];
    for(int i=0;i<n;i++){
        
        double b;
        s[i]=b;
    }    
    qsort(s,n,sizeof(double),cmp);
    for(int j=0;j<n;j++)printf("%s\n",s);
    return 0;
}