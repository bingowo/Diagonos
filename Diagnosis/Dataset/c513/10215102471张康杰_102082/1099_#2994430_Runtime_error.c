#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 256

int main()
{
    char**code;
    int T,i;
    scanf("%d",&T);
    code = (char**)malloc(sizeof(char*) * L);
    for(i = 0;i < L;i++)
    {
        code[i] = (char*)malloc(6);
    }
    code['A'] = ".-",code['B'] = "-...",code['C'] = "-.-.",code['D'] = "-..";
    code['E'] = ".",code['F'] = "..-.",code['G'] = "--.",code['H'] = "....";
    code['I'] = "..",code['J'] = ".---",code['K'] = "-.-",code['L'] = ".-..";
    code['M'] = "--",code['N'] = "-.",code['O'] = "---",code['P'] = ".--.";
    code['Q'] = "--.-",code['R'] = ".-.",code['S'] = "...",code['T'] = "-";
    code['U'] = "..-",code['V'] = "...-",code['W'] = ".--",code['X'] = "-..-";
    code['Y'] = "-.--",code['Z'] = "--..";
    code['0'] = "-----",code['1'] = ".----",code['2'] = "..---",code['3'] = "...--";
    code['4'] = "....-",code['5'] = ".....",code['6'] = "-....",code['7'] = "--...";
    code['8'] = "---..",code['9'] = "----.";
    for(i = 0;i < T;i++)
    {
        char letter[6],decode[1001],input[1001],ch;
        int j,cnt = 0,cnt1 = 0,cnt2 = 0;
        scanf("%s",&input);
        for(j = 0;j < strlen(input);j++)
        {
            if(input[j] == '/')
            {
                letter[cnt] = '\0';
                cnt1++;
                continue;
            }
            if(cnt1 == 1)
            {
                for(int k = 0;k < L;k++)
                {
                    if(strcmp(letter,code[k]) == 0)
                    {
                        decode[cnt2++] = k; 
                        break;
                    }
                }
                cnt1 = 0;
                cnt = 0;
            }
            else if(cnt1 == 3)
            {
                for(int k = 0;k < L;k++)
                {
                    if(strcmp(letter,code[k]) == 0)
                    {
                        decode[cnt2++] = k; 
                        break;
                    }
                }
                decode[cnt2++] = ' ';
                cnt1 = 0;
                cnt = 0;
            }
            else if(cnt1 == 5)
            {
                for(int k = 0;k < L;k++)
                {
                    if(strcmp(letter,code[k]) == 0)
                    {
                        decode[cnt2++] = k; 
                        break;
                    }
                }
                decode[cnt2++] = '.';
                cnt1 = 0;
                cnt = 0;
            }
            letter[cnt++] = input[j];
        }
        letter[cnt] = '\0';
        for(int k = 0;k < L;k++)
        {
            if(strcmp(letter,code[k]) == 0)
            {
                decode[cnt2++] = k; 
                break;
            }
        }
        decode[cnt2] = '\0';
        printf("case #%d:\n%s\n",i,decode);
    }
    for(i = 0;i < L;i++)
        free(code[i]);
    free(code);
    return 0;
}