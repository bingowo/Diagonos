#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int cmp(const void *a,const void *b)
{
  int x=*(char*)a;
  int y=*(char*)b;
  if ((x>='A'&&x<='Z')&&(y>='A'&&y<='Z'))
      return x-y;
   else
    return -1;
}
int main()
{
    int n,len;char s[201];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        gets(s);
        len=strlen(s);
        s[len]='\0';
        qsort(s,len,sizeof(char),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }
    return 0;
}
