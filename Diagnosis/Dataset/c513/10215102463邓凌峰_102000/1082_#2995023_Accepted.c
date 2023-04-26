#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 550
#define BigNUm 10007


typedef struct{
    int zhengshu[LEN];
    int xiaoshu[LEN];
}Num;


Num inPut(char *s){
    Num ans={0};
    char zs[LEN]={0},xs[LEN]={0};
    int i=0,cnt=0;
    for(;s[i]!='.' && s[i];i++) zs[cnt++]=s[i];
    cnt=0;
    if(strlen(zs)==0) zs[0]='0';
    for(i++;s[i];i++) xs[cnt++]=s[i];
    if(strlen(xs)==0) xs[0]='0';
    int len=strlen(zs);
    for(int k=0;k<len;k++) ans.zhengshu[LEN-len+k]=zs[k]-'0';
    for(int k=0;xs[k];k++) ans.xiaoshu[k]=xs[k]-'0';
    return ans;
}

Num add(Num A,Num B){
    Num ans={0};
    for(int i=0;i<LEN;i++){
        ans.zhengshu[i]=A.zhengshu[i]+B.zhengshu[i];
        ans.xiaoshu[i]=A.xiaoshu[i]+B.xiaoshu[i];
    }
    for(int j=LEN-1;j;j--){
        if(ans.xiaoshu[j]>9){
            ans.xiaoshu[j-1]+=ans.xiaoshu[j]/10;
            ans.xiaoshu[j]%=10;
        }
    }
    if(ans.xiaoshu[0]>9){
        ans.zhengshu[LEN-1]+=ans.xiaoshu[0]/10;
        ans.xiaoshu[0]%=10;
    }
    for(int k=LEN-1;k;k--){
        if(ans.zhengshu[k]>9){
            ans.zhengshu[k-1]+=ans.zhengshu[k]/10;
            ans.zhengshu[k]%=10;
        }
    }
    return ans;

}

Num deal(Num sum,int N){
    if(sum.xiaoshu[N]>=5) sum.xiaoshu[N-1]+=1;
    for(int i=N-1;sum.xiaoshu[i]>9;i--){
        sum.xiaoshu[i-1]+=sum.xiaoshu[i]/10;
        sum.xiaoshu[i]%=10;
    }
    if(sum.xiaoshu[0]>9){
        sum.zhengshu[LEN-1]+=sum.xiaoshu[0]/10;
        sum.xiaoshu[0]%=10;
    }
    for(int k=N;sum.zhengshu[k]>9;k--){
        sum.zhengshu[k-1]+=sum.zhengshu[k]/10;
        sum.zhengshu[k]%=10;
    }
    return sum;

}

void outPut(Num ans,int N){
    int idx=0;
    for(;ans.zhengshu[idx]==0 && idx<LEN-1;idx++);
    for(;idx<LEN;idx++) printf("%d",ans.zhengshu[idx]);
    printf(".");
    for(int k=0;k<N;k++) printf("%d",ans.xiaoshu[k]);
}


int main(){
    char a[LEN]={0},b[LEN]={0};
    int N;
    scanf("%s %s %d",a,b,&N);
    Num A=inPut(a);
    Num B=inPut(b);
    Num SUM=add(A,B);
    Num ans=deal(SUM,N);
    outPut(ans,N);








    return 0;

}
