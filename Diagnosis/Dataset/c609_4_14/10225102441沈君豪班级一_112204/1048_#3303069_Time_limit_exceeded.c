#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int s[100];
    int k;     //位数
}BIGINT;


BIGINT add(BIGINT a,BIGINT b)
{
    BIGINT x;
    int len1=a.k;
    int len2=b.k;
    int jw=0;         //进位
    int i;
    for(i=0;i<len1&&i<len2;i++){
        x.s[i]=a.s[i]+b.s[i]+jw;
        if(x.s[i]>10){
            x.s[i]-=10;
            jw=1;
        }else{
            jw=0;
        }
    }
    if(len1==len2){
        if(jw!=0){
            x.s[i]=jw;
            x.k=i+1;
        }else{
            x.k=i;
        }
        return x;
    }else{
        if(len1>len2){
            for(;i<len1;i++){
                x.s[i]=a.s[i]+jw;
                if(x.s[i]>10){
                    x.s[i]-=10;
                    jw=1;
                }else{
                    jw=0;
                }
            }
            if(jw==1){
                x.s[i]=1;
                x.k=i+1;
            }else
                x.k=i;
            return x;
        }else{
            for(;i<len2;i++){
                x.s[i]=b.s[i]+jw;
                if(x.s[i]>10){
                    x.s[i]-=10;
                    jw=1;
                }else{
                    jw=0;
                }
            }
            if(jw==1){
                x.s[i]=1;
                x.k=i+1;
            }else
                x.k=i;
            return x;
        }
    }
}

BIGINT f(int x)
{
    if(x==1){
        BIGINT h;
        h.s[0]=1;
        h.k=1;
        return h;
    }else if(x==0){
        BIGINT h;
        h.s[0]=0;
        h.k=1;
        return h;
    }else{
        return add(f(x-1),f(x-2));
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        BIGINT GG=f(n);
        printf("case #%d:\n",i);
        for(int j=GG.k-1;j>=0;j--){
            printf("%d",GG.s[j]);
        }
        printf("\n");
    }

    return 0;
}
