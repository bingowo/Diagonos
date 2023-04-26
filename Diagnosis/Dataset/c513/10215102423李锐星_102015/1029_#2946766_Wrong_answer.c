#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void*b)
{
	return *(char*)a-*(char*)b;
}

int main()
{
	char c;
	int n,T;
	scanf("%d",&T);
	n=T;
	char all[201],letter[201];
	while(T--){
		printf("case #%d:\n",n-(T+1));
		int i=0,j=0;
		while((c=getchar())!='\n'){
			all[i]=c;
			i++;
			if(c>='A'&&c<='Z'){
				letter[j]=c;
				j++;
			}
		}
		if(strlen(letter)!=0){
			qsort(letter,j,sizeof(letter[0]),cmp);
			j=0;
			for (i=0;i<strlen(all);i++){
				if(all[i]>='A'&&all[i]<='Z'){
					all[i]=letter[j];
					j++;
				}
			}
		}
		printf("%s\n",all);
		
	}
	return 0;
}