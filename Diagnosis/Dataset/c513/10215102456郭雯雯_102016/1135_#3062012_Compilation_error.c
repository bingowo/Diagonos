#include<stdio.h>
#define N 100

typedef struct{
    int ch[N],ln;
} Bigint;

Bigint ans[501];

Bigint add(Bigint s,Bigint t){
    Bigint r={{0},0};
    int min,mal;
    if(s.ln>=t.ln){
        mal=s.ln;min=t.ln;
    }
    else{
        Bigint a;
        mal=t.ln;min=s.ln;
        a=s;s=t;t=a;
    }
    r.ln=mal;
    for(int i=0;i<min;i++){
        r.ch[i]=s.ch[i]+t.ch[i];
        r.ch[i+1]+=r.ch[i]/10;
        r.ch[i]%=10;
    }
    for(int i=min;i<mal;i++){
        r.ch[i]+=s.ch[i];
        r.ch[i+1]+=r.ch[i]/10;
        r.ch[i]%=10;
    }
    if(r.ch[mal]>0)r.ln++;
    return r;
}

Bigint f(int n){
    if(ans[n].ln!=0)return ans[n];
    else if(ans[n].ln==0){
        Bigint t=add(f(n-1),f(n-2));
        ans[n]=add(t,f(n-4));
        return ans[n];
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i++)ans[i]={{0},0};
    ans[0]={{0},1};ans[1]={{1},1};ans[2]={{2},1};ans[3]={{3},1};ans[4]={{6},1};
    if(n>4)ans[n]=f(n);
    for(int i=0;i<ans[n].ln;i++)printf("%d",ans[n].ch[i]);
    return 0;
}