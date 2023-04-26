
	}
	if (n==0) y=0;
	return y;
}

int main()
{
	int T;int a[100];int i;
	scanf("%d",T);
	for (i=0;i<T;i++){
		scanf("%d",a[i]);
		printf("case #%d:\n%d\n",i,f(a[i]));
	}
	return 0;
} 
