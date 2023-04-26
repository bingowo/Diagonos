#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int na = *(int *)a, nb = *(int *)b;

    return (na) < (nb) ? -1 : 1;
}

int main()
{
    int c;
	c = getchar();
	if(c == 'A'){
    int a[100] = {0};
    int i = 0;
    int num;
    while(scanf("%d", &num) != EOF){
    	a[i] = num;
    	i++;
	}
    qsort(a, 100, sizeof(int), cmp);
	int b[1001] = {0};
	for(i=0;i<100;i++){
		if(a[i] != 0){
		b[a[i]]++;
		}
	}
	int m = 0;
	for(i=0;i<1001;i++){
		if(b[i] != 0){
			m++;
			if(m == 1){
				printf("%d",i);
				continue;
			}
			printf(" %d",i);
		}
	}
}
if(c == 'D'){
    int a[100] = {0};
    int i = 0;
    int num;
    while(scanf("%d", &num) != EOF){
    	a[i] = num;
    	i++;
	}
    qsort(a, 100, sizeof(int), cmp);
	int b[1001] = {0};
	for(i=0;i<100;i++){
		if(a[i] != 0){
		b[a[i]]++;
		}
	}
	int m = 0;
	for(i=1000;i>=0;i--){
		if(b[i] != 0){
			m++;
			if(m == 1){
				printf("%d",i);
				continue;
			}
			printf(" %d",i);
		}
	}
}

return 0;
}