#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int chu(char* m,int len)
{
    int jieguo=0,yushu=0;
    for(int i=0;i<len;i++){
        int shu=m[i]-'0';
        jieguo=(yushu*10+shu)/2;
        yushu=(yushu*10+shu)%2;
        jieguo=jieguo%10;
        m[i]=jieguo+'0';
    }
    if(yushu>0) return 1;
    else return 0;
}

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
        scanf("%s",m);
		len=strlen(m);
		int size=0;
		char n[10000];
		while(1){
            int x=0,k=0;
            x=chu(m,len);
            n[size++]=x+'0';
            for(;k<len;k++){
                if(m[k]>'0') break;
            }
            if(k==len) break;
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
