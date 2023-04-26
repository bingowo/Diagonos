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
        int r5=0,r10=0,c=n,d=n,r=1,time5=-5,time10=0;
        if(d>=5)do{
            d-=10;
            time5+=10;
            if(time5%625==0)r5+=3;
            else if(time5%125==0)r5+=2;
            else if(time5%25==0)r5+=1;


            if(d>=5)r5++;
        }while(d>=5);
        if(c>=10)do{
            c-=10;
            time10+=10;
            if(time10%50==0)r10++;
            if(time10%1000==0)r10+=3;
            else if(time10%100==0)r10+=2;
            else r10+=1;
        }while(c>=0);
        printf("%d\n",r5+r10);
    }
    return 0;
}
