#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        printf("case #%d:\n",i);
        int j=0;
        int num,n,max=1,jmax=1;
        scanf("%d",&num);
        int m=num%2;
        if(num>=2)num/=2;
        while(num/2){
            n=num%2;
            if(m!=n){
                max++;
                if(max>jmax){
                    jmax=max;
                }
            }
            else max=1;
            m=n;
            num/=2;
        }
        if(num!=m){
            max++;
            if(max>jmax){
            jmax=max;
                }
        }
        printf("%d\n",jmax);
    }
    return 0;
}
