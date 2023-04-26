#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int cmp(const void*a,const void*b)
{
    char*pa=*(char**)a,*pb=*(char**)b;
    return strcmp(pa,pb);
}
int main()
{
   int i,n;
   scanf("%d\n",&n);
   for(i=0;i<n;i++)
   {
       char ans[500]="",s[501]="",word[501]=" ",*p=s,*a[500];
       int k=0,j,m=0;
       gets(s);
       while(p<s+strlen(s))
       {
           while(!isalpha(*p))p++;
           while(isalpha(*(p+k)))k++;
           strncpy(word+1,p,k);
           k++;
           word[k++]=' ';word[k--]=0;
           if(strstr(ans,word)==NULL)strcat(ans,word);
          // ans[strlen(ans)-1]=0;
           p+=k;k=0;
       }
       p=ans+1;
       int l=strlen(ans);
       while(p<ans+l)
       {
           k=1;
           while(isalpha(*(p+k)))k++;
           *(p+k)=0;
           a[m++]=p;
           p+=k+2;
       }
       qsort(a,m,sizeof(a[0]),cmp);
       printf("case #%d:\n",i);
       for(j=0;j<m;j++)if(*a[j]>='a')printf("%s%c",a[j],j==m-1?'\n':' ');
   }
}
