int len=strlen(A);
int i,j;
Add1(A,len-1);

for(i=1;i<len;i++){
	if(A[i]==A[i-1])
		break;
}

if(i != len){
	i=Add1(A,i);
	while(i>0)	{	
		if(A[i] != A[i-1]) break;
		i=Add1(A,i);
	}
	for(j=i+1;j<len;j++)	{
		A[j] = (j-i+1)%2+‘0’; //填充0101…
	}
}
if(A[0]!='0') printf("%c",A[0]);
printf("%s\n",A+1);
