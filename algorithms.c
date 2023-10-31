#include <stdio.h>
#include <string.h>

//Function Prototypes
int linear_search(char* movie, char* movies[], int size);
int binary_search(char* name, char* names[], int size);

int main()
{
    //Linear Search Test Case
    printf("\n\n-------Linear Search-------\n");
    char* movies[] =  {"Cars", "Ratatouille", "Toy Story", "Monsters Inc.", "The Incredibles", "Wall-E", "Finding Nemo", "Up", "Inside Out", "Coco"};
    int size = sizeof(movies) / sizeof(movies[0]);

    //Linear Search for Wall-E
    printf("Looking for Wall-E:\n");
    int wall_e_index = linear_search("Wall-E", movies, size);
    printf("Wall-E Index: %i\n\n", wall_e_index);
    //Linear Search for Monsters Inc.
    printf("Looking for Monsters Inc.:\n");
    int monsters_inc_index = linear_search("Monsters Inc.", movies, size);
    printf("Monsters Inc. Index: %i\n\n", monsters_inc_index);
    //Linear Search for Monsters Inc.
    printf("Looking for Cars 2:\n");
    int cars_2_index = linear_search("Cars 2", movies, size);
    printf("Cars 2 Index: %i\n\n", cars_2_index);

    //Binary Search Test Case
    printf("\n-------Binary Search-------\n");
    char* names[] = {"Adam", "Brian", "Chloe", "Eva", "Hannah", "Joe", "Olivia", "Matt", "Robert", "Steven", "Will"};
    int size2 = sizeof(names) / sizeof(names[0]);

    //Binary Search for Chloe
    printf("Looking for Chloe:\n");
    int chloe_index = binary_search("Chloe", names, size2);
    printf("Chloe Index: %i\n\n", chloe_index);
    //Binary Search for Will
    printf("Looking for Will:\n");
    int will_index = binary_search("Will", names, size2);
    printf("Will Index: %i\n\n", will_index);
    //Binary Search for Bob
    printf("Looking for Bob:\n");
    int bob_index = binary_search("Bob", names, size2);
    printf("Bob Index: %i\n\n", bob_index);

}

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

int binary_search(char* name, char* names[], int size)
{
    int left = 0;
    int right = size;
    int i = 1;

    while (right > left)
    {
        printf("Step %i:\n", i);

        int middle = (left + right) / 2;
        printf("Middle Element is %s\n", names[middle]);

        printf("Compare %s with %s\n", name, names[middle]);
        if (strcmp(name, names[middle]) == 0)
        {
            printf("Match Found!\n");
            return middle;
        }
        else if (strcmp(name, names[middle]) <= 0)
        {
            printf("%s < %s Search left half\n", name, names[middle]);
            if (right == middle)
            {
                break;
            }
            right = middle;
        }
        else
        {
            printf("%s > %s Search right half\n", name, names[middle]);
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

