#include <stdio.h>
#include <string.h>
char s1[510], s2[510];
void sub(int a[],int b[]){
	for(int i=1;i<=b[0];i++) a[i] -= b[i];
	for(int i=1;i<=a[0];i++){
		if(a[i]<0){
			a[i+1]--;
			a[i] += 10;
		}
	}
}
int main(void)
{
	while(scanf("%s %s",s1,s2)!=EOF){
		int a[510] = {0}, b[510] = {0};
		a[0] = strlen(s1), b[0] = strlen(s2);
		int len = 0;
		for(int i=strlen(s1)-1;i>=0;i--) a[++len] = s1[i]-'0';
		len = 0;
		for(int i=strlen(s2)-1;i>=0;i--) b[++len] = s2[i]-'0';
		if(strcmp(s1,s2)>=0){
			sub(a,b);
			int st = a[0];
			while(st>=1 && a[st]==0) st--;
			if(st>=1){
				for(int i=st;i>=1;i--) {
					printf("%d",a[i]);
				}
			}
			else printf("0");
		}
		else{
			sub(b,a);
			int st = b[0];
			while(st>=1 && b[st]==0) st--;
			if(st>=1){
				putchar('-');
				for(int i=st;i>=1;i--) printf("%d",b[i]);
			}
			else printf("0");
		}
		putchar('\n');
	}
	return 0;
}