/*
Created by Shizumu on 2022-03-14
	感觉这个题目远远超过naive难度（也有可能是自己水平不足）。这个代码写得
十分难看，也没有去重构了，最后我也不清楚怎么过的这个问题…… 
*/ 
#include <stdio.h>
#include <limits.h>
//构造一个分数，还有一些简单的函数。 
typedef struct{
	int numerator;
	int denominator;
}Fraction;
int gcd(int a, int b){ return (a % b == 0) ? b : gcd(b, a % b);}
int min(int a, int b){ return a > b ? b : a;}
int max(int a, int b){ return a > b ? a : b;}

int main(void)
{
	int n, s, p;
	scanf("%d %d %d", &n, &s, &p);
	int a[n + 2];
	Fraction fa[n + 2];
	for(int i = 1 ; i <= n ; i ++){
		scanf("%d", &a[i]);
		//初始化每个地形对应的分数（后面输出会用） 
		fa[i].numerator = 0, fa[i].denominator = 1;
	}
	//两侧立起高墙，表示无限高 
	a[0] = a[n + 1] = INT_MAX;
	fa[0].numerator = fa[n + 1].numerator = INT_MAX;
	fa[0].denominator = fa[n + 1].denominator = 1;
	int l , left, right, h, delta_h;
	//标识，分别是检测“左侧平坦”“右侧平坦”“左侧的水不够多”“右侧水不够多” 
	int LeftIsFlat = 0, RightIsFlat = 0, LeftNotReach = 0, RightNotReach = 0;
	//先让水均分，之后再做调整 
	int left_w = s / 2, right_w = s / 2;
	//记录没有分入左边或是右边的水（也就是奇数的时候会遇见这样的情况） 
	int delta = s - left_w - right_w;
	while(left_w || right_w || delta){
		//下面两个for循环是检测左右是否应当要平坦 ，用来调整数值
		//ps:这里可以重构，写得更加好看些（看了后面就发现这一步走了两次） 
		for(l = p; l >= 1 ; l --){
			if(a[p] > a[l]){
				LeftIsFlat = 0;
				break;
			}else if(a[p] < a[l]){
				break;
			}
		}
		for(l = p; l <= n; l ++){
			if(a[p] > a[l]){
				RightIsFlat = 0;
				break;
			}else if(a[p] < a[l]){
				break;
			}			
		}
		l = p;
		//如果左边或则右边出现“齐平的现象”那么就要把水运到某一边 
		if(RightIsFlat && right_w + delta > 0){
			left_w += (right_w + delta);
			right_w = 0, delta = 0;
			LeftNotReach = 0;	//有可能水变化后就够得着了 
		}else if(LeftIsFlat && left_w + delta > 0){
			right_w += (left_w + delta);
			left_w = 0, delta = 0;
			RightNotReach = 0;
		}
		if(!(LeftIsFlat && RightIsFlat)){
			// 往左边找坑 
			while(l >= 1 && a[l - 1]  <= a[l]){ l --;}
			left = l, h = a[l - 1] - a[l];
			while(l < p && a[l] == a[l + 1]){ l ++;}
			right = l + 1, h = min(h, a[l + 1] - a[l]);
			if(h > 0){	//如果找到坑 
				LeftIsFlat = 0;
				if(left_w >= (right - left) * 1){
					delta_h = min(left_w / (right - left), h);
					for(int i = left; i < right; i ++){
						a[i] += delta_h;
						left_w -= delta_h * 1;
					}
					//狭隘地检测是否平坦，这也是为什么前面需要for循环调整 
					if(a[left] == a[p]){LeftIsFlat = 1;}
				}else if(!LeftNotReach){	//水不够，第一次先不急着填坑，有可能后面会改变这个决策 
					LeftNotReach = 1;
				}else if(LeftNotReach){		//第二次就填坑，但肯定是分数 
					if(left_w > 0){
						for(int i = left; i < right; i ++){
							fa[i].numerator = left_w;
							fa[i].denominator = (right - left);
						}
						left_w = 0;						
					}else{
						for(int i = left; i < right; i ++){
							fa[i].numerator = delta;
							fa[i].denominator = (right - left) * 2;
						}						
					}

				}			
			}else{	//否则这一片就是平坦的 
				LeftIsFlat = 1;
			}
			//往右边找坑，有许多和上面一样的步骤，或许可以优化写在一起（实在是太丑） 
			l = p;
			while(l <= n && a[l] >= a[l + 1]){ l ++;}
			right = l + 1, h = a[l + 1] - a[l];
			while(l > p + 1 && a[l - 1] == a[l]){ l --;} ;
			left = l, h = min(h, a[l - 1] - a[l]);
			if(h > 0){	//如果找到坑 
				RightIsFlat = 0;
				if(right_w >= (right - left) * 1){
					delta_h = min(right_w / (right - left), h);
					for(int i = left; i < right; i ++){
						a[i] += delta_h;
						right_w -= delta_h * 1;
					}
					if(a[left] == a[p]){RightIsFlat = 1;}
				}else if(!RightNotReach){
					RightNotReach = 1;
				}else if(RightNotReach){
					if(right_w > 0){
						for(int i = left; i < right; i ++){
							fa[i].numerator = right_w;
							fa[i].denominator = (right - left);
						}
						right_w = 0;						
					}else{
						for(int i = left; i < right; i ++){
							fa[i].numerator = delta;
							fa[i].denominator = (right - left) * 2;
						}
						delta = 0;						
					}
				}			
			}else{	//否则这一片就是平坦的 
				RightIsFlat = 1;
			}			
		}else{
			//两边都是平坦的，那么就直接铺平这个部分。 
			//有可能是部分平坦，所以要想办法检测。
			l = p;
			while(l >= 1 && a[l - 1]  == a[l]){ l --;}
			left = l, h = a[l - 1] - a[l];
			while(l <= n && a[l] == a[l + 1]){ l ++;}
			right = l + 1, h = min(h, a[l + 1] - a[l]);			
			int temp_s = left_w + right_w + delta, isOverflow = 0;
			left_w = right_w = delta = 0;
			delta_h = min(temp_s / (right - left), h);
			if(temp_s / (right - left) >= h){ isOverflow = 1;}
			for(int i = left ; i < right; i ++ ){
				a[i] += delta_h;
				temp_s -= delta_h * 1;
			}
			if(temp_s > 0){
				if(!isOverflow){
					for(int i = left; i < right ; i ++){
						fa[i].numerator = temp_s;
						fa[i].denominator = right - left;
					}
					s = 0;					
				}else{
					s= temp_s;
					left_w = right_w = s / 2;
					delta = s - left_w - right_w;
					LeftIsFlat = RightIsFlat = 0;
				}
			}			
		}
	}
	//输出数值 
	int multi;
	for(int i = 1; i <=n ; i ++){
		if(a[i] != 0 || fa[i].numerator == 0){
			printf("%d", a[i]);
		}
		if(fa[i].numerator != 0){
			multi = gcd(fa[i].numerator, fa[i].denominator);
			printf("%s%d/%d ", a[i] == 0 ? "" : "+", fa[i].numerator / multi, fa[i].denominator / multi);
		}else{
			printf(" ");
		}
	}
	
	return 0;
}
