# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char MOUTH[20][7] = { "pop", "no", "zip","zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet" };
typedef struct
{
	int mouth;
	int year;
	int day;
}MAYA;

int cmp(const void* a, const void* b)
{
	MAYA A = *(MAYA*)a, B = *(MAYA*)b;
	if (A.year == B.year)
	{
		if (A.mouth == B.mouth)  return A.day - B.day;
		return A.mouth - B.mouth;
	}
	return A.year - B.year;
}

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int cas = 0; cas < cases; ++cas)
	{
		int mount;
		scanf("%d", &mount);
		MAYA* MM = (MAYA*)malloc(mount * sizeof(MAYA));
		for (int i = 0; i < mount; ++i)
		{
			char dayy[5], mou[8];
			scanf("%s %s %d", dayy, mou, &MM[i].year);
			int Day = 0;
			for (int j = 0; j < strlen(dayy) - 1; ++j)
			{
				Day = Day*10 + dayy[j] - '0';
			}
			MM[i].day = Day;
			for (int j = 0; j < 20; ++j)
			{
				if (strcmp(MOUTH[j], mou) == 0)
				{
					MM[i].mouth = j;
					break;
				}
			}
		}
		qsort(MM, mount, sizeof(MM[0]), cmp);
		printf("case #%d:\n", cas);
		for (int i = 0; i < mount; ++i)  printf("%d. %s %d\n", MM[i].day, MOUTH[MM[i].mouth], MM[i].year);
	}
	return 0;
}