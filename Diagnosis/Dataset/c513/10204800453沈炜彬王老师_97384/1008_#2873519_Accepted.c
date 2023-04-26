#include <stdio.h>

int
main()
{
    int questions;
    int result = 0;
    
    scanf("%d",&questions);
    for (int i=0; i<questions; i++)
    {
        int num1,num2;
        
        result = 0;
        scanf("%d%d",&num1,&num2);
        for (int i=0; i<32; i++)
        {
            if (((num1>>i)&1) != ((num2>>i)&1)) result++;
        }
        printf("%d\n",result);
        
    }
    
    return 0;
}