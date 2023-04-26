#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{char s[3];long long num;}val;

char s1[3] = {"IN"},s2[4] = {"MOV"},s3[4] = {"ADD"},s4[4] = {"SUB"},s5[4] = {"MUL"},s6[4] = {"DIV"},s7[4] = {"OUT"},s8[5] = {"XCHG"},s9[4] = {"MOD"},s10[4] = {"AND"},s11[3] = {"OR"},s12[4] = {"XOR"};

int main()
{
    int i,j = 26,k,l,h,h1,h2,h3,sign;
    long long sum,d;
    char imp[37],s[5],ele1[37],ele2[37],ele3[37];
    val cp[26] = {"AX",0,"BX",0,"CX",0,"DX",0,"EX",0,"FX",0,"GX",0,"HX",0,"IX",0,"JX",0,"KX",0,"LX",0,"MX",0,"NX",0,"OX",0,"PX",0,"QX",0,"RX",0,"SX",0,"TX",0,"UX",0,"VX",0,"WX",0,"XX",0,"YX",0,"ZX",0};
    while(scanf("%s",s)!=EOF)
    {
        scanf("%s",imp);
        memset(ele1,0,sizeof(ele1));
        memset(ele2,0,sizeof(ele2));
        memset(ele3,0,sizeof(ele3));
        int len = strlen(imp);
        for(i = 0; imp[i] != ','&&i < len; i++)ele1[i] = imp[i];
        ele1[i] = '\0';
        for(i += 1,k = 0,sign = 1; imp[i] != ','&&i < len; i++,k++)
        {
            if(imp[i] == '-'){sign = -1;k--;continue;}
            else ele2[k] = imp[i];
        }
        ele2[k] = '\0';
        if(i != len)
        {
            for(i += 1,l = 0,sign = 1; imp[i] != ','&&i < len; i++,l++)
            {
                if(imp[i] == '-'){sign = -1;l--;continue;}
                else ele3[l] = imp[i];
            }
            ele3[l] = '\0';
        }
        if(strcmp(s,s1) == 0)
        {
            for(h = 0,sum = 0; h < k; h++)
                sum = sum*10+ele2[h]-'0';
            for(h = 0; h < j; h++)
            {
                if(strcmp(ele1,cp[h].s) == 0)
                    {
                        cp[h].num = sign*sum;
                        break;
                    }
            }
        }
        else if(strcmp(s,s2) == 0)
        {
            for(h = 0; h < j; h++)
            {
                if(strcmp(ele1,cp[h].s) == 0){h1 = h;}
                if(strcmp(ele2,cp[h].s) == 0){h2 = h;}
            }
            cp[h1].num = cp[h2].num;
        }
        else if(strcmp(s,s3) == 0)
        {
            for(h = 0; h < j; h++)
            {
                if(strcmp(ele1,cp[h].s) == 0){h1 = h;}
                if(strcmp(ele2,cp[h].s) == 0){h2 = h;}
                if(strcmp(ele3,cp[h].s) == 0){h3 = h;}
            }
            if(strlen(ele3) != 0)cp[h1].num = cp[h2].num + cp[h3].num;
            else cp[h1].num += cp[h2].num;
        }
        else if(strcmp(s,s4) == 0)
        {
            for(h = 0; h < j; h++)
            {
                if(strcmp(ele1,cp[h].s) == 0){h1 = h;}
                if(strcmp(ele2,cp[h].s) == 0){h2 = h;}
                if(strcmp(ele3,cp[h].s) == 0){h3 = h;}
            }
            if(strlen(ele3) != 0)cp[h1].num = cp[h2].num - cp[h3].num;
            else cp[h1].num -= cp[h2].num;
        }
        else if(strcmp(s,s5) == 0)
        {
            for(h = 0; h < j; h++)
            {
                if(strcmp(ele1,cp[h].s) == 0){h1 = h;}
                if(strcmp(ele2,cp[h].s) == 0){h2 = h;}
                if(strcmp(ele3,cp[h].s) == 0){h3 = h;}
            }
            if(strlen(ele3) != 0)cp[h1].num = cp[h2].num * cp[h3].num;
            else cp[h1].num *= cp[h2].num;
        }
        else if(strcmp(s,s6) == 0)
        {
            for(h = 0; h < j; h++)
            {
                if(strcmp(ele1,cp[h].s) == 0){h1 = h;}
                if(strcmp(ele2,cp[h].s) == 0){h2 = h;}
                if(strcmp(ele3,cp[h].s) == 0){h3 = h;}
            }
            if(strlen(ele3) != 0)cp[h1].num = cp[h2].num / cp[h3].num;
            else cp[h1].num /= cp[h2].num;
        }
        else if(strcmp(s,s7) == 0)
        {
            for(h = 0; h < j; h++)if(strcmp(ele1,cp[h].s) == 0){h1 = h;break;}
            printf("%lld\n",cp[h1].num);continue;
        }
        else if(strcmp(s,s8) == 0)
        {
            for(h = 0; h < j; h++)
            {
                if(strcmp(ele1,cp[h].s) == 0){h1 = h;}
                if(strcmp(ele2,cp[h].s) == 0){h2 = h;}
            }
            d = cp[h1].num;
            cp[h1].num = cp[h2].num;
            cp[h2].num = d;
        }
        else if(strcmp(s,s9) == 0)
        {
            for(h = 0; h < j; h++)
            {
                if(strcmp(ele1,cp[h].s) == 0){h1 = h;}
                if(strcmp(ele2,cp[h].s) == 0){h2 = h;}
                if(strcmp(ele3,cp[h].s) == 0){h3 = h;}
            }
            if(strlen(ele3) != 0)cp[h1].num = cp[h2].num % cp[h3].num;
            else cp[h1].num %= cp[h2].num;
        }
        else if(strcmp(s,s10) == 0)
        {
            for(h = 0; h < j; h++)
            {
                if(strcmp(ele1,cp[h].s) == 0){h1 = h;}
                if(strcmp(ele2,cp[h].s) == 0){h2 = h;}
                if(strcmp(ele3,cp[h].s) == 0){h3 = h;}
            }
            if(strlen(ele3) != 0)cp[h1].num = cp[h2].num & cp[h3].num;
            else cp[h1].num &= cp[h2].num;
        }
        else if(strcmp(s,s11) == 0)
        {
            for(h = 0; h < j; h++)
            {
                if(strcmp(ele1,cp[h].s) == 0){h1 = h;}
                if(strcmp(ele2,cp[h].s) == 0){h2 = h;}
                if(strcmp(ele3,cp[h].s) == 0){h3 = h;}
            }
            if(strlen(ele3) != 0)cp[h1].num = cp[h2].num | cp[h3].num;
            else cp[h1].num |= cp[h2].num;
        }
        else if(strcmp(s,s12) == 0)
        {
            for(h = 0; h < j; h++)
            {
                if(strcmp(ele1,cp[h].s) == 0){h1 = h;}
                if(strcmp(ele2,cp[h].s) == 0){h2 = h;}
                if(strcmp(ele3,cp[h].s) == 0){h3 = h;}
            }
            if(strlen(ele3) != 0)cp[h1].num = cp[h2].num ^ cp[h3].num;
            else cp[h1].num ^= cp[h2].num;
        }
    }
    return 0;
}
