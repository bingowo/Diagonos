#include<stdio.h>
#include<string.h>
int prime[26]=
{97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
int main()
{
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++){
        char s[100];
        int a[26]={0},b[26]={0},c[26]={0};
        scanf("%s",s);
        Readnumber(s,a);
        scanf("%s",s);
        Readnumber(s,b);
        ADD(a,b,c);
        printf("case #%d:\n",i);
        output(c);
    }
    return 0;
}
void Readnumber(char s[], int num[])
{
	char *p = s;
	int temp = 0, index = 0;
	while(*p){
		if(*p == ','){
			num[index++] = temp;
			temp = 0;
		}else{
			temp = temp * 10 + (*p - '0');	
		}
		p ++;
	}
	num[index++] = temp;
	memmove(num + (26 - index), num, sizeof(int) * index);
	memset(num, -1, sizeof(int) * (26 - index));
}
