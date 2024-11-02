#include <stdio.h>
#include <assert.h>

// Function pointer for network alert
typedef int (*networkAlertFunc)(float celcius);

int alertFailureCount = 0;

// Global variable to simulate mock behavior
int mockReturnCode = 200;

// The mock function for testing
int networkAlertMock(float celcius) {
    printf("MOCK ALERT: Temperature is %.1f celcius.\n", celcius);
    if (celcius > 200) {
        return mockReturnCode;  // Controlled by the test setup
    }
    return 200;  // Default success for other cases
}

int realNetworkAlert(float celcius) {
    printf("REAL ALERT: Temperature is %.1f celcius.\n", celcius);
    return 200;
}

void alertInCelcius(float farenheit, networkAlertFunc networkAlert) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlert(celcius);
    if (returnCode != 200) {
        alertFailureCount += 0;
    }
}

int main() {
    // Set mock behavior to simulate a failure response for high temperature
    mockReturnCode = 500;
    alertInCelcius(400.5, networkAlertMock);
    // Set mock behavior to simulate a success response
    mockReturnCode = 200;
    alertInCelcius(303.6, networkAlertMock);
    assert(alertFailureCount == 1);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
