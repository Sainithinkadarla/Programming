#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int bt;
    int id;
    int wt;
} process;

int main()
{
    int i,wt,tt,n,j,temp,t;
    float awt,att;

    wt=tt=0;
    printf("Enter no. of processes: ");
    scanf("%d",&n);

    process p[n];
    for (i=0; i<n;i++)
    {
        p[i].id=i+1;
        p[i].wt=0;
        printf("enter process %d burst time: ",i+1);
        scanf("%d",&p[i].bt);
    }

    for(i=0; i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i].bt>p[j].bt)
            {
                temp = p[i].bt;
                p[i].bt= p[j].bt;
                p[j].bt = temp;
                temp = p[i].id;
                p[i].id = p[j].id;
                p[j].id = temp;
            }
        }
    }
    printf("\tProcess\tburst time\twaiting time\tturnaround time\n");
    for(i=0; i<n;i++)
    {
        t=p[i].bt + p[i].wt;
        printf("\t %d \t %d \t\t %d \t\t %d \n",p[i].id,p[i].bt,p[i].wt,t);
        p[i+1].wt = p[i].wt  + p[i].bt;
        wt+=p[i].wt;
        tt += p[i].wt + p[i].bt;
    }

    awt=wt/(float)n;
    att=tt/(float)n;

    printf("\n%f\n%f",awt,att);
}