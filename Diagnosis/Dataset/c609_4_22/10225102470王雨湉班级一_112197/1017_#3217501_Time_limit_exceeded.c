#include <stdio.h>
#include <stdlib.h>

int cmp1(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}

int cmp2(const void* a, const void* b)
{
    return *(int*)b-*(int*)a;
}

int main()
{
    char c;
    scanf("%c",&c);
    int s[101];
    int n=0;
    while(scanf("%d",&s[n++])!=EOF)
        ;
    n=n-1;
    int count=0;
    if(n!=1)
    {
        if(c=='A')
            qsort(s,n,sizeof(s[0]),cmp1);
        else
            qsort(s,n,sizeof(s[0]),cmp2);
        int i=1;
        while(i<n&&s[i])
        {
            if(s[i]==s[i-1])
            {
                s[i]=s[i+1];
                count++;
            }
            else
                i++;
        }
    }
    for(int z=0; z<n-count; z++)
    {
        if(z!=(n-count-1))
            printf("%d ",s[z]);
        else
            printf("%d\n",s[z]);
    }
    return 0;
}