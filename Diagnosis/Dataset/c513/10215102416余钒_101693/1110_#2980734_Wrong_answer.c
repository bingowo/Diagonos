#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char s[10005];
int main() {
	scanf("%s",s);
	char c;
	long long sum1=0,sum2=0,flg=1,hav=1,res=0;
	for(int i=0;s[i];i++){
		if(s[i]=='-') flg=-1*hav;
		else if(s[i]=='+') flg=hav;
		else if(s[i]=='=') hav=-1,flg=hav;
		else if(s[i]>='0'&&s[i]<='9'){
			res=res*10+s[i]-'0';
			if(s[i+1]>='a'&&s[i+1]<='z'){
				c=s[i+1];
				sum2+=res*flg;
				res=0,flg=hav;
				i++;
			}
			else if(s[i+1]<'0'||s[i+1]>'9'){
				sum1+=res*flg;
				res=0,flg=hav;
			}
		}
		else{
			c=s[i];
			sum2+=flg;
			res=0,flg=hav;
		}
	}
	printf("%c=%.3f\n",c,-1.0*sum1/sum2);
	return 0;
}