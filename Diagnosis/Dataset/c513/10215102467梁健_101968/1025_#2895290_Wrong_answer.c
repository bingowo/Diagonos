#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct text{
    char t[21];
}TEXT;
int check(const void *a){
    int res=0;
    char m[128];
    for(int i=0;i<128;i++)m[i]=0;
    TEXT a1=*(TEXT*)a;
    for(int i=0;i<strlen(a1.t);i++)m[a1.t[i]]++;
    for(int i=0;i<128;i++)if(m[i]==0)res++;
    return res;
}
int cmp(const void *a,const void *b){
    TEXT m=*(TEXT*)a;
    TEXT n=*(TEXT*)b;
    int m1,m2;
    m1=check(a),m2=check(b);
    if(m1!=m2)return m1-m2;
    else return (m.t[0]>n.t[0]?1:-1);
}
int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        TEXT *a=NULL;
        int n;scanf("%d",&n);
        a=(TEXT*)malloc(sizeof(TEXT)*n);
        for(int m=0;m<n;m++)scanf("%s",a[m].t);
        qsort(a,n,sizeof(TEXT),cmp);
        for(int m=0;m<n;m++)printf("%s\n",a[m].t);
    }
    return 0;
}
