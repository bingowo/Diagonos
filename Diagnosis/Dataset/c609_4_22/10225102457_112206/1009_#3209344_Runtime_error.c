#include<stdio.h>
#include<wchar.h>
int GCD(int m,int n);
int main(void)
{
	int n;
	scanf("%d\n",&n);
	for(int i = 0; i < n; i++){
		wchar_t input[122];
		fgetws(input,122,stdin);
		
		int size_all = 0;
		wchar_t *test = input;
		int num_1 = 0;
		
		for(;*test != '\n' && *test != '\0';test++){
			for(int v = *test; v != 0; v /= 2){
				if(v % 2)
					num_1++;
			}
		}
		if(*test == '\n') size_all = wcslen(input)*8-8;
		else size_all = wcslen(input)*8;
		
		int gcd = GCD(size_all,num_1);
		
		printf("%d/%d\n",num_1/gcd,size_all/gcd);
	}
	return 0;
}

int GCD(int m,int n)
{
	int t;
    t = m%n;
    if(t == 0) return n;
    else return GCD(n,t);
}