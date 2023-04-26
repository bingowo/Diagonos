#include <stdio.h>
#include <string.h>
typedef long long int lli;
int Xstep[4] = {-1, 1, 0, 0};
int Ystep[4] = {0, 0, 1, -1};
int path[4] = {'W', 'E', 'N', 'S'};
lli x, y, step, limit;
char s[100];


lli llabs(lli x){ return x > 0 ? x : -x;};

lli distance(lli x1, lli y1, lli x2, lli y2){ return llabs(x1 - x2) + llabs(y1 - y2);}

lli CalculateStep(lli d)
{
	int ret = 0;
	while(d > 0){
		d >>= 1;
		ret += 1;
	}
	return ret;
}

lli CalculatePower(lli n){ return 1LL<<n;}

void solve(lli px, lli py)
{
	static int isFind = 0;
	static int depth = 0;
	static int index = 0;
	static lli multi = 1;
	if(px == x && py == y){
		isFind = 1;
		index = depth - 1;
		return;
	}else if(depth == step){
		multi /= 2;
		return;
	}else if(distance(px, py, x, y) >= 2 * limit){
		multi /= 2;
		return;
	}else{
		for(int i = 0 ; i < 4 && !isFind; i ++){
			depth ++;
			multi = CalculatePower(depth - 1);
			solve(px + multi * Xstep[i], py + multi * Ystep[i]);
			if(isFind){
				s[index --] = path[i];
			}
			depth --;
		}
		return;
	}
}

int main(void)
{
	scanf("%lld %lld", &x, &y);
	lli d = distance(x, y, 0, 0);
	if(d % 2 == 0){
		printf("-1");
	}else{
		step = CalculateStep(d);
		limit = CalculatePower(step - 1);
		printf("%lld\n", step);
		solve(0, 0);
		printf("%s", s);
	}
	
}