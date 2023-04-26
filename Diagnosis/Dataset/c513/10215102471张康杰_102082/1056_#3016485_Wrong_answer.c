#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 5001

void divide(char*a,char b[]);

void divideChr(char*abort);

int main()
{
    char diction[4000][15];
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%s",diction[i]);
    }
    char input[L];
    scanf("%s",input);
    while(strlen(input) != 0)
    {
        char temp[L];
        int pos;
        for(pos = 14;pos >= 1;pos--)
        {
            if(pos == 1)
            {
                printf("%c ",input[0]);
                divideChr(input);
                break;
            }
            memcpy(temp,input,L);
            temp[pos] = '\0';
            for(int j = 0;j < n;j++)
            {
                if(strcmp(temp,diction[j]) == 0)
                {
                    printf("%s ",diction[j]);
                    divide(input,temp);
                    break;
                }
            }

        }
    }
    putchar('\n');
    return 0;
}

void divide(char*a,char b[])
{
    int len1 = strlen(a),len2 = strlen(b);
    char pt[L];
    memcpy(pt,a + len2,L);
    memcpy(a,pt,L);
}

void divideChr(char*a)
{
    char pt[L];
    memcpy(pt,a + 1,L);
    memcpy(a,pt,L);
}