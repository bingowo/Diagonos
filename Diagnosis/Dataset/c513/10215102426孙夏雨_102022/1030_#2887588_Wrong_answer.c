#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[20];
    int first;
} DIG;

int cmp(const void* p3,const void* p4)
{
    DIG* p1=(DIG* )p3;
    DIG* p2=(DIG* )p4;
    int x=1,y=1,len1=strlen(p1->s),len2=strlen(p2->s);
    if((p1->s[0])=='-') x=-1;
    if((p2->s[0])=='-') y=-1;
    if ((p1->first)<(p2->first)) return 1;
    else if((p1->first)>(p2->first)) return -1;
    else{
        if (x+y==2){
            if(len1>len2) return 1;
            else if(len1<len2) return -1;
            else{
                for(int i=1;i<len1;i++){
                    if ((p1->s[i])-(p2->s[i])>0) return 1;
                }
                return -1;
            }
        }
        else if(x+y==-2){
            if(len1>len2) return -1;
            else if(len1<len2) return 1;
            else{
                for(int i=2;i<len1;i++){
                    if ((p1->s[i])-(p2->s[i])>0) return -1;
                }
                return 1;
            }
        }
        else{
            if(x<y) return -1;
            else return 1;
        }
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
