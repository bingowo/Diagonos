#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>

#define N 105
int a[N],r[N],sum[256];
char str[N][21];
int n;

void Init(){
    for(int i=0;i<n;i++)
        r[i]=i;
}

int Count(char* s){
    int ans=0;
    memset(sum,0,sizeof(sum));
    for(int i=0;s[i]!='\0';i++)
        sum[s[i]]++;
    for(int i='A';i<='Z';i++)
        if(sum[i]) ans++;
    return ans;
}

int Cmp(const int* pa, const int* pb){
    if(a[*pa]!=a[*pb]) return a[*pb]-a[*pa];
    return strcmp(str[*pa],str[*pb]);
}

int main(){
    int pros;
    scanf("%d",&pros);
    for(int cnt=0;cnt<pros;cnt++){
        scanf("%d",&n);
        Init();
        for(int i=0;i<n;i++){
            scanf("%s",str[i]);
            a[i]=Count(str[i]);
        }
        qsort(r,n,sizeof(r[0]),Cmp);
        printf("case #%d:\n",cnt);
        for(int i=0;i<n;i++)
            printf("%s\n",str[r[i]]);
    }


    return 0;
}
