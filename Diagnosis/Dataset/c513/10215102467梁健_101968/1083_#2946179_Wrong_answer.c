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
        int r5=5,r10=10,res=0,c=n,d=n;
        while(c>=5){
            if(r5%625==0)res+=4;
            else if(r5%125==0)res+=3;
            else if(r5%25==0)res+=2;
            else res++;
            c-=10;
            r5+=10;
        }
        while(d>=10){
            if(r10%1000==0)res+=3;
            else if(r10%100==0)res+=2;
            else res++;
            if(r10%50==0&&r10%100!=0)res++;
            if(r10==500)res++;
            d-=10;
            r10+=10;
        }
        printf("%d\n",res);
    }
    return 0;
}
