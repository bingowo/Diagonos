#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#include <stdlib.h>
#define num 1009
//.与/ 转换为数字 .为1 -为2



int main()
{

    int n;
    scanf("%d", &n);
    char* p = (char*)malloc(sizeof(char) * 100000);
    p[12] = 'A';
    p[2111] = 'B';
    p[2121] = 'C';
    p[211] = 'D';
    p[1] = 'E';
    p[1121] = 'F';
    p[221] = 'G';
    p[1111] = 'H';
    p[11] = 'I';
    p[1222] = 'J';
    p[212] = 'K';
    p[1211] = 'L';
    p[22] = 'M';
    p[21] = 'N';
    p[222] = 'O';
    p[1221] = 'P';
    p[2212] = 'Q';
    p[121] = 'R';
    p[111] = 'S';
    p[2] = 'T';
    p[112] = 'U';
    p[1112] = 'V';
    p[122] = 'W';
    p[2112] = 'X';
    p[2122] = 'Y';
    p[2211] = 'Z';
    p[22222] = '0';
    p[12222] = '1';
    p[11222] = '2';
    p[11122] = '3';
    p[11112] = '4';
    p[11111] = '5';
    p[21111] = '6';
    p[22111] = '7';
    p[22211] = '8';
    p[22221] = '9';
    for (int i = 0;i < n;i++)
    {
        printf("case #%d:\n", i);
        char mid[1009];
        char res[num];
        scanf("%s", mid);
        int po = 0;
        int pr = 0;
        while (mid[po] != 0)
        {
            int n = 0;
            while (mid[po] != '/' && mid[po] != 0)
            {
                n *= 10;
                if (mid[po] == '.')n += 1;
                else n += 2;
                po++;
            }
            res[pr] = p[n];
            pr++;
            int pok = po;
            while (mid[po] == '/')
            {
                po++;
            }
            if (po - pok ==3)res[pr++] = ' ';
            else if (po - pok ==5)res[pr++] = '.';
        }
        res[pr] = 0;
        printf("%s\n", res);
    }
    free(p);
    return 0;
}
