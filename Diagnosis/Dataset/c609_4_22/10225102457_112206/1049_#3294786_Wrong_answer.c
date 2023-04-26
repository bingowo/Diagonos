#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	int len;
	char num[505];
}NUM;

int main(void)
{
    NUM a,b;
	while(scanf("%s%s",a.num,b.num) != EOF){
        int im = 0;
        if(strlen(a.num) < strlen(b.num) || (strlen(a.num) == strlen(b.num) && strcmp(a.num,b.num) < 0)){
            char temp[505];
            strcpy(temp,a.num);
            strcpy(b.num,a.num);
            strcpy(a.num,temp);
            im = 1;
        }
        int mi = 0;
        a.len = strlen(a.num)-1;
        b.len = strlen(b.num)-1;
        int i;
        for(i = 0; i <= b.len; i++){
            //printf("%d  %d  ",a.num[a.len-i],b.num[b.len-i]+mi);
            if(a.num[a.len-i] < b.num[b.len-i]+mi) {
                int temp = (int)a.num[a.len-i]+10 - mi - (int)b.num[b.len-i] + (int)'0';
                a.num[a.len-i] = temp;
                mi = 1;
            }
            else {
                int temp = (int)a.num[a.len-i]+ (int)'0' - mi - (int)b.num[b.len-i];
                a.num[a.len-i] = temp;
                mi = 0;
            }
        }
        for(; i <= a.len && mi == 1; i++){
            a.num[a.len-i] -= mi;
            if(a.num[a.len-i] < '0') { mi = 1; a.num[i] = a.num[i] + 10;}
            else mi = 0;
        }
        i = 0;
        while(a.num[i] == '0') i++;

        if(im == 1) putchar('-');
        for(; i <= a.len; i++)
            putchar(a.num[i]);
        putchar('\n');
	}

	return 0;
}