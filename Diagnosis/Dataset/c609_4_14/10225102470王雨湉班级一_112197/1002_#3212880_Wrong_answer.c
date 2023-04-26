#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        int n,s[50],j=0,count=1;
        scanf("%d",&n);
        while(n>0)
        {
            s[j++]=n%2;
            n/=2;
        }
        while(j>1)
        {
            if(s[j-1]!=s[j-2])
                count++;
            else
                count=1;
            j--;
        }
        printf("case #%d:\n%d\n",i,count);
    }
    return 0;
}
