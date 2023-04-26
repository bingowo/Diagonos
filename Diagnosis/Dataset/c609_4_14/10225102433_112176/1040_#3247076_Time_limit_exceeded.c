#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s1[1000];
char s2[1000];
int A[51];
int B[51];

void solve(char *s,int *a)
{
	for(int i = 0;i < strlen(s);i++)
	{
		int time=1,sig=0,num=1;      //分别是次数，正负标志，系数
		for(int j = i;j < strlen(s);j++){
			if(s[i] == '-'){
				sig = 1;
				continue;
			}
			if(s[j] == '-' || s[j] == '+'){
				i = j-1;
				break;
			}
			else if(isdigit(s[j])){    //如果读到了数字 
				num = 0;
				for(int k = j;k < strlen(s);k++){
					num = num*10 + s[k]-'0';
					if(s[k] == 'x'){
						j = k-1;
						break;
					}
					if(k == strlen(s)-1){
						time = 0;
						j = strlen(s)-1;
					}
				}
			}
			else if(s[j] == 'x') continue;
			else if(s[j] == '^'){
				time = 0;
				for(int k = j+1;k < strlen(s);k++){
					time = time*10 + s[k]-'0';
					if(s[k] == '+' || s[k] == '-'){
						j = k-1;
						break;
					}
				}
			}
		}
		a[time] = num;
	}
}

int main(void)
{
    scanf("%s",s1);
    scanf("%s",s2);
	solve(s1,A);
	solve(s2,B);    
}