#include <stdio.h>
#include <string.h>

int
main()
{
    long int precise;
    int questions;
    long double result=0;
    char num[53] = {'\0'};
    long int length;
    long double weight=1.0/8;
    
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
        precise = 3*length - 6;
        
        for (long int i=length-1; i>1; i--)
        {
            if (*(num+i) == '0')    precise -= 3;
            
            else    break;
        }
        printf("case #%d:\n",i);
        printf("%.*Lf\n",precise,result);
    }
    
    return 0;
}