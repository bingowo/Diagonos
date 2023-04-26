#include <stdio.h>
#include <string.h>
int GCD(long long int a,long long int b)
{
if(a==0)
{
return b;
}else
{
return GCD(b % a,a);
}
}
int main() {
int i,t;
void solve();
scanf("%d",&t);
for (i = 1;i <= t;i++) {
solve();
}
return 0;
}

void solve() {
char s[120];
int ch,sum = 0,i,size;
fflush(stdin);
gets(s);
for(i = 0;s[i] != '\0';i++) {
ch = s[i];
while(ch != 0) {
if(ch%2) sum++;
ch = ch/2;
}
}
size = 8 * sizeof(char) * strlen(s);
int m=GCD(sum,size);
printf("%d",sum/m);printf("/");printf("%d\n",size/m);
}