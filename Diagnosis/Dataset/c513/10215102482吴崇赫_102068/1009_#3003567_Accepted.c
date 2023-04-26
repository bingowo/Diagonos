#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int Gcd(int m,int n)
{
    if(n==0)
       return m;
    return Gcd(n,m%n);
}
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	for(int i = 0;i < n;i++){
		char a[130];
		int cout = 0;
		gets(a);
		for(int j = 0;a[j] != '\0';j++){
				int cmp = 1;
				for(int k = 0;k < 8;k++){
				int flag = a[j] & cmp;
				if(flag) cout++;
				cmp = cmp<<1;
			}
		}
		int b = strlen(a)*8;
		printf("%d/%d\n",cout/Gcd(cout,b),b/Gcd(cout,b));
	}
}