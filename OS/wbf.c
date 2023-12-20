#include <stdio.h>
int main()
{
    int i, j, temp, b[10], c[10], d[10], arr, n, ch, a, small_diff, small_dif_index, lar_diff, lar_diff_index;
    printf("\t\t FIRST FIT, BEST FIT, WORST FIT\n");
    printf("Enter the size of no. of blocks:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter the size of %d block:", i);
        scanf("%d", &b[i]);
        d[i] = c[i] = b[i];
    }
    printf("\nEnter the size of Arriving block:");
    scanf("%d", &arr);
    printf("\n1.First fit\n2.Best fit\n3.Worst fit\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:

        for (i = 1; i <= n; i++)
        {
            if (b[i] >= arr)
            {
                printf("Arriving block is allocated to block %d.\n", i);
                break;
            }
        }
        if (i > n)
        {
            printf("the arriving block cannot be allocated.\n");
        }
    case 2:
        small_dif_index = 1;
        small_diff = b[1] - arr;
        for (i = 1; i <= n; i++)
        {
            if (b[i] >= arr)
            {
                if (small_diff > (b[i] - arr))
                {
                    small_diff = (b[i] - arr);
                    small_dif_index = i;
                }
            }
        }
        if (b[small_dif_index] > arr)
        {
            printf("the arriving block is allocated at %d, \n", small_dif_index);
            break;
        }
        else
        {
            printf("The arriving block is not executed :");
            break;
        }

    case 3:

        lar_diff_index = 1;
        lar_diff = b[1] - arr;
        for (int i = 1; i <= n; i++)
        {
            if (b[i] >= arr)
            {
                if (lar_diff < (b[i] - arr))
                {

                    lar_diff = b[i] - arr;
                    lar_diff_index = i;
                }
            }
        }
        if (b[lar_diff_index] >= arr)
        {
            printf("the arriving block is allocated at %d, \n", lar_diff_index);
        }
        else
        {
            printf("The arriving block is not executed :");
        }
    }

default:
    printf("Enter the valid choice:");
}
return 0;
}