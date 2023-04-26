#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

 int main()
 {
 	 int k,T,M;
 	 scanf("%d",&T);
 	 for(k=0;k<T;k++){
 	 	scanf("%d",&M);
 	 	char s[2005]={'\0'};
 	 	gets(s);
 	 	int sl=strlen(s);
 	 	printf("case #%d:\n",k);
 	 	int i=0,start;
 	 	for(i=0;s[i]==' ';i++);
 	 	while(i<sl){//一行一行处理 
 	 		int wordn=0,space=0,wordl=0;//一行中，n单词个数，space空格个数，l单词总长度 
 	 		start=i;
 	 		for(;wordl+wordn<=M&&i<sl;)//取一行要输出的单词 
			  {
 	 			int l,p;
 	 			for(l=0,p=i;s[p]!=' ';p++,l++);//找下一个单词 
 	 			if(wordl+l+wordn<=M){
 	 				wordl+=l;
 	 				wordn++;
 	 				for(i=p;s[i]==' ';i++);//跳过原文空格 
				  }
				  else break;
			  }
			  space=M-wordl;
 	 		int j=start;
 	 		while(j<i)//输出此行 
			  { int d;
 	 		for(;s[j]!=' '&&j<sl;j++) printf("%c",s[j]);
 	 		wordn--;//还剩的单词数 
 	 		for(;s[j]==' ';j++);//跳过原文空格 
 	 		for(d=0;wordn&&d<(space/wordn);d++)//排版空格 
 	 				printf(" ");
 	 			space-=d;
 	 			wordn--;
 	 		}
 	 		
		  }
	  }
		return 0;
}