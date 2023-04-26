#include <stdio.h>
#include <string.h>
#define N 100
typedef struct { char s[N+1],sx[2*N+1],sign;} T;
int cmp(const void* a, const void* b){
    T *p1=(T*)a,*p2=(T*)b;
    if(p1->sign!=p2->sign) return p2->sign - p1->sign;
    else if(p1->sign=='0') return strcmp(p1->sx,p2->sx);
    else return -1*strcmp(p1->sx,p2->sx);
}
void preprocess(T* p){
    char t[N+1];
    char *s=t;
    strcpy(t,p->s);
    if(*s=='-'||*s=='+'){
        if(*s=='-') p->sign='1';
        s++;
    }
    if(strchr(t,'+')||strchr(t,'-')) for(int j=1;j<strlen(t);j++){ p->sx[j]=t[j];}
    else for(int j=0;j<strlen(t);j++){ p->sx[j]=t[j];}

}
int main(){
    int i=0;
    int n;scanf("%d",&n);
    T a[N];
    memset(a,'0',sizeof *a);
    for(i=0;i<n;i++)preprocess((scanf("%s",&a[i].s),a+i));
    qsort(a,n,sizeof *a,cmp);
    for(i=0;i<n;i++)printf("%s\n",a[i].s);
    return 0;
}