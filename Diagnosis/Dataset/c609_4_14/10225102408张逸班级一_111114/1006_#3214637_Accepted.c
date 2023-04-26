#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    for (int i=0;i<a;i++){
        printf("case #%d:\n",i);
        char s[61];
        scanf("%s",s);
        int num[123];
        for(int i=0;i<123;i++){
            num[i]=-1;
        }
        char *p=s;
        num[*p]=1;
        int pow=0;
        while(*++p){
            if(num[*p]==-1){
                num[*p]=pow;
                pow=pow?pow+1:2;   
            }           
        }
        if(pow<2){
            pow=2;
        }
        p=s;
        long long result=0;
        while(*p){
          result=result*pow+num[*p++];
        }
        printf("%lld\n",result);
    }
    return 0;
}