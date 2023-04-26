#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	char *n1;
	char *n2;	
}p;
int cmp1(const void* a, const void* b){
	if(strcmp((*(p*)a).n2,(*(p*)b).n2)!=0) return strcmp((*(p*)a).n2,(*(p*)b).n2);
	else return strcmp((*(p*)b).n1,(*(p*)a).n1);
}
int main(){
	int i,n,j;
	//char *p=(char *)malloc(sizeof(int)*1e6);
	scanf("%d",&n);
	getchar();
	p *a=(p*)malloc(sizeof(p)*n);
	for(i=0;i<n;i++){
		//printf("%d %d\n",i,n);
		//char *t=(char *)malloc(sizeof(char));
		int cnt1=0;
		int cnt2=0;
		char cc;
		int f=0;
		char *t1=NULL,*t2=NULL;
		while(scanf("%c",&cc)){
			//printf("%c",cc);
			if(cc=='\n') break;
			if(cc=='@'){
				f=1;
				continue;
			}
			else if(f==0){
				cnt1++;
				t1=(char*)realloc(t1,sizeof(char)*(cnt1+1));
				t1[cnt1-1]=cc;
				//printf("%d\n",cnt1);
			}
			else{
				cnt2++;
				t2=(char*)realloc(t2,sizeof(char)*(cnt2+1));
				t2[cnt2-1]=cc;
			}		
		
		}
		t1[cnt1]='\0';
		t2[cnt2]='\0';
		//strncpy(t1,t1,cnt1);
		//strncpy(t2,t2,cnt2);
		//printf("%s 			%s\n",t1,t2);
		//t1=(char *)malloc(sizeof(char)*strlen(t));
		//t2=(char *)malloc(sizeof(char)*strlen(t));
		a[i].n1=(char *)malloc(sizeof(char)*(cnt1+1));
		a[i].n2=(char *)malloc(sizeof(char)*(cnt2+1));
		//int f=0;
		//int l1=0,l2=0;
		//printf("st=%d",strlen(t));
		/*for(j=0;j<strlen(t);j++){
			if(t[j]=='@') f=1;
			else if(f==0) t1[l1++]=t[j];
			else t2[l2++]=t[j];
			//printf(".");
		}*/ 
		//a[i].n1 = strtok(t,"@");
        //a[i].n2 = strtok(NULL,"@");
		
		strcpy(a[i].n1,t1);
		strcpy(a[i].n2,t2);
		//free(t1);
		//free(t2);
		//printf("sdfsd");
	//	printf("%s\n%s\n",a[i].n1,a[i].n2);
	}
	qsort((void *)a,n,sizeof(a[0]),cmp1);
	for(i=0;i<n;i++){
		printf("%s@%s\n",a[i].n1,a[i].n2);
	}
}
/*8
84934804@qq.com
eruie@ecnu.edu.cn
rtff@163.com
fdll@ecnu.edu.cn
598695@qq.com
23485@qq.com
rieruer@163.com
39489384@qq.com*/

