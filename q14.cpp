#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int n=3,i,brust[5]={2,4,8},priority[5],id[5]={2132, 2102, 2453 };
	char p[5]={'a','b','c'};
	int brust1[5];
	int w_time[5]={0,0,0,0,0},t_time[5]={0,0,0,0,0},time=0,j=0,max=0,k;
	int avg_w,avg_t;
	printf("\nTotal Number Of Students: %d",n);
	sleep(1.5);
	for(i=0;i<n;i++)
	{
		printf("\n\nId Of the Student %c      : %d",p[i],id[i]);
		printf("\nTime Taken By The Student: %d",brust[i]);
		sleep(1.5);
	}
	sleep(1);
	printf("\n\n | Student   |    Id      | Time Taken |");
	for(i=0;i<n;i++)
	{
		printf("\n |    %c\t     |   %d\t  |    %d       |",p[i],id[i],brust[i]);
		time = time + brust[i];
		t_time[i] = t_time[i] + brust[i];
		brust1[i] = brust[i];
	}
	
	printf("\n\n---------------------------------------------------------------------------");
	printf("\n\n\n<<<<<<<<<<<<<< Calculating Waiting Time For Each Student  >>>>>>>>>>>>>>>>>>>");
	sleep(5);
	printf("\n\nExecution Of Process On Each Minutes-->>");
	printf("\nGannt Chart: ");
	max = 2;
	for(i=0;i<time;i++)
	{
		for(j=0;j<n;j++)
		{
			if(brust[j]>brust[max])
			{
				max=j;
			}
			if(brust[max]==brust[j])
			{
				if(id[max]>id[j])
					max = j;
			}
		}
		
		brust[max]=brust[max]-1;
		for(k=0;k<n;k++)
		{
			if(max==k)
			{
				printf("");
			}
			else
			{
				if(brust[k]>0)
				{
					w_time[k] = w_time[k] + 1;
			     	t_time[k] = t_time[k] + 1;
				}
			}
		}
		printf("%c --> ",p[max]);
	}
	
	printf("\n\n  Student       Id       Time Taken       Waiting      Turnarround");
	for(i=0;i<n;i++)
	{
		printf("\n     %c\t       %d\t       %d       \t    %d         \t %d ",p[i],id[i],brust1[i],w_time[i],t_time[i]);
	
	}
	printf("\n----------------------------------------------------------------------------");
	for(i=0;i<n;i++)
	{
		avg_w+=w_time[i];
		avg_t+=t_time[i];
	}
	printf("\n\nAverage Waiting Time    : %d",avg_w/n);
	printf("\nAverage Turnarround Time: %d",avg_t/n);
	printf("\n\n----------------------------------------------------------------------------\n\n\n");
	
}
