#include <stdio.h>
#include <string.h>

int table[10001];

int main()
{

    int T; scanf("%d",&T);
    table[4]='A', table[23]='B', table[25]='C',table[11]='D';
    table[1]='E', table[17]='F', table[13]='G',table[15]='H';
    table[3]='I', table[22]='J', table[12]='K',table[19]='L';
    table[6]='M', table[5]='N', table[14]='O', table[21]='P';
    table[28]='Q',table[9]='R', table[7]='S', table[2]='T';
    table[8]='U', table[16]='V', table[10]='W', table[24]='X';
    table[26]='Y',table[27]='Z', table[62]='0', table[46]='1';
    table[38]='2',table[34]='3', table[32]='4', table[31]='5';
    table[47]='6',table[55]='7', table[59]='8', table[61]='9';
    for (int t=0;t<T;t++)
    {
        char code[1001] = {}; scanf("%s",code);
        int value = 0, cnt = 0;
        printf("case #%d:\n",t);
        for (int i=0;code[i];i++)
        {
            if (code[i]=='/')
            {
                if (!cnt) {printf("%c",table[value]); value = 0;}
                cnt++; 
            }
            else
            {
                if (cnt==3) printf(" ");
                else if (cnt==5) printf(".");
                cnt = 0;
                if (code[i]=='.') value = value*2+1;
                else if (code[i]=='-') value = value*2+2;
            }
        }
        if (cnt==3) printf(" ");
        else if (cnt==5) printf(".");
        printf("%c\n",table[value]);
    }
    return 0;
}