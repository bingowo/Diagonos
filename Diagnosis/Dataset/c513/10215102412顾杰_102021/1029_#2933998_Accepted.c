#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int cmp(const void*a,const void*b)
{
    return *(char*)a-*(char*)b;
}
int main()
{
   int i,n;
   char s[201],s0[201],c;
   scanf("%d\n",&n);
   for(i=0;i<n;i++)
   {
       int j=0,k=0;
       while((c=getchar())!='\n'){s[j++]=c;if(isalpha(c))s0[k++]=c;}
       qsort(s0,k,sizeof(s0[0]),cmp);
       printf("case #%d:\n",i);
       for(int x=0,y=0;x<j;x++)if(isalpha(s[x]))printf("%c",s0[y++]);else printf("%c",s[x]);
        printf("\n");
   }

}
