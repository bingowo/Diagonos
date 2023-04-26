#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char p[27];
int cmp(const void *a,const void *b)
{ char* str1=(char*)a;
  char* str2=(char*)b;
  int len1=strlen(str1);
  int len2=strlen(str2);
  for(int i=0;i<len1&&i<len2;i++){
    int a1=strchr(p,str1[i])-p;
    int b1=strchr(p,str2[i])-p;
    if(a1<b1){
        return -1;
    }else if(a1>b1){
    return 1;}
  }
  if(len1<len2){
    return -1;
  }else if(len1>len2){
  return 1;}
     return 0;
}
int main(){
while(scanf("%s",p)!=EOF){
   char a[101][21];
   int n=0;
   while(scanf("%s",a[n])!=EOF)
    n++;

qsort(a,n,sizeof(a[0]),cmp);
for(int i=0;i<n;i++)
    printf("%s",a[i]);
printf("\n");
}

}