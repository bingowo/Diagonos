/*1019.发愁*/

#include<stdio.h>
#include<stdlib.h>

void bubblesort(int arr[],int tar[],int n,int wins[],int lose[]);
void showin4cols(int tar[],int n);

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);//n为球队数，m为场数
	int a,b,c,index;
	int scores[n] = {0},players[n],wins[n] = {0},lose[n] = {0};
	
	for(index = 0;index < n;index ++)
	players[index] = index + 1;
	
	for(index = 0;index < m;index++)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(c == 1)
		{
			scores[a-1] += 3;
			wins[a-1] ++;
			scores[b-1] += -1;
			lose[b-1]++;
		}
		
		else if(c == -1)
		{
			scores[b-1] += 3;
			wins[b-1]++;
			scores[a-1] += -1;
			lose[a-1]++;
		}
		
		else
		{
			scores[a-1]++;
			scores[b-1]++;
		}
	 } 
	 
	bubblesort(scores,players,n,wins,lose);
	showin4cols(players,n);
	return 0;
}

void bubblesort(int arr[],int tar[],int n,int wins[],int lose[])
{
	int i , j , hold , flag;
	for(i = 0;i < n-1;i++)
	{
		flag = 0;
		for(j = 0;j < n-1-i;j++)
		
		if(arr[j] < arr[j+1])//高的往前排 
		{
			hold = tar[j];
			tar[j] = tar[j+1];
			tar[j+1] = hold;
			flag = 1;
		}
		if(arr[j] == arr[j+1])
		{
			if(wins[j] < wins[j+1])
			{
				hold = tar[j];
				tar[j] = tar[j+1];
				tar[j+1] = hold;
			}
			if(wins[j] == wins[j+1])
			{
				if(lose[j] > lose[j+1])
				{
					hold = tar[j];
					tar[j] = tar[j+1];
					tar[j+1] = hold;
				}
				
			}
			flag = 1;
		}//flag最后再赋值 
		if (flag == 0)
		break;
		
	}
	
}

void showin4cols(int tar[],int n)
{
	int i;
	for(i = 0;i < n;i++)
	{
		if(i%4 != 3 && i != n-1)
		printf("%d ",tar[i]);
		else if(i%4 == 3 && i != n-1)
		printf("%d \n",tar[i]);
		else
		printf("%d",tar[i]);
	}
}