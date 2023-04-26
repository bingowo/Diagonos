#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char alphabet[26];
int c;
for(c=0;c<26;c++)
{
	alphabet[i]=i+1;
}//alphabet 0-25 A-Z  [c]1-26 sort
int main()
{
	char sort[26];
	scanf("%s",sort);
	int i;
	for(i=0;i<26;i++)
	{
		alphabet[sort[i]-'A']=i+1;
	}//顺序
	 
	return 0;
}