#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int nm;        //不同字节数量
    char s[20];    //字符串
}data;

int cmp(const void*a,const void*b)
{
    data A=*(data*)a;
    data B=*(data*)b;
    if(A.nm!=B.nm){
        return B.nm-A.nm;
    }else{
        return strcmp(A.s,B.s);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;
        scanf("%d",&N);
        data* p=(data*)malloc(sizeof(data)*N);
        for(int j=0;j<N;j++){
            scanf("%s",p[j].s);
            int m=1;       //m用于存储字母种类   n用来决定是否m+1
            int n=0;
            for(int k=1;k<strlen(p[j].s);k++){
                for(int l=0;l<k;l++){
                    if(p[j].s[l]==p[j].s[k]){
                        n=1;
                        break;
                    }
                }
                if(n==0)
                    m++;
                n=0;
            }
            p[j].nm=m;
        }
        qsort(p,N,sizeof(data),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++){
            printf("%s\n",p[j].s);
        }
        free(p);

    }
    return 0;
}
