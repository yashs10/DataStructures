#include<stdio.h>
int main()
{
    int n,i,pos;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the  position for deleted element");
    scanf("%d",&pos);                                   
    n--;
    for(i=pos-1;i<n;i++)
    {
        arr[i] = arr[i+1];
    }
      for(i=0;i<n;i++)
    {
        printf("%d \n",arr[i]);
    }
}

