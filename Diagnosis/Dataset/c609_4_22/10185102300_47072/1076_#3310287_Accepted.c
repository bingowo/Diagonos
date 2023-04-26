#include <stdio.h>
#include <string.h>

char M2C(char *s)
{ static char* Mcode[]={
    ".-", "-...", "-.-.","-..",       \
    ".","..-.","--.","....",          \
    "..",".---","-.-",".-..",         \
    "--","-.","---",".--.",            \
    "--.-",".-.","...","-",            \
    "..-","...-",".--","-..-",         \
    "-.--","--..",                     \
    "-----",".----","..---","...--",   \
    "....-",".....","-....","--...",   \
    "---..","----."};
    int i=-1; while (strcmp(s,Mcode[++i]));
    return i+(i<26?'A':'0'-26);
}

char * f(char *r)
{ char c,s[10]; int idx=0,ridx=0,slashCnt=0;
  while ((c=getchar())!='\n')
     if (c!='/')
     { s[idx++]=c;
       if (slashCnt>1) r[ridx++]=(slashCnt==3)?' ':'.';
       slashCnt=0;
     }
     else
	 { if (!slashCnt) idx=s[idx]=0,r[ridx++]=M2C(s);
       slashCnt++;
	 }
  if (idx)  s[idx]=0, r[ridx++]=M2C(s); 
  if (slashCnt>1) r[ridx++]=(slashCnt==3)?' ':'.';
  r[ridx]=0;return r;
}

int main()
{ int I,T,n; char r[1000]={0};
  for(scanf("%d\n",&T),I=0;I<T;I++)
      printf("case #%d:\n""%s\n",I,f(r));
  return 0;
}
