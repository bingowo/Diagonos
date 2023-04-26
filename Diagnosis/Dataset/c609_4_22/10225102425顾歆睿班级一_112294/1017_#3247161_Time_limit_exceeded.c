#include<stdio.h>
#include<stdlib.h>

int cmpa(const void* p,const void* q)
{
    return *(int*)p-*(int*)q;
}
int cmpd(const void* p,const void* q)
{
    return *(int*)q-*(int*)p;
}

int main()
{
    char order;
    scanf("%c",&order);
    int s[100],ans[100],c,cnt=0;
    while((c=getchar())!=EOF){
        for(int i=0;i<100;i++){
            scanf("%d",&s[i]);
            cnt++;
            for(int j=0;j<i;j++){
                if(s[j]==s[i])i--;//删除重复元素
                cnt--;
            }
        }
    }
    if(order=='A')qsort(s,cnt,sizeof(int),cmpa);
    else qsort(s,cnt,sizeof(int),cmpd);
    for(int i=0;i<cnt;i++)printf("%d",s[i]);
    return 0;
}

