#include<stdio.h>
#include<string.h>
const int primes[26] = {97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
void Readnumber(char s[], int num[])
{
	char *p = s;
	int temp = 0, index = 0;
	while(*p!=0){
		if(*p == ','){
			num[index++] = temp;
			temp = 0;
		}else{
			temp = temp * 10 + (*p - '0');	
		}
		p ++;
	}
	num[index++] = temp;
}
void ADD(int num1[], int num2[], int sum[])
{
	int i;
	for(i = 25; num1[i] != -1 || num2[i] != -1 || sum[i] != -1; i --){
		if(num1[i] == -1){
			num1[i] = 0;
		}
		if(num2[i] == -1){
			num2[i] = 0;
		}
		if(sum[i] == -1){
			sum[i] = 0;
		}
		sum[i] = num1[i] + num2[i] + sum[i];
		if(sum[i] >= primes[i]){
			sum[i] -= primes[i];
			sum[i - 1] = 1;
		}
	}
}
void output(int s[])
{
	int i;
	for(i = 0 ; i < 26 ; i ++){
		if(s[i] != -1){
			printf("%d%c", s[i], i == 25 ? '\n' : ',');
		}
	}
}
int main()
{
    int n;   scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[100];
        int a[26]={0},b[26]={0},c[26]={0};
        scanf("%s",s);
        Readnumber(s,a);
        scanf("%s",s);
        Readnumber(s,b);
        ADD(a,b,c);
        printf("case #%d:\n",i);
        output(c);
    }
    return 0;
}
