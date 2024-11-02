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
int printColorMap(void (*fp)(const char*)) {
    int majorIndex, minorIndex;
    for (majorIndex = 0; majorIndex < 5; majorIndex++) {
        for (minorIndex = 0; minorIndex < 5; minorIndex++) {
            fp(getColorMapEntry(majorIndex, minorIndex));
        }
    }
    return majorIndex * minorIndex;
}

void testColorMap() {
    assert(strcmp(getColorMapEntry(0, 0), " 0 | White  | Blue  ") == 0);
    assert(strcmp(getColorMapEntry(1, 1), " 6 | Red    | Orange") == 0);
    assert(strcmp(getColorMapEntry(2, 2), "12 | Black  | Green ") == 0);
    assert(strcmp(getColorMapEntry(3, 3), "18 | Yellow | Brown ") == 0);
    assert(strcmp(getColorMapEntry(4, 4), "24 | Violet | Slate ") == 0);
    assert(strcmp(getColorMapEntry(1, 2), "7 | Red | Green") == 0);
}

// Mock environment to test
char actualManual[1024 * 10] = {0};  // Array to hold all generated strings

void mockPrintOnConsole(const char* manualItem) {
    strcat(actualManual, manualItem);  // Append the current string to the manual buffer
    strcat(actualManual, "\n");        // Add newline after each item for proper formatting
}

int main() {
    int result = printColorMap(&mockPrintOnConsole);
    assert(result == 25);
    testColorMap();
    const char *expectedConsoleBuffer =
    " 0 | White  | Blue  \n"
    " 1 | White  | Orange\n"
    " 2 | White  | Green \n"
    " 3 | White  | Brown \n"
    " 4 | White  | Slate \n"
    " 5 | Red    | Blue  \n"
    " 6 | Red    | Orange\n"
    " 7 | Red    | Green \n"
    " 8 | Red    | Brown \n"
    " 9 | Red    | Slate \n"
    "10 | Black  | Blue  \n"
    "11 | Black  | Orange\n"
    "12 | Black  | Green \n"
    "13 | Black  | Brown \n"
    "14 | Black  | Slate \n"
    "15 | Yellow | Blue  \n"
    "16 | Yellow | Orange\n"
    "17 | Yellow | Green \n"
    "18 | Yellow | Brown \n"
    "19 | Yellow | Slate \n"
    "20 | Violet | Blue  \n"
    "21 | Violet | Orange\n"
    "22 | Violet | Green \n"
    "23 | Violet | Brown \n"
    "24 | Violet | Slate \n";
    
    assert(strcmp(actualManual, expectedConsoleBuffer) == 0);
    printf("All is well (maybe!)\n");
    return 0;
}
