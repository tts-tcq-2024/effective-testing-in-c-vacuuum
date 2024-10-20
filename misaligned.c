#include <stdio.h>
#include <assert.h>

int printColorMap()
{
    const char* majorColor[5] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[5] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[j]);
        }
    }
    return i * j;
}

int main() 
{
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
