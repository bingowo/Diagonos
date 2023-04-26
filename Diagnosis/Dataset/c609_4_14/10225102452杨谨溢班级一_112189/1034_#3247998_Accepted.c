# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
char str[100005] = {0};
int main()
{
	scanf("%s",str);
	char scmp[3] = "0x";
	char* ps = strstr(str, scmp);
	if (ps == NULL)
	{
		printf("-1");
		return 0;
	}
	else
	{
		int flag = 0;
		while (ps != NULL)
		{
			unsigned int num = 0; 
			ps = ps + 2;
			if (*ps > 'f')  // 注意：判断仅有0x 但没有之后元素导致的错误！！！！！
			{
				ps = strstr(ps, scmp);
				continue;
			}
			if (*ps == '\0') break;  // 判断以0x结尾 的字符串！！！！！ 
			while (isdigit(*ps) || ( *ps >= 'a'&& *ps <='f'))
			{
				flag = 1;
				int n = 0;
				if (isdigit(*ps))  n = *ps - '0';
				else n = *ps - 'a'+10;
				num = num * 16 + n;
				ps++;
			}
			if (flag) printf("%u ", num);
			ps = strstr(ps, scmp);
		}
		if (flag == 0)  printf("-1");
	}
	return 0;
}