#include <stdio.h>
#include <stdlib.h>
struct team{
	int score, win, lose, num;
}t[11];
int cmp(const void *a, const void *b){
	const struct team *pa = a, *pb = b;
	if((*pa).score != (*pb).score){
		if((*pa).score > (*pb).score)	return -1;
		else return 1;
	}
	if((*pa).win != (*pb).win){
		if((*pa).win > (*pb).win)	return -1;
		else return 1;
	}
	if((*pa).lose != (*pb).lose){
		if((*pa).lose > (*pb).lose)	return 1;
		else return -1;
	}
	if((*pa).num > (*pb).num)	return 1;
	return -1;
}
int main(){
	int n, m, i, a, b, c;
	while(scanf("%d%d", &n, &m)){
		if(n == 0 && m == 0)	break;
		for(i = 0; i < n; ++i){
			t[i].num = i + 1; t[i].score = 0; t[i].lose = 0; t[i].win = 0;
		}
		for(i = 0; i < m; ++i){
			scanf("%d%d%d", &a, &b, &c);
			if(c == 1){
				t[a-1].win += 1;
				t[b-1].lose += 1;
				t[a-1].score += 3;
				t[b-1].score -= 1;
			}
			else if(c == -1){
				t[a-1].lose += 1;
				t[b-1].win += 1;
				t[a-1].score -= 1;
				t[b-1].score += 3;
			}
			else if(c == 0){
				t[a-1].score += 1;
				t[b-1].score += 1;
			}
		}
		qsort(t, n, sizeof(t[0]), cmp);
/*		for(i = 0; i < n; ++i){
			printf("%d %d %d %d\n", t[i].num, t[i].score, t[i].win, t[i].lose);
		}*/
		for(i = 0; i < n; ++i){
			printf("%d ", t[i].num);
		}
		printf("\n");
	}
	return 0;
}