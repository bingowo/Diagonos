#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100
typedef struct { char s[N+1],sx[2*N+1],sign;} T;
int cmp(const void* a, const void* b){
    T *p1=(T*)a,*p2=(T*)b;
    if(p1->sign!=p2->sign) return p2->sign - p1->sign;
    else return((p1->sign!='1')?1:-1)*strcmp(p1->sx,p2->sx);
        //if(p1->sign=='1'&&p2->sign=='1') return atof(p2->sx)- atof(p1->sx);
    //else return atof(p1->sx)-atof(p2->sx);
}
void preprocess(T* p){
    char t[N+1];
    char *s=t;
    strcpy(s,p->s);
    if(*s=='-'||*s=='+'){
        if(*s=='-'||*s=='0') p->sign='1';
        s++;
    }
    if(strchr(s,'+')==0&&strchr(s,'-')==0) for(int j=0;*s!=0&&*s!='.';s++) p->sx[j++]=*s;
    else for(int j=1;*s!=0&&*s!='.';s++) p->sx[j++]=*s;

}
int main(){
    int i=0;
    int n;scanf("%d",&n);
    char c;
    c=getchar();
    T a[N];
    for(i=0;i<n;i++)preprocess((scanf("%s",a[i].s),a+i));
    qsort(a,n,sizeof *a,cmp);
    for(i=0;i<n;i++)printf("%s\n",a[i].s);
    return 0;
}
