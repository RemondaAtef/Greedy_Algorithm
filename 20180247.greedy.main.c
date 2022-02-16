#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;


    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted*/
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for

        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}


/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("\n\tarr[%d] : %d",i,A[i]);
       // printf("arr[%d] : ",A[i]);
        //printf("%d ", A[i]);
    printf("\n");
}


//compare 2 arrays
void CompareArrays(int arr[],int arr2[],int n)
{
    int i;
    int flag = 0;
    for(i = 0; i < n ; i++){
    if (arr[i] < arr2[i]){
      flag = 0;
      break;
    }
    else
     flag = 1;
  }

  if(flag == 0){
    printf("Not Possible to make everyone happy");
  }
  else
  {
    printf("Possible to make everyone happy");
  }      /*
       // printf("%d %d ",arr[i] = arr2[i] );
       printf("arr[%d]  = arr2[%d]\n",i,i);
       printf("possible\n");
    }

    else
        printf("not possible\n");
    }*/
}

int main()
{
    int n;
    printf("\nenter the number of slices and travellers : \n");
    scanf("%d",&n);
    //int a[n],b[n];
    int arr[n],arr2[n];


    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("\nEnter elements of slices sizes : \n");
	//readArray(a,n);
    int s =0;

    for(s =0; s < n; s++){
        printf("Enter arr[%d] : ",s);
        scanf("%d",&arr[s]);
    }

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array of slices sizes is \n");

    printArray(arr, arr_size);

    //print satisfactions factors array

   int arr2_size = sizeof(arr2)/sizeof(arr2[0]);
    printf("\nEnter elements of satisfactions factors : \n");
	//readArray2(b,n);
    int t =0;

    for(t =0; t < n; t++)
    {
        printf("Enter arr2[%d] : ",t);
        scanf("%d",&arr2[t]);
    }

    mergeSort(arr2, 0, arr2_size - 1);

    //mergeSortTwo(b, 0, b - 1);

    printf("\nSorted array of  is satisfactions factors : \n");
    printArray(arr2, arr2_size);

  //compare
  int n2 = sizeof(arr) / sizeof(arr[0]);

  CompareArrays(arr, arr2, n2);

    return 0;
}
