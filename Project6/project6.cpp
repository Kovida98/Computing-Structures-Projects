//Computing Structures
//Fall 2022
//Project 6
//Author: Aditya Narasimhan

#include<iostream>
#include<cstdlib> // used for random number generation
#include<math.h> // used for math functions 
#include<unordered_set> // used for generating unique elements

using namespace std;

// bubble sort algorithm with D number of comparisons allowed
int* bubbleSort(int* arr, int numElements, int D)
{
    int numComp = 0; // used to count the number of comparisons and to check with D

    int* arrCopy = new int[numElements]; // making a copy of arr as this is an inplace sorting algorithm
    // we want to retain the ordering of arr for shell sort 
    for (int i = 0; i < numElements; i++)
        arrCopy[i] = arr[i];

    // bubble sort starts
    for (int i = 0; i < numElements; i++)
    {
        for (int j = 0; j < numElements - 1; j++)
        {
            numComp++; // incrementing the number of comparisons done right before 
            // the if condition where the comparison happens each time
            if (numComp >= D) // checking for number of comparisons
                return arrCopy; // return the not necessarily sorted array = approximately sorted array

            if (arrCopy[j] > arrCopy[j + 1])
            {
                // swap
                int temp = arrCopy[j];
                arrCopy[j] = arrCopy[j + 1];
                arrCopy[j + 1] = temp;
            }
        }
    }
    // return the completely sorted array
    return arrCopy;
}

// shell sort algorithm with D number of comparisons allowed
int* shellSort(int* arr, int numElements, int D)
{
    int j;
    int numComp = 0;

    // need not make a copy of the arr array since shell sort is performed later/last

    // Start with a largest increment, then reduce by factors of 3 
    for (int inc = numElements / 3; inc > 1; inc /= 3)
    {
        // Insertion sort for the increment length
        for (int i = inc; i < numElements; ++i)
        {
            int temp = arr[i];
            j = i - inc;

            while ((j >= 0) && (arr[j] > temp))
            {
                numComp++; // incrementing the number of comparisons done right before 
                // the if condition where the comparison happens each time
                if (numComp >= D) // checking for number of comparisons
                    return arr; // return the not necessarily sorted array = approximately sorted array
                arr[j + inc] = arr[j];
                j = j - inc;
            }
            arr[j + inc] = temp;
        }
    }
    // Insertion sort for the increment length = 1; force length 1 in case of inc/3 == 0
    for (int i = 1; i < numElements; ++i)
    {
        int temp = arr[i];
        j = i - 1;


        while ((j >= 0) && (arr[j] > temp))
        {
            numComp++; // incrementing the number of comparisons done right before 
            // the if condition where the comparison happens each time
            if (numComp >= D) // checking for number of comparisons
                return arr; // return the not necessarily sorted array = approximately sorted array
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
    return arr;
}
// This method takes array and number of elements as parameters and is for calculating number of inversions 
int inversions(int* A, int n) {
    // initialising to zero
    int inv_count = 0;
    /*Using two for loops, comparing the elements in array A. if the A[i] > A[j] then increment the variable*/
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (A[i] > A[j]) {
                inv_count++;
            }
        }
    }
    return inv_count;
}

// This method takes two arrays and number os elements as parameters and is used to find chebyshave distance
int chebyshave(int* comp_arr,int* arr,int n){
    // declaring an array of size n
    int* distances = new int[n];
    int x = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // By using teo for loops, if this condition satisfies
            if (comp_arr[i] == arr[j]) {
                // Fetching the difference between the indexes of that number from two different arrays
                int diff = i - j;
                // And pushing that value into the array distances
                distances[x] = diff;
                x++;
            }
        }
    }
    // By using for loop, changing the negative values into positive values
    for(int i=0;i<n;i++){
        if (distances[i] < 0) {
            distances[i] = -1 * distances[i];
        }
        //cout << distances[i] << ",";
    }
    // Finding the maximum value from the array distances
    int max = distances[0];
    for (int j = 1; j < n; j++) {
        if (distances[j] > max) {
            max = distances[j];
        }
    }
    return max;
}


//main function
int main()
{
    int n;
    cin >> n; // read the number of elements
    cout << "Number of elements: " << n << endl;

    int s, l, u, D;
    

    cin >> s >> l >> u >> D; // read the seed, lower range, upper range and the number of comparisons
    cout << "Number of comparisons allowed: " << D << endl;
    cout << endl;

    // generate n random elements with the seed s, within the lower and upper range 
    // store the randomly generated UNIQUE set of elements in an array 'A'

    // you may use the unordered set to help generate unique elements
    srand(s);
    int numberrange = u - l + 1;
    std::unordered_set<int> random_numbers;
    while (random_numbers.size() < n) {
        random_numbers.insert(rand() % numberrange + l);
    }
    int* A = new int[n];
    int i = 0;
    for (auto itr = random_numbers.begin(); itr != random_numbers.end(); ++itr) {
        A[i] = *itr;
        i++;
        //cout << *itr << endl;
    }
    cout << "Randomly generated elements: ~~~~~~~~~~" << endl;
    for (int j = 0; j < n; j++) {
        cout << A[j] << " ";
    }
    cout << endl;
    // display the array A

    // use one of the sorting algorithms with the third argument for D as n*n (for bubble sort) and store the fully sorted result 
    int* comp_sorted = new int[n];
    comp_sorted = bubbleSort(A, n, n * n);
    cout << "Completely sorted elements: ~~~~~~~~~~" << endl;
    // display the completely sorted array 
    for (int j = 0; j < n; j++) {
        cout << comp_sorted[j] << " ";
        
    }
    cout << endl;

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // sort the array A with only given D comparions using the Bubble Sort algorithm and store the output array as bubResult in an array
    // calculate and display the two quality measures for bubResult
    int* bubResult = new int[n];
    bubResult = bubbleSort(A, n, D);
    cout << "Bubble Sort Result: ~~~~~~~~~~" << endl;
    for (int j = 0; j < n; j++) {
        cout << bubResult[j] << " ";
    }
    cout << endl;

    int bubinv = inversions(bubResult, n);
    cout << "Number of inversions in bubResult : " << bubinv << endl;
    int bub_maxdist=chebyshave(comp_sorted, bubResult, n);
    cout << "Chebyshev distance in bubResult: " << bub_maxdist << endl;

    // display bubResult

    // find both the quality metrics for bubResult

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // sort the array A with only given D comparions using the Shell Sort algorithm and store the output array as shellResult in an array
    // calculate and display the two quality measures for shellResult
    int* shellResult = new int[n];
    shellResult = shellSort(A, n, D);
    cout << "Shell Sort Result: ~~~~~~~~~~" << endl;
    for (int j = 0; j < n; j++) {
        cout << shellResult[j] << " ";
    }
    cout << endl;

    int shellinv = inversions(shellResult, n);
    cout << "Number of inversions in shellResult: " << shellinv << endl;
    int shell_maxdist = chebyshave(comp_sorted, shellResult, n);
    cout << "Chebyshev distance in shellResult: " << shell_maxdist << endl;
    // display shellResult

    // find both the quality metrics for shellResult

    return 0;
}
