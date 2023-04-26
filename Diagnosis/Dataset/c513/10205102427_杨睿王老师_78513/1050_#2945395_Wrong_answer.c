#include <stdio.h>
#include <string.h>
int main(){
	int T,i;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		printf("case #%d:\n",i);
		char a[81],b[81],c[81];
		memset(a,'\0',81);
		memset(b,'\0',81);
		memset(c,'\0',81);
		scanf("%s",&a);
		scanf("%s",&b);
		scanf("%s",&c);
		/*if(strcmp(a,b)==0){
			printf("0\n");
			return 0;
		}*/
		int la=strlen(a);
		int lb=strlen(b);
		int lc=strlen(c);
		int i=0,j=0,p=0,q=0;
		char *tmp=strstr(c,a);
		if(tmp==NULL){
			printf("0\n");
			continue;
		}
		int pa=tmp-c;
		pa+=la;
		//printf("test-a-pa:%c %d\n",c[pa],pa);
		char rb[81],rc[81];
		memset(rb,'\0',81);
		memset(rc,'\0',81);
		int rlb=lb-1;
		int rlc=lc-1;
		//printf("test-rb:\n");
		for(int y=0;y<lb;y++){
			rb[y]=b[rlb];
			rlb--;
			//printf("%c",rb[y]);
		}
		//printf("\n");
		//printf("test-rc:\n");
		for(int y=0;y<lc;y++){
			rc[y]=c[rlc];
			rlc--;
			//printf("%c",rc[y]);
		}
		//printf("\n");
		char * tp=strstr(rc,rb);
		if(tp==NULL){
			printf("0\n");
			continue;
		}		
		int pb=tp-rc+lb;
		//printf("test-b-pb:%c %d\n",c[pb],pb);
		pb=lc-pb;
		//printf("test-b-pb:%c %d\n",c[pb],pb);
		int ans=pb-pa;
		if(ans<0){
			printf("0\n");
			continue;
		}
		printf("%d\n",ans);		
	}
}