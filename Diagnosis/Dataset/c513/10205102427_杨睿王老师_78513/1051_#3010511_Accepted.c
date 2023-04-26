#include <stdio.h>
#include <string.h>
char table[65];
int main(){
	memset(table,'\0',sizeof(char));
	for(int i=0;i<64;i++){
		if(i<=25){
			table[i]=65+i;
		}
		else if(i<=51){
			table[i]=71+i;
		}
		else if(i<=61){
			table[i]=i-4;
		}
		else if(i==62){
			table[i]='+';
		}
		else if(i==63){
			table[i]='/';
		}
		//printf("%c",table[i]);
	}
	
	int i,T;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		printf("case #%d:\n",i);
		char s[101];
		memset(s,'\0',sizeof(char));
		scanf("%s",&s);
		int l=strlen(s);
		int lb=0;
		int b[1000];
		//printf("\n%d\n",l);
		for(int j=0;j<l;j++){
			memset(b,0,sizeof(int));		
			//printf("\n pass%d:\n",j);
			int templb=0;
			int temp=s[j];
			int tempb[8];
			memset(tempb,0,sizeof(int));
			int y=0;
			while(temp>0){
				tempb[templb]=temp%2;
				temp/=2;
				templb++;
				//printf("%d",tempb[templb-1]);
			}
			while(templb<8){
				tempb[templb]=0;
				templb++;
			}
			//printf("\n");
			for(y=7;y>=0;y--){
				b[lb]=tempb[y];
				//printf("%d",b[lb]);	
				lb++;
			}
			//lb++;
		}
		
		/*printf("\ntest-binary-1:\n");
		for(int o=0;o<lb;o++){
			printf("%d",b[o]);
		}
		printf("\n");*/	
		int rest=6-lb%6;
		if(rest!=6){
			for(int j=0;j<rest;j++){
				b[lb]=0;
				lb++;
			}
		}
		//binary finished
		/*printf("test-binary-2:\n");
		for(int o=0;o<lb;o++){
			printf("%d",b[o]);
		}
		printf("\n");*/
		char res[10000];
		int lr=0;
		int q=0;
		while(q<lb){
			int num=0;
			for(int w=q;w<q+5;w++){
				num=(num+b[w])*2;
			}
			num+=b[q+5];
			res[lr]=table[num];
			//printf("test-num:%d\n",num);
			lr++;
			q+=6;
		}
		int restf=4-lr%4;
		if(restf!=4){
			for(int e=0;e<restf;e++){
				res[lr]='=';
				lr++;				
			}
		}
		for(int u=0;u<lr;u++){
			printf("%c",res[u]);
		}
		printf("\n");
	}
}