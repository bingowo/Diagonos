#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int N;
	int R;
} TAB;

void change (TAB* p1)
{
	if ((p1->N)<0) printf("-");
	int t=abs(p1->N);
	int f=p1->R;
	char s[100];
	if((p1->R)<10){
		int i=0;
		if (t==0) printf("0");
		while(t>0){
			int k=t%f;
			char c='0'+k;
			s[i]=c;
			i++;
			t=t/f;
		}
		s[i]=0;
		for (int j=i-1;j>=0;j--) {
			printf("%c",s[j]);
		}
		printf("\n");
	}
	else if ((p1->R)==10) printf("%d\n",p1->N);
	else {
		if (t==0) printf("0");
		int i=0;
		while (t>0){
			int k=t%f;
			char c;
			if (k>=10) c='A'+k-10;
			else c='0'+k;
			s[i]=c;
			i++;
			t=t/f;
		}
		s[i]=0;
		for (int j=i-1;j>=0;j--) {
			printf("%c",s[j]);
		}
		printf("\n");
	}
}

int main()
{
	
	int n;
	scanf("%d",&n);
	TAB* p;
	p=(TAB*)malloc(n*sizeof(TAB));
	for(int i=0;i<n;i++){
		scanf("%d %d",&((p+i)->N),&((p+i)->R));
	}
	for (int j=0;j<n;j++){
		TAB* p1=p+j;
		change(p1);
	}
	free (p);
	return 0;
}