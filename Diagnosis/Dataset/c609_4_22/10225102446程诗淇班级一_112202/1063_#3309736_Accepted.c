#include <stdio.h>
#include <stdlib.h>
long long int s[51];
long long int f(int b){
    if(b>=5){
        if(s[b]==0){
            s[b]=f(b-1)+f(b-2)+f(b-3)+f(b-4);
            return s[b];
        }
        else{
            return s[b];
        }
    ;
    }
    else if(b==4){
        return 8;
    }
    else if(b==3){
        return 4;
    }
    else if(b==2){
        return 2;
    }
    else if(b==1){
        return 1;

    }


}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int a;
        long long int d=0;
        scanf("%d",&a);
        for(int k=0;k<a;k++){
            s[k]=0;
        }

        d=f(a);
        printf("case #%d:\n",i);
        printf("%lld\n",d);

    }
    return 0;
}
