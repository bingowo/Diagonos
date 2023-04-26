#include <stdio.h>
#include <string.h>

int
main()
{
    int questions;
    
    scanf("%d",&questions);
    
    for (int i=0; i<questions; i++)
    {
        int N=0;
        int judge[123] = {0};
        int value[123] = {-1};
        char str[60] = {'\0'};
        long length;
        int val;
        long long int min_sum=0;
        long long weight = 1;
        int count = 0;
        
        scanf("%s",str);
        length = strlen(str);
        
        for (int i=0; i<123; i++)
        {
            value[i] = -1;
        }
        for (int i=0; i<length; i++)
        {
            if ( *(judge + *(str+i)) == 0)
            {
                N++;
                *(judge + *(str+i)) = 1;
            }
        }
        if (N<2) N=2;
        
        *(value + *(str+0)) = 1;
        val = 0;
        for (int i=0; i<length; i++)
        {
            if (*(value + *(str+i)) == -1)
            {
                *(value + *(str+i)) = val;
                val++;
                count++;
                if (count==1) val++;
            }
        }
        for (long i=length-1; i>-1; i--)
        {
            min_sum += *(value + *(str+i)) * weight;
            
            weight *= N;
        }
        printf("case #%d:\n",i);
        printf("%lld\n",min_sum);
        
        
    }
    
    
    
    return 0;
}