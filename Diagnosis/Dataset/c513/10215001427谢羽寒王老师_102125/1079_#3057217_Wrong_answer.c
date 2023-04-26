#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b){
    int a1=* (int*)a;
    int b1=* (int*)b;
    return a1-b1;}






int main()
{
   int n,m,T,i,j,N,k,l,u,x,e;
   scanf("%d",&T);              // 输入问题数T
   for(i=0;i<T;i++){
    scanf("%d%d",&n,&m);               //输入 n、m
    N=n*(n+1)/2;
    int a[n],b[N];
    for(j=0;j<n;j++){                   //输入 n个数字 的数组
        scanf("%d",&a[j]);
    }


    int o=0;
    for(u=0;u<n;u++){
        for(e=0;e<(n-u);e++){
            x=a[e];
            int z;
            z=e+1;
        for(l=0;l<u;l++){
        x=x+a[z++];
                        }
                                        //求出b数组的内容(第一步
        b[o++]=x;
        }

    }

     qsort(b,N,sizeof(int),cmp);               //第二步排序 得到b


    printf("case #%d:",i);

    for(k=0;k<m;k++){
        int L,U,g,result=0;
        scanf("%d%d",&L,&U);
        g=L-1;
        while(g<U)
        {
            result+=b[g++];
        }

        printf("%d",result);
    }










   }





}