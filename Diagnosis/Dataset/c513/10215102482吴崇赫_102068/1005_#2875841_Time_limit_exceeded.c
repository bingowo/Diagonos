#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isnotInt(double a) {
	int b = a;
	if (b - a != 0.00)return 1;
	else return 0;
}

int dTos(double d) {
	int ans = 0;double temp=d;
	while (isnotInt(temp)) {
		temp = temp * 10;
		ans++;
	}
	return ans;
}

void transEight(char* s) {
	int len = strlen(s);
	double ret = 0;
	for (int i = len - 1;i > 1;--i) {
		ret += s[i] - '0';
		ret /= 8.0;
	}
	//int bit=dTos(ret);
	//printf("%.6lf %d",ret,bit);
	int bit=dTos(ret);
	if(bit==1)printf("%.1lf",ret);
	else if(bit==2)printf("%.2lf",ret);
	else if(bit==3)printf("%.3lf",ret);
	else if(bit==4)printf("%.4lf",ret);
	else if(bit==5)printf("%.5lf",ret);
	else if(bit==6)printf("%.6lf",ret);
	else if(bit==7)printf("%.7lf",ret);
	else if(bit==8)printf("%.8lf",ret);
	else if(bit==9)printf("%.9lf",ret);
	else if(bit==12)printf("%.12lf",ret);
	else if(bit==24)printf("%.24lf",ret);
	else if(bit==2)printf("%.2lf",ret);
	else if(bit==2)printf("%.2lf",ret);
	else printf("%.2lf",ret);
	printf("\n");
}

int main() {
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        char s[55] = { '\0' };
	    scanf("%s", s);
	    printf("case #%d:\n",x++);
	    transEight(s);
	    
    }
	char s[55] = { '\0' };
	scanf("%s", s);
	transEight(s);
	
	return 0;
}