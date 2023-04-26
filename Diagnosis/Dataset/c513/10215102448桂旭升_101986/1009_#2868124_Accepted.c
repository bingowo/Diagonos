#include<stdio.h>
#include<string.h>
char B[500];
int GCD(int m,int n)
{
    int a, b;
    a = m>n?m:n;
    b = m<n?m:n;
    m = a;n = b;
    if(n == 0)return m;
    else return GCD(n, m%n);
}

int f(){
	int res = strlen(B), i = 0, j = 0;unsigned num = 0;
	while(j < res){
		while(i < 8){
			if((B[j] & (1<<i)) != 0)num ++;
			i++;
		}
		i = 0;
		j++;
	}
	printf("%d/%d", num/GCD(num, res*8), res*8/GCD(num, res*8));
	return 0;
}

int main()
{
	int t, i, j;long long n;
	scanf("%d", &t);
	gets(B);
	for(i = 0; i < t; i++){
		for(j = 0; j < 500; j++){
			B[j] = 0;
		}
		gets(B);
		f();
		printf("\n");
		
	}
	return 0;
}