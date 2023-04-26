#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1005

char* transBin(char* s) {
	int length = strlen(s)*4,len=strlen(s);
	char* ret = (char*)malloc(N);
	for (int i = 0;i < 4 * length;++i)ret[i] = '\0';
	for (int i = 2;i < len;++i) {
		if (s[i] == '0')strcat(ret, "0000");if (s[i] == '1')strcat(ret, "0001");if (s[i] == '8')strcat(ret, "1000");
		if (s[i] == '2')strcat(ret, "0010");if (s[i] == '3')strcat(ret, "0011");if (s[i] == '9')strcat(ret, "1001");
		if (s[i] == '4')strcat(ret, "0100");if (s[i] == '5')strcat(ret, "0101");if (s[i] == 'A')strcat(ret, "1010");
		if (s[i] == '6')strcat(ret, "0110");if (s[i] == '7')strcat(ret, "0111");if (s[i] == 'B')strcat(ret, "1011");
		if (s[i] == 'C')strcat(ret, "1100");if (s[i] == 'D')strcat(ret, "1101");if (s[i] == 'E')strcat(ret, "1110");if (s[i] == 'F')strcat(ret, "1111");
	}
	return ret;
}

void Multi(long long* r,long long* v)
{
    long long tmp1=*r,tmp2=*v;
    *r=-tmp1-tmp2;
    *v=tmp1-tmp2;
}

void Add(long long* r,long long* v)
{
    long long tmp1=*r,tmp2=*v;
    *r=tmp1+1;
    *v=tmp2;
}

int main()
{
    char tmp[100]={'\0'};
    scanf("%s",tmp);
    char s[N]={'\0'};strcpy(s,transBin(tmp));
    int l=strlen(s);
    long long real=0,vir=0;
    for(int i=0;i<l;++i){
        if(s[i]=='1'){
            Multi(&real,&vir);
            Add(&real,&vir);
        }
        else Multi(&real,&vir);
    }
    // printf("%d,%d",real,vir);
    if(vir==0)printf("%lld",real);
    else if(real==0)printf("%lldi",vir);
    else if(vir<0)printf("%lld-%lldi",real,-vir);
    else if(vir==1)printf("%lld+i",real);
    else if(vir==-1)printf("%lld-i",real,-vir);
    else printf("%lld+%lldi",real,vir);
    return 0;
}

