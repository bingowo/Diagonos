#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct data{
	int grade;
	int win;
	int lose;
	int teamnum;
};
typedef struct data S;

int cmp(const void*a, const void *b);

int main(int argc, char *argv[]) {
	int n,m,j,a,b,c; 
	while(scanf("%d %d",&n,&m) != EOF){
		S s[n+1];
		for (j = 0; j <= n; j++){
			s[j].teamnum = j;
			s[j].grade = 0;
			s[j].lose = 0;
			s[j].win = 0;
		}
		while (m != 0){
			scanf("%d %d %d",&a,&b,&c);
			switch (c){
				case 0:
					s[a].grade++;
					s[b].grade++;
					break;
				case 1:
					s[a].grade += 3;
					s[a].win++;
					s[b].lose++;
					s[b].grade--;
					break;
				case -1:
					s[a].lose++;
					s[a].grade--;
					s[b].grade += 3;
					s[b].win++;
					break;
			}
			m--;
		}
		qsort(s+1,n,sizeof(s[0]),cmp);
		int k;
		for (k = 1; k <= n; k++){
			printf("%d ",s[k].teamnum);
			if ( k == n){
				printf("\n");
			}
		}
	}
	return 0;
}

int cmp(const void*a, const void *b){
	S s1 = (*(S*)a);
	S s2 = (*(S*)b);
	if (s1.grade != s2.grade){
		return s2.grade - s1.grade;
	}else if (s1.win != s2.win){
		return s2.win - s1.win;
	}else if (s1.lose != s2.lose){
		return s1.lose - s2.lose;
	}else{
		return s1.teamnum - s2.teamnum;
	}
}
