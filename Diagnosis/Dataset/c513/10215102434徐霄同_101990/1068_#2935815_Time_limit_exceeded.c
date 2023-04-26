#include <stdio.h>

int main()
{
    int n,m,i,i0,t,f,x,s;
    scanf("%d%d",&n,&m);
    while(n!=-1&&m!=-1){
        if(n==31)
            x=2147483647;
        else{
            x=1;
            for(i=0;i<n;i++)
                x=x*2;
            x=x-1;
        }
        s=0;
        for(i=1;i<=x;i++){
            i0=i;
            t=0;
            f=0;
            while(i0>0){
                if(i0%2==1)
                    t++;
                else{
                    if(t>=m)
                        f=1;
                    t=0;
                }
                i0=i0/2;
            }
            if(f==1||t>=m)
                s++;
        }
        printf("%d\n",s);
        scanf("%d%d",&n,&m);
    }
    return 0;
}
