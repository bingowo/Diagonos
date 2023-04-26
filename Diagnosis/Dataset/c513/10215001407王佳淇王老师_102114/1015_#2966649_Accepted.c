#include<stdio.h>
#include<string.h>
#include<ctype.h>

int num, len1, len2;
int read(char* s, int* x) {
	int c=0;
 int l = strlen(s);
 for (int j = 0; j < l; j++) {
  if (isdigit(s[j]))
   x[c] = x[c] * 10 + s[j] - '0';
  else c++;
 }
 return c;
}
void ADD(int a[], int b[], int c[]) {
 int prime[26] = { 97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2 };
 
 int* k = &prime[25];//
 num = 0;
 for(;len1>=0||len2>=0;len1--,len2--,k--){
 	if(len1>=0) c[num]+=a[len1];
 	if(len2>=0) c[num]+=b[len2];
	 c[num+1]+=c[num]/(*k);
	 c[num]=c[num]%(*k);
	 num++; 
 }
 
}
void output(int c[]) {
 if (!c[num]) num--;
 for (; num >= 0; num--) {
  printf("%d", c[num]);
  if (num > 0) printf(",");
 }
 printf("\n");
}
int main() {
 int T;
 scanf("%d",&T);
 int A[26] = { 0 }, B[26] = { 0 }, C[26] = { 0 };
 char s[100];
 for (int i = 0; i < T; i++)
 {
  len1 = len2 = 0;
  scanf("%s",s); len1=read(s, A);
  scanf("%s",s); len2=read(s, B);
  ADD(A, B, C);
  printf("case #%d:\n", i);
  output(C);
  memset(A, 0, sizeof(A));
  memset(B, 0, sizeof(B));
  memset(C, 0, sizeof(C));
 }
 return 0;
}