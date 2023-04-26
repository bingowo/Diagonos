#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[21];
    int kinds;
}Zmc;

int Count(Zmc zmc)
{
    int cnt=0,nums[128]={0};
    for(int i=0;i<strlen(zmc.s);i++){
        nums[zmc.s[i]]+=1;
    }
    for(int i=0;i<128;i++){
        if(nums[i]!=0){cnt++;}
    }
    return cnt;
}

int cmp(const void *a,const void *b)
{
    Zmc pa=*(Zmc*)a,pb=*(Zmc*)b;
    if(pa.kinds!=pb.kinds){return (pa.kinds>pb.kinds)?-1:1;}
    else return strcmp(pa.s,pb.s);
}


int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;scanf("%d",&n);
        Zmc zmc[n];
        for(int j=0;j<n;j++){
                scanf("%s",zmc[j].s);
                zmc[j].kinds=Count(zmc[j]);
        }
        qsort(zmc,n,sizeof(Zmc),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<n;k++){
            printf("%s\n",zmc[k].s);
        }
    }
	return 0;
}
