#include<stdio.h>
#define N 100

typedef struct{
    int ch[N],ln;
} Bigint;

Bigint ans[501];

Bigint add(Bigint s,Bigint t){
    Bigint r;
    r.ln=0;memset(r.ch,0,sizeof(r.ch));
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
    for(int i=0;i<=n;i++){
        ans[i].ln=0;memset(ans[i].ch,0,sizeof(ans[i].ch));
    }
    for(int i=0;i<=4;i++){
        ans[i].ln=1;
        ans[i].ch[0]=i;
    }
    ans[4].ch[0]=6;
    if(n>4)ans[n]=f(n);
    for(int i=ans[n].ln-1;i>=0;i--)printf("%d",ans[n].ch[i]);
    return 0;
}