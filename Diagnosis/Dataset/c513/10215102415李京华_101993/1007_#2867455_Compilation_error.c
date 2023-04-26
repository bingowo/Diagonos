#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int ncase, T;
	int ans;
	scanf("%d", &T);
	for (ncase = 0; ncase  < T;ncase++){
		int n;
		scanf("%d",&n);
		char L[32];
		itoa(n, L, 2);
		int len = strlen(L);
		if (n < 3)
			ans = n;
		else{
			int left = 0;
			int right = 1;
			
			while (right < len){
				if (L[right - 1] == L[right]){
					if (ans == 0)
						ans = right - left;
					else
						if (ans < (right - left))
							ans = right - left;

					left = right;
				}
				right++;
			}
			if (ans == 0)
				ans = right - left;
			else
				if (ans < (right - left))
					ans = right - left;
		}
		
		printf("case #%d:\n",ncase);
		printf("%d\n",ans);
	}
	return 0;
}