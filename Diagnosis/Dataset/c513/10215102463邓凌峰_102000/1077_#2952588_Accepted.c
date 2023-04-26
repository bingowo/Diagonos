#include <stdio.h>
#include <stdlib.h>

int m,n;
int A[501]={0};

int find(int tmp){
    for(int i=0;i<m;i++){
        if(tmp==A[i]) return i;
    }
    return -1;
}


int cmp(const void *a,const void *b){
    int pa=*(int*)a,pb=*(int*)b;
    int oa=find(pa),ob=find(pb);
    if(oa!=-1 && ob!=-1) return oa>ob?1:-1;
    else if(oa==-1 && ob==-1) return pa>pb?1:-1;
    else if(oa==-1) return 1;
    else if(ob==-1) return -1;


}

int main()
{
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&A[i]);
    }

    scanf("%d",&n);
    int B[n];
    for(int i=0;i<n;i++){
        scanf("%d",&B[i]);
    }

    qsort(B,n,sizeof(int),cmp);

    for(int i=0;i<n;i++){
        printf("%d ",B[i]);
    }
}
