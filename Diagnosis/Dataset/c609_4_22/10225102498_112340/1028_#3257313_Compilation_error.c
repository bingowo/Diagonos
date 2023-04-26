#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    long long num[51];
    int cnt;
}line;

int main()
{
    int T, N, i, j, k;
    int t;
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%d", &N);
        line ln[N];
        for(j=0; j<N; j++)
        {
            ln[j].cnt = 0;
            for(t=0; t<51; t++)
            {
                ln[j].num[t] = 0;
                scanf("%lld", &ln[j].num[t]);
                if(ln[j].num[t] == -1)
                    break;
                ln[j].cnt++;
            }
        }
        
        qsort
        
        
        
        
        
        
        
        
        
    }
    
    
    
    

    return 0;
}
