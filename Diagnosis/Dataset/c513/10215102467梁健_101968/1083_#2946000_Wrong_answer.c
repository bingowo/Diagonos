#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int n;scanf("%d",&n);
        int r5=n/10,r10=0,c=n+1,r=1,time=0;
        while(c-10>0){
            c-=10;
            time+=10;
            if(time%1000==0)r10+=3;
            else if(time%100==0)r10+=2;
            else r10+=1;
        }
        printf("%d\n",r5+r10);
    }
    return 0;
}
