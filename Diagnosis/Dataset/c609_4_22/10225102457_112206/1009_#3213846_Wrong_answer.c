#include<stdio.h>
#include<wchar.h>
int GCD(int m,int n);
int main(void)
{
	int n;
	scanf("%d\n",&n);
	
	for(int i = 0; i < n; i++){
		wchar_t input[122];
		fgetws(input,sizeof(input),stdin);
		
		int size_all = 0;
		wchar_t *test;
		int num_1 = 0;
		
		for(test = input; *test != '\n' && *test != '\0'; test++){
			for(unsigned long long j = 0; j < 8*sizeof(wchar_t); j++){
   				if((*test) & (1<<j))
        			num_1++;
			}
		}
		size_all = (test - input)*8;
		int gcd = GCD(size_all,num_1);
		
		printf("%d/%d\n",num_1/gcd,size_all/gcd);
	}
	return 0;
}

int GCD(int m,int n)
{
	int t;
	if(n == 0) return 1;
    t = m%n;
    if(t == 0) return n;
    else return GCD(n,t);
}