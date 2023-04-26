#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef long long ll;
typedef unsigned long long ull;

int n,m,n2;
int a[1005];
ll sa[1005];
ll b[500505],sb[500505];

void InputA(){
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
}

int Cmp(const int* pa,const int* pb){return *pa-*pb;}

void Fun(){
    n2=1;
    for(int i=1;i<=n;i++)
        sa[i]=sa[i-1]+a[i];
    for(int i=0;i<n;i++)
        for(int j=i+1;j<=n;j++)
                b[n2++]=sa[j]-sa[i];
    n2--;
    qsort(b+1,n2,sizeof(int),Cmp);
    for(int i=1;i<=n2;i++)
        sb[i]=sb[i-1]+b[i];
}

int main(){
    int pros,l,r;
    scanf("%d",&pros);
    for(int cnt=0;cnt<pros;cnt++){
        printf("case #%d:\n",cnt);
        scanf("%d%d",&n,&m);
        InputA();
        Fun();
        while(m--){
            scanf("%d%d",&l,&r);
            printf("%lld\n",sb[r]-sb[l-1]);
        }
    }

    return 0;
}

