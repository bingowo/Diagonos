#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int cmp(const void* a,const void* b){
   char* p1,*p2,*d1,*d2;
   int i;
   p1=*((char**)a);
   p2=*((char**)b);
   while(*(p1+i)!='@')i++;
   d1=p1+i+1;
   while(*(p2+i)!='@')i++;
   d2=p2+i+1;
   if(strcmp(d1,d2)==0)return strcmp(p2,p1);
   else return strcmp(d1,d2);

}

int main()
{
   char** mail;
   int n;
   scanf("%d",&n);
   mail=(char**)malloc(n*sizeof(char*));
   char s[1000001];
   char* p;
   int i,len;
   for(i=0;i<n;i++){
      scanf("%s",s);
      len=strlen(s);
      p=(char*)malloc(len+1);
      strcpy(p,s);
      *(mail+i)=p;
   }
   qsort(mail,n,sizeof(char*),cmp);
   for(i=0;i<n;i++){
      printf("%s\n",mail[i]);

   }
   for(i=0;i<n;i++){
      p=mail[i];
      free(p);
   }
   free(mail);
   
   return(0);
}