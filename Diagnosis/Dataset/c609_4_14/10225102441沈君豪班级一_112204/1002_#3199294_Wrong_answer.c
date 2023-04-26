#include <stdio.h>

int main()
{
    int T,a,x;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&a);
        int s[100];
        int n=0;
        x=1;
        while(a/2>0){
            s[n]=a%2;
            n++;
            a=a/2;
        }
        s[n]=a%2;
        int b=1;
        for(;n>0;n--){
            if(s[n]!=s[n-1]){
                b++;
            }
            else{
                if(b>x){
                    x=b;
                    b=1;
                }else{
                    b=1;}
            }
        }
        if(b>x){
            x=b;
        }
        printf("case #%d:\n%d\n",i+1,x);

    }
    return 0;
}
