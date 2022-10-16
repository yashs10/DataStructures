#include <stdio.h>
int main()
{
    int n,i,sum1=0,sum2=0;
    scanf("%d",&n);
    int arr[n];
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        if (arr[i]%2==0)
        {
           sum1+=arr[i]; 
        }
        else
        {
            sum2+=arr[i];
        }
    }
    printf("%d %d",sum1,sum2);
    
    return 0;
}
bcxgdshsrttr
