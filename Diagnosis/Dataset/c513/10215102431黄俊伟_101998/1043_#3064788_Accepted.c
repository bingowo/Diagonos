#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int elim(char *a, char *b) { // return value: output index.
    if(!*a) return 1;
    char *left = a, *right = a + 1, *r = b;
    bool flag = false;//判断能否消除
    while(*left && *right) {
        if(*left == *right) {
            flag = true;
            while(*right && *left  == *right) {
                right++;
            }
        } else {
            *r++ = *left;
        }
        left = right++;
    }
    if(*left) *r++ = *left;
    *r = '\0';
    if(flag && *b) return !elim(b, a);
    return 1;
}

int main()
{
   int T;
   scanf("%d",&T);
   char s[110];
   char table[]={'A','B','C'};
   for(int cas=0;cas<T;cas++)
   {
       scanf("%s",s);
       int len=strlen(s);
       int min=len;
       for(int i=0;i<len;i++)
       {
           for(int tt=0;tt<3;tt++)
           {
                int k=0;char t[110];    //t为插入A/B/C后的新字符串
                for(int j=0;j<i;j++)
                {
                    t[k++]=s[j];
                }
                t[k++]=table[tt];
                for(int j=i;j<len;j++)
                {
                    t[k++]=s[j];
                }
                t[k++]='\0';
                char b[110];            //b为消除后的字符串
                strcpy(b, t);
                int r = elim(t, b), l;
                if(r) {
                    if(strlen(b) <= min)
                        min = strlen(b);
                } else {
                    if(strlen(t) <= min)
                        min = strlen(t);
                }
            }
       }
       printf("case #%d:\n",cas);
       printf("%d\n",len+1-min);
   }
   return 0;
}
