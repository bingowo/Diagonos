
int main()
{
	char str[101];
	scanf("%s",str);
	int len,max=0,i,n=0;
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]>'0'&&str[i]<='9')
		{
			i++;n++;
			for(i;i<len;i++)
			{
				if(str[i]>='0'&&str[i]<='9') n++;
				else
				{
					if(n>max) max=n;
					n=0;
					i++;
					break;
				}
				
			}
		}
	
	}
	printf("%d\n",max);
	return 0;
}