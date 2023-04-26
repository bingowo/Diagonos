#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char s[])
{
	int i,len=strlen(s),g;
	for(i=0;i<=len/2-1;i++){
		g=s[i];
		s[i]=s[len-i-1];
		s[len-i-1]=g;}
}
void itob(int n,char s[100],int b)
{
  int i,point;
 if(n<0) n=-n,point=1;
 else point=0;
  for(i=0;n>0;i++){
  	if(n%b<10)
  	s[i]=n%b+'0';
  	if(n%b>=10)
  		s[i]='A'+n%b-10;
  		n=n/b;
	 }
 
  if(point==1) s[i]='-',s[i+1]='\0';
   else s[i]='\0';
   swap(s);
}


int main()
{
    int n,i,b;
    char s[100];
    scanf("%d",&i);
   for(;i>0;i--) {
	scanf("%d %d",&n,&b);
    
    itob(n,s,b);
    printf("%s\n",s);}
    return 0;
}