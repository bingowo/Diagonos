#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>



int main()
{

    char opera[13][4] = {"IN","MOV","ADD","SUB","MUL","DIV","OUT","XCHG","MOD","AND","OR","XOR"};

    long long ABCD[30];
    for(int i = 0; i < 30; i++)
        ABCD[i] = 0;
    char s[110];
    while(scanf("%s",s)!=EOF)
    {
        int o;
        for(int i=0;i<13;i++)
            if(strcmp(s,opera[i])==0) {o=i;break;}
        scanf("%s",s);
        int len=strlen(s);
        int loc;
        int loc2;
        int loc3;
        int flag = 0;
        switch (o)
        {
        case 0:
            {int space=0;
            loc = s[space ] - 'A';
            while(s[space]!=',') space++;

            ABCD[loc] = 0;

            while(space < len-1)
            {
                if(s[space+1] == '-')
                {
                    flag = 1;
                    space++;continue;
                }
                ABCD[loc] *= 10;
                ABCD[loc] += s[++space] - '0';
            }
            if(flag)
                ABCD[loc]*=-1;
            //IN
            break;}
        case 1:
            {int space=0;
            loc = s[space] - 'A';
            while(s[space]!=',') space++;

            loc2 = s[space + 1] - 'A';
            ABCD[loc] = ABCD[loc2];
            break;}//MOV
        case 2:
            {int space=0;
            loc = s[space] - 'A';
            while(s[space]!=',') space++;

            loc2 = s[space + 1] - 'A';
            space+=3;
            if(space==len)
            ABCD[loc] += ABCD[loc2];
            else {loc3=s[space+1]-'A';ABCD[loc]=ABCD[loc2]+ABCD[loc3];}
            break;}//ADD
        case 3:
            {int space=0;
            loc = s[space] - 'A';
            while(s[space]!=',') space++;

            loc2 = s[space + 1] - 'A';
            space+=3;
            if(space==len)
            ABCD[loc] -= ABCD[loc2];
            else{loc3=s[space+1]-'A';ABCD[loc]=ABCD[loc2]-ABCD[loc3];}
            break;}//SUB
        case 4:
            {int space=0;
            loc = s[space] - 'A';
            while(s[space]!=',') space++;

            loc2 = s[space + 1] - 'A';
            space+=3;
            if(space==len)
            ABCD[loc] *= ABCD[loc2];
            else {loc3=s[space+1]-'A';ABCD[loc]=ABCD[loc2]*ABCD[loc3];}
            break;}//MUL
        case 5:
            {int space=0;
            loc = s[space] - 'A';
            while(s[space]!=',') space++;

            loc2 = s[space + 1] - 'A';
            space+=3;
            if(space==len)
            ABCD[loc] /= ABCD[loc2];
            else {loc3=s[space+1]-'A';ABCD[loc]=ABCD[loc2]/ABCD[loc3];}
            break;}//DIV
        case 6:
            {int space=0;
            loc = s[space] - 'A';
            printf("%lld\n",ABCD[loc]);
            break;}//OUT
        case 7:
            {int space=0;
            loc = s[space] - 'A';
            while(s[space]!=',') space++;

            loc2 = s[space + 1] - 'A';
            int huan=ABCD[loc];
            ABCD[loc] = ABCD[loc2];
            ABCD[loc2]=huan;
            break;}//XCHG
        case 8:
            {int space=0;
            loc = s[space] - 'A';
            while(s[space]!=',') space++;

            loc2 = s[space + 1] - 'A';
            space+=3;
            if(space==len)
            ABCD[loc]%=ABCD[loc2];
            else {loc3=s[space+1]-'A';ABCD[loc]=ABCD[loc2]%ABCD[loc3];}
            break;}//MOD
        case 9:
            {int space=0;
            loc = s[space] - 'A';
            while(s[space]!=',') space++;

            loc2 = s[space + 1] - 'A';
            space+=3;
            if(space==len)
            ABCD[loc] &= ABCD[loc2];
            else {loc3=s[space+1]-'A';ABCD[loc]=ABCD[loc2]&ABCD[loc3];}
            break;}//AND
        case 10:
            {int space=0;
            loc = s[space] - 'A';
            while(s[space]!=',') space++;

            loc2 = s[space + 1] - 'A';
            space+=3;
            if(space==len)
            ABCD[loc]|= ABCD[loc2];
            else {loc3=s[space+1]-'A';ABCD[loc]=ABCD[loc2]|ABCD[loc3];}
            break;}//OR
        case 11:
            {int space=0;
            loc = s[space] - 'A';
            while(s[space]!=',') space++;

            loc2 = s[space + 1] - 'A';
            space+=3;
            if(space==len)
            ABCD[loc] ^= ABCD[loc2];
            else {loc3=s[space+1]-'A';ABCD[loc]=ABCD[loc2]^ABCD[loc3];}
            break;}//XOR
        default:
            break;
        }
    }
    return 0;
}
