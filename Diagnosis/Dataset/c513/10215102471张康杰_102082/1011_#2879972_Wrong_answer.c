#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct Complex
{
    int real;
    int imaginary;
};
int main()
{
    //16进制下每隔一位仅相差-4！！！！！！！！！！！！
    struct Complex table[16] = {{0,0},{1,0},{-1,1},{0,1},{0,-2},{1,-2},{-1,-1},{0,-1},{2,2},{3,2},{1,3},{2,3},{2,0},{3,0},{1,1},{2,1}};
    //enum table1{'0','1','2','3','4','5','6','7','8','9','A'};
    int table1[256];
    table1['0'] = 0,table1['1'] = 1,table1['2'] = 2,table1['3'] = 3,table1['4'] = 4,table1['5'] = 5,table1['6'] = 6;
    table1['7'] = 7,table1['8'] = 8,table1['9'] = 9,table1['A'] = 10,table1['B'] = 11,table1['C'] = 12,table1['D'] = 13;
    table1['E'] = 14,table1['F'] = 15;
    char input[100];
    scanf("0x%s",input);
    int i,length = strlen(input);
    long long int real = 0,imaginary = 0;
    for(i = length - 1;i > -1;i--)
    {
        real += table[table1[input[i]]].real*(long long int)pow(-4,length - i - 1);
        imaginary = +table[table1[input[i]]].imaginary*(long long int)pow(-4,length - i - 1);
    }
    if(real == 0)
        {
            if(imaginary == 0)
                printf("0");
            else if(imaginary == 1)
                printf("i");
            else if(imaginary == -1)
                printf("-i");
            else
                printf("%lldi",imaginary);
        }
    else if(imaginary == 0)
        printf("%lld\n",real);
    else
    {
        printf("%lld",real);
        if(imaginary < 0)
        {
            if(imaginary == (-1))
                printf("-i");
            else
                printf("%lldi",imaginary);
        }

        else
        {
            if(imaginary == 1)
                printf("+i");
            else
                printf("+%lldi",imaginary);
        }

    }

    return 0;
}