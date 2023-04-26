#include <stdio.h>
#include <string.h>
int
main()
{
    char num[31] = {'\0'};
    int length;
    int dot_pos = -1;
    long long int weight = 1;
    long long int A=0;
    long long int B=0,C=0;
    
    scanf("%s",num);
    length = strlen(num);
    for (int i=0; i<length; i++)
    {
        if (*(num+i)=='.')
        {
            dot_pos = i;
        }
    }
    if (dot_pos==-1)
    {
        for (int i=length-1; i>-1; i--)
        {
            switch (*(num+i))
            {
                case ('0'):
                    A += 0;
                    break;
                case ('1'):
                    A += weight;
                    break;
                case ('2'):
                    A += (weight*-1);
                    break;
            }
            weight *= 3;
        }
        printf("%lld\n",A);
    }
    else
    {
        for (int i=dot_pos-1; i>-1; i--)
        {
            switch (*(num+i))
            {
                case ('0'):
                    A += 0;
                    break;
                case ('1'):
                    A += weight;
                    break;
                case ('2'):
                    A += (weight*-1);
                    break;
            }
            weight *= 3;
        }
        weight = 1;
        for (int i=length-1; i>dot_pos; i--)
        {
            switch (*(num+i))
            {
                case ('0'):
                    B += 0;
                    break;
                case ('1'):
                    B += weight;
                    break;
                case ('2'):
                    B += (weight*-1);
                    break;
            }
            weight *= 3;
        }
        C = weight;
        
        if (A>0 && B<0)
        {
            A -= 1;
            B = B+C;
        }
        else if (A<0 && B<0)
        {
            A += 1;
            B = B+C;
        }
        for (long long int i=B; i>1; i--)
        {
            if (B%i==0 && C%i==0)
            {
                B /= i;
                C /= i;
            }
        }
        
        if (A != 0) printf("%lld ",A);
        
        printf("%lld %lld\n",B,C);
    }

    return 0;
}