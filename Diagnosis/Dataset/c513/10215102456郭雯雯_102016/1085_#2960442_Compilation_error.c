#include<stdio.h>
#include<string.h>
#define N 500

typedef struct{ 
    int cnt,v[N]; 
} BIGINT ;

int equal(BIGINT S, BIGINT T){//判断是否相同
    if(S.cnt!=T.cnt)return 0;
    for(int i=0;i<max(S,T).cnt;i++)
        if(S.v[i]!=T.v[i])return 0;
    return 1;
}

BIGINT max(BIGINT S, BIGINT T){//输出较大的
    if(S.cnt>T.cnt)return S;
    if(S.cnt<T.cnt)return T;
    for(int i=0;i<S.cnt;i++){
        if(S.v[i]>T.v[i]){
            return S;break;
        }
        else if(S.v[i]<T.v[i]){
            return T;break;
        }
    }
}

BIGINT min(BIGINT S, BIGINT T){//输出较小的
    if(S.cnt>T.cnt)return T;
    if(S.cnt<T.cnt)return S;
    for(int i=0;i<S.cnt;i++){
        if(S.v[i]>T.v[i]){
            return T;break;
        }
        else if(S.v[i]<T.v[i]){
            return S;break;
        }
    }
}

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
    char m[1010];
    gets(m);
    BIGINT S= {0,{0}},T= {0,{0}},R= {0,{0}};
    int l=strlen(m),i;
    for(i=0;i<l&&m[i]!=' ';i++){
        S.v[i]=m[i]-'0';S.cnt++;
    }
    i++;
    for(;i<l;i++){
        T.v[T.cnt++]=m[i]-'0';
    }
    R=minu(max(S,T),min(S,T));
    if(equal(max(S,T),S)==0)printf("-");
    for(int i=R.cnt-1;i>=0;i--)printf("%d",R.v[i]);
    printf("\n");
    
    
}