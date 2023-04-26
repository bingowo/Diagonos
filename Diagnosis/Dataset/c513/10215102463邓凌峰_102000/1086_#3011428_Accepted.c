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

Num sub(Num A,Num B){
    Num ans={0};
    for(int i=LEN-1;i;i--){
        ans.xiaoshu[i]=A.xiaoshu[i]-B.xiaoshu[i];
        if(ans.xiaoshu[i]<0){
            ans.xiaoshu[i]+=10;
            A.xiaoshu[i-1]-=1;
        }
    }

    ans.xiaoshu[0]=A.xiaoshu[0]-B.xiaoshu[0];
    if(ans.xiaoshu[0]<0){
            ans.xiaoshu[0]+=10;
            A.zhengshu[LEN-1]-=1;
    }

    for(int i=LEN-1;i;i--){
        ans.zhengshu[i]=A.zhengshu[i]-B.zhengshu[i];
        if(ans.zhengshu[i]<0){
            ans.zhengshu[i]+=10;
            A.zhengshu[i-1]-=1;
        }
    }

//    for(int j=LEN-1;j;j--){
//        if(ans.xiaoshu[j]>9){
//            ans.xiaoshu[j-1]+=ans.xiaoshu[j]/10;
//            ans.xiaoshu[j]%=10;
//        }
//    }
//    if(ans.xiaoshu[0]>9){
//        ans.zhengshu[LEN-1]+=ans.xiaoshu[0]/10;
//        ans.xiaoshu[0]%=10;
//    }
//    for(int k=LEN-1;k;k--){
//        if(ans.zhengshu[k]>9){
//            ans.zhengshu[k-1]+=ans.zhengshu[k]/10;
//            ans.zhengshu[k]%=10;
//        }
//    }

    return ans;

}

Num deal(Num sub,int N){
    if(sub.xiaoshu[N]>=5) sub.xiaoshu[N-1]+=1;
    for(int i=N-1;sub.xiaoshu[i]>9;i--){
        sub.xiaoshu[i-1]+=sub.xiaoshu[i]/10;
        sub.xiaoshu[i]%=10;
    }
    if(sub.xiaoshu[0]>9){
        sub.zhengshu[LEN-1]+=sub.xiaoshu[0]/10;
        sub.xiaoshu[0]%=10;
    }
    for(int k=N;sub.zhengshu[k]>9;k--){
        sub.zhengshu[k-1]+=sub.zhengshu[k]/10;
        sub.zhengshu[k]%=10;
    }
    return sub;

}

void outPut(Num ans,int N){
    int idx=0;
    for(;ans.zhengshu[idx]==0 && idx<LEN-1;idx++);
    for(;idx<LEN;idx++) printf("%d",ans.zhengshu[idx]);
    printf(".");
    for(int k=0;k<N;k++) printf("%d",ans.xiaoshu[k]);
}


int compare(Num A,Num B){
    int idx=0;
    for(;idx<LEN;idx++){
        if(A.zhengshu[idx]>B.zhengshu[idx]){
            return 1;
        }
        else if(A.zhengshu[idx]<B.zhengshu[idx]){
            return -1;
        }
    }
    idx=0;
    for(;idx<LEN;idx++){
        if(A.xiaoshu[idx]>B.xiaoshu[idx]){
            return 1;
        }
        else if(A.xiaoshu[idx]<B.xiaoshu[idx]){
            return -1;
        }
    }
    return 0;
}

int main(){
    char a[LEN]={0},b[LEN]={0};
    int N;
    scanf("%s %s %d",a,b,&N);
    Num A=inPut(a);
    Num B=inPut(b);
    if(compare(A,B)==0){
        Num ans={0};
        outPut(ans,N);
    }
    else if(compare(A,B)==1){
        Num SUB=sub(A,B);
        Num ans=deal(SUB,N);
        outPut(ans,N);
    }
    else if(compare(A,B)==-1){
        Num SUB=sub(B,A);
        Num ans=deal(SUB,N);
        printf("-");
        outPut(ans,N);
    }

    return 0;

}
