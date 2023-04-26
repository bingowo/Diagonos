#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 int main()
 {    char s[1000001]={'\0'};
      scanf("%s",s);
      int l=0,i=0,st=0,start=0;
      int m[128]={0};
      for(st=0,i=1;i<strlen(s)&&st<strlen(s)-l;i++)
      {    
      	 if(m[s[i]]>=st) {// 
      	 	if((i-st)>l) l=i-st,start=st-1;
      	 	st=m[s[i]]+1;
		   }
      	 else
			 m[s[i]]=i;//记录字符最后一次出现的位置 
	  }
	  for(i=0;i<l-1;i++) 
	  printf("%c",s[start+i]);
		return 0;
}