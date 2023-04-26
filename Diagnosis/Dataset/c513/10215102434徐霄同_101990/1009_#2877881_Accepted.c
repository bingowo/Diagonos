#include <stdio.h>
int GCD(int m,int n)
{
    if(n==0)
        return m;
    return GCD(n,m%n);
}
int main()
{
    int n,i,x,y,y0,t;
    char c;
    scanf("%d%c",&n,&c);
    for(i=0;i<n;i++){
        x=0;
        y=0;
        c=getchar();
        while(c!='\n'){
            x=x+8;
            t=0;
            y0=0;
            if(c<0){
                t=1;
                c=-c-1;
            }
            while(c>0){
                if(c%2==1)
                    y0++;
                c=c/2;
            }
            if(t==1)
                y0=8-y0;
            y=y+y0;
            c=getchar();
        }
        printf("%d/%d\n",y/GCD(x,y),x/GCD(x,y));
    }
    return 0;
}
