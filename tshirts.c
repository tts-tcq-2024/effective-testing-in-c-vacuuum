#include <stdio.h>
#include <assert.h>

char size(int cms) 
{
    char sizeName = '\0';
    if(cms <= 38) 
    {
        sizeName = 'S';
    } 
    else if(cms > 38 && cms <= 42)
    {
        sizeName = 'M';
    }
    else if(cms > 42) 
    {
        sizeName = 'L';
    }
    else
    {
        /* do nothing */
    }
    return sizeName;
}

int main() {
    assert(size(37) == 'S');
    assert(size(38) == 'S'); // Test the boundary condition
    assert(size(39) == 'M');
    assert(size(42) == 'M'); // Test the boundary condition
    assert(size(43) == 'L');
    printf("All is well (maybe!)\n");
    return 0;
}
