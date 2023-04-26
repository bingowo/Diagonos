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
	//排列坑的深度 
	qsort(a, n, sizeof(int), cmp);
	/*接下来我们将同样深度的坑组成区间，left表示区间的左侧，right表示区间的右侧 
	  注：right不包括不在区间内。
	  level表示水高度，delta表示变化的高度 */
	int left = 0, right = 0, width = 0, level = a[0], delta = 0;
	while(1){
		while(right != n && a[left] == a[right]){
			right ++;
		}
		//计算出同样高度的坑组成区间的长度 
		width += (right - left);
		//当然，如果降雨量没有这个坑宽，那么就要跳出，处理分数 
		if(s < width){
			break;
		}else{
			delta = (s / width) * width;
			if(right != n){
				//水的变化量最大也不应该超过坑的容量 
				if(delta > (a[right] - a[left]) * width){
					delta = (a[right] - a[left]) * width;
				}
			}
			s -= delta;
			level += (delta) / width;
			/*经过上面的处理后，如果水已经没有坑宽，同时还没有填满，那么就 
			  不应该继续计算，否则将会让这个坑变得更宽（这显然是不科学的）*/
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
		//要是初始的深度为0，就不打印符号。由于字符不能为空，于是用字符串 
		printf("%s%d/%d", level == 0 ? "" : "+", s/multi, width/multi);
	}
}