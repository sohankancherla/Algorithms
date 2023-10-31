#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Function Prototypes
void str_print_array(char* array[], int size);
int linear_search(char* movie, char* movies[], int size);
int binary_search(char* name, char* names[], int size);
void int_print_array(int array[], int size);
void selection_sort(int numbers[], int size);
void bubble_sort(int numbers[], int size);

int main()
{
    //Linear Search Test Case
    printf("\n\n-------Linear Search-------\n");
    char* movies[] =  {"Cars", "Ratatouille", "Toy Story", "Monsters Inc.", "The Incredibles", "Wall-E", "Finding Nemo", "Up", "Inside Out", "Coco"};
    int size = sizeof(movies) / sizeof(movies[0]);

    //Linear Search for Wall-E
    printf("Looking for Wall-E:\n");
    str_print_array(movies, size);
    int wall_e_index = linear_search("Wall-E", movies, size);
    printf("Wall-E Index: %i\n\n", wall_e_index);
    //Linear Search for Monsters Inc.
    printf("Looking for Monsters Inc.:\n");
    str_print_array(movies, size);
    int monsters_inc_index = linear_search("Monsters Inc.", movies, size);
    printf("Monsters Inc. Index: %i\n\n", monsters_inc_index);
    //Linear Search for Monsters Inc.
    printf("Looking for Cars 2:\n");
    str_print_array(movies, size);
    int cars_2_index = linear_search("Cars 2", movies, size);
    printf("Cars 2 Index: %i\n\n", cars_2_index);

    //Binary Search Test Case
    printf("\n-------Binary Search-------\n");
    char* names[] = {"Adam", "Brian", "Chloe", "Eva", "Hannah", "Joe", "Olivia", "Matt", "Robert", "Steven", "Will"};
    int size2 = sizeof(names) / sizeof(names[0]);

    //Binary Search for Chloe
    printf("Looking for Chloe:\n");
    str_print_array(names, size2);
    int chloe_index = binary_search("Chloe", names, size2);
    printf("Chloe Index: %i\n\n", chloe_index);
    //Binary Search for Will
    printf("Looking for Will:\n");
    str_print_array(names, size2);
    int will_index = binary_search("Will", names, size2);
    printf("Will Index: %i\n\n", will_index);
    //Binary Search for Bob
    printf("Looking for Bob:\n");
    str_print_array(names, size2);
    int bob_index = binary_search("Bob", names, size2);
    printf("Bob Index: %i\n\n", bob_index);

    //Sorting Test Case
    int numbers[] = {7, 2, 5, 4, 1, 6, 0, 3};
    int size3 = sizeof(numbers) / sizeof(numbers[0]);

    //Selection Sort
    printf("\n-------Selection Sort-------\n");
    selection_sort(numbers, size3);

    //Reset Test Case
    int numbers2[] = {7, 2, 5, 4, 1, 6, 0, 3};

    //Bubble Sort
    printf("\n-------Bubble Sort-------\n");
    bubble_sort(numbers2, size3);
}

//Function to print an int array
void str_print_array(char* array[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        if (i > 0){
            printf(", ");
        }
        printf("%s", array[i]);
    }
    printf("]\n");
}

//Linear Search Implementation
int linear_search(char* movie, char* movies[], int size)
{
    //Loop through array
    for (int i = 0; i < size; i++)
    {
        printf("Step %i:\n", i + 1);
        printf("Compare %s with %s\n", movie, movies[i]);
        //Compare element with the movie we are searching for
        if (strcmp(movie, movies[i]) == 0)
        {
            printf("Match Found!\n");
            return i;
        }
    }
    printf("Match not Found.\n");
    return -1;
}

//Binary Search Implementation
int binary_search(char* name, char* names[], int size)
{
    int left = 0;
    int right = size;
    int i = 1;

    //Loop till there is no middle
    while (right > left)
    {
        printf("Step %i:\n", i);
        //Get the middle element
        int middle = (left + right) / 2;
        printf("Middle Element is %s\n", names[middle]);

        //Compare element with the movie we are searching for 
        printf("Compare %s with %s\n", name, names[middle]);
        if (strcmp(name, names[middle]) == 0)
        {
            printf("Match Found!\n");
            return middle;
        }
        //Search left half of array if name < middle
        else if (strcmp(name, names[middle]) <= 0)
        {
            printf("%s < %s Search left half\n", name, names[middle]);
            //Check if we are reating the same subarray
            if (right == middle)
            {
                break;
            }
            right = middle;
        }
        //Search right half of array if name > middle
        else
        {
            printf("%s > %s Search right half\n", name, names[middle]);
            //Check if we are repeating the same subarray
            if (left == middle)
            {
                break;
            }
            left = middle;
        }
        i++; 
    }
    printf("Match not Found.\n");
    return -1;
}

//Function to print an int array
void int_print_array(int array[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        if (i > 0){
            printf(",");
        }
        printf("%i", array[i]);
    }
    printf("]\n");
}

void selection_sort(int numbers[], int size)
{
    // Loop through size-1
    for (int i = 0; i < size - 1; i++)
    {
        int_print_array(numbers, size);
        printf("Step %i:\n", i + 1);
        int min_value = numbers[i];
        int index = i;

        //Find the smallest number between numbers[i] and numbers[size-1]
        for (int j = i + 1; j < size; j++)
        {
            if (numbers[j] < min_value)
            {
                min_value = numbers[j];
                index = j;
            }
        }
        //Swamp smallest number with numbers[i]
        printf("Swap %i with %i\n", numbers[i], numbers[index]);
        int temp = numbers[i];
        numbers[i] = min_value;
        numbers[index] = temp;
    }
    printf("Array is Sorted!\n");
    int_print_array(numbers, size);
}

void bubble_sort(int numbers[], int size)
{
    int iteration = 1;
    //Loop until none of the adjacent elements are swapped
    while (true)
    {
        bool swapped = false;
        int_print_array(numbers, size);
        printf("Step %i:\n", iteration);

        //Loop through list
        for (int i = 0; i < size - 1; i++)
        {
            //Swap adjacent elements that are unordered
            if (numbers[i] > numbers[i + 1])
            {
                printf("Swap %i with %i\n", numbers[i], numbers[i + 1]);
                int temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;
                swapped = true;
            }
        }

        //Break if none of the elements got swapped
        if (swapped == false)
        {
            break;
        }

        iteration++;
    }
    printf("Array is Sorted!\n");
    int_print_array(numbers, size);
}