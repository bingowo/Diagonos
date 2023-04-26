#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct { int cnt,v[101]; } BIGINT;

void MUL2ADD(BIGINT *n, int d) {

	int carry=d,i;

	for (i=0;i<n->cnt;i++) {

		int t=carry+n->v[i]*2;

		n->v[i]=t%10;

		carry=t/10;

	}

	if (carry>0) n->v[n->cnt++]=carry;

}
void DIV2(BIGINT *n){

	int carry=0,i;

	if (n->v[n->cnt-1]<2){

		n->cnt--;

		carry=1;

	}

	for (i=n->cnt-1;i>=0;i--) {

		int t=10*carry+n->v[i];

		n->v[i]=t/2;
		carry=t%2;
	}
	// 13 t=3 n->v[1]=1 carry=1
     //     t=11 n->v[0]=5 carry=1
}
solve (int t) {
    printf ("case #%d:\n", t);
    char line[102];

int i;

BIGINT n;

scanf("%s",line);


n.cnt=strlen(line);

for (i=0;i<n.cnt;i++)

	n.v[i]=line[n.cnt-i-1] -'0';
int bin[334],cnt=0;
int cn=0;
while (n.cnt>0) {
    cn=n.cnt;
	bin[cn++]=n.v[0]%2;

	DIV2(&n);
	n.cnt--;

}
	for (i=0;i<n.cnt;i++)  MUL2ADD(&n,bin[i]);
if (n.cnt==0){

	n.cnt++;

}
//printf ("%d", n.cnt);

for (i=n.cnt-1;i>=0;i--) {

	printf("%d",n.v[i]);

}

printf("\n");

}
int main () {
    int T;
    scanf ("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i);
    return 0;
}
