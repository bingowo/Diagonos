#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char a[100005],ans[100005];
int main()
{
	scanf("%s",a);
	int len=strlen(a),cnt=0,tap=0;
	for(int i=0;i<len;i++)
	{
		while(tap<len&&a[i]==a[tap])
			tap++;
		if(tap<len&&a[i]<a[tap])
			ans[cnt++]=a[i];
		ans[cnt++]=a[i];
	}
	ans[cnt]='\0';
	printf("%s",ans);
	return 0;
 } 