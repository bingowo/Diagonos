#include<stdio.h>
#include<stdlib.h>

int cmpA(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}
int cmpD(const void* a, const void* b)
{
    return *(int*)b-*(int*)a;
}

int main()
{
    char a;
    scanf("%c",&a);
    int input[1000],cnt=0,i=0,j,res[1000];
    while (scanf("%d",&input[i])!=EOF)
    {
        int flag=0;
        for(j=0;j<i;j++)
        {
            if(input[j]==input[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0) res[cnt++]=input[i];
        i++;
    }
    if(a=='A') qsort(res,cnt,sizeof(res[0]),cmpA);
    else qsort(res,cnt,sizeof(res[0]),cmpD);
    for(i=0;i<cnt;i++) i==cnt-1 ? printf("%d",res[i]) : printf("%d ",res[i]);
    return 0;
}