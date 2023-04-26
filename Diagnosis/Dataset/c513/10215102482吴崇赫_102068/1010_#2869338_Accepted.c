#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 505 // max input string length
#define M 200

char* transtring(char* s) {
	int n = strlen(s);
	char* ret = (char*)malloc(10);
	for (int i = 0;i < 10;++i)ret[i] = '\0';
	int a = atoi(s);
	
	if (n == 1) {
		int index = 3;
    	while (a) {
		ret[index--] = a % 2 + '0';
		a >>= 1;
	    }
	    for(int i=0;i<=index;++i)ret[i]='0';
	}
	else if (n == 2) {
	    int index = 6;
	    while (a) {
		ret[index--] = a % 2 + '0';
		a >>= 1;
	    }
	    for(int i=0;i<=index;++i)ret[i]='0';
	}
	else {
		int index = 9;
	    while (a) {
		ret[index--] = a % 2 + '0';
		a >>= 1;
	    }
	    for(int i=0;i<=index;++i)ret[i]='0';
	}
	return ret;
}

char* transint(int a) {
	char* ret = (char*)malloc(10);
	for (int i = 0;i < 10;++i)ret[i] = '\0';
	int index = 9;
	while (a) {
		ret[index--] = a % 2 + '0';
		a >>= 1;
	}
	
	while (index > -1)ret[index--] = '0';
	return ret;
}

int main(){
    char input[N] = { '\0' };
	scanf("%s", input);
	int length = strlen(input);
	char ans[5005]={'\0'};
	ans[0] = ans[1] = ans[2] = '0';ans[3] = '1';
	strcat(ans, transint(length));
	for(int i=0;i<length;i+=3){
	    char temp[5]={'\0'};
	    if(length-i==1){
	        temp[0]=input[i];
	        //printf("%s\n",temp);
	        strcat(ans, transtring(temp));
	    }
	    else if(length-i==2){
	        temp[0]=input[i];temp[1]=input[i+1];
	        //printf("%s\n",temp);
	        strcat(ans, transtring(temp));
	    }
	    else{
	        temp[0]=input[i];temp[1]=input[i+1];temp[2]=input[i+2];
	        //printf("%s\n",temp);
	        strcat(ans, transtring(temp));
	    }
	}
	printf("%s",ans);
	return 0;
}