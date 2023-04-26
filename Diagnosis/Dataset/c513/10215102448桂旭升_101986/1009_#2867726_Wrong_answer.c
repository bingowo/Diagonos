#include<stdio.h>
#include<string.h>
int GCD(int m,int n)
{
    int a, b;
    a = m>n?m:n;
    b = m<n?m:n;
    m = a;n = b;
    if(n == 0)return m;
    else return GCD(n, m%n);
}
char B[50];
int f(){
	int num = 0, res = strlen(B), i = 0, j = 0;
	while(j < res){
		while(i < 8){
			num += B[j]%2;
			B[j] = B[j]/2;
			i++;
			
		}
		i = 0;
		j++;
	}
	printf("%d %d\n", num, res*8);
	printf("%d/%d", num/GCD(num, res*8), res*8/GCD(num, res*8));
	return 0;
}

int main()
{
	int t, i;long long n;
	scanf("%d", &t);
	gets(B);
	for(i = 0; i < t; i++){
		gets(B);
		f();
		printf("\n");
		
	}
	return 0;
}