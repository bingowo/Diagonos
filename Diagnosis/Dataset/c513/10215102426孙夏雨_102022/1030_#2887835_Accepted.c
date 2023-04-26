#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char s[20];
    int first;
} DIG;

int cmp(const void* p3,const void* p4)
{
    DIG* p1=(DIG* )p3;
    DIG* p2=(DIG* )p4;
    if ((p1->first)<(p2->first)) return 1;
    else if((p1->first)>(p2->first)) return -1;
    else{
        long long int x=atoll(p1->s),y=atoll(p2->s);
        if(x>y) return 1;
        else return -1;
    }
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n=0;
        scanf("%d",&n);
        DIG* p=(DIG* )malloc(n*sizeof(DIG));
        char s0[20];
        for(int i=0;i<n;i++){
            scanf("%s",s0);
            if(s0[0]=='-') {
                strcpy((p+i)->s,s0);
                (p+i)->first=s0[1]-'0';
            }
            else{
                strcpy((p+i)->s,s0);
                (p+i)->first=s0[0]-'0';
            }
        }
        qsort(p,n,sizeof(DIG),cmp);
        printf("case #%d:\n",t);
        for(int j=0;j<n;j++) printf("%s ",(p+j)->s);
        printf("\n");
        free(p);
    }
    return 0;
}
