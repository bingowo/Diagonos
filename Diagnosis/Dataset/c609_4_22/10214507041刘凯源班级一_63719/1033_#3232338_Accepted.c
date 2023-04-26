#include<stdio.h>
#include<string.h>
char Base64[70];
void sov(char a, char b, char c)
{
	unsigned int A = a;
	unsigned int B = b;
	unsigned int C = c;
//	printf("%c %c %c %u %u %u\n",a, b, c, A, B, C);
	unsigned int x = 0 | (A << 16) | (B << 8) | C;
	unsigned int mod = (1 << 6) - 1;
	char ans[] = {'=','=','=','='};
	for(int i = 3; i >= 0; --i)
	{
		unsigned int tmp = (x >> (i * 6)) & mod;
		ans[3-i] = Base64[tmp];
	}
	if(C == 0)
		ans[3] = '=';
	if(B == 0)
		ans[2] = '=';
	for(int i = 0; i < 4; ++i)
		putchar(ans[i]);
}
int main()
{
	for(char i = 'A'; i <= 'Z'; ++i)
		Base64[i - 'A'] = i;
	for(char i = 'a'; i <= 'z'; ++i)
		Base64[i - 'a' + 26] = i;
	for(char i = '0'; i <= '9'; ++i)
		Base64[i - '0' + 52] = i;
	Base64[62] = '+';
	Base64[63] = '/';
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		printf("case #%d:\n", i-1);
		char s[115] = {0};
		scanf("%s", s);
		int len = strlen(s);
		for(int i = 0; i < len; i += 3)
			sov(s[i], s[i + 1], s[i + 2]);
		putchar('\n');
	}
}