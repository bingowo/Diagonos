#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char c;
    int cnt;
}pair;

#define N 100000
pair f[N][101];

int stat(char *s, pair *r){
    int rcnt=0,cnt=0;char prev;
    for(prev=*s++;*s;cnt++,prev=*s++)
        if(*s!=prev)
            r[rcnt].c=prev,r[rcnt++].cnt=cnt,cnt=0;
    r[rcnt].c=prev,r[rcnt++].cnt=cnt;
    return rcnt;
}

int allSameLength_Char(pair (*f)[101],int n, int *fn){
    int i,j;
    for(i=1;i<n;i++)
        if(fn[i]!=fn[0])
            return 0;
    for(i=0;i<fn[0];i++)
        for(j=1;j<n;j++)
            if(f[j][i].c!=f[0][i].c)
                return 0;
    return 1;
}

int cmp(const void *a, const void *b){
    return *(int *)a-*(int *)b;
}

int main(){
    int n,ans=0,fn[N],a[N],i,j;
    char s[101];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",s);
        fn[i]= stat(s,f[i]);
    }
    if(allSameLength_Char(f,n,fn)){
        for(i=0;i<fn[0];i++){
            for(j=0;j<n;j++)
                a[j]=f[j][i].cnt;
            qsort(a,n,sizeof (a[0]),cmp);
            for(j=0;j<n;j++)
                ans+=abs(a[j]-a[n/2]);
        }
        printf("%d\n",ans);
    } else
        printf("-1\n");
    return 0;
}