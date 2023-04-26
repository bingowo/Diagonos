#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[21];
    int different;
} SSS;

int cmp(const void* p3,const void* p4)
{
    SSS* p1=(SSS* )p3;
    SSS* p2=(SSS* )p4;
    if((p1->different)<(p2->different)) return 1;
    else if((p1->different)>(p2->different)) return -1;
    else{
        int w=strcmp((p1->s),(p2->s));
        if(w<0) return -1;
        else return 1;
    }
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n=0;
        scanf("%d",&n);
        SSS* p=(SSS* )malloc(n*sizeof(SSS));
        for(int nn=0;nn<n;nn++){
            char s0[21];
            scanf("%s",s0);
            char c=s0[0];
            int diff=1;
            for(int k=1;k<strlen(s0);k++){
                c=s0[k];
                int kk=0;
                for(;kk<k;kk++) if(s0[kk]==c) break;
                if(kk==k) diff++;
            }
            strcpy((p+nn)->s,s0);
            (p+nn)->different=diff;
        }
        qsort(p,n,sizeof(SSS),cmp);
        printf("case #%d:\n",t);
        for(int j=0;j<n;j++) printf("%s\n",(p+j)->s);
        free(p);
    }
    return 0;
}
