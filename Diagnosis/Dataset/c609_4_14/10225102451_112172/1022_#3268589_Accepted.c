#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char s[2000005];
struct node {
	int p1, p2;
} A[500005];
 
int cmp(const void* a,const void* b) {
	struct node x = *(struct node *)a,y = *(struct node *)b;
	if(strcmp(s + x.p2, s + y.p2) != 0) return strcmp(s + x.p2, s + y.p2);
	else return strcmp(s + y.p1, s + x.p1);}
int main() {
	scanf("%d", &n);
	int l = 0;
	for(int i = 0; i < n; i ++) {
		A[i].p1 = l, scanf("%s", s + l); 
		for(int j = 0 ;; j ++)
			if(s[l + j] == '@') {
				A[i].p2 = l + j + 1; 
				break;
			}
		l += strlen(s + l) + 1;
	}
	qsort(A , n, sizeof(struct node), cmp);
	for(int i = 0; i < n; i ++)
		printf("%s\n",s + A[i].p1);
	return 0;
}
