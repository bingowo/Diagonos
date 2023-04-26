#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        int a[1000],b[1000];
        for(int j=0;j<1000;j++){
            a[j]=-1;b[j]=-1;
        }//初始化为-1；
        int k=0;
        while(x!=0){
            a[k]=x%2;
            x=x/2;k++;
        }
        k=0;
        while(y!=0){
            b[k]=y%2;
            y=y/2;k++;
        }
        int dif=0;
        for(int j=0;j<1000;j++){
            if(a[j]!=b[j]) dif++;
        }
        printf("%d\n",dif);
    }
    return 0;
}
