#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long long GCD(long long  x,long long  y){
	long long  r;
	if(x%y==0) return y;
	else { r=x%y;
		GCD(y,r);
	}
	return r;
}
 
int main()
{ char s[1000]={"\0"};
	scanf("%s",s);
	unsigned int p=0;
	long long ansA=0;
	long long ansB=0, ansC=1;
	for (;p<strlen(s);p++) {//整数部分
   	if (s[p]=='.') break;
   	ansA = ansA *3;
   	if (s[p]=='1') ansA += 1;
   	if (s[p]=='2') ansA -= 1;
	}
	p++;
		for (;p<strlen(s);p++) { //小数部分
    		ansB =ansB * 3;      //分子
    	if (s[p]=='2') ansB -= 1;
    	if (s[p]=='1') ansB += 1;  
    	ansC = ansC * 3;      //分母
	}
//数组s存放平衡三进制

	    if(ansA>0&&ansB<0){
	    	ansA--;
	    	ansB=ansC+ansB;
		}
		else if(ansA<0&&ansB>0){
			ansA++;
			ansB=ansC-ansB;
			if(ansA==0) ansB=-ansB;
		}
		long long r=GCD(abs(ansB),abs(ansC));
	    	ansB=ansB/r;ansC=ansC/r;
		if(ansB==0)printf("%lld\n",ansA);
		else {
			if(ansA!=0) printf("%lld ",ansA);
			printf("%lld %lld",ansB,ansC);
		}
		
   
 return 0;
}