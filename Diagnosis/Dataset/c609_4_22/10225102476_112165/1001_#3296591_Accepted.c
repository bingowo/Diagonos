#include<stdio.h>
#include<math.h>
#include<malloc.h>
int main()
{
	int a,i=0,t,m=0;
	scanf("%d", &a);
	while (i < a) {
		scanf("%d %d", &t, &m);
		if (t > 0)
		{
			int r = 0, m1 = m, t1 = t;
			while (t1) {
				t1 = t1 / m1;
				r++;
			}
			char* A = (char*)malloc((r + 1) * sizeof(char));
			int b = 0;
			while (b <= r) {
				int r1 = t % m;
				if (r1 >= 10)
					A[b] = r1 - 10 + 'A';
				else
					A[b] = r1 + '0';
				t = t / m;
				b++;
			}
			char* B = (char*)malloc((r + 1) * sizeof(char));
			for (int h = 0;B[h] = A[r - h - 1];h++);
			int y = 0;
			while (y < r) {
				printf("%c", B[y]);
				y++;
			}
			printf("\n");
			i++;
		}

		else
		{
			int r = 0, m1 = m, t1 = -t;
			while (t1) {
				t1 = t1 / m1;
				r++;
			}
			char* A = (char*)malloc((r + 1) * sizeof(char));
			int b = 0;
			while (b <= r) {
				int r1 = -t % m;
				if (r1 >= 10)
					A[b] = r1 - 10 + 'A';
				else
					A[b] = r1 + '0';
				t = -(-t / m);
				b++;
			}
			char* B = (char*)malloc((r + 1) * sizeof(char));
			for (int h = 0;B[h] = A[r - h - 1];h++);
			int y = 0;
			printf("%c", '-');
			while (y < r) {
				printf("%c", B[y]);
				y++;
			}
			printf("\n");
			i++;
		}
	}

}
