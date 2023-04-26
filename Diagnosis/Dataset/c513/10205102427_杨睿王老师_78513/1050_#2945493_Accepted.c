#include <stdio.h>
#include <string.h>
#include <math.h>
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
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
		char *ta=strstr(c,a);
		char *tb=strstr(c,b);
		if(ta==NULL || tb==NULL){
			printf("0\n");
			continue;
		}
		int pamin=ta-c;
		int pbmin=tb-c;
		//pa+=la;
		//printf("test-a-pa:%c %d\n",c[pamin],pamin);
		char rb[81],rc[81],ra[81];
		memset(ra,'\0',81);
		memset(rb,'\0',81);
		memset(rc,'\0',81);
		int rla=la-1;
		int rlb=lb-1;
		int rlc=lc-1;
		//printf("test-ra:\n");
		for(int y=0;y<la;y++){
			ra[y]=a[rla];
			rla--;
			//printf("%c",ra[y]);
		}
		//printf("\n");		
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
		char * tpa=strstr(rc,ra);
		char * tpb=strstr(rc,rb);
		int pamax=tpa-rc+la;		
		int pbmax=tpb-rc+lb;
		pamax=lc-pamax;
		pbmax=lc-pbmax;
		//printf("test-a-pa:%c %d\n",c[pamax],pamax);
		//printf("test-b-pb:%c %d\n",c[pbmax],pbmax);
		int ans=0;
		ans=max(pbmax-pamin-la,pamax-pbmin-lb);
		if(ans<0){
			printf("0\n");
			continue;
		}
		printf("%d\n",ans);		
	}
}