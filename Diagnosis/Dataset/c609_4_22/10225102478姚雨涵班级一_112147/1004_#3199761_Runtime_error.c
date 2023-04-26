#include <stdio.h>
#include <stdlib.h>
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
int powe(int n){
    int o = 1;
    for(int i = 0;i<n;i++)
        o *= 15;
    return(o);
}
int main(){
    int n,r,i = 0;
    scanf("%d",&n);
    char a[10000];
    while(scanf("%c",&a[i++])!=EOF);
    scanf("%d",&r);
    int t,numb;
    for(int j = 0;i >= 0;i--,j++){
        t = toupper(a[i]) - 30;
        numb += (t*powe(j));
    }
    inte(numb,r);
return 0;
}
