#include <stdio.h>

int
main()
{
    int questions;
    
    scanf("%d",&questions);
    for (int i=0; i<questions; i++)
    {
        int num;
        int final_length = 0;
        int temp_length = 1;
        int count=0;
        
        scanf("%d",&num);
        int num_temp = num;
        while (num_temp>0)
        {
            count++;
            num_temp /= 2;
        }
        
        for (int i=1; i<count; i++)
        {
            if (((num>>i)&1) == ((num>>(i-1))&1 ))
            {
                final_length = temp_length>final_length?temp_length:final_length;
                temp_length = 1;
            }
            else temp_length++;
        }
        final_length = temp_length>final_length?temp_length:final_length;
        printf("case #%d:\n",i);
        printf("%d\n",final_length);
    }
    
    return 0;
}