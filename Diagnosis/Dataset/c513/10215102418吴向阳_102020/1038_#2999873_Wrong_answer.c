#include <stdio.h>

int main()
{
	int n,m,k;
	scanf("%d%d%d", &n, &m, &k);
	int a[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
	}
	int maxlen = n > m ? m : n;
	int num = 0;
	for(int i = 0; i < n - 1; i++)//行 
	{
		for (int j = 0; j < m - 1; j++)//列
		{
			int count, len = 2;
			while (i + len < n + 1 && j + len < m + 1 && len <= maxlen)
			{
				count = 0;
				int p,line = 1;
				while (line <= len) 
				{
					p = 0;
					while (p < line) count += a[i+line-1][j+p], p++;
					line++;
				}
				if (count >= k)
				{
					num += (maxlen - i - len + 1); 
					break;
				}
				len++;
			}
		}
	}  
	for(int i = 0; i < n - 1; i++)//行 
	{
		for (int j = 0; j < m - 1; j++)//列
		{
			int count, len = 2;
			while (i + len < n + 1 && j + len < m + 1 && len <= maxlen)
			{
				count = 0;
				int p,line = len;
				while (line >= 1) 
				{
					p = line-1;
					while (p >= 0) count += a[i+len-line][j+p], p--;
					line--;
				}
				if (count >= k)
				{
					num += (maxlen - i - len + 1); 
					break;
				}
				len++;
			}
		}
	}
	for(int i = 0; i < n - 1; i++)//行 
	{
		for (int j = m - 1; j > 0; j--)//列
		{
			int count, len = 2;
			while (i + len < n + 1 && j - len >= -1 && len <= maxlen)
			{
				count = 0;
				int p,line = 1;
				while (line <= len) 
				{
					p = 0;
					while (p < line) count += a[i+line-1][j-p],	p++;	
					line++;
				}
				if (count >= k)
				{
					num += (maxlen - i - len + 1); 
					break;
				}
				len++;
			}
		}
	} 
	for(int i = 0; i < n - 1; i++)//行 
	{
		for (int j = m - 1; j > 0; j--)//列
		{
			int count, len = 2;
			while (i + len < n + 1 && j - len >= -1 && len <= maxlen)
			{
				count = 0;
				int p,line = len;
				while (line >= 1) 
				{
					p = line-1;
					while (p >= 0) count += a[i+len-line][j-p], p--;
					line--;
				}
				if (count >= k)
				{
					num += (maxlen - i - len + 1); 
					break;
				}
				len++;
			}
		}
	} 
	printf("%d", num);
	return 0;
}