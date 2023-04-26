#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[18];
    long long value;
}STR;

int cmp1(const void* a,const void* b)
{
    char* pa=(char*)a; char* pb=(char*)b;
    return (*pa>*pb)?-1:1;
}


int cmp(const void* a,const void* b)
{
    STR* pa=(STR*)a; STR* pb=(STR*)b;
    if (pa->value>pb->value) return 1;
    if (pa->value<pb->value) return -1;
    if (pa->value==pb->value)
    {
        return strcmp(pa->s,pb->s);
    }
}

int main()
{
    int N;
    int i,j,k;
    scanf("%d",&N);
    STR* arr=(STR*)malloc(N*sizeof(STR));
    for (i=0;i<N;i++)
    {
        scanf("%s",arr[i].s);
        arr[i].value=0;
    }
    for (i=0;i<N;i++)
    {
        int vc[128]={0};
        for (k=0;k<128;k++) vc[k]=-1;
        int n=strlen(arr[i].s);
        int cnt=1; int digit=0;
        vc[arr[i].s[0]]=1;
        for (j=1;j<n;j++)
            if (arr[i].s[j]!=arr[i].s[j-1])
            {
                if (vc[arr[i].s[j]]==-1)
                {
                    vc[arr[i].s[j]]=digit;
                    digit=digit?digit+1:2;
                    cnt++;
                }
            }
        if (cnt<2) cnt=2;
        for (j=0;j<n;j++)
        {
                arr[i].value=arr[i].value*cnt+vc[arr[i].s[j]];
        }

    }
    qsort(arr,N,sizeof(STR),cmp);
    for (i=0;i<N;i++)
        printf("%s\n",arr[i].s);
    free(arr);

    return 0;
}
