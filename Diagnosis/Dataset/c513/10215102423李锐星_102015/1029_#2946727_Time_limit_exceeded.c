#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b)
{
	char c,d;
	c=*(char*)a;
	d=*(char*)b;
	if(c<d){
		return -1;
	}
	else{
		return 1;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	int i;
	char all[201],letter[201],c;
	for (i=0;i<T;i++){
		printf("case #%d:",i);
		int j=0,k=0;
		while((c=getchar())!='\n'){
			while(c!=' '){
				all[j]=c;
				j++;
				if(c>='A'&&c<='Z'){
					letter[k]=c;
					k++;
				}
			}
			if(c==' '){
				k=0;
				qsort(letter,strlen(letter),sizeof(letter[0]),cmp);
				for (j=0;j<strlen(all);j++){
					if(all[j]>='A'&&all[j]<='Z'){
						all[j]=letter[k];
						k++;
					}
				}
				k=0;
				j=0;
				printf("%s ",all);
			}
		}
		printf("\n");
	}
	return 0;
}