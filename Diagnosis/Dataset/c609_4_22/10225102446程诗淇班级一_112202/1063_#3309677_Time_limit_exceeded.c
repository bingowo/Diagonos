#include <stdio.h>
#include <stdlib.h>

int f(int b){
    if(b>=5){
        return f(b-1)+2*f(b-2)+4*f(b-3)+8*f(b-4);
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

        d=f(a);
        printf("case #%d:\n",i);
        printf("%lld\n",d);

    }
    return 0;
}
