#include<stdio.h>
int GCD(int m,int n);
int main(void)
{
	int n;
	scanf("%d\n",&n);

	for(int i = 0; i < n; i++){
		char input[122];
		fgets(input,sizeof(input),stdin);

		int size_all = 0;
		char *test;
		int num_1 = 0;

		for(test = input; *test != '\n' && *test != '\0'; test++){
            int in = *test;
			for(int j = 0; j < 8*sizeof(char); j++){
   				if(in & (1<<j))
        			num_1++;
			}
		}

		size_all = (test - input)*8;
        //printf("%d\n",size_all);
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