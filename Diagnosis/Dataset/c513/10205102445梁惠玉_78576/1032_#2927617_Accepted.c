#include <stdio.h>
#include <stdlib.h>

struct T{
    int Nn[51];
};

int cmp(const void* a,const void* b)
{
    struct T* p1=(struct T*)a;
    struct T* p2=(struct T*)b;
    for(int i=0;i<50;i++)
    {
        if(p1->Nn[i]=='\0')
        {
            return 1;
        }
        if(p2->Nn[i]=='\0')
        {
            return -1;
        }
        if(p1->Nn[i]!='\0'&&p2->Nn[i]!='\0')
        {
            if(p1->Nn[i]>p2->Nn[i])
            {
                return -1;
            }
            else if(p1->Nn[i]<p2->Nn[i])
            {
                return 1;
            }
            else{
                continue;
            }
        }
    }
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        struct T t[N];
        for(int i=0;i<N;i++)
        {
            int j=0;
            while(1)
            {
                int temp;
                scanf("%d",&temp);
                if(temp==-1)
                {
                    t[i].Nn[j]='\0';
                    break;
                }
                else{
                    t[i].Nn[j++]=temp;
                }
            }
        }
        qsort(t,N,sizeof(t[0]),cmp);
        for(int i=0;i<N;i++)
        {
           for(int j=0;t[i].Nn[j];j++){
            printf("%d ",t[i].Nn[j]);
           }
           printf("\n");
        }
    }
    return 0;
}
