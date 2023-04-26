#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d %d",&a,&b);
        char s[100];
        int n=0;
        int k=0;
        if(a<0){
            a = -a;
            k+=1;
        }
        while(a/b>0){
            if(a%b<10){
               s[n]=a%b+48;
               n++;
               a=a/b;}
            else{
               s[n]=a%b-10+65;
               n++;
               a=a/b;
            }
        }
        if(a%b<10){
               s[n]=a%b+48;
               }
        else{
            s[n]=a%b-10+65;
            }
        if(k==1){
            printf("-");
        }
        for(;n>=0;n--){
            printf("%c",s[n]);
        }
    }

    return 0;
}
