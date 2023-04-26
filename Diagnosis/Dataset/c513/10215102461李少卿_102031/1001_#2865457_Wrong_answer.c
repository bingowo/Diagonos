#include<stdio.h>
int main(){
    int n,T,R;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&T,&R);
        int b,c;
        if(T<=R)printf("%d",T);
        else {
            int a[10000];
            int i=0;
            while(T>0){
            b=T/R;
            c=T%R;
            T=b;
            a[i++]=c;
            }
            for(i;i>=0;i--)printf("%d",a[i]);
        
        }
        
    }
    return 0;
    
}