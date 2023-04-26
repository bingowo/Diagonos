#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
	int T;
	scanf("%d",&T);
	char c;
	scanf("%c",&c);
	for(int i=0;i<T;i++){
		char str[1005];
		char dest[1005];
		scanf("%s",str);
		memset(dest,0,sizeof(dest));
		int len=strlen(str);
		int p=0,k,tmp;
		for(int j=len-1;j>1;j--){
			int num=str[j]-'0';
			for(k=0;k<p||num!=0;k++){
				tmp=10*num+(k<p?dest[k]-'0':0);
				dest[k]=tmp/8+'0';
				num=tmp%8;
			}
			p=k;
		}
		printf("case #%d:\n",i);
		printf("0.%s\n",dest);
	}
	return 0;
}