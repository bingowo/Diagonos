#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int T;scanf("%d",&T);
    for(int step = 0; step < T; step++){
        int n,p,m,t;
        scanf("%d %d %d %d",&n,&p,&m,&t);
        int minus=abs(p-t);
        if((m+minus)%2==1){
            printf("0\n");
            continue;
        }
        if(m==minus){
            printf("1\n");
            continue;
        }
    }
    return 0;
}
