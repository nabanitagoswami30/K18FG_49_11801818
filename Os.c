#include<stdio.h>
struct pp
{
    int pname;
    int atime, wtime, ttime, p, btimec,burT;
}q1[10],q2[10];
int main()
{
	struct pp tp;
    int i,time=0,t1,t2,b_t=0,greatest,totalp,count=0,k,pf2=0,totalp2,n,pos,j,f=0,y;
    float waitT=0,tTime= 0,avg_waitT,average_tTime;
    printf("\n Enter Total Number of Processes:\t");
    scanf("%d", &totalp);
    n=totalp;
    for(i=0;i<totalp;i++)
    {
	printf("\nEnter name of the Process:-");
        scanf("%d",&q1[i].pname);
        printf("\nEnter Characteristics For processor %d:\n",q1[i].pname);
        printf("Enter Arrival Time:-");
        scanf("%d",&q1[i].atime);
        printf("Enter Burst Time:-");
        scanf("%d",&q1[i].burT);
        q1[i].btimec=q1[i].burT;
        printf("Enter Priority:\t");
        scanf("%d",&q1[i].p);
    }
    printf("\nEnter Time Quantum for Fixed priority queue:-");
    scanf("%d",&t1);
    printf("\nEnter Time Quantum for Round Robin queue:-");
    scanf("%d",&t2);
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for(i=0;i<totalp;i++)
    {
        pos=i;
        for(j=i+1;j<totalp;j++)
        {
            if(q1[j].atime<q1[pos].atime)
                pos=j;
        }
        tp=q1[i];
        q1[i]=q1[pos];
        q1[pos]=tp;
    }
    time=q1[0].atime;
    for(i=0;totalp!=0;i++)
    {
	while(count!=t1)
	{
		count++;
		if(q1[i].atime<=time)
		{
			for(j=i+1;j<totalp;j++)
			{
				if(q1[j].atime==time && q1[j].p<q1[i].p)//pr<
				{
					q2[pf2]=q1[i];
						pf2++;
					for(k=i; k<totalp-1;k++)
						q1[k]=q1[k+1];
					totalp--;
						count=0;
					i=j-1;
					j--;
					}
				}
			}
			time++;
			q1[i].burT--;
			if(q1[i].burT==0)
			{
				q1[i].ttime=time-q1[i].atime;
				q1[i].wtime=q1[i].ttime-q1[i].btimec;
				printf("%d\t|\t%d\t|\t%d\n",q1[i].pname,q1[i].ttime,q1[i].wtime);
				waitT+=time-q1[i].wtime; 
			tTime+=time-q1[i].ttime;
			for(k=i;k<totalp-1;k++)
				q1[k]=q1[k+1];i--;
			totalp--;
				count=t1;break;
			}
		}
		count=0;
		if(q1[i].burT!=0)
		{
			q2[pf2]=q1[i];
			pf2++;
			for(k=i;k<totalp-1;k++)
			q1[k]=q1[k+1];
		totalp--;
		}
			if(i==totalp-1)
				i=-1;
	}
	
	totalp2=pf2;
	for(count=0;totalp2!=0;) 
	{ 
		if(q2[count].burT<=t2&&q2[count].burT>0) 
	{ 
		time+=q2[count].burT; 
		q2[count].burT=0; 
		f=1; 
	} 
	else if(q2[count].burT>0) 
	{ 
		q2[count].burT-=t2; 
		time+=t2; 
	} 
	if(q2[count].burT==0&&f==1) 
	{ 
		totalp2--; 
		q2[count].ttime=time-q2[count].atime;
			q2[count].wtime=q2[count].ttime-q2[count].btimec; 
			printf("%d\t|\t%d\t|\t%d\n",q2[count].pname,q2[count].ttime,q2[count].wtime); 
		tTime+=time-q2[count].atime; 
		waitT+=time-q2[count].atime-q2[count].btimec;
		for(k=count; k<totalp2;k++)
			q2[k]=q2[k+1];count--;
		f=0; 
	} 

	if(count==totalp2-1) 
		count=0; 
	else 
		count++; 
    }
    printf("\n Average Waiting Time= %f\n", waitT/n); 
    printf("Average Turnaround Time = %f" ,tTime/n);   
}

