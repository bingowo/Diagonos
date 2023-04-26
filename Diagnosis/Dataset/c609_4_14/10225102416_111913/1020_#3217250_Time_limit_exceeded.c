

# include<stdio.h>

# include<string.h>

void main()

{

	char a[100][30];

	int i=0,j=0;

	int k=1;

	while(scanf("%s",a[i++])!=EOF);

	int n=i--;

	int b[100]={-1};

	int c[30]={-1};

	for(i=0;i<100;i++)

	while(a[i][j]!='/0')

	{

		if(a[i][j]>='0'&&a[i][j]<='9')

		{

			b[i]=k*a[i][j];

			k*=10;

		}

		j++;

	}

	for(i=0;i<n;i++)

		for(j=n-i;j<n;j++)

	{

		c[i]=i;

		int m;

		if(b[c[i]]==-1&&b[j]==-1)

		{

			if(strcmp(a[i],a[j]))

				c[i]=j;

		}

		if(b[c[i]]==-1&&b[j]!=-1)

			c[i]=j;

		if(b[c[i]]!=-1&&b[j]!=-1)

			if(b[c[i]]>b[j])	c[i]=j;



	}

		while(c[i]!=-1)

			printf("%s ",a[c[i]]);

		printf("/n");

}
