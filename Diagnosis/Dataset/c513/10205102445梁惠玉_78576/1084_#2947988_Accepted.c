#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int N;
        scanf("%d",&N);
        int solve=1;
        for(int j=0;j<N;j++)
        {
            solve*=2;
        }
        printf("%d\n",solve);
        
    }
    
}