#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>

typedef long long ll;
typedef unsigned long long ull;

#define N 1005
#define M 55
int a[N][M],r[N];
int n;

void Init(){
    for(int i=0;i<n;i++) r[i]=i;
}

int Cmp(const int* pa, const int* pb){
    static int i;
    for(i=0;a[*pa][i]>=0&&a[*pb][i]>=0;i++)
        if(a[*pa][i]!=a[*pb][i])
            return a[*pb][i]-a[*pa][i];
    return a[*pb][i]-a[*pa][i];
}

int main(){
    int pros;
    scanf("%d",&pros);
    for(int cnt=0;cnt<pros;cnt++){
        scanf("%d",&n);
        Init();
        for(int i=0,j;i<n;i++){
            j=0;
            for(scanf("%d",a[i]+j);
                    a[i][j]>=0;
                    scanf("%d",a[i]+j))
                j++;
        }
        qsort(r,n,sizeof(r[0]),Cmp);
        for(int i=0;i<n;i++){
            for(int j=0;a[r[i]][j]>=0;j++){
                if(j) printf(" ");
                printf("%d",a[r[i]][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
