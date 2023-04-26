#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*关键在于cmp的编写*/
double f[26];//输入频率 

int cmp(const void* a, const void* b)
{
	char aa=*(char*)a;
	char bb=*(char*)b;
	char a_=toupper(aa);
	char b_=toupper(bb);
	if(f[a_-'A']==f[b_-'A']) 
	{
		if(aa==(bb+32)) return -1;
		else if(bb==(aa+32)) return 1;
		else return (a_>b_)?1:-1;
	}
	else return (f[a_-'A']<f[b_-'A'])?1:-1;
}


int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<26; j++)
		{
		scanf("%lf",&f[j]);
		}
		
		char s[101];//最多输入100个字符 
		scanf("%s",s);
		
		qsort(s,strlen(s),sizeof(char),cmp); 
		printf("case #%d:\n", i );
		for(int j=0; j<strlen(s); j++)
		{
			printf("%c",s[j]);
		}
		printf("\n");
	}
	return 0;
} 