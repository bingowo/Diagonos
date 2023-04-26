#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int m,n;
struct node
{
	int len;
	char s[1000];
	int val;
}a[400][400];
int main(void)
{
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j].val);
			a[i][j].len = 0;
			a[i][j].s[0] = '\0';
		};
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i==1 && j==1) continue;
			else if(i==1) {
				a[i][j].val += a[i][j-1].val;
				strcpy(a[i][j].s,a[i][j-1].s);
				a[i][j].len = a[i][j-1].len+1;
				a[i][j].s[a[i][j].len-1] = 'R';
				a[i][j].s[a[i][j].len] = '\0';
			}
			else if(j==1) {
				a[i][j].val += a[i-1][j].val;
				strcpy(a[i][j].s,a[i-1][j].s);
				a[i][j].len = a[i-1][j].len+1;
				a[i][j].s[a[i][j].len-1] = 'D';
				a[i][j].s[a[i][j].len] = '\0';
			}
			else{
				if(a[i-1][j].val < a[i][j-1].val) {
					a[i][j].val += a[i-1][j].val;
					strcpy(a[i][j].s,a[i-1][j].s);
					a[i][j].len = a[i][j-1].len+1;
					a[i][j].s[a[i][j].len-1] = 'D';
					a[i][j].s[a[i][j].len] = '\0';
				}
				else{
					a[i][j].val += a[i][j-1].val;
					strcpy(a[i][j].s,a[i][j-1].s);
					a[i][j].len = a[i][j-1].len+1;
					a[i][j].s[a[i][j].len-1] = 'R';
					a[i][j].s[a[i][j].len] = '\0';
				}
			}
		}
	}
	printf("%d\n%s",a[m][n].val,a[m][n].s);
	return 0;
}