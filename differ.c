#include <stdio.h>
#include <stdlib.h>
int main()
{

    int n,flag,k=0,i,n;
    printf("enter the value of n");
    scanf("%d",&n);
     printf("enter set A \n");
    int arr1[n],arr2[n],arr[n];
     for(i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("enter set B \n");
     for(i=0;i<n;i++)
    {
        scanf("%d",&arr2[i]);
    }
    for( i=0;i<n;i++)
{
flag =0;
for (int j=0;j<n;j++)
{
    if(arr1[i]==arr2[j])
    flag = 1;
}
if (flag == 0)
{
    arr[k]=arr1[i];
k++;
}
}
printf("set  A - B equals \n");
 for(i=0;i<k;i++)
    {
        printf("%d \n",arr[i]);
    }

}