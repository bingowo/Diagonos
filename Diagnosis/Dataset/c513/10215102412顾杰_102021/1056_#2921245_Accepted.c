#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
int cmp(const void*a,const void*b)
{
    return strcmp((char*)a,(char*)b);
}
int main()
{
   int i,j,k,n;
   char s[5001],dic[4000][15],cpy[2]=" ",cp[5001],ans[10001];
   scanf("%d",&k);
   for(i=0;i<k;i++)scanf("%s",dic[i]);
   scanf("%s",s);
   char* start=s,*end=s+strlen(s)-1,*p,*e;
   qsort(dic,k,sizeof(dic[0]),cmp);
   while(start<=end)
   {
       for(e=end;start<e;e--)
       {
           strncpy(cp,start,e-start+1);
           cp[e-start+1]=0;
           p=bsearch(cp,dic,k,sizeof(dic[0]),cmp);
           if(p!=NULL){strcat(ans,p);strcat(ans,cpy);start=e+1;break;}
       }
       if(e==start){strncpy(cp,e,1);cp[1]=0;strcat(ans,cp);strcat(ans,cpy);start++;}
   }
   s[strlen(s)-1]='\n';
   printf("%s",ans);
   return(0);
}
