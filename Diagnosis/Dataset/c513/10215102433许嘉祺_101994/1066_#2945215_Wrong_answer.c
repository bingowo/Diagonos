#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int n,p,m,t;
int find(floor,time){
    if (time<abs(floor-t)||floor>t) return 0;
    else if (time==abs(floor-t)) return 1;
    else if (floor==1) return find(2,time-1);
    else if (floor==n) return find(n-1,time-1);
    else return find(floor-1,time-1)+find(floor+1,time-1);
}
int main()
{

    int cas;
    scanf("%d",&cas);
    for(int i=0;i<cas;i++){

        scanf("%d%d%d%d",&n,&p,&m,&t);
        
        printf("%d\n",find(p,m));

    }
    return 0;
}
