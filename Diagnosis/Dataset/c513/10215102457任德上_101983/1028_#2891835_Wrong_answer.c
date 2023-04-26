#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *a,const void *b){
    int *m1,*m2;
    m1=(int *)a;
    m2=(int *)b;
    return *m2-*m1;
}
int cmp2(const void *a,const void *b){
    int *m1,*m2;
    m1=(int *)a;
    m2=(int *)b;
    return *m1-*m2;
}
int main(){
    char c,m,s[1001]={0};
    int a[100],i=0,b[100],n=0;
    scanf("%c",&c);
    m=getchar();
    while((m=getchar())!='\n'){
        ungetc(m,stdin);
        scanf("%d",&a[i++]);

    }
    for(int k=0;k<i;k++){
        if(s[a[k]]==0)b[n++]=a[k],s[a[k]]=1;
    }
    if(c=='A')qsort(b,n,sizeof(int),cmp2);
    else qsort(b,n,sizeof(int),cmp2);
    for(int i=0;i<n;i++)printf("%d ",b[i]);
    return 0;



}