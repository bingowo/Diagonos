#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{char ch;int po;}point;

int main()
{
    int i,j,max,k;
    char s[1007],**ss;
    point *wave;
    while(scanf("%s",s)!=EOF)
    {
        int len = strlen(s);
        wave = (point*)malloc(len*sizeof(point));
        for(i = 0; i < len; i++)wave[i].ch = s[i];
        ss = (char**)malloc(len*sizeof(char*));
        for(i = 0; i < len ;i++)ss[i] = (char*)malloc(len*sizeof(char));
        for(i = 0; i < len; i++)
            for(j = 0; j < len; j++)ss[i][j] = ' ';
        ss[0][0] = s[0];
        wave[0].po = 0;
        for(i = 0,j = 0; i < len-1; i++)
        {
            if(s[i+1] > s[i]){ss[wave[i].po+1][i+1]  = s[i+1];wave[i+1].po = wave[i].po+1;}
            else if(s[i+1] < s[i])
                {
                    if(wave[i].po >= 1){ss[wave[i].po-1][i+1] = s[i+1];wave[i+1].po = wave[i].po-1;}
                    else
                    {
                        for(k = len-1; k >= 0; k--)strcpy(ss[k+1],ss[k]);
                        ss[0][i+1] = s[i+1];
                        wave[i+1].po = 0;
                    }
                }
            else {ss[wave[i].po][i+1] = s[i+1];wave[i+1].po = wave[i].po+1;}
        }
        for(i = 0; i < len-1; i++)
        {
            if(wave[i].po > wave[i+1].po)max = wave[i].po;
            else max = wave[i+1].po;
        }
        for(i = 0; i <= max; i++)
        {
            for(j = len-1; ss[i][j] == ' '; j--);
            ss[i][j+1] = '\0';
        }
        for(j = max; j >= 0; j--)printf("%s\n",ss[j]);
    }
    return 0;
}