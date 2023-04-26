#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mul(char* ans)
{
    int len=strlen(ans);
    int jieguo=0,jinwei=0;
    for(int i=0;i<len;i++){
        jieguo=(ans[i]-'0')*2+jinwei;
        if(jieguo>=10){
            jinwei=jieguo/10;
            jieguo=jieguo%10;
            ans[i]=jieguo+'0';
        }
        else {
            jinwei=0;
            ans[i]=jieguo+'0';
        }
    }
    if(jinwei>0) {
        ans[len]=jinwei+'0';
        ans[len+1]='\0';
    }
}

int main(){
	char m[101];
	int len;
	int T=0;
	scanf("%d",&T);
	for(int t=0;t<T;t++){
        scanf("%s",&m);
		len=strlen(m);
		int sum=1,size=0;
		char n[10000];
		while(sum){
			sum=0;
			for(int i=0;i<len;i++){
				int x=m[i]-'0';
				int d=x/2;
				sum+=d;
				if(i<len-1){
					m[i+1]=x%2*10+m[i+1];
				}
				if(i==len-1){
					n[size++]=x%2+'0';
				}
				m[i]=d+'0';
			}
		}
		n[size]=0;
		char ans[1000];
		ans[0]=n[0];
		ans[1]=0;
		for(int i=1;i<size;i++){
            mul(ans);
            if(n[i]=='1') ans[0]++;
		}
		printf("case #%d:\n",t);
		for(int i=strlen(ans)-1;i>=0;i--) printf("%c",ans[i]);
		printf("\n");
	}
	return 0;
}
