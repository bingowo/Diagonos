#include <stdio.h>
#include <string.h>
#define N 100
typedef struct { char s[N+1],sx[2*N+1],sign;} T;
int cmp(const void* a, const void* b){
    T *p1=(T*)a,*p2=(T*)b;
    if(p1->sign!=p2->sign) return p2->sign - p1->sign;
    return ((p1->sign=='0')?1:-1)*strcmp(p1->sx,p2->sx);
}
void preprocess(T* p){
    char t[N+1],*s=t;strcpy(s,p->s);if(*s=='-'||*s=='+'){if(*s=='-') p->sign='1';s++;}
    if(!strchr(t,'.')) strcat(s,".");strcpy(p->sx+N-(strchr(s,'.')-s),s);

}
int main(){
    int i,n;
    T a[N];memset(a,'0',sizeof a);
    for(scanf("%d",&n),i=0;i<n;i++)preprocess((scanf("%s",a[i].s),a+i));
    qsort(a,n,sizeof *a,cmp);
    for(i=0;i<n;i++)printf("%s\n",a[i].s);
    return 0;
}