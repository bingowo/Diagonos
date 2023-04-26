
#include<iostream>
#include<algorithm>
using namespace std;

struct node {
	int id;
	int score;
	int win;
	int lose;
} A[11];

bool cmp(node x,node y) {
	if(x.score!=y.score)
		return x.score>y.score;
	else if(x.win!=y.win)
		return x.win>y.win;
	else if(x.lose!=y.lose)
		return x.lose<y.lose;
	else
		return x.id<y.id;
}

int main() {
	int n,m;
	while(cin>>n>>m) {
		for(int i=1; i<=n; i++) {
			A[i].score=0;
			A[i].lose=0;
			A[i].win=0;
			A[i].id=i;
		}
		while(m--) {
			int a,b,c;
			cin>>a>>b>>c;
			if(c==1) {
				A[a].score+=3;
				A[a].win++;
				A[b].score--;
				A[b].lose++;
			} else if(c==-1) {
				A[b].score+=3;
				A[b].win++;
				A[a].score--;
				A[a].lose++;
			} else {
				A[a].score++;
				A[b].score++;
			}
		}
		sort(A+1,A+n+1,cmp);
		for(int i=1; i<=n; i++) {
			cout<<A[i].id<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
