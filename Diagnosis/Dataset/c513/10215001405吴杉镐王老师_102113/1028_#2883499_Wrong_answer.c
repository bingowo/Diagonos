#include <stdio.h>
#include <stdlib.h>

int cmp1(const void* a,const void* b) //降序
{
    int m=*(int*)a;
    int n=*(int*)b;
    if(a<b) return -1;
    else return 1;
}

int cmp2(const void* a,const void* b) //升序
{
    int m=*(int*)a;
    int n=*(int*)b;
    if(a<b) return 1;
    else return -1;
}

int main()
{
    char c;
    scanf("%c",&c);
    int res[101];
    int i=0;
    for(i=0;scanf("%d",&res[i])!=EOF;i++);
    i--;
    if(c=='D')
        qsort(res,i,sizeof(res[0]),cmp1);
    else
        qsort(res,i,sizeof(res[0]),cmp2);
    int ans=res[0];
    printf("%d",ans);
    for(int j=1;res[j]!='\0';j++)
    {
        //if(res[j]==ans);
        //else
            printf(" %d",res[j]);
        //ans=res[j];
    }
    return 0;
}
