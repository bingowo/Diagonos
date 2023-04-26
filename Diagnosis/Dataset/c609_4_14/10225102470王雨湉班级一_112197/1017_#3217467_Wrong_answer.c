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
    do
        scanf("%d",&s[n++]);
    while(n<101&&((getchar())!=EOF));
    int count=0;
    if(n!=1)
    {
        if(c=='A')
            qsort(s,n-count,sizeof(s[0]),cmp1);
        else
            qsort(s,n-count,sizeof(s[0]),cmp2);
        int i=1;
        while(i<n&&s[i])
        {
            if(s[i]==s[i-1])
                s[i]=s[i+1];
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
