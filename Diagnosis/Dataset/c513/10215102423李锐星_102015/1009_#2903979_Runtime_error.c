#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	int a,b;
	char s[121],c;
	getchar();
	for (i=0;i<n;i++){
		gets(s);
		a=0;
		b=8*strlen(s);
		for (j=0;j<strlen(s);j++){
			c=s[j];
			while(c>0){
				if(c&1==1){
					a+=1;
				}
				c>>=1;
			}
		}
		if (b%a==0){
			b=b/a;
			a=1;
		}
		printf("%d/%d\n",a,b);
	}
	return 0;
}