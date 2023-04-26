#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[21];
    int varych;
} string;
int cmp(const void *a,const void *b)
{
    string *pa,*pb;
    pa = (string*)a;
    pb = (string*)b;
    if(pa->varych != pb->varych) return pb->varych-pa->varych;
    else return strcmp(pa->s,pb->s);
}
int main()
{
    int T,cnt = 0;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        string L[n];
        for(int i=0;i<n;i++){
            char tmps[21];
            scanf("%s",tmps);
            strcpy(L[i].s,tmps);
            L[i].varych = 0;
            int l = strlen(tmps);
            for(int j=0;j<l-1;j++){
                int flag = 1;
                for(int k=j+1;k<l;k++){
                    if(tmps[k] == tmps[j]){
                        flag = 0;
                        break;
                    }
                }
                if(flag) L[i].varych++;
            }
        }
        qsort(L,n,sizeof(string),cmp);
        printf("case #%d:\n",cnt++);
        for(int i=0;i<n;i++) printf("%s\n",L[i].s);
    }
    return 0;
}
