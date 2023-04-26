#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

 
int main()
{ int i,T,j;
 char s[200];
 char*p;
 char shi[200];
 scanf("%d\n",&T);
 for(i=0;i<T;i++){
    int k=0,num=0;
    int di,beichu;
  scanf("%s",s);
  p=s;
  while(*p) p++ ;
  while(*--p!='.'){ 
  di=*p-'0';
  j=0;
  do{
      if(j<num) beichu=di*10+shi[j]-'0';
  else beichu=di*10;
  shi[j++]=beichu/8+'0';
  di=beichu%8;
  }while(di!=0||j<num);
  num=j;
  }
  shi[num]='\0';
  printf("case #%d:\n",i);
  printf("0.");
  printf("%s\n",shi);
 }
 return 0;
}