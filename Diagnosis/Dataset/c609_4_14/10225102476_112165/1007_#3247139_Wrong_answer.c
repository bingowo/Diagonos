#include<stdio.h>
#include<math.h>
int main()
{
	int a = 0;
	scanf("%d", &a);
	int i = 0;
	while (i < a) {
		int m = 0;
		scanf("%d", &m);
		int n = 0;
		int M[100],N[100],M1[100];
		while (n < m) {
			int t, b = 0;
			scanf("%d", &t);
			M[n] = t;
			t = fabs(t);
			int c = 0;
			while (t) {
				c = c + t % 2;
				t = t / 2;
			}
			N[n] = c;
			n++;
		}
		int temp,g;
		for (int l = 0;l < n; l++)
		{
			for (int j = n-1;j > l;j--)
			{
				if (N[j] > N[j - 1])
				{
					temp = N[j];
					N[j] = N[j - 1];
					N[j - 1] = temp;
					g = M[j];
					M[j] = M[j - 1];
					M[j - 1] = g;
				}
			}
		}
		for (int z = 0;z < n;z++) {
			if (N[z] = N[z + 1])
			{
				if(M[z]>M[z+1])
				{
					int r = M[z];
					M[z] = M[z + 1];
					M[z + 1] = r;
				}
			}
		}
		int h = 0;
		printf("case #%d\n", i);
		while (h < m) {
			printf("%d ", M[h]);
			h++;
		}
		i++;
	}
}
