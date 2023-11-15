#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i,j,n=5,time,sum_w=0,sum_tt=0,smallest;
	int at[10]={0,1,2,3,4},bt[10]={10,1,2,1,5}, pt[10]={3,1,4,5,2},rt[10], remain=n;
	for(i=0;i<n;i++)
	{
		rt[i]=bt[i];
	}
	pt[9]=11;
	for(time=0; remain!=0; time++)
	{
		smallest=9;
		for(i=0;i<n;i++)
		{
			if(at[i]<=time && pt[i]<pt[smallest] && rt[i]>0)
			{
				smallest=i;
			}
		}
		rt[smallest]--;
		if(rt[smallest]==0)
		{
			remain--;
			printf("P[%d]\t|\t%d\t|\t%d\n",smallest+1,time+1-at[smallest]-bt[smallest],time+1-at[smallest]);
			sum_w+=time+1-at[smallest]-bt[smallest];
			sum_tt+=time+1-at[smallest];
		}
	}	
	printf("%f\n",sum_w*1.0/n);
	printf("%f",sum_tt*1.0/n);
}

