#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
 char *p;
 int cnt;//出现次数 
}DNA;

int cmp1(const void*a,const void*b){
    return strcmp(*(char**)a,*(char**)b);
}

int cmp2(const void*a,const void*b){
	int n1=((DNA*)a)->cnt,n2=((DNA*)b)->cnt;
	char *p1=((DNA*)a)->p,*p2=((DNA*)b)->p;
	if(n1!=n2) return n1>n2?1:-1;
	else return strcmp(p1,p2);
}

int main(){
 	int n,len;
 	char s[21],*p;
 	scanf("%d",&n);
 	char**d;
	 d = (char**)malloc(n*sizeof(char*));
	 
	for(int i=0;i<n;i++){
		memset (s,0,sizeof(s));
		scanf("%s",s);
		len=strlen(s);
		p=(char*)malloc(len+1);
		strcpy(p,s);
	 	*(d+i)=p;
 	}	
 	qsort(d,sizeof(d)/sizeof(d[0]),sizeof(char *),cmp1);
 	DNA* dna;
 	int m=0;
 	dna=(DNA*)malloc(n*sizeof(DNA));
 	dna[0].p=d[0];
 	dna[0].cnt=1;
 	for(int i=1;i<n;i++){
 	 if(strcmp(d[i],d[i-1])==0) dna[m].cnt++;
  
  	else{
   		m++;
   		dna[m].p=d[i];
  		dna[m].cnt=1;
 		}
	}
 qsort(dna,m+1,sizeof(dna[0]),cmp2);
    for(int i=0;i<=m;i++)
        printf("%s\n",dna[i].p);
    free(dna);
    for(int i=0;i<n;i++) free(d[i]);
    free(d);

 return 0;
}