#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	char s1[5],s2[5],s3[5];
	scanf("%s %s %s",s1,s2,s3);
	if(strcmp(s1,"AB")==0) 
	{
		s1[0] = 'C';
		s1[1] = '\0';
	}
	if(strcmp(s2,"AB")==0) 
	{
		s2[0] = 'C';
		s2[1] = '\0';
	}
	if(strcmp(s3,"AB")==0) 
	{
		s3[0] = 'C';
		s3[1] = '\0';
	}
	if(strcmp(s1,"?")==0)
	{
		if(s2[0]=='A' && s3[0]=='A') printf("{A,AB,B,O} A A");
		else if(s2[0]=='A' && s3[0]=='B') printf("{AB,B} A B");
		else if(s2[0]=='A' && s3[0]=='C') printf("{AB,B} A AB");
		else if(s2[0]=='A' && s3[0]=='O') printf("{A,B,O} A O");
		
		else if(s2[0]=='B' && s3[0]=='A') printf("{A,AB} B A");
		else if(s2[0]=='B' && s3[0]=='B') printf("{A,AB,B,O} B B");
		else if(s2[0]=='B' && s3[0]=='O') printf("{A,B,O} B O");
		else if(s2[0]=='B' && s3[0]=='C') printf("{A,AB} B AB");
		
		else if(s2[0]=='C' && s3[0]=='A') printf("{A,AB,B,O} AB A");
		else if(s2[0]=='C' && s3[0]=='B') printf("{A,AB,B,O} AB B");
		else if(s2[0]=='C' && s3[0]=='O') printf("impossible AB O");
		else if(s2[0]=='C' && s3[0]=='C') printf("{A,AB,B} AB AB");
		
		else if(s2[0]=='O' && s3[0]=='A') printf("{A,AB} O A");
		else if(s2[0]=='O' && s3[0]=='B') printf("{B,AB} O B");
		else if(s2[0]=='O' && s3[0]=='O') printf("{A,B,O} O O");
		else if(s2[0]=='O' && s3[0]=='C') printf("impossible O AB");
	}
	else if(strcmp(s2,"?")==0)
	{
		if(s1[0]=='A' && s3[0]=='A') printf("A {A,AB,B,O} A");
		else if(s1[0]=='A' && s3[0]=='B') printf("A {AB,B} B");
		else if(s1[0]=='A' && s3[0]=='C') printf("A {AB,B} AB");
		else if(s1[0]=='A' && s3[0]=='O') printf("A {A,B,O} O");
		
		else if(s1[0]=='B' && s3[0]=='A') printf("B {A,AB} A");
		else if(s1[0]=='B' && s3[0]=='B') printf("B {A,AB,B,O} B");
		else if(s1[0]=='B' && s3[0]=='O') printf("B {A,B,O} O");
		else if(s1[0]=='B' && s3[0]=='C') printf("B {A,AB} AB");
		
		else if(s1[0]=='C' && s3[0]=='A') printf("AB {A,AB,B,O} A");
		else if(s1[0]=='C' && s3[0]=='B') printf("AB {A,AB,B,O} B");
		else if(s1[0]=='C' && s3[0]=='O') printf("AB impossible O");
		else if(s1[0]=='C' && s3[0]=='C') printf("AB {A,AB,B} AB");
		
		else if(s1[0]=='O' && s3[0]=='A') printf("O {A,AB} A");
		else if(s1[0]=='O' && s3[0]=='B') printf("O {B,AB} B");
		else if(s1[0]=='O' && s3[0]=='O') printf("O {A,B,O} O");
		else if(s1[0]=='O' && s3[0]=='C') printf("O impossible AB");
	}
	else if(strcmp(s3,"?")==0)
	{
		if(s1[0]=='A' && s2[0]=='A') printf("A A {A,O}");
		else if(s1[0]=='A' && s2[0]=='B') printf("A B {A,AB,B,O}");
		else if(s1[0]=='A' && s2[0]=='C') printf("A AB {A,AB,B}");
		else if(s1[0]=='A' && s2[0]=='O') printf("A O {A,O}");
		
		else if(s1[0]=='B' && s2[0]=='A') printf("B A {A,AB,B,O}");
		else if(s1[0]=='B' && s2[0]=='B') printf("B B {B,O}");
		else if(s1[0]=='B' && s2[0]=='O') printf("B O {B,O}");
		else if(s1[0]=='B' && s2[0]=='C') printf("B AB {A,AB,B}");
		
		else if(s1[0]=='C' && s2[0]=='A') printf("AB A {A,AB,B}");
		else if(s1[0]=='C' && s2[0]=='B') printf("AB B {A,AB,B}");
		else if(s1[0]=='C' && s2[0]=='O') printf("AB O {A,B}");
		else if(s1[0]=='C' && s2[0]=='C') printf("AB AB {A,AB,B}");
		
		else if(s1[0]=='O' && s2[0]=='A') printf("O A {A,O}");
		else if(s1[0]=='O' && s2[0]=='B') printf("O B {B,O}");
		else if(s1[0]=='O' && s2[0]=='O') printf("O O {O}");
		else if(s1[0]=='O' && s2[0]=='C') printf("O AB {A,B}");
	}
	return 0;
} 