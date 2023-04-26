#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
void comb(char* s,char* char_comb)
{
    if(*s)
    {
        char left[17]={0};
        sprintf(left,"%s%c",char_comb,s[0]);
        printf("%s\n",left);
        comb(s+1,left);
        comb(s+1,char_comb);
    }
}
int cmp(const void* p,const void* q)
{
    char* a=(char*)p;
    char* b=(char*)q;
    return (*a-*b);
}
int main()
{
    int T;
    scanf("%d",&T);
    char s[20];char x[20];
    for(int cas=0;cas<T;cas++)
    {
        scanf("%s",s);
        int len=strlen(s);
        qsort(s,len,sizeof(s[0]),cmp);
        int i=0,k=0;
        for(i=0,k=0;i<len-1;i++)
        {
            if(s[i]!=s[i+1])
            {
                x[k]=s[i];k++;
            }
        }
        x[k++]=s[len-1];x[k]='\0';
        char t[5]={};
        printf("case #%d:\n",cas);
        comb(x,t);
    }
    return 0;
}
