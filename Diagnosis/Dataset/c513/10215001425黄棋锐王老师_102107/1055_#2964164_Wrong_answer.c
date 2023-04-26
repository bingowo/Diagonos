#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 int main()
 {    char s[1000001]={'\0'};
      scanf("%s",s);
      int l=0,i=0,st=0,start=0;
      int m[128];
      for(i=0;i<128;i++) m[i]=-1;
      for(st=0,i=0;i<strlen(s)&&st<strlen(s)-l;i++)
      {    
      	 if(m[s[i]]>=st) {// 
      	 	if((i-st)>l) l=i-st,start=st;
      	 	st=m[s[i]]+1;
		   }
      	 else
			 m[s[i]]=i;//记录字符最后一次出现的位置 
	  }
	  
	  if(l!=0)
	  {for(i=0;i<l;i++) 
	  printf("%c",s[start+i]);}
	  
	  else printf("%s",s);
		return 0;
}