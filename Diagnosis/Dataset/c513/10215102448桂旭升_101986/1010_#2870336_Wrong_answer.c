#include<stdio.h>
#include<string.h>

char B[11] = {0};//每三个数的二进制 
char C[501];//输入的数字串
void reverse(char s[]) {
    int  R = strlen(s);
	if (R  <= 1)
		return ;
	else {
		char tmp = s[0];
		s[0] = s[R-1];
		s[R - 1] = '\0';
		reverse(s+1);
		s[R - 1] = tmp;
	}
}
void f1(int a){
	int i = 0, j = 0;
	for(j = 0; j < 11; j++){
		B[j] = 0;
	}
	if(a < 2)B[i] = a;
	else{
		while(a >= 2){
		B[i] = a%2 + '0';
		a = a/2;
		i++;
		}
		B[i] = a + '0';i++;
		}
	while(i < 10){
		B[i] = '0';i++;
	}
	reverse(B);
	for(i = 0; i < 10; i++){
		printf("%c", B[i]);
	}
}
void f2(int a){
	int i = 0, j = 0;
	for(j = 0; j < 11; j++){
		B[j] = 0;
	}
	if(a < 2)B[i] = a;
	else{
		while(a >= 2){
		B[i] = a%2;
		a = a/2;
		i++;
		}
		B[i++] = a;
	
	}
	while(i < 7){
		B[i] = '0';i++;
	}
	reverse(B);
	for(i = 0; i < 7; i++){
		printf("%c", B[i]);
	}
}
void f3(int a){
	int i = 0, j = 0;
	for(j = 0; j < 11; j++){
		B[j] = 0;
	}
	if(a < 2)B[i] = a;
	else{
		while(a >= 2){
		B[i] = a%2;
		a = a/2;
		i++;
		}
		B[i++] = a;
	}
	while(i < 4){
		B[i] = '0';i++;
	}
	reverse(B);
	for(i = 0; i < 4; i++){
		printf("%c", B[i]);
	}
}
int ctoi(){
	int len = strlen(C), i = 0, j = 0, flag = 0, ten = 0;
	for(i = 0; i < len/3;i++){
		for(j = 0; j < 3; j++){
			ten = ten * 10 + (C[i] - '0');
		}
		f1(ten);
		ten = 0;
	}
	if(len%3 == 2){
		for(i = 0; i < len%3; i++){
			ten = ten * 10 + (C[i] - '0');
		}
		f2(ten);
	}
	if(len%3 == 1){
		for(i = 0; i < len%3; i++){
			ten = ten * 10 + (C[i] - '0');
		}
		f3(ten);
	}
	return 0;
}
int main()

{
    int i;
    scanf("%s", &C);
	printf("0001");
    f1(strlen(C));ctoi();
    

}
