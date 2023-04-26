#include<stdio.h>
int main(){
    char c,m,s[1001]={0};
    int a[100],i=0,b[100],n=0;
    scanf("%c",&c);
    while((m=getchar())!=EOF){
        scanf("%d",a[i++]);

    }
     printf("%d",i);
    for(int k=0;k<i;k++){
        if(s[a[k]]==0)b[n++]=a[k],s[a[k]]=1;
    }

    for(int i=0;i<n;i++)printf("%d\n",b[i]);






}