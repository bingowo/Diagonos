#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct filename{
    char st1[1234];
    char st2[1234];
    char st3[1234];
    long long size;
}file[123];

int cmp1(const void* datai,const void* dataj){
    struct filename *dai=(struct filename *)datai;
    struct filename *daj=(struct filename *)dataj;
    return strcmp(dai->st3,daj->st3);
}

int cmp2(const void* datai,const void* dataj){
    struct filename *dai=(struct filename *)datai;
    struct filename *daj=(struct filename *)dataj;
    if (dai->size==daj->size) return strcmp(dai->st3,daj->st3);
    else return dai->size-daj->size;
}

int cmp3(const void* datai,const void* dataj){
    struct filename *dai=(struct filename *)datai;
    struct filename *daj=(struct filename *)dataj;
    if (strcmp(dai->st1,daj->st1)==0) {
        if (strcmp(dai->st2,daj->st2)==0) return strcmp(dai->st3,daj->st3);
        else return strcmp(dai->st2,daj->st2);
    }
    else return strcmp(dai->st1,daj->st1);
}

int main(){
    int n;
    scanf("%d",&n);
    while (n!=0){
        for (int i=1;i<=n;i++){
            scanf("%s %s %lld %s",file[i].st1,file[i].st2,&file[i].size,file[i].st3);
        }
        char check[1234];
        gets(check);
        gets(check);
        if (strcmp(check,"LIST /NAME")==0) qsort(file+1,n,sizeof(file[1]),cmp1);
        if (strcmp(check,"LIST /SIZE")==0) qsort(file+1,n,sizeof(file[1]),cmp2);
        if (strcmp(check,"LIST /TIME")==0) qsort(file+1,n,sizeof(file[1]),cmp3);
        for (int i=1;i<=n;i++){
            printf("%s %s %16lld %s\n",file[i].st1,file[i].st2,file[i].size,file[i].st3);
        }
        scanf("%d",&n);
    }
    return 0;
}
