#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long int LLD;

int main()
{
    char input[100];
    char*table[256];
    table['0'] = "0000",table['1'] = "0001",table['2'] = "0010";
    table['3'] = "0011",table['4'] = "0100",table['5'] = "0101";
    table['6'] = "0110",table['7'] = "0111",table['8'] = "1000";
    table['9'] = "1001",table['A'] = "1010",table['B'] = "1011";
    table['C'] = "1100",table['D'] = "1101",table['E'] = "1110";
    table['F'] = "1111";
    char bi[400] = {0},*pt;
    scanf("%s",input);
    pt = strchr(input,'x');
    pt++;
    while(*pt)
    {
        strcat(bi,table[*pt]);
        pt++;
    }
    int i,len = strlen(bi),re,im;
    int temp_re = 0,temp_im = 0;
    for(i = 0;i < len;i++)
    {
        temp_im = re - im;
        temp_re = -re - im + bi[i] - '0';
        re = temp_re;
        im = temp_im;
    }
    if(re == 0)
    {
        if(im == 0)
            printf("0\n");
        else
            printf("%di\n",im);
    }
    else
    {
        if(im == 0)
            printf("%d\n",re);
        else if(im < 0)
            printf("%d%di\n",re,im);
        else
            printf("%d+%di\n",re,im);
    }
    return 0;
}