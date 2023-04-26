#include<stdio.h>
#include<string.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    int a[T][2];
    int d1[20],d2[20];
    for(int i=0;i<T;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    for(int i=0;i<T;i++){
        for(int m=0;m<20;m++){
            d1[m]=0,d2[m]=0;
        }
        int step1=0,step2=0;
        int num1=a[i][0],num2=a[i][1];
        while(num1>0){
            d1[step1++]=num1%2;
            num1/=2;
        }
        while(num2>0){
            d2[step2++]=num2%2;
            num2/=2;
        }
        int res=0;
        for(int ju=0;ju<20;ju++){
            if(d1[ju]!=d2[ju])res++;
        }
        printf("%d\n",res);
        res=0;
    }
    return 0;
}
