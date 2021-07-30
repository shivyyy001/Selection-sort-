
/**
 * Program to analyze run time complexity of Selection sort.
 * Compilation : gcc Selection_sort_time_analysis.c
 * Execution : ./a.out 
 *
 * @Shivansh Kaushal ( 1910990128 )  , 26/7/2021
 * Coding_Assignment - Sorting. 
 *
 */


#include<stdio.h>
#include <sys/time.h>  // Library which includes time function.
#include <stdlib.h>    // Standard Library.

// function to sort array using selection sort.
void sort_selection(int array[] , int size)
{
    int i = 0;
    int j = 0;

    for(i = 0 ; i< size-1 ; i++)
    {
	// initializing the minindex to i.
        int min_index = i;

        for(j = i + 1 ; j < size ; j++)
        {
	    // comparing minindex with every other index to store index of minimum element.
            if(array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        
	// Swap the found minimum element with ith element.
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}


// function to print details of time taken by code for different number of elements.
void print_details(int initial_size , int increase_by)  
{   
    // timeval structure that includes time in seconds and microseconds.
    struct timeval clck;  
  
    // initializing current size with initial size.
    int current_size = initial_size; 
  
    // iterating till current size is lesser than or equals to 36000.
    while(current_size <= 36000)
    {
      // creating an array of current_size.
      int array[current_size];
      
      // filling the array using rand() function.
      for(int iterator = 0 ; iterator < current_size ; iterator++)
      {
          // rand() to produce any random element.
          // %current_size to decrease limit to 0 to current_size-1.
          // +1 to make the limit 1 to current_size.
          array[iterator] = (rand() % current_size) + 1; 
      }
      
      // The gettimeofday() function gets the system’s clock time.
      gettimeofday(&clck , NULL);
      
      // converting the current time to milliseconds using seconds and microseconds.
      long long current = (clck.tv_sec * 1000LL) + (clck.tv_usec / 1000);
      
      // calling this function to sort the array using selection sort.
      sort_selection(array , current_size);  
      
      // The gettimeofday() function gets the system’s clock time.
      gettimeofday(&clck , NULL);
      
      // converting the end time to milliseconds using seconds and microseconds.
      long long final = (clck.tv_sec * 1000LL) + (clck.tv_usec / 1000);
      
      // printing the time taken in milliseconds.
      printf("For %d Elements Time Taken = %lld milliseconds \n" , current_size ,final - current);
      
      // incrementing the current size by increase_by number of elements.
      current_size += increase_by;  
                        
    }    
}

// Main function.
int main()
{
    // initial size of the array.
    int initial_size = 8000;   
    
    // size to be incremented by in each iteration. 
    int increase_by = 4000;

    // function to print details of every iteration.
    print_details(initial_size , increase_by); 
    
    return 1;
}
