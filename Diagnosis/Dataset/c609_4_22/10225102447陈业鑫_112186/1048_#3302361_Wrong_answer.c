#include<stdio.h>
#include<string.h>
//数组形式全加器
void add_char_plus(char *a, char *b, char *ans){
	char carry = '0';
	for(int i=0;i<100;i++){
		if(a[i]=='0'&&a[i+1]=='0'&&b[i]=='0'&&b[i+1]=='0'&&carry=='0')break;
		int ret = a[i]+b[i]+carry-48*3;
		carry = ret/10+48;
		ans[i] = ret%10+48;
	}
}
void resev(char*a){
	int len = 0;
	int tp = 0;
	for(int i=0;i<=29;i++){
		if(a[i]=='0')tp++;
		if(a[i]!='0'&&tp>0)tp = 0;
		if(tp==5)break;
		len++;
	}
	len-=4;
	a[len--] = '\0';
	tp = 0;
	while(tp!=len){
		char temp = a[tp];
		a[tp] = a[len];
		a[len] = temp;
		tp++;
		len--;
	}
}
int main(){
	int num = 0;
	int getint[10] = {0};
	scanf("%d", &num);
	for(int i = 0;i<num;i++){
		scanf("%d", &getint[i]);
	}
	char a[31] = {'0'};
	char b[31] = {'1'};
	char c[31] = {'0'};//temp
	for(int i=0;i<30;i++){
		if(i==0){
			a[i] = '0';
			b[i] = '1';
			c[i] = '0';
			continue;
		}
		a[i] = '0';
		b[i] = '0';
		c[i] = '0';
	}
	int max = 0;
	for(int i = 0;i<num;i++){
	    if(getint[i]>max)max = getint[i];
		if(getint[i]<2){
		    printf("case #%d:\n", i);
		    printf("%d\n", getint[i]);
		}
		else{
			for(int j = max;j<=getint[i];j++){
				add_char_plus(a, b, c);				
				if(j==getint[i]){
					resev(c);
					printf("case #%d:\n", i);
					printf("%s\n", c);
					memset(c, '0', 30);
				}
				strcpy(a, b);
				strcpy(b, c);
				memset(c, '0', 30);
			}
		}
	}
	return 0;
}