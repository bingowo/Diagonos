#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){
    int t,i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        char light[100];
        scanf("%s",light);
        int len=strlen(light);
        int p1=0,p2=0,p3=0,p4=0;
        int num1=0,num2=0,num3=0,num4=0;
        while(light[p1]!='R'&&p1<len) p1++;
        while(light[p2]!='B'&&p2<len) p2++;
        while(light[p3]!='Y'&&p3<len) p3++;
        while(light[p4]!='G'&&p4<len) p4++;            
        //printf("%d %d %d %d",p1,p2,p3,p4); 
        if(p1!=len){
        	if(p1>=4){
        		for(j=p1;j>=0;j-=4){
        			if(light[j]!='R') num1++;
				}
			}
			for(j=p1;j<len;j+=4){
				if(light[j]!='R') num1++;
			}
		}
		if(p2!=len){
        	if(p2>=4){
        		for(j=p2;j>=0;j-=4){
        			if(light[j]!='B') num2++;
				}
			}
			for(j=p2;j<len;j+=4){
				if(light[j]!='B') num2++;
			}
		}
		if(p3!=len){
        	if(p3>=4){
        		for(j=p3;j>=0;j-=4){
        			if(light[j]!='Y') num3++;
				}
			}
			for(j=p3;j<len;j+=4){
				if(light[j]!='Y') num3++;
			}
		}
		if(p4!=len){
        	if(p4>=4){
        		for(j=p4;j>=0;j-=4){
        			if(light[j]!='G') num4++;
				}
			}
			for(j=p4;j<len;j+=4){
				if(light[j]!='G') num4++;
			}
		}
		printf("%d %d %d %d",num1,num2,num3,num4);
    }
       
}