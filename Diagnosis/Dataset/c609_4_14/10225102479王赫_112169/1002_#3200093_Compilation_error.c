#include<stdio.h>
int len(int n){
    int fir=n%2,sec;
    int len=1,temp=1;
    do{
        n>>=1;
        sec=n%2;
        if(fir!=sec) len+=1;
        else{
            if(temp>len){len=temp;}
            temp=1;
        }
        fir=sec;
    }while(n);
    if(temp > len){len = --temp;}
    return len;
    
}
int main()
{
    int T;
    scanf("%d\n",&T);
    int n[10],i=0;
    for(i=0;i<T;i++){
        scanf("%d\n",n[i]);
    };
    for(i=0;i<T;i++){
        printf("case #%d:%d\n",);
    };
    return 0;
}