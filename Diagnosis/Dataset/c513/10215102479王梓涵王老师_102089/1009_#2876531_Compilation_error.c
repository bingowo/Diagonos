//
// Created by Shizumu on 2022/2/23.
//
#include <stdio.h>

void CalculateOne(char s[], int *num, int *oneNum)
{
    unsigned char *end = s;
    int temp;
    while(*end){
        end ++;
    } 
    unsigned char *p = (unsigned char *) s;
    while(p != end){
        temp = *p;
        *num += 8; 
		while(temp > 0){
            if(temp % 2 == 1){
                *oneNum += 1;
            }
            temp /= 2;
        }
        p ++;	
    }
}

int gcd(int a, int b)
{
    int ret, rest = a % b;
    while(rest){
        a = b;
        b = rest;
        rest = a % b;
    }
    ret= b;
    return ret;
}

int main(void)
{
    int t;
    scanf("%d", &t);
    char c = getchar();	。 
    for(int i = 0; i < t; i ++){
        char s[121];
        gets(s);
        int num = 0, oneNum = 0;
        CalculateOne(s, &num, &oneNum);
        int multi = gcd(num, oneNum);
        printf("%d/%d\n", oneNum / multi, num / multi);
    }
	
    return 0;
}