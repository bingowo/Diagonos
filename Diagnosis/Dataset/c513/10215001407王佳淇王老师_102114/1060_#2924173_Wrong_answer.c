#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main(){
	char str[10000];
	char  s[10000];
	scanf("%s",str);
	int len=strlen(str);
	int i=0,j,k=0,start,max=0;
	for(;i<len;i++){
		if(isalpha(str[i])) continue;
		else{start=i;
			int z=0;
			for(j=start;isdigit(str[j]);j++)
			{s[z]=str[j];
			z++;}
			s[z]='\0';
			max=fmax(max,strlen(s));
			memset(s,0,10000);
		}
		
	}
	printf("%d",max);
	return 0;
} 