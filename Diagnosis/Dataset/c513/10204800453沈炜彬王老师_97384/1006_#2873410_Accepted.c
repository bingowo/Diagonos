#include <stdio.h>
#include <string.h>

int
main()
{
    int questions;
    int sum=0;
    int weight=1;
    
    scanf("%d",&questions);
    for (int i=0; i<questions; i++)
    {
        char str[100] = {'\0'};
        long length;
        
        sum = 0;
        weight = 1;
        scanf("%s",str);
        length = strlen(str);
        for (long i=length-1; i>-1; i--)
        {
            switch (*(str+i))
            {
                case ('-'):
                    sum += ((-1) * weight);
                    weight *= 3;
                    break;
                case ('0'):
                    sum += 0;
                    weight *= 3;
                    break;
                case ('1'):
                    sum += weight;
                    weight *= 3;
                    break;
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",sum);
    }

    return 0;
}