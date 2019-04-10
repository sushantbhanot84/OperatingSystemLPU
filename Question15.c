#include<stdio.h>
#include<fcntl.h>
typedef struct 
{
    int pid;
    int arrival;
    int burst,tb;
    int prior;
    int flag,status;
}process;
process p1[100];
int sumw,sumTat;
int fl=0;
int c1=0;
int pehla=1;

int Tcount=0;
int prevIndex=0;
void traversal(process arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("pid is:%d",arr[i].pid);
    }
}
int max(process p[],int k)
{
    int index=0;
    int max=-9999;
    for(int i=0;i<k;i++)
    {
        if(p[i].arrival<=Tcount && p[i].prior>max && p[i].flag!=1 && p[i].status!=1)
        {
            index=i;
            max=p[i].prior;
            p[i].status=0;
        }
        //printf("\t%d\t",max);
    }
    for(int i=0;i<k;i++)
    {
        if(p[i].status!=1 && p[i].flag!=1 && i!=index)
        {
            if(i==index){p[i].status=0;continue;}
            p[i].status=-2;
        }
    }
    return index;
}

void FCFS(process p[],int k)
{
    int Tat=0,wait=0;
    for(int i=0;i<k;i++)
    {
        if(p[i].status==-2 && p[i].flag!=1 && p[i].arrival<=Tcount)
        {
            Tcount+=p[i].tb;
            p[i].tb=0;
            Tat=Tcount-p[i].arrival;
            wait=Tat-p[i].burst;
            sumw+=wait;
            sumTat+=Tat;
            p[i].flag=1;
            p[i].status=1;
            printf("\nprocess with pid[%d] COMPLETED\tWaitTime is[%d]\tTurnAroundTime is [%d]\n",p[i].pid,wait,Tat);
            fl++;
        }
    }
    for(int i=0;i<k;i++)
    {
        if(p[i].status!=1)
        {
        p[i].flag=0;
        p[i].status=0;
        }
    }
}

void push(process arr[],int a,int b,int c,int d,int pos)
{
    arr[pos].pid=a;
    arr[pos].arrival=b;
    arr[pos].burst=c;
    arr[pos].tb=c;
    arr[pos].prior=d;
}
void RR(process p[],int tQ,int Totaltq,int k)
{
    //Tcount=p[index].arrival;
    int i=0,index=0;
    //traversal(p1,k);
    //printf("%d K val",k);
    int TurnAround,wait;
    while(1){
        //printf("%d Val tcount\n",Tcount);
        if(i==k){i=0;}
        if(fl==k)break; //Aging Implementation
        //printf("%d\n",i);     
        index=max(p,k);
        if(pehla==1){    Tcount=p[index].arrival;pehla++;}
        if(index!=prevIndex){
            tQ=4;
        }
        
        //if(index>99){Tcount++;continue;}
        //printf("%d is index\n",index);
        prevIndex=index;
        if(Totaltq>0)//Aging Implementation
        {
            if(Totaltq<tQ){tQ=Totaltq;}
            // if(p[index].tb<=tQ)
            // {
                Tcount++;
                //printf("%dLol",Tcount);
                Totaltq--;
                p[index].tb--;
                tQ--;
                if(p[index].tb==0)
                {
                 TurnAround=Tcount-p[index].arrival;
                 wait=TurnAround-p[index].burst;
                 sumw+=wait;
                 sumTat+=TurnAround;
                 p[index].flag=1;
                 p[index].status=1;
                 fl++;
                 printf("\nprocess with pid[%d] COMPLETED\tWaitTime is[%d]\tTurnAroundTime is [%d]\n",p[index].pid,wait,TurnAround);
                 continue;
                }
            if(tQ==0)
            {
                p[index].flag=1;
            }
            //}
        }
        else{
            printf("Time Quantum expired");
            FCFS(p,c1);
            Totaltq=16;
        }

}
}
int main()
{
    int temp1=0,temp2=0,temp3=0,prior=0;
    int n,j,full=0;
    printf("Enter total number of processes");
    scanf("%d",&n);
    j=n;
    while(n!=0)
    {
        printf("Enter pid of process");
        scanf("%d",&temp1);
        printf("Enter arrival time:");
        scanf("%d",&temp2);
        printf("Enter burst time:");
        scanf("%d",&temp3);
        
        printf("Enter priority of process");
        scanf("%d",&prior);
        push(p1,temp1,temp2,temp3,prior,c1);c1++;
        n--;
    }
    //traversal(p1,c1);
    //int x=max(p1,c1);
    //printf("%d max value",x);
    RR(p1,4,16,c1);
    printf("\n\nAverage Waiting Time: %d \t Average Turn Around Time:%d\n\n",sumw/c1,sumTat/c1);
    return 0;
}