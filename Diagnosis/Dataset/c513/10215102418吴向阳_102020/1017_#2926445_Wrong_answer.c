#include <stdio.h>
#include <string.h>

unsigned long long Calculate(const char s[]){
	int a[128];
	a['I']=1,a['V']=5;a['X']=10,a['L']=50,a['C']=100,a['D']=500,a['M']=1000;
	const char ch1='(',ch2=')';
	char *p=strchr(s,ch1),*q=strrchr(s,ch2);
	if (p!=NULL){
		char t[60],m[60],n[60];
		strncpy(m,s,p-s);
		strncpy(t,p+1,q-p-1);
		strncpy(n,q+1,strlen(s)-(q-s));
		return Calculate(m)+Calculate(n)+1000*Calculate(t);
	}
	else {
		const char *o=s;
		unsigned long long num=0;
		while(*o){
			if(a[*o]==a[*(o+1)]){
				int rep=2;
				while(a[*o]==a[*(o+rep)]) rep++;
				num+=rep*a[*o];
				o+=rep;
			}
			else if(a[*o]<a[*(o+1)]&&a[*o]!=1&&a[*o]!=10&&a[*o]!=100){
				num+=a[*o];
				o++;
			}
			else if(a[*o]<a[*(o+1)]&&(a[*o]==1||a[*o]==10||a[*o]==100)){
				num-=a[*o];
				o++;
			}
			else if(a[*o]>a[*(o+1)]){
				num+=a[*o];
				o++;
				if(a[*(o)]==a[*(o+1)]){
					int rep=2;
					while(a[*(o)]==a[*(o+rep)]) rep++;
					num+=a[*(o)]*rep;
					o+=rep;
				}
			}
		}
		return num;
	}
}

int main(){
	char s[60];
	scanf("%s",s);
	unsigned long long num=0;
	num=Calculate(s);
	printf("%llu",num);
	return 0;
}