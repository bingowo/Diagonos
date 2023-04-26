#include <stdio.h>
#include <stdlib.h>

int* F(int* p) //化为最简分数
{
    int n=2;
    int max=1;
    int x=*p,y=*(p+1);
    if(x%y==0){
        *p=x/y;
        *(p+1)=1;
    }
    else{
        for(;n*n<=x;n++){
            if((x%n==0)&&(y%n==0)) max=n;
        }
        *p=x/max;
        *(p+1)=y/max;
    }
    return p;
}

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++){
        char c;
        int one=0,all=0;
        while((c=getchar())!='\n'){
            for(int j=0;j<8;j++){
                int k=1&c;
                if (k==1) one++;
                c=c>>1;
            }
            all+=8;
        }
        int arr[2];
        int* a2;
        arr[0]=all;
        arr[1]=one;
        a2=F(arr);
        printf("%d/%d\n",*(a2+1),*a2);
    }
    return 0;
}
