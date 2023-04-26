#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    scanf("%s",&s);
    int i,chance;
    chance=0;
    long long  sum=0,fz=0,fm=1;  //sum代表整数部分的值，fz表示分子，fm表示分母
    for(i=0;i<strlen(s)&&s[i]!='.';i++){
        if(s[i]=='0') sum=sum*3+0;
        else if(s[i]=='1') sum=sum*3+1;
        else sum=sum*3-1;
        chance=i+1;
    }
    int j;
    for(j=chance+1;j<strlen(s);j++){
        if(s[j]=='1'){
            fz=fz*3+1;
            fm=fm*3;
        }
        else if(s[j]=='0'){
            fz=fz*3;
            fm=fm*3;
        }
        else{
            fz=fz*3-1;
            fm=fm*3;
        }
    }
    if(sum==0) printf("%lld %lld",fz,fm);
    else if(sum>0&&fz<0){
    	fz=fm+fz;
    	sum=sum-1;
    	printf("%lld %lld %lld",sum,fz,fm);
	}
	else if(sum<0&&fz>0){
		fz=fm-fz;
		sum=sum+1;
		printf("%lld %lld %lld",sum,fz,fm);
	}
	else if(fz==0) printf("%lld",sum);
	else printf("%lld %lld %lld",sum,fz,fm);
    
}