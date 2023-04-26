#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    while(a--){
        long long b;
        scanf("%lld",&b);
        long long cb=b;
        int num=1;
        if(cb<2333){printf("%d\n",cb);}
        else{
        while(cb/2333){
            num++;
            cb/=2333;
        }
        int s[num];
        for(int i=0;i<num;i++){
            s[num-i-1]=b%2333;
            b/=2333;
        }
        if(num>=2){
        for(int k=0;k<num-1;k++){
         printf("%d ",s[k]);
        }
         printf("%d\n",s[num-1]);
        }
    }}
    return 0;
}