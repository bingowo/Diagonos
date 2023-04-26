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
        int r5=0,r10=0,c=n+1,d=n,r=1,time5=0,time10=0;
        while(d>5){
            d-=10;
            r5++;
        }
        while((c-10)>0){
            c-=10;
            time10+=10;
            if(time10%50==0)r10++;
            if(time10%1000==0)r10+=3;
            else if(time10%100==0)r10+=2;
            else r10+=1;
        }
        printf("%d\n",r5+r10);
    }
    return 0;
}
