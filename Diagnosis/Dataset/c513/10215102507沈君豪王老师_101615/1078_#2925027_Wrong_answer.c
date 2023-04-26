#include <stdio.h>
#include <limits.h>

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
		fa[i].numerator = 0, fa[i].denominator = 1;
	}
	a[0] = a[n + 1] = INT_MAX;
	fa[0].numerator = fa[n + 1].numerator = INT_MAX;
	fa[0].denominator = fa[n + 1].denominator = 1;
	int l , left, right, h, delta_h;
	int LeftIsFlat = 0, RightIsFlat = 0, LeftNotReach = 0, RightNotReach = 0;
	int left_w = s / 2, right_w = s / 2;
	int delta = s - left_w - right_w;
	while(left_w || right_w || delta){
		l = p;
		if(RightIsFlat && right_w){
			left_w += (right_w + delta);
			right_w = 0;
			LeftNotReach = 0;
		}else if(LeftIsFlat && left_w){
			right_w += (left_w + delta);
			left_w = 0;
			RightNotReach = 0;
		}
		if(!(LeftIsFlat && RightIsFlat)){
			// 往左边找
			while(l >= 1 && a[l - 1]  <= a[l]){ l --;}
			left = l, h = a[l - 1] - a[l];
			while(l < p && a[l] == a[l + 1]){ l ++;}
			right = l + 1, h = min(h, a[l + 1] - a[l]);
			if(h > 0){
				LeftIsFlat = 0;
				if(left_w >= (right - left) * 1){
					delta_h = min(left_w / (right - left), h);
					if(delta_h + a[p - 1] >= a[p]){ LeftIsFlat = 1;}
					for(int i = left; i < right; i ++){
						a[i] += delta_h;
						left_w -= delta_h * 1;
					}
				}else if(!LeftNotReach){
					LeftNotReach = 1;
				}else if(LeftNotReach){
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
			}else{
				LeftIsFlat = 1;
			}
			//往右边找
			l = p;
			while(l <= n && a[l] >= a[l + 1]){ l ++;}
			right = l + 1, h = a[l + 1] - a[l];
			while(l > p + 1 && a[l - 1] == a[l]){ l --;} ;
			left = l, h = min(h, a[l - 1] - a[l]);
			if(h > 0){
				RightIsFlat = 0;
				if(right_w >= (right - left) * 1){
					delta_h = min(right_w / (right - left), h);
					if(delta_h + a[p + 1]>= a[p]){ RightIsFlat = 1;}
					for(int i = left; i < right; i ++){
						a[i] += delta_h;
						right_w -= delta_h * 1;
					}
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
			}else{
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
		printf("%d", a[i]);
		if(fa[i].numerator != 0){
			multi = gcd(fa[i].numerator, fa[i].denominator);
			printf("%s%d/%d ", a[i] == 0 ? "" : "+", fa[i].numerator / multi, fa[i].denominator / multi);
		}else{
			printf(" ");
		}
	}
	
	return 0;
}