#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char word[15];
    int len;
}DIC;

int cmp(const void* p3,const void* p4)
{
    DIC* p1=(DIC* )p3;
    DIC* p2=(DIC* )p4;
    if((p1->len)<(p2->len)) return 1;
    else return -1;
}

int main()
{
    int n=0;
    scanf("%d",&n);
    DIC* p=(DIC* )malloc(n*sizeof(DIC));
    char s0[15],s[5001];
    for(int t=0;t<n;t++){
        scanf("%s",s0);
        int length=strlen(s0);
        strcpy((p+t)->word,s0);
        (p+t)->len=length;
    }
    qsort(p,n,sizeof(DIC),cmp);
    scanf("%s",s);
    int i=0,len0=strlen(s);
    while(i<len0){
        int zuihou=len0;
        for(;zuihou>1;zuihou--){
            int j=0;
            for(;j<n;j++){
                if(((p+j)->len)==zuihou){
                    int k=0;
                    for(;k<zuihou;k++){
                        if(s[i+k]!=((p+j)->word[k])) break;
                    }
                    if(k==zuihou) {printf("%s ",(p+j)->word);break;}
                }
                if(((p+j)->len)<zuihou) break;
            }
        if(((p+j)->len)==zuihou) break;
        }
        if(zuihou==1) printf("%c ",s[i]);
        i+=zuihou;
    }
    free(p);
    return 0;
}
