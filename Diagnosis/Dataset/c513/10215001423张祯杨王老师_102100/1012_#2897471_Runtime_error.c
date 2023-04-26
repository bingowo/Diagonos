#include <stdio.h>
#include <math.h>
#include <string.h>
void seperate_complex(char complex[], int *ptr, int *pti);
int reminder(int r_complex, int i_complex);
void complex_division(int *ptr, int *pti, int r);
int main()
{
	char complex[200];
	char rem[900000000000000] = {0};
	int r_complex = 0, i_complex = 0;
	int r;
	int cnt = 0;
	gets(complex);
	seperate_complex(complex, &r_complex, &i_complex);
	if (r_complex == 0 && i_complex == 0)
		printf("0");
	else
	{
		while (r_complex != 0 || i_complex != 0)
		{
			r = reminder(r_complex, i_complex);
			rem[cnt] = r;
			printf("%d %d %d\n", rem[cnt], r_complex, i_complex);
			complex_division(&r_complex, &i_complex, r);
			cnt++;
		}

		for (int i = (cnt - 1); i >= 0; i--)
		{
			printf("%d", rem[i]);
		}
	}
}
void seperate_complex(char complex[], int *ptr, int *pti)
{
	int i = 0, j = 0, k = 0, h = 0;
	char complex_r[100] = {0};
	char complex_i[100] = {0};
	if (complex[0] == '-')
		i++;
	for (; (complex[i]) != '\0'; i++, h++)
	{
		if (complex[i] == '+' || complex[i] == '-')
		{
			break;
		}
		else if (complex[i] == 'i')
		{
			for (int c = 0; c < (h + 1); c++)
				complex_r[c] = 0;
			break;
		}
		else
			complex_r[h] = complex[i];
	}
	if (complex[i] == '+' || complex[i] == '-')
	{
		for (j = i + 1, k = 0; (complex[j]) != 'i'; j++, k++)
			complex_i[k] = complex[j];
	}
	else if (complex[i] == 'i')
	{
		if (i == 0)
			complex_i[0] = '1';
		else
		{
			int b = 0;
			for (int a = 0; b < i; a++, b++)
			{
				if (complex[0] == '-')
				{
					b++;
					if (complex[1] == 'i')
					{
						complex_i[0] = '1';
						break;
					}
				}
				complex_i[a] = complex[b];
			}
		}
	}

	for (int len_r = strlen(complex_r), k = 0; len_r > 0; len_r--, k++)
	{
		*ptr += (complex_r[k] - 48) * pow(10, len_r - 1);
	}
	if (complex[0] == '-')
		*ptr = -*ptr;
	for (int len_i = strlen(complex_i), j = 0; len_i > 0; len_i--, j++)
	{
		*pti += (complex_i[j] - 48) * pow(10, len_i - 1);
	}
	if (complex[i] == '+' && complex[i + 1] == 'i')
		*pti = 1;
	if (complex[i] == '-' && complex[i + 1] == 'i')
		*pti = 1;
	if (complex[i] == '-')
		*pti = -*pti;
	if (complex[i] == 'i' && complex[0] == '-')
		*pti = -*pti;
}
int reminder(int r_complex, int i_complex)
{
	int r;
	if (r_complex % 2 == i_complex % 2 || r_complex % 2 == -i_complex % 2)
		r = 0;
	else
		r = 1;
	return r;
}
void complex_division(int *ptr, int *pti, int r)
{
	int nr_complex = 0, ni_complex = 0;
	nr_complex = (*pti - *ptr + r) / 2;
	ni_complex = (-*ptr + r - *pti) / 2;
	*ptr = nr_complex;
	*pti = ni_complex;
	// printf("%d%d\n",*ptr,*pti);
}