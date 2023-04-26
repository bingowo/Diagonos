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
    scanf("%s",s);
    while(strcmp(s,"END")!=0)
    {
    	int a[6]={0};
    	for(int i=7;i<13;i++)
    	{
			a[i-7]=s[i]-'0';
		}
		add(a);
    	printf("%d%d:%d%d:%d%d\n",a[0],a[1],a[2],a[3],a[4],a[5]);
    	
		scanf("%s",s);
	}
}