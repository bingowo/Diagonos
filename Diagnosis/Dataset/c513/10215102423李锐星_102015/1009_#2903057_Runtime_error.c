#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	int a,b;
	char s[121],c;
	for (i=0;i<n;i++){
		a=0;
		j=0;
		while(c=getchar()!=0&&c!='\n'){
			s[j]=c;
			j++;
		}
		s[j]='\0';
		
		b=8*strlen(s);
		for (j=0;j<strlen(s);j++){
			while(s[i]>0){
				if((s[i]&1)==1){
					a+=1;
				}
				s[i]>>=1;
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