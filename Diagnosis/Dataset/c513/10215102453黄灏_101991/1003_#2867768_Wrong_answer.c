#include <stdio.h>
#include <stdlib.h>

int number(int a){
    int count=0,b=1;
    for(int j=0;j<64;j++){
        if(a&b){count++;}
        else count=count+0;
        b=(b<<1);
    }
    return count;
}

int main()
{
    int t=0,r=0;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int N;
        scanf("%d",&N);
        int a[64]={0};
        for(int e=0;e<N;e++){
            int c;//count
            int m;
            scanf("%d",&m);
            c=number(m);
            a[c]=m;
        }
        for(int E=0;E<64;E++){
            if (a[E]!=0){printf("%d",a[E]);
            a[E]=0;}
        }
    }
    return 0;
}
