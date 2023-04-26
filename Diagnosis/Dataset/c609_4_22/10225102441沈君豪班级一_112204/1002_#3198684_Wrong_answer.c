#include <stdio.h>

int main()
{
    int T,a,max=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&a);
        int s[100];
        int n=0;
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
                if(b>max){
                    max=b;
                }else{
                    b=1;}
            }
        }
        printf("case #%d:\n%d\n",i+1,max);

    }
    return 0;
}
