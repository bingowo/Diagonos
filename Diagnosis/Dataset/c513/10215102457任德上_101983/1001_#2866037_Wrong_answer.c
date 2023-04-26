#include<stdio.h>
int main(){
    int N,R,T,a,b,i=0,p=1;
    char m[32];
    scanf("%d",&T);
    while(T>0){
        scanf("%d%d",&N,&R);
        if(N<0)N=-N,p=-1;
        else p = 1;
        do{
        a = N/R;
        b = N%R;
        if(b<10)m[i++]=b+'0';
        else
            m[i++]=b-10+'A';
        N = a;
        }while(N!=0);
        if(p==1){while(i>0)printf("%c",m[--i]);}
        else{
            printf("-");
            while(i>0)printf("%c",m[--i]);
        }
        i=0;
        T--;
    }
    return 0;
}
