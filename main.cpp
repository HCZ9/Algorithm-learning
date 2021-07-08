#include"BasicAlgorithm.h"

int main()
{
    int a[5]={2,4,1,5,3};
    Quick_Sort(a,0,4);
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d",a[i]);
    }

    system("pause");
    return 0;
    
}