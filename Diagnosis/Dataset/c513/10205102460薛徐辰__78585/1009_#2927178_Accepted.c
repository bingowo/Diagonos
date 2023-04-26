#include<stdio.h>

void geta(char* s,int i){
    int a=0,y=i*8,x,z=1;
    for(int j=0;j<i;j++){
        x=s[j];
        for(int m=0;m<8;m++){
         a+=(x&1);
         x=x>>1;
        }
    }
    for(int m=1;m<=a;m++){
        if(a%m==0&&y%m==0)z=m;
    }
    a=a/z;y=y/z;
    printf("%d/%d\n",a,y);
}

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        char s[400];int i;
        for(i=0;(s[i]=getchar())!='\n';i++);
        geta(s,i);
        
    }
    return 0;
}