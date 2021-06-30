/*2) To find Minimum Spanning tree using Prim's algorithm*/
#include<stdio.h>
void prims();
int vis[10],vt[10],et[10][10],e=0,u,v,n;
float cost[10][10],sum=0.0F;
void main()
{
 printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the cost of adjacency matrix\n");
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            scanf("%f", &cost[i][j]);
        }
    }
    prims();
    printf("Minimum Spanning Tree\n");
    for (int i=1; i<=e; i++)
    {
        printf("%d,%d-->", et[i][1], et[i][2]);
    }
    printf("\n Total Cost = %f\n", sum);
}
void prims()
{
	int x=1,k,j;
	float min;
	vt[x]=1;
	vis[x]=1;
	for(int i=1;i<n;i++)
	{
		j=x;
		min=999.0;
		while(j>0)
		{
			k=vt[j];
			for(int m=2;m<=n;m++)
			{
				if((cost[k][m]<min)&&(vis[m]==0))
				{
					min=cost[k][m];
					u=k;
					v=m;
				}
			}
			j--;
		}
		vt[++x]=v;
		et[i][1]=u;
		et[i][2]=v;
		e++;
		vis[v]=1;
		sum=sum+min;
	}
}