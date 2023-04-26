#include<stdio.h>
#include<string.h>
int main()
{
    char s[20000];
    scanf("%s",s);
    int l=strlen(s);
    int number=0;
    for(int i=0;i<l-1;i++){
        if(s[i]>'9'&&s[i+1]<='9'){
            number++;
        }
    }
    if(number!=0){
    	int a[number];
    	int t=0;
    	for(int i=0;i<l;i++){
    	    if(s[i]>'9'&&s[i+1]<='9'){
    	        if(s[i+2]>'9'||i+1==l-1){
    	            a[t]=s[i+1]-'0';
    	        }
    	        else if(s[i+3]>'9'||i+2==l-1){
    	            a[t]=(s[i+1]-'0')*10+(s[i+2]-'0');
    	        }
    	        else if(s[i+4]>'9'||i+3==l-1){
    	            a[t]=(s[i+1]-'0')*100+(s[i+2]-'0')*10+(s[i+3]-'0');
    	        }
    	        t++;
    	    }
    	}
    	int begin[number];
    	int end[number];
    	begin[0]=0;
    	int num1=1;
    	int num2=0;
    	for(int i=0;i<l;i++){
    	    if(s[i]<='9'&&s[i+1]>'9'){
    	        begin[num1]=i+1;
    	        num1++;
    	    }
    	    if(s[i]>'9'&&s[i+1]<='9'){
    	        end[num2]=i;
    	        num2++;
    	    }
    	}
    	for(int i=0;i<number;i++){
    	    for(int j=0;j<a[i];j++){
    	        for(int k=begin[i];k<=end[i];k++){
        	        printf("%c",s[k]);
        	    }
        	}
    	}
	}
	else{
		printf("%s",s);
	}
    return 0;
}