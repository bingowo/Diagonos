#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    char name[1000009];
    char add[1000000];
}N;

int cmp(const void* a,const void* b)
{
    N x=*(N*)a;
    N y=*(N*)b;
    if(strcmp(x.add,y.add))return strcmp(x.add,y.add);
    else return strcmp(y.name,x.name);
}

int main()
{
    N *a=(N*)malloc(1000000*sizeof(N));
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int flag=0;
        int k=0;
        scanf("%s",a[i].name);
        for(int j=0;a[i].name[j]!=0;j++){
            if(flag==1)a[i].add[k++]=a[i].name[j];
            if(a[i].name[j]=='@')flag=1;
        }
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i=0;i<n;i++){
        printf("%s\n",a[i].name);
    }
    free(a);
    return 0;
}
