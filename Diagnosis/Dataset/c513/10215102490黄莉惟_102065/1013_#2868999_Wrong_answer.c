#include<stdio.h>
#include<string.h>
int main(){
    char s[30];
    long long int sum1;   //分子 
	long long int sum2;    //分母
    scanf("%s",s);
    int m,i;
    long long int sum=0;
    long long int k=1;
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
	if(m!=strlen(s)){
		long long int t;
		k=1;
		sum1=0;
		for(i=m+1;i<strlen(s);i++){
			k*=3;
		} 
		sum2=k;
		k/=3;
		for(i=m+1;i<strlen(s);i++){
			sum1=sum1+(num(s[i]))*k;
			k/=3;
		}
		if(sum1<0){
		    sum1=sum1+sum2;
		    sum-=1;
		}
		t=GCD(sum1,sum2);
	}
	if(m==strlen(s)){
	    printf("%lld",sum);
	}else{
	    printf("%lld %lld %lld",sum,sum1,sum2);
		
	}
	
}
int GCD(long long int m,long long int n)
{
    long long int i;
    if(m>=n){
        for(i=n;i>0;i--){
            if(m%i==0&&n%i==0){
                return i;
            }
        }
    }else{
        for(i=m;i>0;i--){
            if(m%i==0&&n%i==0){
                return i;
            }
        }
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