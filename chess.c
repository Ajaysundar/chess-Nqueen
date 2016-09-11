#include<stdio.h>
#include<math.h>
int a[30],count=0;
int place(int pos)
{
int i;
for(i=1;i<pos;i++)
{
if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos))))
return 0;         //queens placed in same diagonal or row
}
return 1;
}
void print(int n)
{
int i,j;
count++;
printf("\n\n number of solutions %d:\n",count);
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(a[i]==j)
printf("Q\t");
else
printf("*\t");
}
printf("\n");
}
}
void queen(int n)
{
int k=1;             //Number of queens,row number
a[k]=0;             //column number 
while(k!=0)
{
a[k]=a[k]+1;
while((a[k]<=n)&&!place(k)) 
a[k]++;
if(a[k]<=n)
{
if(k==n)
print(n);
else
{
k++;              //increment queen
a[k]=0;
}
}
else
k--;//backtracking
}
}
void main()
{
int n=8;          //Number of queens 
queen(n);
printf("\n total solution =%d",count);
}
