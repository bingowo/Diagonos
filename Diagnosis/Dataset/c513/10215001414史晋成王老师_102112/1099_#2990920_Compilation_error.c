#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{ int t,i,j,m,n,ch,flag;
  char s[10000],text[501];
  char *moose[36]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
  scanf("%d",&t);
  for(i=0;i<t;i++)
  { gets(s); j=0;
  while(s[j])
  {
  n=0;
  char code[6];
  k=0;
  while(s[j]=='.'||s[j]=='-') code[k++]=s[j++]
  code[k]=0;
   for(k=0;k<36;k++)
   if(strcmp(moose[k],code)==0)  
     { if(k<26) ch=k+65;
       else ch=k+22;
       text[n++]=ch;
       break;
     }
    flag=0;
    while(s[j]=='/') {flag++;j++;}
      if(flag==3) text[n++]=' '; else if(flag==5) text[n++]='.';
  }
  printf("case #%d:\n",i);
  text[n]=0;  printf("%s\n",text);
      
  }
    
}