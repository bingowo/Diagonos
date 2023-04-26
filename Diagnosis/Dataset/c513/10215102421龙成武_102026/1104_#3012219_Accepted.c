#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int reg[128];
int main()
{
    int i, x, len, val;
    char s[100], * s2, op[10], reg1[5], reg2[5], reg3[5];
    while (gets(s))
    {
        if (strcmp(s, "") == 0)
            break;
        x = 0; //空格的个数，也就是x个运算数
        len = strlen(s);
        for (i = 0;i < len;i++)
        {
            if (s[i] == ',')
            {
                s[i] = ' ';
                x++;
            }
            else if (s[i] == ' ') x++;
        }
        //sscanf(s,"%s %s",op,s2);                //把指令放到op里，然后把后面部分存到s2里
        sscanf(s, "%s", op);
        s2 = s + strlen(op) + 1;
        if (strcmp(op, "IN") == 0)
        {
            sscanf(s2, "%s %d", reg1, &val);
            reg[reg1[0]] = val;
        }
        else if (strcmp(op, "OUT") == 0)
        {
            sscanf(s2, "%s", reg1);
            printf("%d\n", reg[reg1[0]]);
        }
        else if (strcmp(op, "MOV") == 0)
        {
            sscanf(s2, "%s %s", reg1, reg2);
            reg[reg1[0]] = reg[reg2[0]];
        }
        else if (strcmp(op, "XCHG") == 0)
        {
            sscanf(s2, "%s %s", reg1, reg2);
            val = reg[reg1[0]];
            reg[reg1[0]] = reg[reg2[0]];
            reg[reg2[0]] = val;
        }
        else if (strcmp(op, "ADD")==0)
        {
            if (x == 3)
            {
                sscanf(s2, "%s %s %s", reg1, reg2, reg3);
                reg[reg1[0]] = reg[reg3[0]] + reg[reg2[0]];
            }
            else
            {
                sscanf(s2, "%s %s", reg1, reg2);
                reg[reg1[0]] = reg[reg1[0]] + reg[reg2[0]];
            }
        }
        else if (strcmp(op, "SUB")==0)
        {
            if (x == 3)
            {
                sscanf(s2, "%s %s %s", reg1, reg2, reg3);
                reg[reg1[0]] = reg[reg2[0]] - reg[reg3[0]];
            }
            else
            {
                sscanf(s2, "%s %s", reg1, reg2);
                reg[reg1[0]] = reg[reg1[0]] - reg[reg2[0]];
            }
        }
        else if (strcmp(op, "MUL")==0)
        {
            if (x == 3)
            {
                sscanf(s2, "%s %s %s", reg1, reg2, reg3);
                reg[reg1[0]] = reg[reg2[0]] * reg[reg3[0]];
            }
            else
            {
                sscanf(s2, "%s %s", reg1, reg2);
                reg[reg1[0]] = reg[reg1[0]] * reg[reg2[0]];
            }
        }
        else if (strcmp(op, "DIV")==0)
        {
            if (x == 3)
            {
                sscanf(s2, "%s %s %s", reg1, reg2, reg3);
                reg[reg1[0]] = reg[reg2[0]] / reg[reg3[0]];
            }
            else
            {
                sscanf(s2, "%s %s", reg1, reg2);
                reg[reg1[0]] = reg[reg1[0]] / reg[reg2[0]];
            }
        }
        else if (strcmp(op, "MOD")==0)
        {
            if (x == 3)
            {
                sscanf(s2, "%s %s %s", reg1, reg2, reg3);
                reg[reg1[0]] = reg[reg2[0]] % reg[reg3[0]];
            }
            else
            {
                sscanf(s2, "%s %s", reg1, reg2);
                reg[reg1[0]] = reg[reg1[0]] % reg[reg2[0]];
            }
        }
        else if (strcmp(op, "AND")==0)
        {
            if (x == 3)
            {
                sscanf(s2, "%s %s %s", reg1, reg2, reg3);
                reg[reg1[0]] = reg[reg2[0]] & reg[reg3[0]];
            }
            else
            {
                sscanf(s2, "%s %s", reg1, reg2);
                reg[reg1[0]] = reg[reg1[0]] & reg[reg2[0]];
            }
        }
        else if (strcmp(op, "OR")==0)
        {
            if (x == 3)
            {
                sscanf(s2, "%s %s %s", reg1, reg2, reg3);
                reg[reg1[0]] = reg[reg2[0]] | reg[reg3[0]];
            }
            else
            {
                sscanf(s2, "%s %s", reg1, reg2);
                reg[reg1[0]] = reg[reg1[0]] | reg[reg2[0]];
            }
        }
        else if (strcmp(op, "XOR")==0)
        {
            if (x == 3)
            {
                sscanf(s2, "%s %s %s", reg1, reg2, reg3);
                reg[reg1[0]] = reg[reg2[0]] ^ reg[reg3[0]];
            }
            else
            {
                sscanf(s2, "%s %s", reg1, reg2);
                reg[reg1[0]] = reg[reg1[0]] ^ reg[reg2[0]];
            }
        }
    }
    return 0;
}
//从这道题学到的：利用数组模拟map、gets的终止条件（s==“”）