#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct T{
    char string[21];
    int count;
};

void getcount(struct T* ans)
{
    int m[26]={0};
    int temp=0;
    for(int k=0;k<strlen(ans->string);k++)
    {
        int flag=ans->string[k]-'A';
        if(m[flag]==0)
        {
            temp++;
            m[flag]++;
        }
        else{
            m[flag]++;
            continue;
        }
    }
    ans->count=temp;
    //printf("%s %d\n",ans->string,ans->count);
}

int cmp(const void* a,const void* b)
{
    struct T* p1=*(struct T**)a;
    struct T* p2=*(struct T**)b;
    if(p1->count>p2->count)
    {
        return -1;
    }
    else if(p1->count<p2->count)
    {
        return 1;
    }
    else{
        return strcmp(p1->string,p2->string);
    }
}


int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0;j<T;j++)
    {
        printf("case #%d:\n",j);
        int n;
        scanf("%d",&n);
        struct T* ans[n+1];
        for(int i=0;i<n;i++)
        {
           ans[i]=(struct T*)malloc(sizeof(struct T));
           scanf("%s",&ans[i]->string);
           getcount(ans[i]);
        }
        qsort(ans,n,sizeof(ans[0]),cmp);
        for(int i=0;i<n;i++)
        {
            printf("%s\n",ans[i]->string);
        }

    }
    return 0;
}
