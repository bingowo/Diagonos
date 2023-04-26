#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>


int main()
{
	char *moose[36]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char ind[1010];
		scanf("%s",ind);
		int l=strlen(ind);
		int a=0;
		char out[1010];int u=0;
		char code[10];int d=0;
		while(a<l)
		{
			d=0;
			while(a<l&&ind[a]!='/')
			{
				code[d++]=ind[a];
				a++;
			}
			code[d]='\0';
			for(int k=0;k<36;k++) 
			{
				if(strcmp(code,moose[k])==0) 
				{
					char ch;
					if(k<26) ch=k+65;else ch=k+22;
					out[u++]=ch;break; 
				}
			}
			int flag=0;
			while(a<l&&ind[a]=='/') flag++,a++;
			if(flag==3) out[u++]=' ';
			else if(flag==5) out[u++]='.';
		}
		out[u]='\0';
		printf("case #%d:\n",i);
		printf("%s\n",out);
	}
	
	
	
	
	
	return 0;
}





