#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int way[51];


long long int ways(int steps){
    //way[steps-1]=ways(steps-1);
    //way[steps-2]=ways(steps-2);
    //way[steps-3]=ways(steps-3);
    //way[steps-4]=ways(steps-4);
    //way[steps]=ways(steps-1)+ways(steps-2)+ways(steps-3)+ways(steps-4);
    if(steps<0)return way[0];
    else if(steps==1)  return way[1];
    else if(steps==2) return way[2];
    else if(steps==3) return way[3];
    else if(steps==4) return way[4];
    else return ways(steps-1)+ways(steps-2)+ways(steps-3)+ways(steps-4);;
}

int main(){
    way[0]=0;
    way[1]=1;
    way[2]=2;
    way[3]=4;
    way[4]=8;
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",t);
        printf("%lld\n",ways(n));
    }
}
