#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* s1, const void* s2){
    int* p1=(int*)s1;
    int* p2=(int*)s2;
    while(*p1!=-1 && *p2!=-1 && *p1==*p2){
        p1++;p2++;
    }
    if(*p1==-1) return 1;
    if(*p1 != -1 && *p2!=-1) return *p2-*p1;
}

void solve(){
    int n,i,j;
    scanf("%d",&n);
    int data[n][51];
    for (i=0;i<n;i++){
        j=0;
        do {
            scanf("%d",&data[i][j]);
            j++;
        }
        while(data[i][j-1]!=-1);
    }
    qsort(data,n,sizeof(data[n]),cmp);
    for(i=0;i<n;i++){
        j=0;
        while(data[i][j]!=-1)
            printf("%d ",data[i][j++]);
        printf("\n");
    }
}

int main()
{   int tot;
    scanf("%d",&tot);
    for (int i=0;i<tot;i++) solve();
    return 0;
}
