#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 70000
#define BigNUm 10007

typedef struct{
    char combine[17];
}Coms;

Coms all[70000]={0};

int contain(char tmp,char *type){
    for(int k=0;k<strlen(type);k++){
        if(tmp==type[k]) return 1;
    }
    return 0;
}

int cmp(const void*a,const void *b){
    char pa=*(char*)a,pb=*(char*)b;
    return pa>pb?1:-1;
}

int cmp2(const void*a,const void *b){
    Coms pa=*(Coms*)a,pb=*(Coms*)b;
    return strcmp(pa.combine,pb.combine)>0?1:-1;
}

int main(){
    int T;scanf("%d",&T);
    for(int I=0;I<T;I++){
        char s[17]={0};
        scanf("%s",s);
        int len=strlen(s);
        printf("case #%d:\n",I);
        char type[17]={0};
        int cnt=0;
        for(int k=0;k<len;k++){
            if(contain(s[k],type)==0) type[cnt++]=s[k];
        }
        qsort(type,cnt,sizeof(type[0]),cmp);
        int max=(1<<strlen(type))-1;
        int order=0;
        while(max){
            int tmp=max;
            int idx=0;
            int l=strlen(type);
            while(tmp){
                if(tmp%2==1){
                    all[order].combine[idx++]=type[l-1];
                }
                l--;
                tmp/=2;
            }
            qsort(all[order++].combine,idx,sizeof(char),cmp);
            max--;
        }
        qsort(all,order,sizeof(all[0]),cmp2);
        for(int k=0;k<order;k++){
            printf("%s\n",all[k].combine);
        }
        memset(all,0,sizeof(all));
    }

    return 0;
}
