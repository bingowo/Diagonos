#include <stdio.h>
#include <ctype.h>
#include <string.h>


void solve()
{
	char F[10],M[10],S[10];
	scanf("%s%s%s",F,M,S);
	int f=strlen(F)-1,m=strlen(M)-1,s=strlen(S)-1;
	char a,b;
	if(!strcmp(F,"?"))
	{
		if(!strncmp(M,"A",m))
		{
			if(!strncmp(S,"A",s)) printf("{A+,A-,AB+,AB-,B+,B-,O+,O-} %s %s\n",M,S);
			else if(!strncmp(S,"B",s)) printf("{AB+,AB-,B+,B-} %s %s\n",M,S);
			else if(!strncmp(S,"O",s)) printf("{A+,A-,B+,B-,O+,O-} %s %s\n",M,S);
			else if(!strncmp(S,"AB",s)) printf("{AB+,AB-,B+,B-} %s %s\n",M,S);
		}
		else if(!strncmp(M,"B",m))
		{
			if(!strncmp(S,"A",s)) printf("{A+,A-,AB+,AB-} %s %s\n",M,S);
			else if(!strncmp(S,"B",s)) printf("{A+,A-,AB+,AB-,B+,B-,O+,O-} %s %s\n",M,S);
			else if(!strncmp(S,"O",s)) printf("{A+,A-,B+,B-,O+,O-} %s %s\n",M,S);
			else if(!strncmp(S,"AB",s)) printf("{A+,A-,AB+,AB-} %s %s\n",M,S);
		}
		else if(!strncmp(M,"O",m))
		{
			if(!strncmp(S,"A",s)) printf("{A+,A-,AB+,AB-} %s %s\n",M,S);
			else if(!strncmp(S,"B",s)) printf("{AB+,AB-,B+,B-} %s %s\n",M,S);
			else if(!strncmp(S,"O",s)) printf("{A+,A-,B+,B-,O+,O-} %s %s\n",M,S);
			else if(!strncmp(S,"AB",s)) printf("impossible %s %s\n",M,S);
		}
		else if(!strncmp(M,"AB",m))
		{
			if(!strncmp(S,"A",s)) printf("{A+,A-,AB+,AB-,B+,B-,O+,O-} %s %s\n",M,S);
			else if(!strncmp(S,"B",s)) printf("{A+,A-,AB+,AB-,B+,B-,O+,O-} %s %s\n",M,S);
			else if(!strncmp(S,"O",s)) printf("impossible %s %s\n",M,S);
			else if(!strncmp(S,"AB",s)) printf("{A+,A-,AB+,AB-,B+,B-} %s %s\n",M,S);
		}	
	}
	else if(!strcmp(M,"?"))
	{
		if(!strncmp(F,"A",f))
		{
			if(!strncmp(S,"A",s)) printf("%s {A+,A-,AB+,AB-,B+,B-,O+,O-} %s\n",F,S);
			else if(!strncmp(S,"B",s)) printf("%s {AB+,AB-,B+,B-} %s\n",F,S);
			else if(!strncmp(S,"O",s)) printf("%s {A+,A-,B+,B-,O+,O-} %s\n",F,S);
			else if(!strncmp(S,"AB",s)) printf("%s {AB+,AB-,B+,B-} %s\n",F,S);
		}
		else if(!strncmp(F,"B",f))
		{
			if(!strncmp(S,"A",s)) printf("%s {A+,A-,AB+,AB-} %s\n",F,S);
			else if(!strncmp(S,"B",s)) printf("%s {A+,A-,AB+,AB-,B+,B-,O+,O-} %s\n",F,S);
			else if(!strncmp(S,"O",s)) printf("%s {A+,A-,B+,B-,O+,O-} %s\n",F,S);
			else if(!strncmp(S,"AB",s)) printf("%s {A+,A-,AB+,AB-} %s\n",F,S);
		}
		else if(!strncmp(F,"O",f))
		{
			if(!strncmp(S,"A",s)) printf("%s {A+,A-,AB+,AB-} %s\n",F,S);
			else if(!strncmp(S,"B",s)) printf("%s {AB+,AB-,B+,B-} %s\n",F,S);
			else if(!strncmp(S,"O",s)) printf("%s {A+,A-,B+,B-,O+,O-} %s\n",F,S);
			else if(!strncmp(S,"AB",s)) printf("%s impossible %s\n",F,S);
		}
		else if(!strncmp(F,"AB",f))
		{
			if(!strncmp(S,"A",s)) printf("%s {A+,A-,AB+,AB-,B+,B-,O+,O-} %s\n",F,S);
			else if(!strncmp(S,"B",s)) printf("%s {A+,A-,AB+,AB-,B+,B-,O+,O-} %s\n",F,S);
			else if(!strncmp(S,"O",s)) printf("%s impossible %s\n",F,S);
			else if(!strncmp(S,"AB",s)) printf("%s {A+,A-,AB+,AB-,B+,B-} %s\n",F,S);
		}
	}
	else if(!strcmp(S,"?"))
	{
		if(F[f]=='-'&&M[m]=='-')
		{
			if(!strncmp(F,"A",f))
			{
				if(!strncmp(M,"A",m)) printf("%s %s {A-,O-}\n",F,M);
				else if(!strncmp(M,"B",m)) printf("%s %s {A-,AB-,B-,O-}\n",F,M);
				else if(!strncmp(M,"O",m)) printf("%s %s {A-,O-}\n",F,M);
				else if(!strncmp(M,"AB",m)) printf("%s %s {A-,AB-,B-}\n",F,M);
			}
			else if(!strncmp(F,"B",f))
			{
				if(!strncmp(M,"A",m)) printf("%s %s {A-,AB-,B-,O-}\n",F,M);
				else if(!strncmp(M,"B",m)) printf("%s %s {B-,O-}\n",F,M);
				else if(!strncmp(M,"O",m)) printf("%s %s {B-,O-}\n",F,M);
				else if(!strncmp(M,"AB",m)) printf("%s %s {A-,AB-,B-}\n",F,M);
			}
			else if(!strncmp(F,"O",f))
			{
				if(!strncmp(M,"A",m)) printf("%s %s {A-,O-}\n",F,M);
				else if(!strncmp(M,"B",m)) printf("%s %s {B-,O-}\n",F,M);
				else if(!strncmp(M,"O",m)) printf("%s %s O-\n",F,M);
				else if(!strncmp(M,"AB",m)) printf("%s %s {A-,B-}\n",F,M);
			}
			else if(!strncmp(F,"AB",f))
			{
				if(!strncmp(M,"A",m)) printf("%s %s {A-,AB-,B-}\n",F,M);
				else if(!strncmp(M,"B",m)) printf("%s %s {A-,AB-,B-}\n",F,M);
				else if(!strncmp(M,"O",m)) printf("%s %s {A-,B-}\n",F,M);
				else if(!strncmp(M,"AB",m)) printf("%s %s {A-,AB-,B-}\n",F,M);
			}
		}
		else
		if(!strncmp(F,"A",f))
		{
			if(!strncmp(M,"A",m)) printf("%s %s {A+,A-,O+,O-}\n",F,M);
			else if(!strncmp(M,"B",m)) printf("%s %s {A+,A-,AB+,AB-,B+,B-,O+,O-}\n",F,M);
			else if(!strncmp(M,"O",m)) printf("%s %s {A+,A-,O+,O-}\n",F,M);
			else if(!strncmp(M,"AB",m)) printf("%s %s {A+,A-,AB+,AB-,B+,B-}\n",F,M);
		}
		else if(!strncmp(F,"B",f))
		{
			if(!strncmp(M,"A",m)) printf("%s %s {A+,A-,AB+,AB-,B+,B-,O+,O-}\n",F,M);
			else if(!strncmp(M,"B",m)) printf("%s %s {B+,B-,O+,O-}\n",F,M);
			else if(!strncmp(M,"O",m)) printf("%s %s {B+,B-,O+,O-}\n",F,M);
			else if(!strncmp(M,"AB",m)) printf("%s %s {A+,A-,AB+,AB-,B+,B-}\n",F,M);
		}
		else if(!strncmp(F,"O",f))
		{
			if(!strncmp(M,"A",m)) printf("%s %s {A+,A-,O+,O-}\n",F,M);
			else if(!strncmp(M,"B",m)) printf("%s %s {B+,B-,O+,O-}\n",F,M);
			else if(!strncmp(M,"O",m)) printf("%s %s {O+,O-}\n",F,M);
			else if(!strncmp(M,"AB",m)) printf("%s %s {A+,A-,B+,B-}\n",F,M);
		}
		else if(!strncmp(F,"AB",f))
		{
			if(!strncmp(M,"A",m)) printf("%s %s {A+,A-,AB+,AB-,B+,B-}\n",F,M);
			else if(!strncmp(M,"B",m)) printf("%s %s {A+,A-,AB+,AB-,B+,B-}\n",F,M);
			else if(!strncmp(M,"O",m)) printf("%s %s {A+,A-,B+,B-}\n",F,M);
			else if(!strncmp(M,"AB",m)) printf("%s %s {A+,A-,AB+,AB-,B+,B-}\n",F,M);
		}
	}

} 



int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		solve();
	}
	return 0;
}