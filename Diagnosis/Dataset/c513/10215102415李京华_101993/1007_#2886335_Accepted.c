#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int ncase, T;
	scanf("%d", &T);
	for (ncase = 0; ncase  < T; ncase++){
		int n;
		int ans = 1;
		scanf("%d",&n);
		int L[32];
		int i = 0, j = 0;
		int m = n;
		while (m) {
			L[i++] = m & 1;
			m /= 2;
		}
		int len = i;
		i--;
		while (j < i)
		{
			int swap = L[i];
			L[i--] = L[j];
			L[j++] = swap;
		}
		


		//已完成
		if (n < 3)
			ans = n;
		else {
			int left = 0;
			int right = 1;

			while (right < len){	//右指针未到末尾
				if (L[right - 1] == L[right])	//重复
					left = right;
				right++;
				if (ans < (right - left))
					ans = right - left;
			}
		}
		
		//输出
		printf("case #%d:\n",ncase);
		printf("%d\n",ans);
	}
	return 0;
}
