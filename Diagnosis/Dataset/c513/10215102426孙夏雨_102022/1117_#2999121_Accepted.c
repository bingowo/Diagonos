#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int x0=0,y0=0,min=0,x=0,y=0;
    int n=0;
    scanf("%lld %lld %d",&x0,&y0,&n);
    for(int i=0;i<n;i++){
        long long int x1=0,y1=0,jvli=0,xx=0,yy=0;
        scanf("%lld %lld",&x1,&y1);
        xx=llabs(x1-x0);
        yy=llabs(y1-y0);
        jvli= xx<yy ? yy:xx;
        if(i==0||jvli<min){
            min=jvli;
            x=x1,y=y1;
        }
        else if(jvli==min){
            if(x1<x){
                x=x1,y=y1;
            }
            else if(x1==x){
                if(y1<y){
                    x=x1,y=y1;
                }
            }
        }
    }
    printf("%lld\n%lld %lld\n",min,x,y);
    return 0;
}
