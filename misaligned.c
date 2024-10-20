#include <stdio.h>
#include <assert.h>
#include <string.h>

// Function to get a formatted string for a color map entry
const char* getColorMapEntry(int majorIndex, int minorIndex) {
    const char* majorColor[5] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[5] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    static char colorPair[50];
    sprintf(colorPair, "%2d | %-6s | %-6s", majorIndex * 5 + minorIndex, majorColor[majorIndex], minorColor[minorIndex]);
    return colorPair;
}

// Function to print the color map using the getColorMapEntry function
void printColorMap() {
    int majorIndex, minorIndex;
    for ( majorIndex = 0; majorIndex < 5; majorIndex++) {
        for (minorIndex = 0; minorIndex < 5; minorIndex++) {
            printf("%s\n", getColorMapEntry(majorIndex, minorIndex));
        }
    }
}

// Test function to check if the color map entries are correctly aligned and formatted
void testColorMap() {
    assert(strcmp(getColorMapEntry(0, 0), " 0 | White  | Blue  ") == 0);
    assert(strcmp(getColorMapEntry(1, 1), " 6 | Red    | Orange") == 0);
    assert(strcmp(getColorMapEntry(2, 2), "12 | Black  | Green ") == 0);
    assert(strcmp(getColorMapEntry(3, 3), "18 | Yellow | Brown ") == 0);
    assert(strcmp(getColorMapEntry(4, 4), "24 | Violet | Slate ") == 0);
    assert(strcmp(getColorMapEntry(1, 2), "7 | Red | Green") == 0);
}

int main() {
    testColorMap();
    printColorMap();
    printf("All is well (maybe!)\n");
    return 0;
}
