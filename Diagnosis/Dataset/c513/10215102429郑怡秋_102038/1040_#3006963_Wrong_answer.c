#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main()
{
	char F[10],M[10],S[10];
	scanf("%s%s%s",F,M,S);
	if(!strcmp(F,"?"))
	{
		if(!strcmp(M,"A"))
		{
			if(!strcmp(S,"A")) printf("{A,AB,B,O} %s %s\n",M,S);
			else if(!strcmp(S,"B")) printf("{AB,B} %s %s\n",M,S);
			else if(!strcmp(S,"O")) printf("{A,B,O} %s %s\n",M,S);
			else if(!strcmp(S,"AB")) printf("{AB,B} %s %s\n",M,S);
		}
		else if(!strcmp(M,"B"))
		{
			if(!strcmp(S,"A")) printf("{A,AB} %s %s\n",M,S);
			else if(!strcmp(S,"B")) printf("{A,AB,B,O} %s %s\n",M,S);
			else if(!strcmp(S,"O")) printf("{A,B,O} %s %s\n",M,S);
			else if(!strcmp(S,"AB")) printf("{A,AB} %s %s\n",M,S);
		}
		else if(!strcmp(M,"O"))
		{
			if(!strcmp(S,"A")) printf("{A,AB} %s %s\n",M,S);
			else if(!strcmp(S,"B")) printf("{AB,B} %s %s\n",M,S);
			else if(!strcmp(S,"O")) printf("{A,B,O} %s %s\n",M,S);
			else if(!strcmp(S,"AB")) printf("impossible %s %s\n",M,S);
		}
		else if(!strcmp(M,"AB"))
		{
			if(!strcmp(S,"A")) printf("{A,AB,B,O} %s %s\n",M,S);
			else if(!strcmp(S,"B")) printf("{A,AB,B,O} %s %s\n",M,S);
			else if(!strcmp(S,"O")) printf("impossible %s %s\n",M,S);
			else if(!strcmp(S,"AB")) printf("{A,AB,B} %s %s\n",M,S);
		}	
	}
	else if(!strcmp(M,"?"))
	{
		if(!strcmp(F,"A"))
		{
			if(!strcmp(S,"A")) printf("%s {A,AB,B,O} %s\n",F,S);
			else if(!strcmp(S,"B")) printf("%s {AB,B} %s\n",F,S);
			else if(!strcmp(S,"O")) printf("%s {A,B,O} %s\n",F,S);
			else if(!strcmp(S,"AB")) printf("%s {AB,B} %s\n",F,S);
		}
		else if(!strcmp(F,"B"))
		{
			if(!strcmp(S,"A")) printf("%s {A,AB} %s\n",F,S);
			else if(!strcmp(S,"B")) printf("%s {A,AB,B,O} %s\n",F,S);
			else if(!strcmp(S,"O")) printf("%s {A,B,O} %s\n",F,S);
			else if(!strcmp(S,"AB")) printf("%s {A,AB} %s\n",F,S);
		}
		else if(!strcmp(F,"O"))
		{
			if(!strcmp(S,"A")) printf("%s {A,AB} %s\n",F,S);
			else if(!strcmp(S,"B")) printf("%s {AB,B} %s\n",F,S);
			else if(!strcmp(S,"O")) printf("%s {A,B,O} %s\n",F,S);
			else if(!strcmp(S,"AB")) printf("%s impossible %s\n",F,S);
		}
		else if(!strcmp(F,"AB"))
		{
			if(!strcmp(S,"A")) printf("%s {A,AB,B,O} %s\n",F,S);
			else if(!strcmp(S,"B")) printf("%s {A,AB,B,O} %s\n",F,S);
			else if(!strcmp(S,"O")) printf("%s impossible %s\n",F,S);
			else if(!strcmp(S,"AB")) printf("%s {A,AB,B} %s\n",F,S);
		}
	}
	else if(!strcmp(S,"?"))
	{
		if(!strcmp(F,"A"))
		{
			if(!strcmp(M,"A")) printf("%s %s {A,O}\n",F,M);
			else if(!strcmp(M,"B")) printf("%s %s {A,AB,B,O}\n",F,M);
			else if(!strcmp(M,"O")) printf("%s %s {A,O}\n",F,M);
			else if(!strcmp(M,"AB")) printf("%s %s {A,AB,B}\n",F,M);
		}
		else if(!strcmp(F,"B"))
		{
			if(!strcmp(M,"A")) printf("%s %s {A,AB,B,O}\n",F,M);
			else if(!strcmp(M,"B")) printf("%s %s {B,O}\n",F,M);
			else if(!strcmp(M,"O")) printf("%s %s {B,O}\n",F,M);
			else if(!strcmp(M,"AB")) printf("%s %s {A,AB,B}\n",F,M);
		}
		else if(!strcmp(F,"O"))
		{
			if(!strcmp(M,"A")) printf("%s %s {A,O}\n",F,M);
			else if(!strcmp(M,"B")) printf("%s %s {B,O}\n",F,M);
			else if(!strcmp(M,"O")) printf("%s %s {O}\n",F,M);
			else if(!strcmp(M,"AB")) printf("%s %s {AB}\n",F,M);
		}
		else if(!strcmp(F,"AB"))
		{
			if(!strcmp(M,"A")) printf("%s %s {A,AB,B}\n",F,M);
			else if(!strcmp(M,"B")) printf("%s %s {A,AB,B}\n",F,M);
			else if(!strcmp(M,"O")) printf("%s %s {A,B}\n",F,M);
			else if(!strcmp(M,"AB")) printf("%s %s {A,AB,B}\n",F,M);
		}
	}
	return 0;
} 