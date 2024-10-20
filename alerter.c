#include <stdio.h>
#include <assert.h>

// Function pointer for network alert
typedef int (*networkAlertFunc)(float celcius);

int alertFailureCount = 0;

// The stub function for testing
int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if (celcius > 200) {
        return 500;  // Fail
    }
    return 200;  // Success
}

int realNetworkAlert(float celcius) {
    printf("REAL ALERT: Temperature is %.1f celcius.\n", celcius);
    return 200;
}

void alertInCelcius(float farenheit, networkAlertFunc networkAlert) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlert(celcius);
    if (returnCode != 200) {
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(400.5, networkAlertStub);
    alertInCelcius(303.6, networkAlertStub);
    assert(alertFailureCount == 1);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
