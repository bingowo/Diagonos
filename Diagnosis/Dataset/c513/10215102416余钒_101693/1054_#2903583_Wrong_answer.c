#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int n,T,id[2005],l[2005];
char s[1000005];
int main() {
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		scanf("%d\n",&n);
		gets(s);
		int cnt=0;
		id[++cnt]=l[1]=0;
		for(int i=0;s[i];i++)
			if(s[i]==' ') s[i]=0,id[++cnt]=i+1,l[cnt]=0; 
			else l[cnt]++;
		int nwcnt=0,nwlen=0;
		printf("case #%d:\n",c);
		for(int i=1;i<=cnt;i++){
			nwcnt++,nwlen+=l[i];
			if(nwcnt-1+nwlen>n){
				nwcnt--,nwlen-=l[i];
				int tots=(n-nwlen)/(nwcnt-1),res=(n-nwlen)%(nwcnt-1);
				for(int j=0;j<nwcnt;j++){
					if(j!=0){
						for(int k=0;k<tots;k++) putchar(' ');
						if(nwcnt-j<=res) putchar(' ');
					}printf("%s",s+id[i-nwcnt+j]);
					if(j==nwcnt-1) puts("");
				}
				i--;
				nwcnt=0,nwlen=0;
			}else if(i==cnt){
				int lasl=n;
				for(int j=i-nwcnt+1;j<=cnt;j++){
					printf("%s",s+id[j]);
					lasl+=l[j];
					if(lasl>0) putchar(' '),lasl--;
				}
				while(lasl) putchar(' '),lasl--;
			}
		}
		puts("");
	} 
	return 0;
}
