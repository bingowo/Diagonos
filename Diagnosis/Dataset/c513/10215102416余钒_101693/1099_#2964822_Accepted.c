#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int T;
char A[100005],s[10005];
void init(){
	A[22222]='0',A[12222]='1',A[11222]='2',A[11122]='3',A[11112]='4',A[11111]='5';
	A[21111]='6',A[22111]='7',A[22211]='8',A[22221]='9';
	A[12]='A',A[2111]='B',A[2121]='C',A[211]='D',A[1]='E',A[1121]='F',A[221]='G';
	A[1111]='H',A[11]='I',A[1222]='J',A[212]='K',A[1211]='L',A[22]='M',A[21]='N';
	A[222]='O',A[1221]='P',A[2212]='Q',A[121]='R',A[111]='S',A[2]='T',A[112]='U';
	A[1112]='V',A[122]='W',A[2112]='X',A[2122]='Y',A[2211]='Z';
	
}
int main() {
	scanf("%d",&T);
	init();
	for(int c=0;c<T;c++){
		scanf("%s",s+1);
		int res=0;
		printf("case #%d:\n",c);
		for(int i=1;s[i];i++){
			if(s[i]=='.') res=res*10+1;
			else if(s[i]=='-') res=res*10+2;
			else{
				int cnt=0;
				for(int j=i;s[j];j++){
					if(s[j]!='/') break;
					cnt++;
				}
				putchar(A[res]),res=0;
				if(cnt==3) putchar(' ');
				else if(cnt==5) putchar('.'); 
				i+=cnt-1;
			}
		}
		if(res) putchar(A[res]);
		puts("");
	}
	
	return 0;
}
