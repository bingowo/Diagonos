#include <stdio.h>
#include <string.h>
char word[1001];
int a[10000],b[10000],c[10000];
int lenth;

void caculate();
int main()
{
    scanf("%s",word);
	lenth = strlen(word); 
	if (word[lenth - 2] == word[lenth - 1])
    b[lenth - 1] = 1;
    else
    b[lenth - 1] = 2;
    if (word[0] != word[1]&&word[1] != NULL)
    b[0] = 2;
    else
    b[0] = 1;
    for (int i = 1; i <lenth - 1; i++)
    {
    	int j = 0;
    	if (word[i-1] == word [i])
    	j++;
    	if (word[i-1] == word[i+1])
    	j++;
    	if (word[i+1] == word[i])
    	j++;
    	if (j == 3)
    	b[i] = 1;
    	if (j == 0)
    	b[i] = 3;
    	else
    	b[i] = 2;
	}
		caculate();
	return 0;
}
void caculate()     
{
	int l = 1;
	memset(c,0,sizeof(c));
	c[0] = 1;
	for (int m = 0;m<lenth;m++)
	{
		for (int i = 0;i < l;i++)
		{
			c[i] = c[i]*b[m];
		}
		if (c[0]>2*10e5) 
	{
		for (int i = 0 ; i < l ;i++)
	{
		c[i + 1] += c[i] / 10;    //保证每一位的数都只有一位，并进位 
		c[i] %= 10;
	}
	if (c[l] > 0) l++;     //保证最高位数是对的 
	while (c[l - 1] >= 10)
	{
		c[l] = c[l - 1] / 10;
		c[l - 1] %= 10;
		l++;
	}
	while (c[l - 1] == 0 && l > 1) 
		l--;    //while去零法
	}
	}
	for (int i = 0 ; i < l ;i++)
	{
		c[i + 1] += c[i] / 10;    //保证每一位的数都只有一位，并进位 
		c[i] %= 10;
	}
	if (c[l] > 0) l++;     //保证最高位数是对的 
	while (c[l - 1] >= 10)
	{
		c[l] = c[l - 1] / 10;
		c[l - 1] %= 10;
		l++;
	}
	while (c[l - 1] == 0 && l > 1) 
		l--;    //while去零法
	for (int i = l - 1; i >= 0 ; i--)    //输出结果 
		printf("%d",c[i]);
}