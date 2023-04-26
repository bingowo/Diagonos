#include <stdio.h>
#include <string.h>

int
main()
{
    int questions;
    double result=0;
    char num[53] = {'\0'};
    long int length;
    double weight=1.0/8;
    
    scanf("%d",&questions);
    for (int i=0; i<questions; i++)
    {
        result = 0;
        scanf("%s",num);
        length = strlen(num);
        weight = 1.0/8;
        
        for (int i=2; i<length; i++)
        {
            switch (*(num+i))
            {
                case ('0'):
                    result += 0;
                    break;
                case ('1'):
                    result += weight;
                    break;
                case ('2'):
                    result += weight*2;
                    break;
                case ('3'):
                    result += weight*3;
                    break;
                case ('4'):
                    result += weight*4;
                    break;
                case ('5'):
                    result += weight*5;
                    break;
                case ('6'):
                    result += weight*6;
                    break;
                case ('7'):
                    result += weight*7;
                    break;
            }
            weight /= 8;
        }
        printf("case #%d:\n",i);
        printf("%.*f\n",3*(length-2),result);
    }
    
    return 0;
}