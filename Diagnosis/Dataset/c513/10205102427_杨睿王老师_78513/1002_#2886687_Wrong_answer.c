//1002_test
#include <stdio.h>
typedef struct number{
	int v;
	char w;
	int p;
}N;
int main(){
	int T,i;
	scanf("%d",&T);
	char ch=getchar();
	for(i=0;i<T;i++){
		printf("case #%d:\n",i);
		N a[63];
		int l=0,flag=0;
		while((ch=getchar())!='\n'){
			a[l].w=ch;
			a[l].v=-1; 
			l++;
		}
		a[0].v=1;
		for(int q=0;q<l;q++){
			if(a[q].w!=a[0].w){
				a[q].v=0;
				break;
			}
		}
		/*for(int q=0;q<l;q++){
			printf("%d",a[q].v);
		}
		printf("\n");*/
		int cnt=2;
		for(int q=1;q<=l;q++){
			int t=0;
			for(t=0;t<q;t++){
				if(a[t].w==a[q].w){
					flag=1;
					break;
				}
			}
			if(flag==1){
				a[q].v=a[t].v;
			}
			else if(a[q].v!=0){
				a[q].v=q;
				cnt++;
			}
			flag=0;
		}
		
		/*for(int q=0;q<l;q++){
			printf("%d",a[q].v);
		}
		printf("\n%d\n",l);*/
		unsigned long long int ans=0;
		for(int q=0;q<l-1;q++){
			ans=(ans+a[q].v)*cnt;
		}
		//printf("%d\n",cnt);
		ans=ans+a[l-1].v;
		printf("%lld\n",ans);
	}
}