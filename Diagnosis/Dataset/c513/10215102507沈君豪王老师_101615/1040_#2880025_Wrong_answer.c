#include <stdio.h>
#include <string.h>

void PrintPhenotype(char f[], char m[])
{
	if(strcmp(f, "A") == 0 && strcmp(m, "A") == 0){
		printf("A A {A,O}");
	}else if(strcmp(f, "A") == 0 && strcmp(m, "B") == 0){
		printf("A B {A,AB,B,O}");
	}else if(strcmp(f, "B") == 0 && strcmp(m, "A") == 0){
		printf("B A {A,AB,B,O}");
	}else if(strcmp(f, "B") == 0 && strcmp(m, "B") == 0){
		printf("B B {B,O}");
	}else if(strcmp(f, "A") == 0 && strcmp(m, "O") == 0){
		printf("A O {A,O}");
	}else if(strcmp(f, "O") == 0 && strcmp(m, "A") == 0){
		printf("O A {A,O}");
	}else if(strcmp(f, "B") == 0 && strcmp(m, "O") == 0){
		printf("B O {B,O}");
	}else if(strcmp(f, "O") == 0 && strcmp(m, "B") == 0){
		printf("O B {B,O}");
	}else if(strcmp(f, "O") == 0 && strcmp(m, "O") == 0){
		printf("O O {O}");
	}else if(strcmp(f, "AB") == 0 && strcmp(m, "AB") == 0){
		printf("AB AB {A,AB,B}");
	}else if(strcmp(f, "AB") == 0 && strcmp(m, "A") == 0){
		printf("AB A {A,AB,B}");
	}else if(strcmp(f, "A") == 0 && strcmp(m, "AB") == 0){
		printf("A AB {A,AB,B}");
	}else if(strcmp(f, "AB") == 0 && strcmp(m, "B") == 0){
		printf("AB B {A,AB,B}");
	}else if(strcmp(f, "B") == 0 && strcmp(m, "AB") == 0){
		printf("B AB {A,AB,B}");
	}else if(strcmp(f, "AB") == 0 && strcmp(m, "O") == 0){
		printf("AB O {A,B}");
	}else if(strcmp(f, "O") == 0 && strcmp(m, "AB") == 0){
		printf("O AB {A,B}");
	}
}

void FindFather(char f[], char k[])
{
	if(strcmp(f, "A") == 0 && strcmp(k, "A") == 0){
		printf("{A,AB,B,O}");
	}else if(strcmp(f, "A") == 0 && strcmp(k, "B") == 0){
		printf("{AB,B}");
	}else if(strcmp(f, "B") == 0 && strcmp(k, "A") == 0){
		printf("{A,AB}");
	}else if(strcmp(f, "B") == 0 && strcmp(k, "B") == 0){
		printf("{A,AB,B,O}");
	}else if(strcmp(f, "A") == 0 && strcmp(k, "O") == 0){
		printf("{O}");
	}else if(strcmp(f, "O") == 0 && strcmp(k, "A") == 0){
		printf("{A,AB}");
	}else if(strcmp(f, "B") == 0 && strcmp(k, "O") == 0){
		printf("{O}");
	}else if(strcmp(f, "O") == 0 && strcmp(k, "B") == 0){
		printf("{AB,B}");
	}else if(strcmp(f, "O") == 0 && strcmp(k, "O") == 0){
		printf("{O}");
	}else if(strcmp(f, "AB") == 0 && strcmp(k, "AB") == 0){
		printf("{A,AB,B}");
	}else if(strcmp(f, "AB") == 0 && strcmp(k, "A") == 0){
		printf("{A,AB,B,O}");
	}else if(strcmp(f, "A") == 0 && strcmp(k, "AB") == 0){
		printf("{AB,B}");
	}else if(strcmp(f, "AB") == 0 && strcmp(k, "B") == 0){
		printf("{A,AB,B,O}");
	}else if(strcmp(f, "B") == 0 && strcmp(k, "AB") == 0){
		printf("{A,AB}");
	}else if(strcmp(f, "AB") == 0 && strcmp(k, "O") == 0){
		printf("impossible");
	}else if(strcmp(f, "O") == 0 && strcmp(k, "AB") == 0){
		printf("impossible");
	}
}

int main(void)
{
	char f[3], m[3], k[3];
	scanf("%s %s %s", f, m, k);
	if(strcmp(k, "?") == 0){
		PrintPhenotype(f, m);
	}else if(strcmp(m, "?") == 0){
		printf("%s ", f);
		FindFather(f, k);
		printf(" %s", k);
	}else if(strcmp(f, "?") == 0){
		FindFather(m, k);
		printf(" %s %s", m, k);
	}
	
	return 0;
}