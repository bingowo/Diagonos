#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int isnum(const char* a)
{
    int i = 0;
    while(a[i]!='\0')
    {
        if(a[i]>='0'&&a[i]<='9') return i;
        i++;
    }
    return -1;
}
int strnumcmp(const void* a,const void* b)
{
   char *s1,*s2;
   s1 = (char*)a;s2 = (char *)b;
   int m,n,x = 0,y = 0;
   m = isnum(s1);n = isnum(s2);
   if(m>=0&&n>=0&&m==n)
   {
       while(s1[m]>='0'&&s1[m]<='9')
       {
           x = x*10 + s1[m];
           m++;
       }
       while(s2[n]>='0'&&s2[n]<='9')
       {
           y = y*10 + s2[n];
           n++;
       }
       if(x<y) return -1;
       else return 1;

   }
    else if(m>=0&&n<0) return 1;
    else if(m<0&&n>=0) return -1;
    else return strcmp(s1,s2);
}
int main()
{
    char s[100][30];int i = 0,j;
    while(scanf("%s",s[i])!=EOF) i++;
    qsort(s,i,30,strnumcmp);
    for(j = 0;j<i;j++)
        printf("%s ",s[j]);
    return 0;
}

