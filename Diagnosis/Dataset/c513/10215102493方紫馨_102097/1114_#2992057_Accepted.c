#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
void reserve(char s[]){	
	char t ;
	for(int i=0,j=strlen(s)-1;i<j;i++,j--){
		t = s[i];s[i] = s[j];s[j] = t;
	}
}
void trans(int *x,const char *s){
	for(int i=0;i<strlen(s);i++){
		char num[5]={'\0'};
		int a,n;
		if(s[i]=='x'){
			if(i-1<0)
				a = 1;
			else if(s[i-1]=='-')
				a = -1;
			else{
				int cnt=1;
				while(i-cnt>=0){
					num[cnt-1] = s[i-cnt];
					if(s[i-cnt]=='-'||s[i-cnt]=='+'){
						cnt++;break;
					}
					cnt++;
				}
				num[cnt-1] = '\0';
				reserve(num);
				a = atoi(num);
			}
			if(i+1>=strlen(s))
				n = 1;
			else {
				if(s[i+1]=='^')
					n = 2;
				else
					n=1;
			}			
			x[n] = a;
		}
	}
	char num[5] = {'\0'};
	int cnt = 0;
	for(int i = strlen(s)-1;i>=0;i--){
		num[cnt] = s[i];
		if(s[i]=='+'||s[i]=='-'){
			cnt++;break;
		}			
		if(s[i]=='x'){
			num[0]='\0';break;
		}
		cnt++;			
	}
	reserve(num);
	x[0] = atoi(num);
}

typedef struct{
	int a1,a2;
}data;
data va[100];
int gcd(int a){
	int cnt = 1;
	va[0].a1 = 1;
	va[0].a2 = a;
	for(int i=2;i<=a;i++){
		if(a%i==0){
			va[cnt].a1 = i;
			va[cnt].a2 = a/i;
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	int x[3] = {0};
	char s[20];
	scanf("%s",s);
	trans(x,s);
	int a = x[2],b = x[1],c = x[0];
	int na;
	na = gcd(a);
	double x1,x2;
	x1 = (b+sqrt(b*b-4*a*c))/2/a;
	x2 = (b-sqrt(b*b-4*a*c))/2/a;
	double c1,c2;
	int ic1,ic2,sign=0;
	for(int i=0;i<na;i++){
		c1=x1 * va[i].a1;
		c2=x2 * va[i].a2;
		ic1 = (int)c1;
		ic2 = (int)c2;
		if(c1-ic1>=-1e-6&&c1-ic1<=1e-6){
			sign=1;
			if(va[i].a1!=va[i].a2){
				if(va[i].a1>va[i].a2)
					printf("%d %d %d %d",va[i].a2,ic2,va[i].a1,ic1);
				if(va[i].a1<va[i].a2)
					printf("%d %d %d %d",va[i].a1,ic1,va[i].a2,ic2);
			}
			if(va[i].a1==va[i].a2){
				if(ic1<ic2)
					printf("%d %d %d %d",va[i].a1,ic1,va[i].a2,ic2);
				else
					printf("%d %d %d %d",va[i].a1,ic2,va[i].a2,ic1);		
			}
			break;		
		}
	}
	if(sign==0)
		printf("No Answer!");
	return 0;
}