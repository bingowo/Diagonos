#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
typedef struct{
	char c;
	double frequency;
}word;
int cmp(const void* a,const void* b); 
int main(){
	int T;
	scanf("%d",&T);
	double tab[27];
	char a;
	for(int i = 0;i < T;i++){
		for(int j = 0;j < 26;j++){
			scanf("%lf",&tab[j]);
		}
		word* p = (word*)malloc(sizeof(word) * 101);
		int k = 0; 
		getchar();
		while((a = getchar()) != '\n'){
			(p+k)->c = a;
			if(a>='a' && a<='z')
				(p+k)->frequency = tab[a-'a'];
			else
				(p+k)->frequency = tab[a - 'A'];
			k++;
		} 
		qsort(p,k,sizeof(word),cmp);
		printf("case #%d:\n",i);
		for(int cnt = 0;cnt < k;cnt++){
			printf("%c",(p+cnt)->c);
		}
		printf("\n");
		free(p);
		memset(tab,0,27);
	}
}
int cmp(const void* a,const void* b){
	word* aa = (word*)a;
	word* bb = (word*)b;
	char x = aa->c,y = bb->c;
	if(!isupper(aa->c))
		x = aa->c -'a' +'A';
	if(!isupper(bb->c))
		y = bb->c -'a' +'A';
	if(fabs(aa->frequency-bb->frequency) < 1e-9){
		if(x == y)
			return bb->c - aa->c;
		else
			return x - y;
	}else{
		if(aa->frequency > bb->frequency)
			return -1;
		else
			return 1;
	}
}