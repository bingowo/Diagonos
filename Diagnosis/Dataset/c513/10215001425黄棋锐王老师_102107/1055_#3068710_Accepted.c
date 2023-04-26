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
      for(i=0;s[i];i++){
      	if(m[s[i]]>=st)//重复就重置起点 
		  {
      		st=m[s[i]]+1;
      		m[s[i]]=i;//重复的字符也要设位置 
			  }
		else{//记录字符最后出现的位置 
			m[s[i]]=i;
			if((i-st+1)>l){
				start=st;
				l=i-st+1;//记录无重复的长度 
			}
		}
		  } 
	  for(i=0;i<l;i++) 
	  printf("%c",s[start+i]);
		return 0;
}