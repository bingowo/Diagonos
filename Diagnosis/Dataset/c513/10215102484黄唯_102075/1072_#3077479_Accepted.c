/*
Created by Shizumu on 2022-03-14
	这个问题想到思路就是naive，想不到思路就是hardcore。
	首先，原点到目标点的距离只能为奇数，偶数的话无法到达。同时，可以得出最少步数n满足：
				2^(n - 1) < 曼哈顿距离 < 2^n
	这个就可以优化很大部分了，然后再dpf一下，但是……仔细一想，这个过程还是有很多可能，
而且有很多根本就是一眼丁真，电脑也要傻傻的去计算。那就想办法剪枝吧。 
*/ 
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
lli CalculatePower(lli n){ return 1LL<<n;}
lli CalculateStep(lli d)
{
	int ret = 0;
	while(d > 0){
		d >>= 1;
		ret += 1;
	}
	return ret;
}

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
	//达到了步数但是没到目标，那肯定是走岔了 
	}else if(depth == step){	
		return;
	//如果跑得太远了，那也走岔了。 
	}else if(distance(px, py, x, y) >= 2 * limit){
		return;
	//如果走出来目前位置到目标点位置的水平距离和垂直距离 都是奇数，那也走岔了
	/*
	但是尽管如此，还是有很多东西根本没剪掉……嗯，那我们要换一个思路了。一开始，我们思考
	的是第一次走1步，第二次走2步，第三次走4步……但反过来，我们可不可以压缩距离呢？走完
	第一步，把当前位置到目标点的水平距离与垂直距离都除以2，走第二步后，再重复这样的动作。
	这样子，每一次走都是第一次。
	我们发现，走第一步的时候，最容易判断成不成功——那就是，如果当前位置与目标点的水平距
	离和垂直距离中有且仅有1个奇数（每次都要除以2后看）或者是均为0，才可以成功，这也是下
	面大规模剪枝的法子。 
	*/ 
	}else if(distance(px, py, px, y) % 2 && distance(px, py, x, py) % 2){
		return ;
	}else if(!(px == 0 && py == 0) && (llabs(x - px) / 2 + llabs(y - py) / 2) % 2 == 0){
		return ;
	}else{
		for(int i = 0 ; i < 4 && !isFind; i ++){
			depth ++;
			if(!(px == 0 && py == 0)){
				x = (x - px) / 2;
				y = (y - py) / 2;
				px = 0, py = 0;
			}
			solve(px + Xstep[i], py + Ystep[i]);
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
	if(x == 0 && y == 0){
		printf("0");
	}else if(d % 2 == 0){
		printf("-1");
	}else{
		step = CalculateStep(d);
		limit = CalculatePower(step - 1);
		printf("%lld\n", step);
		solve(0, 0);
		printf("%s", s);
	}
	
}
