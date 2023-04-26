#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct node{
	char tmp[507];
	char inte[507];
	char flo[507];
	int len;
};
struct node a,b;
int n;
node init(node t){
	int len = strlen(t.tmp);
	bool f=1;
	node x;
	int po1,po2;
	po1=po2=0;
	for(int i=0;i<len;i++){
		if(t.tmp[i]=='.'&&f){
			f=0;
			continue;
		}
		if(f){
			x.inte[po1++] = t.tmp[i];
		}else{
			x.flo[po2++] = t.tmp[i];
		}
	}
	x.inte[po1++] = '\0';
	x.flo[po2++] = '\0';
	if(!strlen(x.inte)){
		po1 = 0;
		x.inte[po1++] = '0';
		x.inte[po1++] = '\0';
	}
	if(!strlen(x.flo)){
		po2 = 0;
		x.flo[po2++] = '0';
		x.flo[po2++] = '\0';
	}
	
	for(int i=0;i<len;i++){
		x.tmp[i] = t.tmp[i];
	}
	x.len = len;
	return x;
}

int find_po(node t){
	for(int i=0;i<t.len;i++){
		if(t.tmp[i] == '.'){
			return i;
		}
	}
}

node add(node a,node b){    
    node ans;
    ans.len = 0;
    int c=0;
    for(int i=0;i<a.len;i++){
        if(a.tmp[i]=='.'){    
            ans.tmp[ans.len++]='.';
            continue;
        }
        int temp=(a.tmp[i]-'0')+(b.tmp[i]-'0')+c;
        ans.tmp[ans.len++]=temp%10+'0';
        c=temp/10;
    }
	//printf("%s\n",ans.tmp);
    if(c!=0)    //还有进位
        ans.tmp[ans.len++]=c+'0';
    ans.tmp[ans.len]='\0';
    
    return ans;
}



int main()
{
    scanf("%s %s %d",a.tmp,b.tmp,&n);
    node x,y;
    x = init(a);
    y = init(b);
    x.tmp[0]='\0';
    y.tmp[0]='\0';
    strcat(x.tmp,x.inte);strcat(x.tmp,".");strcat(x.tmp,x.flo);
    strcat(y.tmp,y.inte);strcat(y.tmp,".");strcat(y.tmp,y.flo);
    
    x.len = strlen(x.tmp);
    y.len = strlen(y.tmp);
    
    int po1 = find_po(x);
    int po2 = find_po(y);
    //小数部分 补零 
    if(x.len - po1 > y.len - po2){
    	int tmp = x.len - po1 - (y.len - po2);
    	for(int i=0;i<tmp;i++){
    		y.tmp[y.len] = '0';
    		y.len++;
		}
		y.tmp[y.len] = '\0';
	}else{
		int tmp = y.len - po2 - (x.len - po1);
    	for(int i=0;i<tmp;i++){
    		x.tmp[x.len] = '0';
    		x.len++;
		}
		x.tmp[x.len] = '\0';
	}
	strrev(x.tmp);
	strrev(y.tmp);
	//整数部分补零
	if(x.len > y.len){
		for(int i = y.len; i<x.len;i++){
			y.tmp[y.len] = '0';
    		y.len++;
		}
		y.tmp[y.len] = '\0';
	} else{
		for(int i = x.len; i<y.len;i++){
			x.tmp[x.len] = '0';
    		x.len++;
		}
		x.tmp[x.len] = '\0';
	}
	node ans = add(x,y);
	int pos;
	for(int i=0;i<ans.len;i++)    //去除小数部分里没有必要的0
        if(ans.tmp[i]!='0'){
            pos=i;
            break;
        }
    node realans;
    realans.len = 0;
    for(int i=ans.len-1;i>=pos;i--){//输出
    	realans.tmp[realans.len++] = ans.tmp[i];
	}
	realans.tmp[realans.len] = '\0';
	realans = init(realans);
	//printf("%s\n",realans.inte);
	
	if(strlen(realans.flo)>n){
		//printf("%c\n",)
		if(realans.flo[n]>='5' && realans.flo[n]<='9'){
			//printf("1111111\n");
			realans.tmp[strlen(realans.inte)+n+1] = '\0';
			realans.flo[n] = '\0';
			realans.len = strlen(realans.inte)+n+1;
			node jin; jin.len = 0;
			int l = strlen(realans.inte);
			for(int i=0;i<l;i++){
				jin.tmp[jin.len] = '0';
				jin.len++;
			}
			jin.tmp[jin.len++] = '.';
			for(int i = 0; i<n-1 ; i++){
				jin.tmp[jin.len] = '0';
				jin.len++;
			}
			jin.tmp[jin.len++] = '1';
			jin.tmp[jin.len] = '\0';
			strrev(realans.tmp);
			strrev(jin.tmp);
			node ans1 = add(realans, jin);
			
		    realans.len = 0;
			
		    for(int i=ans1.len-1;i>=0;i--){//输出
		    	realans.tmp[realans.len++] = ans1.tmp[i];
			}
			//realans.tmp[realans.len] = '\0';
		}else{
			
			realans.tmp[strlen(realans.inte)+n+1] = '\0';
		}
	}else if(strlen(realans.flo)<n){
		for(int i=strlen(realans.flo);i<n;i++){
			realans.tmp[realans.len++] = '0';
		}
		realans.tmp[realans.len] = '\0';	
	}
    printf("%s\n",realans.tmp);
    return 0;
}