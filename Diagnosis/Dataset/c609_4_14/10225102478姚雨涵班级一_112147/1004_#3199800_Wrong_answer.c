#include <stdio.h>
#include <string.h>
char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void inte(int n,int r){
	if(n > 0){
		inte(n / r,r);
		putchar(table[n%r]);
	}
}
int toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return c + ('A' - 'a');
	return c;
}
int powe(int n,int p){
    int o = 1;
    for(int i = 0;i<=n;i++)
        o *= p;
    return o;
}
int main(){
    int n,r,i = 0;
    char a[10000];
    scanf("%d %s %d",&n,a,&r);
    int t,numb;
    for(int j = 0;j < strlen(a);j++){
        t = toupper(a[j]) - '0';
        numb += (t*powe(j,n));
    }
    inte(numb,r);
return 0;
}
