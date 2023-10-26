#include <stdio.h>
#include <string.h>

//Function prototypes
int linear_search(char* movie, char* movies[], int size);

int main()
{
    //Linear Search Test Case
    printf("-------Linear Search-------\n");
    char* movies[] =  {"Cars", "Ratatouille", "Toy Story", "Monsters Inc.", "The Incredibles", "Wall-E", "Finding Nemo", "Up", "Inside Out", "Coco"};
    int size = sizeof(movies) / sizeof(movies[0]);

    //Linear Search for Wall-E
    int wall_e_index = linear_search("Wall-E", movies, size);
    printf("Wall-E Index: %i\n", wall_e_index);
    //Linear Search for Monsters Inc.
    int monsters_inc_index = linear_search("Monsters Inc.", movies, size);
    printf("Monsters Inc. Index: %i\n", monsters_inc_index);
    //Linear Search for Monsters Inc.
    int cars_2_index = linear_search("Cars 2", movies, size);
    printf("Cars 2 Index: %i\n", cars_2_index);
}

int linear_search(char* movie, char* movies[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(movie, movies[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}