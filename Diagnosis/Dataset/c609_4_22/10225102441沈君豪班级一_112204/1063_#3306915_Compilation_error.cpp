#include <stdio.h>
#include <stdlib.h>

typedef struct{
     int s[100];          //用来存储大整数
     int k;

}BIGINT;

BIGINT add(BIGINT a,BIGINT b)
{
    BIGINT x;
    int lena=a.k;
    int lenb=b.k;
    int jw=0;
    int i=0
    for(;i<lena&&i<lenb;i++){
        int m=a.s[i]+b.s[i]+jw;
        if(m>=10){
            m-=10;
            jw=1;
            x.s[i]=m;
        }else{
            jw=0;
        }
    }
    if(lena==lenb){
        if(jw!=0){
            x.s[i]=1;
            x.k=i+1;
        }else{
            x.k=i;
        }
    }else if(lena>lenb){
        for(;i<lena;i++){
            int m=a.s[i]+jw;
            if(m>=10){
               m-=10;
               jw=1;
               x.s[i]=m;
            }else{
              jw=0;
            }
        }
        if(jw!=0){
            x.s[i]=1;
            x.k=i+1;
        }else{
            x.k=i;
        }
    }else{
        for(;i<lenb;i++){
            int m=b.s[i]+jw;
            if(m>=10){
               m-=10;
               jw=1;
               x.s[i]=m;
            }else{
              jw=0;
            }
        }
        if(jw!=0){
            x.s[i]=1;
            x.k=i+1;
        }else{
            x.k=i;
        }
    
    }
}


int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        
    }
    return 0;
}
