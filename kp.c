//written by sowell....
// mail me at @iamsohail.srk@gmail.com

#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>


long n;

long bubble_sort(long a[], long n)
{
    long  long i, j, temp;
    long b[n];

     for (i = 0; i < n; ++i)
     {
          b[i]=a[i];
     }

     for (i = 0; i < n; ++i)
     {
          for (j = 0; j < n - 1 - i; ++j)
          {
               if (b[j] > b[j+1])
               {
                    temp = b[j+1];
                    b[j+1] = b[j];
                    b[j] = temp;
               }
          }
     }
     /*for(i=0;i<n;i++)
	  printf("%d\t",b[i]);
     printf("\n");*/
}


long insertion_sort(long a[], long n)
{
    long i, j, index;

     long b[n];

     for (i = 0; i < n; ++i)
     {
          b[i]=a[i];
     }


     for (i = 0; i < n; ++i)
     {
          index = b[i];
          for (j = i; j > 0 && b[j-1] > index; j--)
               b[j] = b[j-1];
          b[j] = index;
     }
     /*for(i=0;i<n;i++)
	  printf("%d\t",b[i]);
     printf("\n");*/
}

long selection_sort(long a[],long n)
{
     long i;

   long b[n];

     for (i = 0; i < n; ++i)
     {
          b[i]=a[i];
     }


     for (i = 0; i < n; ++i)
     {
         long j, min, temp;
          min = i;
          for (j = (i + 1); j < n; ++j)
          {
               if (b[j] < b[min])
                    min = j;
          }

          temp = b[i];
          b[i] = b[min];
          b[min] = temp;
     }
     /*for(i=0;i<n;i++)
	  printf("%d\t",b[i]);
     printf("\n");*/
}

long heap_sort(long a[], long n)
{
    long i,j,c,root;

   long b[n];

     for (i = 0; i < n; ++i)
     {
          b[i]=a[i];
     }

    for (i = 0; i < n; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;             
            if (b[root] < b[c])   /* to create MAX b array */
            {
	  long temp;
                temp = b[root];
                b[root] = b[c];
                b[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
    for (j = n - 1; j >= 0; j--)
    {
	long temp;
        temp = b[0];
        b[0] = b[j];   /* swap max element with rightmost leaf element */
        b[j] = temp;
        root = 0;
        do 
        {
            c = 2 * root + 1;    /* left node of root element */
            if ((b[c] < b[c + 1]) && c < j-1)
                c++;
            if (b[root] < b[c] && c<j)    /* again rearrange to max b array */
            {
                temp = b[root];
                b[root] = b[c];
                b[c] = temp;
            }
            root = c;
        } while (c < j);
    }
    /*for(i=0;i<n;i++)
	printf("%d\t",b[i]);
    printf("\n");*/
}

long radix_sort(long a[],long n)
{

    long k,i,j,t,min,b[n],c[n];

     for (i = 0; i < n; ++i)
     {
          b[i]=a[i];
	  c[i]=a[i];
     }

    for (k = 0; k < 3; k++)
    {    
        for (i = 0; i < n; i++)
        {
            min = b[i] % 10;        /* To find minimum lsd */
            t = i;
            for (j = i + 1; j < n; j++)    
            {
                if (min > (b[j] % 10))
                {
                    min = b[j] % 10; 
                    t = j;
                }
            }
           long temp = c[t];
            c[t] = c[i];
            c[i] = temp;
            temp = b[t];
            b[t] = b[i];
            b[i] = temp;
        }
        for (j = 0; j < n; j++)        /*to find MSB */
        b[j] = b[j] / 10;
    }
    /*for(i=0;i<n;i++)
	printf("%d\t",c[i]);
    printf("\n");*/
}


long merge(long b[],long n,long low, long mid,long high)
{
   long i, m, k, l, temp[n];
    l=low;
    i=low;
    m=mid+1;
    while((l<=mid) && (m<=high))
    {
         if(b[l]<=b[m])
         {
             temp[i]=b[l];
             l++;
         }
         else
         {
             temp[i]=b[m];
             m++;
         }
         i++;
    }
    if(l>mid)
    {
         for(k=m; k<=high; k++)
         {
             temp[i]=b[k];
             i++;
         }
    }
    else
    {
         for(k=l; k<=mid; k++)
         {
             temp[i]=b[k];
             i++;
         }
    }
    for(k=low; k<=high; k++)
    {
         b[k]=temp[k];
    }
    /*for(k=0;k<n;k++)
	printf("%d\t",b[k]);
    printf("\n");*/
}

long merge_sort(long a[],long n, long l,long u)
{
	long i,m,b[n];
	for (i = 0; i < n; ++i)
	{
		b[i]=a[i];
	}
	if(l<u)
	{
		m=(l+u)/2;
		merge_sort(b, n, l, m);
		merge_sort(b, n, m+1, u);
		merge(b, n, l, m, u);
	}
}

//bucket
long bucket(long array[],long n)
{  
long  long i, j;  
 long b[n]; 
 for(i=0; i < n; i++)
 {  
  b[i] = 0;  
 }    
 for(i=0; i < n; i++)
 {   
  (b[b[i]])++;
 }    
 for(i=0,j=0; i < n; i++)
 {  
  for(; b[i]>0;(b[i])--)
  {      
   array[j++] = i;
  } 
 }  
} 




long quicksort(long a[], long k, long n)
{
	long pivot, i, j, temp;
	if(k < n)
	{
		pivot = k;
		i = k;
		j = n;
		while(i < j)
		{
			while(a[i] <= a[pivot] &&  i <= n)
			i++;
			while(a[j] > a[pivot] && j >= k)
			j--;
			if(i < j)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		temp = a[j];
		a[j] = a[pivot];
		a[pivot] = temp;
		quicksort(a, k, j-1);
		quicksort(a, j+1, n);
	}
}





long counting_sort(long a[], long k, long n)
{
   long  long i, j;
    long b[15], c[100];
    for(i = 0; i <= k; i++)
            c[i] = 0;
    for(j =1; j <= n-1; j++)
            c[a[j]] = c[a[j]] + 1;
    for(i = 1; i <= k; i++)
            c[i] = c[i] + c[i-1];
    for(j = n; j >= 1; j--)
    {
            b[c[a[j]]] = a[j];
            c[a[j]] = c[a[j]] - 1;
    }
    /*printf("\nThe Sorted array is :\n");
    for(i = 1; i <= n; i++)
          printf("\t%d",b[i]);*/
}
void main()
{
	long i;
	struct timeval t1;
	struct timeval t2;
	struct timeval t3;
	struct timeval t4;
	struct timeval t5;
	struct timeval t6;
	struct timeval t7;
        struct timeval t8;
	struct timeval t9;
	struct timeval t10;





	long time_diff,time_diff1;

	int n=10000;
	long a[n];
	for(i=0;i<n;i++)
	  scanf("%ld",&a[i]);

	gettimeofday(&t1,NULL);
	bubble_sort(a,n);
	gettimeofday(&t2,NULL);

	insertion_sort(a,n);
	gettimeofday(&t3,NULL);

	selection_sort(a,n);
	gettimeofday(&t4,NULL);

	heap_sort(a,n);
	gettimeofday(&t5,NULL);

	radix_sort(a,n);
	gettimeofday(&t6,NULL);

	merge_sort(a, n, 0, n - 1);
	gettimeofday(&t7,NULL);
         
         bucket(a,n);
         gettimeofday(&t8,NULL);

	//counting_sort(a, 0, n-1);
	gettimeofday(&t9,NULL);

	quicksort(a,0,n-1);
	gettimeofday(&t10,NULL);


	time_diff = (t2.tv_sec - t1.tv_sec);
	time_diff1 = (t2.tv_usec - t1.tv_usec);
	printf("Bubble Sort \t Time : %ld second %ld microsecond\n",time_diff,time_diff1);


	//Insertion Sort
	time_diff = (t3.tv_sec - t2.tv_sec);
	time_diff1 = (t3.tv_usec - t2.tv_usec);
	printf("Insertion Sort \t Time : %ld second %ld microsecond\n",time_diff,time_diff1);

	//Selection Sort
	time_diff = (t4.tv_sec - t3.tv_sec);
	time_diff1 = (t4.tv_usec - t3.tv_usec);
	printf("Selection Sort \t Time : %ld second %ld microsecond\n",time_diff,time_diff1);

	//Heap Sort
	time_diff = (t5.tv_sec - t4.tv_sec);
	time_diff1 = (t5.tv_usec - t4.tv_usec);
	printf("Heap Sort \t Time : %ld second %ld microsecond\n",time_diff,time_diff1);

	//Radix Sort
	time_diff = (t6.tv_sec - t5.tv_sec);
	time_diff1 = (t6.tv_usec - t5.tv_usec);
	printf("Radix Sort \t Time : %ld second %ld microsecond\n",time_diff,time_diff1);

	//Merge Sort
	time_diff = (t7.tv_sec - t6.tv_sec);
	time_diff1 = (t7.tv_usec - t6.tv_usec);
	printf("Merge Sort \t Time : %ld second %ld microsecond\n",time_diff,time_diff1);

        //Bucket Sort
	time_diff = (t8.tv_sec - t7.tv_sec);
	time_diff1 = (t8.tv_usec - t7.tv_usec);
	printf("Bucket Sort \t Time : %ld second %ld microsecond\n",time_diff,time_diff1);
		

	//counting sort
	time_diff = (t9.tv_sec - t8.tv_sec);
	time_diff1 = (t9.tv_usec - t8.tv_usec);
	printf("counting Sort \t Time : %ld second %ld microsecond\n",time_diff,time_diff1);
	

	//quicksort Sort
	time_diff = (t10.tv_sec - t9.tv_sec);
	time_diff1 = (t10.tv_usec - t9.tv_usec);
	printf("quick Sort \t Time : %ld second %ld microsecond\n",time_diff,time_diff1);
	


}
