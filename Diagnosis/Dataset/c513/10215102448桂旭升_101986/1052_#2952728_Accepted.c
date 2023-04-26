#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char s[30] = {'\0'};//zero, one, two, three, four, five, six, seven, eight, nine     w, z, x, g    h, s   v, u, 
int d[128] = {0};
int b[7] = {0};
int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}
int main(){
	int n, len1, len2, len, i, j, k = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%s", &s);
		len = strlen(s);
		//printf("%s\n",s);
		for(j = 0; j < len; j++){
			d[s[j]+32]++;
		}
		if(d['z'] != 0){
			d['e'] -= d['z'];
			d['r'] -= d['z'];
			d['o'] -= d['z'];
			for(j = 0; j < d['z']; j++){
				b[k++] = 0;
			}
			d['z'] = 0;
		}
		if(d['w'] != 0){
			d['t'] -= d['w'];
			d['o'] -= d['w'];
			for(j = 0; j < d['w']; j++){
				b[k++] = 2;
			}
			d['w'] = 0;
		}
		if(d['x'] != 0){
			d['s'] -= d['x'];
			d['i'] -= d['x'];
			for(j = 0; j < d['x']; j++){
				b[k++] = 6;
			}
			d['x'] = 0;
		}
		if(d['g'] != 0){
			d['e'] -= d['g'];
			d['i'] -= d['g'];
			d['h'] -= d['g'];
			d['t'] -= d['g'];
			for(j = 0; j < d['g']; j++){
				b[k++] = 8;
			}
			d['g'] = 0;
		}
		if(d['h'] != 0){
			d['t'] -= d['h'];
			d['r'] -= d['h'];
			d['e'] -= d['h'];
			d['e'] -= d['h'];
			for(j = 0; j < d['h']; j++){
				b[k++] = 3;
			}
			d['h'] = 0;
		}
		if(d['s'] != 0){
			d['e'] -= d['s'];
			d['v'] -= d['s'];
			d['e'] -= d['s'];
			d['n'] -= d['s'];
			for(j = 0; j < d['s']; j++){
				b[k++] = 7;
			}
			d['s'] = 0;
		}
		if(d['v'] != 0){
			d['f'] -= d['v'];
			d['i'] -= d['v'];
			d['e'] -= d['v'];
			for(j = 0; j < d['v']; j++){
				b[k++] = 5;
			}
			d['v'] = 0;
		}
		if(d['u'] != 0){
			d['f'] -= d['u'];
			d['o'] -= d['u'];
			d['t'] -= d['u'];
			for(j = 0; j < d['u']; j++){
				b[k++] = 4;
			}
			d['u'] = 0;
		}//printf("%d\n", d['o']);
		if(d['o'] != 0){
			d['n'] -= d['o'];
			d['e'] -= d['o'];
			for(j = 0; j < d['o']; j++){
				b[k++] = 1;
			}
			d['o'] = 0;
		}
		if(d['i'] != 0){
			d['n'] -= d['i'];
			d['n'] -= d['i'];
			d['e'] -= d['i'];
			for(j = 0; j < d['i']; j++){
				b[k++] = 9;
			}
			d['i'] = 0;
		}
		printf("case #%d:\n", i);
		qsort(b, k, sizeof(int), cmp);
		for(j = 0; j < k; j++){
			printf("%d", b[j]);
		}
		for(j = 0; j < k; j++){
			b[j] = 0;
		}
		printf("\n"); k = 0; j = 0;
	}
	
	return 0;
}