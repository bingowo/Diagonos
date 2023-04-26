#include<stdio.h>
#include<string.h>

int count (int u)
{
    int r;
    if(u>0){while(u){r+=u%2;u/=2;} return r;}
    if(u=0){return 0;}
    if(u<0){ u=-u;
             u=~u;
             while(u){r+=u%2;u/=2;}
             r+=1;

            return r;}
}




int main()
{
    int T,N,Y=1000;
    int i,j,x,y,result,r,z,c;
    int s;
    int a[Y];
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        for(j=0;j<N;j++){
        scanf("%d ",&a[j]);
        //先把十进制转成二进制 算1的个数
        a[j]=int count (a[j]);

        }

        printf("case #%d:\n",i);
        printf("%d\n",a);
    }






   return 0;
}

