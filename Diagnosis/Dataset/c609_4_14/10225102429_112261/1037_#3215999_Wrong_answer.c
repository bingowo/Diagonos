#include <stdio.h>
#define Maxlen 1000000
char s[Maxlen],t[63],v[63];
int a[128];
#include <string.h>
int main()
{
	scanf("%s",s);
	memset(a,0,sizeof(a));
	for(int i = 0,k = 0; i<strlen(s); i++)
	{
		if(!a[s[i]]) {
			a[s[i]] = 1;
//			printf("%d",a[s[i]]);
			v[k++] = s[i];
//			printf("%c",s[i]);
		}
		else
		{
			if(strlen(t)<strlen(v)) 
			{
				strcpy(t,v);
			}
//			k = 0;
//			printf("v = %s\n",v);
			memset(v,0,k*sizeof(char));
			memset(a,0,sizeof(a));
			a[s[i]] = 1;
			v[0] = s[i];
			k = 1;
		}
//		printf("%s\n",v);
	}
	if(strlen(t)<strlen(v)) 
	{
		strcpy(t,v);
	}
	printf("%s",t);
	return 0;
} 
