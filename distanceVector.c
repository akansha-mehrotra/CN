#include<stdio.h>
struct node
{
    unsigned dist[20];
    unsigned from[20];
    int hop[10];
}rt[10];

int main()
{
    int costmat[20][20];
    int nodes,i,j,k,count=0;
    printf("\nEnter the number of routers : ");
    scanf("%d",&nodes);//Enter the nodes
    printf("\nEnter the cost matrix (1 if adjacent else 99 :\n");
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            scanf("%d",&costmat[i][j]);
            costmat[i][i]=0;
            if (costmat[i][j]>0)
            {
                rt[i].hop[j]=1;
            }
            else
                rt[i].hop[j]=0;
            rt[i].dist[j]=costmat[i][j];//initialise the distance equal to cost matrix
            rt[i].from[j]=j;
        }
    }
        do
        {
            count=0;
            for(i=0;i<nodes;i++)//We choose arbitary vertex k and we calculate the direct distance from the node i to k using the cost matrix
            //and add the distance from k to node j
            {
                for(j=0;j<nodes;j++)
                    for(k=0;k<nodes;k++)
                        if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
                            {//We calculate the minimum distance
                                rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                                rt[i].hop[j]=rt[i].hop[k]+rt[k].hop[j];
                                rt[i].from[j]=k;
                                count++;
                            }
            }
        }while(count!=0);
        for(i=0;i<nodes;i++)
        {
            printf("\n\n For router %d\n",i+1);
            for(j=0;j<nodes;j++)
            {
                printf("\t\nNode %d via %d Distance %d ",j+1,rt[i].from[j]+1,rt[i].dist[j]);
                printf("\nHop Count: %d\n",rt[i].hop[j]);
            }
        }
    printf("\n\n");
    getch();
}

//Input matrix:
/* 0 1 1 99 99
   1 0 99 99 99
   1 99 0 1 1
   99 99 1 0 99
   99 99 1 99 0*/
