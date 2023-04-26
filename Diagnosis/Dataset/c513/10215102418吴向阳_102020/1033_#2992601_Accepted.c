#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum MONTH{pop=1, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu, uayet
};

const char * m[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

typedef struct{
	int day;
	int month;
	int year;
} TIME;

int cmp(const void *a, const void *b)
{
	TIME *p1 = (TIME *)a, *p2 = (TIME *)b;
	if (p1->year > p2->year) return 1;
	else if (p1->year < p2->year) return -1;
	else
	{
		if (p1->month > p2->month) return 1;
		else if (p1->month < p2->month) return -1;
		else
		{
			if (p1->day > p2->day) return 1;
			else if (p1->day <= p2->day) return -1;
		}
	}
};

int main()
{
	int T,t;
	scanf("%d\n", &T);
	t = T;
	while(T)
	{
		int N;
		scanf("%d\n", &N);
		TIME time[N];
		for (int i = 0; i < N; i++)
		{
			char s[10];
			scanf ("%d.%s%d", &time[i].day, s, &time[i].year);
			for (int a = pop; a <= uayet; a++)
			{
				if (strcmp(s, m[a-1]) == 0)
				{
					time[i].month = a;
				}
			}
		}
		qsort (time, N, sizeof (time[0]), cmp);
		printf ("case #%d:\n", t-T);
		for (int i = 0; i < N; i++) printf ("%d. %s %d\n", time[i].day, m[time[i].month-1],time[i].year);
		T--;
	}
}