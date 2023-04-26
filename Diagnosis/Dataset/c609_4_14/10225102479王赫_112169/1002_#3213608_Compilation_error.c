#include<stdio.h>
int len(int n){
    int fir=n%2,sec;
    int len=1,temp=1;
    do{
        n>>=1;
        sec=n%2;
        if(fir!=sec) len+=1;
        else{
            if(len>temp){temp=len;}
            len=1;
        }
        fir=sec;
    }while(n);
    if(len > temp){temp = --len;}
    return temp;
}
int main()
{
    int T;
    scanf("%d",&T);
    for( int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        printf("case #%d:%d\n",len(n[i]));
    };
    return 0;
}