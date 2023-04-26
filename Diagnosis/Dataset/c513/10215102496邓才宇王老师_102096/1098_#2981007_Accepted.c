#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void func(char *s)
{
    int light[130];
    memset(light, 0 , 520);
    int len = strlen(s);
    int i,j,k,l;
    i = j = k = l = 0;
    while(i < len && s[i] != 'R')
        i++;
    while(j < len && s[j] != 'B')
        j++;
    while(k < len && s[k] != 'Y')
        k++;
    while(l < len && s[l] != 'G')
        l++;
    if(i == len)
    {
        j%=4;k%=4;l%=4;
        i = 6 - j - k - l;
    }
    if(j == len)
    {
        i%=4;k%=4;l%=4;
        j = 6 - i - k - l;
    }
    if(k == len)
    {
        j%=4;i%=4;l%=4;
        k = 6 - j - i - l;
    }
    if(l == len)
    {
        j%=4;k%=4;i%=4;
        l = 6 - j - k - i;
    }
    i%=4;j%=4;k%=4;l%=4;
    for(;i < len || j < len || k < len || l < len; i+=4, j+=4, k+=4, l+=4)
    {
        if(s[i] != 'R' && i < len)
            light['R']++;
        if(s[j] != 'B' && j < len)
            light['B']++;
        if(s[k] != 'Y' && k < len)
            light['Y']++;
        if(s[l] != 'G' && l < len)
            light['G']++;
    }
    printf("%d %d %d %d\n",light['R'],light['B'],light['Y'],light['G']);

}
int main()
{
   int T;
   scanf("%d",&T);
   for(int i=0;i<T;i++)
   {
       char s[200];
       scanf("%s",s);
       printf("case #%d:\n",i);
       func(s);
   }
}
