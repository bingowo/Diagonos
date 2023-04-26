#include <stdio.h>
#include <string.h>

int main()
{
	int a,n;
	scanf("%d %d",&a,&n);
	int i;
	char s[100];
	for (i=0;a!=0;i++){
		if(a>0){
			int x;
			x=a%n;
			if(x>=0&&x<=9){
				s[i]=x+'0';
			}
			else{
				s[i]=x+55;
			}
			a/=n;
		}
		else{
			int x;
			x=a%n;
			a/=n;
			if(x==0){
				s[i]='0';
			}
			else{
				a++;
				x=-n+x;
				if(x>0&&x<=9){
					s[i]=x+'0';
				}
				else{
					s[i]=x+55;
				}
			}
		}
	}
	s[i]=0;
	for (i=strlen(s)-1;i>-1;i--){
		printf("%c",s[i]);
	}
	printf("\n");
	return 0;
}