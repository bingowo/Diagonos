#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int gcd(int a, int b)
{
	return (a % b == 0) ? b : gcd(b, a % b);
}

int main(void)
{
	int n, s;
	scanf("%d %d", &n, &s);
	int a[n];
	for(int i = 0 ; i < n ; i ++){
		scanf("%d", &a[i]);
	}
	qsort(a, n, sizeof(int), cmp);
	int left = 0, right = 0, width = 0, level = a[0], delta = 0;
	while(1){
		while(right != n && a[left] == a[right]){
			right ++;
		}
		width += (right - left);
		if(s < width){
			break;
		}else{
			delta = (s / width) * width;
			if(right != n){
				if(delta > (a[right] - a[left]) * width){
					delta = (a[right] - a[left]) * width;
				}
			}
			s -= delta;
			level += (delta) / width;
			if(s < width && level != a[right]){
				break;
			}
		}
		left = right;
	}
	if(level != 0){
		printf("%d", level);
	}
	if(s != 0){
		int multi = gcd(s, width);
		printf("%s%d/%d", level == 0 ? "" : "+", s/multi, width/multi);
	}
}