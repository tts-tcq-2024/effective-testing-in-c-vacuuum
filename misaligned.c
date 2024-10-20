#include <stdio.h>
#include <assert.h>

// Function to return a formatted string for testing purposes
const char* getColorMapEntry(int majorIndex, int minorIndex) {
    const char* majorColor[5] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[5] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    
    static char colorPair[50];
    sprintf(colorPair, "%d | %s | %s", majorIndex * 5 + minorIndex, majorColor[majorIndex], minorColor[minorIndex]);
    return colorPair;
}

int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%s\n", getColorMapEntry(i, j));
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    assert(strcmp(getColorMapEntry(0, 0), "0 | White | Blue") == 0);
    assert(strcmp(getColorMapEntry(1, 1), "6 | Red | Orange") == 0);
    assert(strcmp(getColorMapEntry(2, 2), "12 | Black | Green") == 0);
    assert(strcmp(getColorMapEntry(3, 3), "18 | Yellow | Brown") == 0);
    assert(strcmp(getColorMapEntry(4, 4), "24 | Violet | Slate") == 0);
    assert(strcmp(getColorMapEntry(1, 2), "7 | Red | Green") == 0);
    printf("All is well (maybe!)\n");
    return 0;
}
