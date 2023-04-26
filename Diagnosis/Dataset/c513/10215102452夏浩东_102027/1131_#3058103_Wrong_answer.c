#include <stdio.h>
#define Max 50
int Z[Max],X[Max],flag,pos1,pos2,end;
void func1(int A,int B){
    int temp1 = A/B, temp2=A-B*temp1,temp3;
    int index1=Max-1,index2=Max-1;
    int behind = 0;
    while(B!=1){
        B=B/3;
        behind++;
    }
    while(temp1!=0){
        temp3 = temp1%3;
        temp1 = temp1/3;
        Z[index1--] = temp3;
    }
    while(temp2!=0){
        temp3 = temp2%3;
        temp2 = temp2/3;
        X[index2--]= temp3;
    }
    for(int i=Max-1-behind;i<=index2;i++)
        X[i] = 0;
    pos1=index1+1;
	pos2=Max-behind;
	return;
}
void func2(){
    int jw=0,temp;
    for(int i=Max-1;i>=pos2;i--){
    	temp = jw+X[i]+1;
		X[i] = temp%3;
		jw = temp/3;  
	}
	for(int i=Max-1;i>=pos1;i--){
		temp = jw+Z[i]+1;
		Z[i] = temp%3;
		jw = temp/3;
	}
	if(jw!=0) Z[--pos1]=jw+1;
	return;
}
void func3(int flag){
	if(flag==1) {
	    for(int i=pos1;i<Max;i++){
	    	if(Z[i]-1==-1) Z[i]=2;
			else Z[i] = Z[i]-1; 
		}
		for(int i=pos2;i<Max;i++){
			if(X[i]-1==-1) X[i]=2;
			else X[i] = X[i]-1;
		}
	} else {
		for(int i=pos1;i<Max;i++){
	    	if(Z[i]-1==-1) Z[i]=1;
			else if(Z[i]-1==1) Z[i]=2;
			else Z[i]=0; 
		}
		for(int i=pos2;i<Max;i++){
			if(X[i]-1==-1) X[i]=1;
			else if(X[i]-1==1) X[i]=2;
			else X[i]=0; 
		}
	}
	for(int i=pos1;Z[i]==0 && i<Max;i++) pos1=i+1;
	for(int i=Max-1;X[i]==0 && i>=0;i--) end=i-1;
	return; 
}
void Output(){
	printf("%d\n",end);
	if(pos1==Max){
		printf("0");
	} else {
		for(int i=pos1;i<Max;i++)
			printf("%d",Z[i]);
	}
	if(pos2<=end){
		printf(".");
		for(int i=pos2;i<=end;i++)
			printf("%d",X[i]);
	}
	return;
}
int main()
{
    for(int i=0;i<Max;i++)
        Z[i]=X[i]=-1;
    flag = 1; 
	end=Max-1;
    int A,B;
    scanf("%d %d",&A,&B);
    if((A<0 && B>0)||(A>0 && B<0))
    {
    	flag = -1;
    	if(A<0) A=-A;
    	else B=-B;
	}
    func1(A,B);
    func2();
    func3(flag);
    Output();
    return 0; 
}