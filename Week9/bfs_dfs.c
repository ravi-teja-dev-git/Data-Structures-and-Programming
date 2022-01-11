#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int adjMatrix[20][20],reach[20],n,q[20], visited[20], f = 0, r = -1;


//Breadth First Search
void bfs(int v) 
{
 for(int i = 1; i <= n; i++)
 if(adjMatrix[v][i] && !visited[i])
 q[++r] = i;
   if(f <= r) 
     {
     visited[q[f]] = 1;
     bfs(q[f++]);
     }
}




//Depth First Search
void dfs(int v)
{
 int i;
 reach[v]=1;
 
 for(i=1;i<=n;i++)
  if(adjMatrix[v][i] && !reach[i])
  {
   printf("\n %d",i);
   dfs(i);
  }
}



void main()
{
 int i,j,count=0,choice,v;
 printf("\n Enter your choice \n 1. DFS 2. BFS 3. Exit \n");
 scanf("%d",&choice);
 printf(" Enter number of vertices:");
 scanf("%d",&n);

 
 while(1)
 {
    if(choice == 1)
     {
          for(int i=1;i<=n;i++)
          {
          reach[i]=0;
          for(int j=1;j<=n;j++)
           adjMatrix[i][j]=0;
          }
         
         printf("\n Enter the adjacency matrix: ");
         for(i=1;i<=n;i++)
         {
             for(j=1;j<=n;j++)
             {
             scanf("%d",&adjMatrix[i][j]);
             }
        }
          
           
         printf("\n The nodes which are reachable are: \n");
         printf(" %d",1);
         dfs(1);
         printf("\n");
         for(int i=1;i<=n;i++)
         {
          if(reach[i])
           count++;
         }
        
           
     }
 
   else if(choice == 2)
     {
         for(int i=1; i <= n; i++) 
         {
             q[i] = 0;
             visited[i] = 0;
         }
         
         printf("\n Enter the adjacent matrix: \n");
         for(i=1; i<=n; i++) 
         {
             for(j=1;j<=n;j++) 
             {
             scanf("%d", &adjMatrix[i][j]);
             }
         }
         
         
         bfs(1);
         printf("\n The node which are reachable are:\n");
         
         for(i=1; i <= n; i++) 
         {
             if(visited[i])
             printf("\n %d", i);
             else 
                 {
                 printf("\n Bfs is not possible and all nodes are not reachable");
                 break;
                 }
         }
     }
     
    else
     {
         exit(1);
     } 
     
    printf("\n Enter your choice");
    scanf("%d",&choice);
 
     
  }//End of while
 
 
 
 }
