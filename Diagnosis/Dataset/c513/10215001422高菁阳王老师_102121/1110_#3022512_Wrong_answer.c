#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void ans(char*s,int *a1,int *b1,char *c){
	int a=*a1,b=*b1;
	int m=0,flag=0,sign=0,i=0;
	while(s[i]){
		m=0,sign=1;
		if(s[i]=='+'){
			sign=1;
			i++;
		}
		if(s[i]=='-'){
			sign=-1;
			i++;
		}
		if(s[i]>='a'&&s[i]<='z'){
			*c=s[i];
			m=1;
			i++;
			if(flag)
				a+=sign*m;
			else a-=sign*m;
			continue;
		}
		else if(s[i]>='0'&&s[i]<='9'){
			while(s[i]>='0'&&s[i]<='9'){
				m=10*m+s[i]-'0';
				i++;
			}
		if(s[i]>='a'&&s[i]<='z')
			{
				*c=s[i];
				if(flag)
					a+=sign*m;
				else
					a-=sign*m;
				i++; 
			}
		else{
			if(flag)
				b+=sign*m;
			else	
			b-=sign*m;
			continue;
		}		
		}
		if(s[i]=='='){
			flag=0;
			i++;
		}
	}
}
int main(int argc, char *argv[]) {
	char s[81],c;
    scanf("%s",s);
    int a=1,b=0;
	ans(s,&a,&b,&c);
	double res;
	res=(double)b/(double)a;
	printf("%c=%.3f",c,res);
	return 0;
}