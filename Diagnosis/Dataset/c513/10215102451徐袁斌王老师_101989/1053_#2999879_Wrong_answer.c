#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void add(int a[])
{
	a[1]=a[1]+8;
	if(a[1]>=10) {a[1]=a[1]%10;a[0]++;}
	if(a[0]==2&&a[1]>=4){a[0]-=2;a[1]-=4;}
}
int main()
{
    char s[100];
    int a[6]={0};
    scanf("%s",s);
    while(strcmp(s,"END")!=0)
    {
    	char c[100];
    	strncpy(c,s,6);c[6]='\0';
    	if(strcmp(c,"$GPRMC")!=0) {scanf("%s",s);continue;}
    	long long int d=s[1]^s[2],i;
    	for(i=3;s[i]!='*';i++)
    	{
			d=d^s[i];
		}
		d=d%65536;
		int e=0;
		for(int j=i+1;s[j]!='\0';j++)
		{
			if(s[j]>='0'&&s[j]<='9') e=e*16+s[j]-'0';
			else e=e*16+s[j]-'A'+10;
		}
		if(d!=e){scanf("%s",s);continue;}
    	
    	for(int i=7;i<13;i++)
    	{
			a[i-7]=s[i]-'0';
		}
		add(a);
    	
		scanf("%s",s);
	}
	printf("%d%d:%d%d:%d%d\n",a[0],a[1],a[2],a[3],a[4],a[5]);
}