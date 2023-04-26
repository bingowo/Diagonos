#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>



int main()
{

    char opera[7][4] = {"IN","MOV","ADD","SUB","MUL","DIV","OUT"};

    long long ABCD[10];
    for(int i = 0; i < 10; i++)
        ABCD[i] = 0;
    char s[110];
    while(scanf("%s",s)!=EOF)
    {
        int o;
        for(int i=0;i<7;i++)
            if(strcmp(s,opera[i])==0) {o=i;break;}
        scanf("%s",s);
        int len=strlen(s);
        int loc;
        int loc2;
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
            //cout << ABCD[loc];
            break;}
        case 1:
            {int space=0;
            loc = s[space] - 'A';
            while(s[space]!=',') space++;

            loc2 = s[space + 1] - 'A';
            ABCD[loc] = ABCD[loc2];
            break;}
        case 2:
            {int space=0;
            loc = s[space] - 'A';
            while(s[space]!=',') space++;

            loc2 = s[space + 1] - 'A';
            ABCD[loc] += ABCD[loc2];
            break;}
        case 3:
            {int space=0;
            loc = s[space] - 'A';
            while(s[space]!=',') space++;

            loc2 = s[space + 1] - 'A';
            ABCD[loc] -= ABCD[loc2];
            break;}
        case 4:
            {int space=0;
            loc = s[space] - 'A';
            while(s[space]!=',') space++;

            loc2 = s[space + 1] - 'A';
            ABCD[loc] *= ABCD[loc2];
            break;}
        case 5:
            {int space=0;
            loc = s[space] - 'A';
            while(s[space]!=',') space++;

            loc2 = s[space + 1] - 'A';
            ABCD[loc] /= ABCD[loc2];
            break;}
        case 6:
            {int space=0;
            loc = s[space] - 'A';
            printf("%d\n",ABCD[loc]);
            break;}
        default:
            break;
        }
    }
    return 0;
}
