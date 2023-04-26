#include <stdio.h>
#include <string.h>
typedef struct{
	int sum;	//“前缀”和，但要看是哪个前面 
	char from;	//记录“来”的字母。 
}Block;

Block in[210][210];

void reverse(char s[])
{
	int len = strlen(s);
	char temp;
	for(int i = 0 ; i < len / 2; i ++){
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}

int main(void)
{
	int m, n;
	int temp;
	char path[11000];
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= m; i ++){
		for(int j = 1 ; j <= n ; j ++){
			scanf("%d", &temp);
			if(i == 1 && j == 1){
				in[i][j].sum = temp;
				in[i][j].from = 'N';
			}else if(i == 1){
				//一下都用了“前缀和”的思想 
				in[i][j].sum = in[i][j - 1].sum + temp;
				in[i][j].from = 'R';
			}else if(j == 1){
				in[i][j].sum = in[i - 1][j].sum + temp;
				in[i][j].from = 'D';
			}else{
				if(in[i - 1][j].sum < in[i][j - 1].sum){
					in[i][j].sum = in[i - 1][j].sum + temp;
					in[i][j].from = 'D';					
				}else{
					in[i][j].sum = in[i][j - 1].sum + temp;
					in[i][j].from = 'R';					
				}
			}
		}
	}
	int i = m, j = n, index = 0;
	while(i != 1 || j != 1){
		//反向读取路径，后面再reverse。 
		path[index++] = in[i][j].from;
		if(in[i][j].from == 'R'){
			j -= 1;
		}else if(in[i][j].from == 'D'){
			i -= 1;
		}
	}
	path[index] = '\0';
	reverse(path);
	printf("%d\n", in[m][n].sum);
	printf("%s", path);
}

