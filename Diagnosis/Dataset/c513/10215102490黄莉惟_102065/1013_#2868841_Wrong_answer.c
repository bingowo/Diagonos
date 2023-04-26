#include<stdio.h>
#include<string.h>
int main(){
    char s[30];
    scanf("%s",s);
    int m,i;
    int sum=0;
    int k=1;
    m=strlen(s);
    for(i=0;i<strlen(s);i++){
        if(s[i]=='.'){
            m=i;
        }
    }
    for(i=m-1;i>=0;i--){
    	sum=sum+(num(s[i]))*k;
    	k*=3;
	}
	
}
int num(char *a){
	if(a=='1'){
		return 1;
	}else if(a=='0'){
		return 0;
	}else{
		return -1;
	}
}