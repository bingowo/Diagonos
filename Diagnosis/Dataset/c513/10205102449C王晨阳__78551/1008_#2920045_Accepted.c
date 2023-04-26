#include<stdio.h>
int f(int x,int y);
int main()
{
    int t,x,y,a;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d %d\n",&x,&y);
        printf("%d\n",f(x,y));
    }
    return 0;
}
int f(int x,int y){
    int a[1000]={0},b[1000]={0},i,m=0;
    i=0;
    while(x>0){
        a[i++]=x%2;
        x=x/2;
    }
    i=0;
    while(y>0){
        b[i++]=y%2;
        y=y/2;
    }
    for(i=0;i<1000;i++){
        if(a[i]!=b[i]){
            m++;
        }
    }    
    return m;
}