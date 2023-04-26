#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{char ch;int num;}alph;

int cmp(const void*a,const void*b)
{
    int c = *(int*)a;
    int d = *(int*)b;
    if(c < d)return -1;
    else return 1;
}

int main()
{
    int cas,i,j,k,l;
    int code[1007];
    char s[1007];
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        alph t[26] = {'A',0,'B',0,'C',0,'D',0,'E',0,'F',0,'G',0,'H',0,'I',0,'J',0,'K',0,'L',0,'M',0,'N',0,'O',0,'P',0,'Q',0,'R',0,'S',0,'T',0,'U',0,'V',0,'W',0,'X',0,'Y',0,'Z',0};
        scanf("%s",s);
        int len = strlen(s);
        for(j = 0; j < len; j++)
           for(k = 0; k < 26; k++)
            if(s[j] == t[k].ch){t[k].num++;break;}
        k = 0;
        if(t[25].num>0)
            if(t[4].num >= t[25].num&&t[17].num >= t[25].num&&t[14].num >= t[25].num)
        {
            for(k = 0; k < t[25].num; k++)code[k] = 0;
            t[4].num -= t[25].num;
            t[17].num -= t[25].num;
            t[14].num -= t[25].num;
        }
        if(t[6].num > 0)
            if(t[4].num >= t[6].num&&t[8].num >= t[6].num&&t[7].num >= t[6].num&&t[19].num >= t[6].num)
          {
             if(k)for(l = 0; l < t[6].num; l++,k++)code[k] = 8;
             else for(k = 0; k < t[6].num; k++)code[k] = 8;
             t[4].num -= t[6].num;
             t[8].num -= t[6].num;
             t[7].num -= t[6].num;
             t[19].num -= t[6].num;
          }
        if(t[20].num > 0)
          if(t[5].num >= t[20].num&&t[14].num >= t[20].num&&t[17].num >= t[20].num)
          {
            if(k)for(l = 0; l < t[20].num; l++,k++)code[k] = 4;
            else for(k = 0; k < t[20].num; k++)code[k] = 4;
            t[5].num -= t[20].num;
            t[14].num -= t[20].num;
            t[17].num -= t[20].num;
          }
        if(t[22].num > 0)
          if(t[19].num >= t[22].num&&t[14].num >= t[22].num)
        {
            if(k)for(l = 0; l < t[22].num; l++,k++)code[k] = 2;
            else for(k = 0; k < t[22].num; k++)code[k] = 2;
            t[19].num -= t[22].num;
            t[14].num -= t[22].num;
        }
        if(t[23].num > 0)
          if(t[18].num >= t[23].num&&t[8].num >= t[23].num)
        {
            if(k)for(l = 0; l < t[23].num; l++,k++)code[k] = 6;
            else for(k = 0; k < t[23].num; k++)code[k] = 6;
            t[18].num -= t[23].num;
            t[8].num -= t[23].num;
        }
        if(t[14].num > 0)
          if(t[13].num >= t[14].num&&t[4].num >= t[14].num)
        {
            if(k)for(l = 0; l < t[14].num; l++,k++)code[k] = 1;
            else for(k = 0; k < t[14].num; k++)code[k] = 1;
            t[13].num -= t[14].num;
            t[4].num -= t[14].num;
        }
        if(t[5].num > 0)
          if(t[8].num >= t[5].num&&t[21].num >= t[5].num&&t[4].num >= t[5].num)
        {
            if(k)for(l = 0; l < t[5].num; l++,k++)code[k] = 5;
            else for(k = 0; k < t[5].num; k++)code[k] = 5;
            t[8].num -= t[5].num;
            t[21].num -= t[5].num;
            t[4].num -= t[5].num;
        }
        if(t[18].num > 0)
          if(t[4].num >= 2*t[18].num&&t[21].num >= t[18].num&&t[13].num >= t[18].num)
        {
            if(k)for(l = 0; l < t[18].num; l++,k++)code[k] = 7;
            else for(k = 0; k < t[18].num; k++)code[k] = 7;
            t[4].num -= 2*t[18].num;
            t[21].num -= t[18].num;
            t[13].num -= t[18].num;
        }
        if(t[7].num > 0)
          if(t[19].num >= t[7].num&&t[17].num >= t[7].num&&t[4].num >= 2*t[7].num)
        {
            if(k)for(l = 0; l < t[7].num; l++,k++)code[k] = 3;
            else for(k = 0; k < t[7].num; k++)code[k] = 3;
            t[19].num -= t[7].num;
            t[17].num -= t[7].num;
            t[4].num -= 2*t[7].num;
        }
        if(t[8].num > 0)
          if(t[13].num >= 2*t[8].num&&t[4].num >= t[8].num)
        {
            if(k)for(l = 0; l < t[8].num; l++,k++)code[k] = 9;
            else for(k = 0; k < t[8].num; k++)code[k] = 9;
            t[13].num -= 2*t[8].num;
            t[4].num -= t[8].num;
        }
        qsort(code,k,sizeof(code[0]),cmp);
        printf("case #%d:\n",i);
        for(j = 0; j < k; j++)printf("%d",code[j]);
        printf("\n");
    }
    return 0;
}