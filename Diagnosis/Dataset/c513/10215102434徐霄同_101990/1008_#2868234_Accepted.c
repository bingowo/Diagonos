#include <stdio.h>

int main()
{
    int t,x,y,i,j,n;
    int a[30],b[30];
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d%d",&x,&y);
        for(j=0;j<30;j++){
            a[j]=0;
            b[j]=0;
        }
        j=0;
        while(x>0){
            a[j]=x%2;
            x=x/2;
            j++;
        }
        j=0;
        while(y>0){
            b[j]=y%2;
            y=y/2;
            j++;
        }
        n=0;
        for(j=0;j<30;j++)
            if(a[j]+b[j]==1)
                n++;
        printf("%d\n",n);
    }
    return 0;
}
