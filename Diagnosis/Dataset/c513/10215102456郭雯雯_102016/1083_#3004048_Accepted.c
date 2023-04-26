#include<stdio.h>
#include<string.h>

typedef struct{ 
    int cnt,v[3000],num; 
} BIGINT ;

BIGINT int2BIG(int x){//int 转换成BIGINT
    BIGINT R= {0,{0},0};
    do{
        R.v[R.cnt++]=x%10;
        x/=10;
    } while (x>0);
    return R;
}

BIGINT mul(BIGINT S, BIGINT T){//两个大整数相乘
    BIGINT R= {S.cnt+T.cnt,{0},0};
    for (int i=0; i<T.cnt; i++)
    {
        int t,k,j;
        int carry=0;
        for (j=0; j<S.cnt; j++)
        {
            t=S.v[j]*T.v[i]+carry+R.v[i+j];
            R.v[i+j]=t%10;
            carry=t/10;
        }
        k=i+j;
        while (carry>0)
        {
            t=carry+R.v[k];
            R.v[k]=t%10;
            carry=t/10;
            k++;
        }
    }
    if (R.v[S.cnt+T.cnt-1]==0) R.cnt--; //最高位0不统计在一个大整数的位数中
    int j=0;
    while(R.v[j]==0)j++;
    R.num=j;
    return R;
}

int main(){
    int t,a=0;
    scanf("%d",&t);
    BIGINT g[1001];
    for(int i=0;i<1001;i++){
        memset(g[i].v,0,sizeof(g[i].v));
        g[i].num=0;g[i].cnt=0;
    }
    g[1].v[0]=1;g[1].num=0;g[1].cnt=1;
    for(int i=2;i<1001;i++)g[i]=mul(g[i-1],int2BIG(i));
    while(a<t){
        int n;
        scanf("%d",&n);
        printf("case #%d:\n%d\n",a,g[n].num);
        a++;
    }
}