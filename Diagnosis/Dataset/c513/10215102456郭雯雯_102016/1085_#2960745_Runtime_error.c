#include<stdio.h>
#include<string.h>
#define N 500

typedef struct{ 
    int cnt,v[N]; 
} BIGINT ;

BIGINT minu(BIGINT S, BIGINT T){//两个大整数相减
    BIGINT R= {S.cnt,{0}};
    while(S.cnt!=T.cnt){
        for(int j=T.cnt-1;j>=0;j--)T.v[j+1]=T.v[j];
        for(int j=0;j<S.cnt-T.cnt;j++)T.v[j]=0;
        T.cnt=S.cnt;
    }
    for(int i=T.cnt-1;i>=0;i--){
        if(S.v[i]>=T.v[i])R.v[i]=S.v[i]-T.v[i];
        else{
            R.v[i]=S.v[i]-T.v[i]+10;
            S.v[i-1]--;
        }
    }
    while(R.v[S.cnt-1]==0) R.cnt--; //最高位0不统计在一个大整数的位数
    return R;
}

int main(){
    char m[500],n[500],z[500];
    while(scanf("%s %s",m,n)!=EOF){
        BIGINT S= {0,{0}},T= {0,{0}},R= {0,{0}};
        int l1=strlen(m),l2=strlen(n);
        if(l1<l2){printf("-");strcpy(z,n);strcpy(n,m);strcpy(m,z);}//判断大小并完成交换
        else if(l1==l2){
            for(int i=0;i<l1;i++)
                if(m[i]<n[i]){printf("-");strcpy(z,n);strcpy(n,m);strcpy(m,z);break;}
        }
        S.cnt=strlen(m);T.cnt=strlen(n);
        for(int i=0;i<S.cnt;i++)S.v[S.cnt-1-i]=m[i]-'0';
        for(int j=0;j<T.cnt;j++)T.v[T.cnt-1-j]=n[j]-'0';
        while(T.cnt<S.cnt)T.v[T.cnt++]=0;//补0
        
    

        
        
    }
    
    
}