int jud(char *s)
{
	int len = strlen(s);
	int i, j;
	char x[120];
	int k = 0;

	memset(x, 0, 120);
	for(i=0;i<len;i++)
	{
		switch( s[i] )
		{
			case '(':
				{
                    if( (k<=0) || (x[k-1]=='[') )
                    {
                        x[k++] = s[i];
                    }
                    else
                        return -1;
                    break;
				}
			case '[':{
				if( (k<=0) || (x[k-1]=='{') )
				{
					x[k++] = s[i];
				}
				else
					return -1;
				break;}
			case '{':{
				if( (k<=0) || (x[k-1]=='(') )
				{
					x[k++] = s[i];
				}
				else
					return -1;
				break;}
			case ')':{
				if( (k>0) && (x[k-1]=='(') )
				{
				    k--;
					x[k] = 0;

				}
				else
					return -1;
				break;}
			case ']':{
				if( (k>0) && (x[k-1]=='[') )
				{
				    k--;
					x[k] = 0;

				}
				else
					return -1;
				break;}
			case '}':{
				if( (k>0) && (x[k-1]=='{') )
				{
				    k--;
					x[k] = 0;

				}
				else
					return -1;
				break;}
		}
		//printf("test: x=%s\n",x);
	}

	if( strlen(x)>0 ) return -1;
	else return 1;
}

int main()
{
   int i,t;
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
       char s[120];
       int re=0;
       memset(s,0,sizeof(char)*120);
       scanf("%s",s);
       int len=strlen(s);
       //if((len%2)!=0) re=-1;
       //re=pipei(s);
        re=jud(s);
       if(re==-1) printf("No\n");
       else if(re==1) printf("Yes\n");

   }
   return 0;
}