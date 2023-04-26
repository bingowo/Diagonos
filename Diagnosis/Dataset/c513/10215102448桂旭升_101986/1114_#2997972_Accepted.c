#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>
#include<ctype.h>
int fen(int x, int* a){
    int temp = (int)sqrt(fabs(x)), j = 0;
    for(int i = 1; i <= temp; i++){
        if(x%i == 0){
            *a++ = i;j++;
        }
    }
    return j;
}
void readpoly(char *p, int* co){
    while (*p){
        int sign=1,c=0,d=0;
        if (*p=='+') p++; 
        else if (*p=='-') sign=-1,p++;
        while (isdigit(*p)){
            c=c*10+*p-'0'; p++;
        }
        if (*p!='x') { co[0]=c*sign; return; }
        else p++;
        if (c==0) c=1;
        if (*p=='^') p++;
        while (isdigit(*p)) { d=d*10+*p-'0'; p++; }
        if (d==0) d=1;
        co[d]=c*sign;
    }
}
int main(){
	int i, j;
    char s[17];
    int d[3] = {0};
    scanf("%s", s);
    readpoly(s, d);
    //printf("%d %d %d\n", d[2], d[1], d[0]);
    if(d[1] == 0){
        if(d[0] > 0)printf("No Answer!");
        else printf("%d %d %d %d", (int)sqrt((double)d[2]), -(int)sqrt(-(double)d[0]), (int)sqrt((double)d[2]), (int)sqrt(-(double)d[0]));
    }
    else if(d[0] == 0){
        if(d[2] > 1)printf("%d %d %d %d", 1, 0, d[2], d[1]);
        else{
            if(d[1]>0)printf("%d %d %d %d", 1, 0, 1, d[1]);
            else printf("%d %d %d %d", 1, d[1], 1, 0);
        }
    }
    else{
        int a0[15], a2[15], cnt0, cnt2, sign = 1, flag = 0;
        int ans1[2], ans2[2];
        cnt0 = fen(d[0], a0); cnt2 = fen(d[2], a2);//printf("%d %d\n", a0[0], a0[1]);
        if(d[0] > 0){
            if(d[1] < 0)sign = -1;
            for(i = 0; i < cnt2; i++){
                for(j = 0; j < cnt0; j++){
                    if(a2[i]*a0[j] + d[2]/a2[i]*d[0]/a0[j] == sign*d[1]){
                        ans1[0] = a2[i]; ans2[0] = d[2]/a2[i];
                        ans1[1] = sign*d[0]/a0[j]; ans2[1] = sign*a0[j];
                        flag = 1;
                        break;
                    }
                    if(a2[i]*d[0]/a0[j] + d[2]/a2[i]*a0[j] == sign*d[1]){
                        ans1[0] = a2[i]; ans2[0] = d[2]/a2[i];
                        ans1[1] = sign*a0[j]; ans2[1] = sign*d[0]/a0[j];
                        flag = 1;
                        break;
                    }
                }
                if(flag)break;
            }
            if(flag == 0)printf("No Answer!");
            else{
                if(ans1[0] < ans2[0])printf("%d %d %d %d", ans1[0], ans1[1], ans2[0], ans2[1]);
                else if(ans1[0] > ans2[0])printf("%d %d %d %d", ans2[0], ans2[1], ans1[0], ans1[1]);
                else if(ans1[0] == ans2[0]){
                    if(ans1[1] <= ans2[1])printf("%d %d %d %d", ans1[0], ans1[1], ans2[0], ans2[1]);
                    else printf("%d %d %d %d", ans2[0], ans2[1], ans1[0], ans1[1]);
                }
            }
        }
        else{
            d[0] = -d[0];
            for(i = 0; i < cnt2; i++){
                for(j = 0; j < cnt0; j++){
                    if(-1*a2[i]*a0[j] + d[2]/a2[i]*d[0]/a0[j] == d[1]){
                        ans1[0] = a2[i]; ans2[0] = d[2]/a2[i];
                        ans1[1] = d[0]/a0[j]; ans2[1] = -a0[j];
                        flag = 1;
                        break;
                    }
                    if(a2[i]*a0[j] - d[2]/a2[i]*d[0]/a0[j] == d[1]){
                        ans1[0] = a2[i]; ans2[0] = d[2]/a2[i];
                        ans1[1] = (-1)*d[0]/a0[j]; ans2[1] = a0[j];
                        flag = 1;
                        break;
                    }
                    //printf("%d\n", d[2]/a2[i]*(-1)*d[0]/a0[j]);
                    if(-a2[i]*d[0]/a0[j] + d[2]/a2[i]*a0[j] == d[1]){
                        ans1[0] = a2[i]; ans2[0] = d[2]/a2[i];
                        ans1[1] = a0[j]; ans2[1] = -d[0]/a0[j];
                        flag = 1;
                        break;
                    }
                    if(a2[i]*d[0]/a0[j] - d[2]/a2[i]*a0[j] == d[1]){
                        ans1[0] = a2[i]; ans2[0] = d[2]/a2[i];
                        ans1[1] = -a0[j]; ans2[1] = d[0]/a0[j];
                        flag = 1;
                        break;
                    }
                }
                if(flag)break;
            }
            if(flag == 0)printf("No Answer!");
            else{
                if(ans1[0] < ans2[0])printf("%d %d %d %d", ans1[0], ans1[1], ans2[0], ans2[1]);
                else if(ans1[0] > ans2[0])printf("%d %d %d %d", ans2[0], ans2[1], ans1[0], ans1[1]);
                else if(ans1[0] == ans2[0]){
                    if(ans1[1] <= ans2[1])printf("%d %d %d %d", ans1[0], ans1[1], ans2[0], ans2[1]);
                    else printf("%d %d %d %d", ans2[0], ans2[1], ans1[0], ans1[1]);
                }
            }
        }
    }
    system("pause");
	return 0;
}