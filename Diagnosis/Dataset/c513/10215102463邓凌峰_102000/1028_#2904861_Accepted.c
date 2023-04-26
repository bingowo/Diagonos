#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int panduan(int nums[],int cnt,int tmp)
{
    for(int i=0;i<cnt;i++){
        if(nums[i]==tmp) return 0;
    }
    return 1;
}


int cmpA(const void *a,const void *b)
{
    int pa=*(int *)a,pb=*(int*)b;
    return pa>pb?1:-1;
}


int cmpD(const void *a,const void *b)
{
    int pa=*(int *)a,pb=*(int*)b;
    return pa>pb?-1:1;
}


int main()
{

    char type;scanf("%c",&type);
    int nums[100],tmp,cnt=0;
    char mid;
    scanf("%d%c",&tmp,&mid);
    while(mid!='\n'){
//        printf("%d\n",tmp);
        if(cnt==0) nums[cnt++]=tmp;
        else if(panduan(nums,cnt,tmp)) nums[cnt++]=tmp;
        scanf("%d%c",&tmp,&mid);
    }
    if(panduan(nums,cnt,tmp)) nums[cnt++]=tmp;
    if(type=='A') qsort(nums,cnt,sizeof(int),cmpA);
    if(type=='D') qsort(nums,cnt,sizeof(int),cmpD);
    for(int k=0;k<cnt;k++){
        printf("%d ",nums[k]);
    }


    return 0;
}
