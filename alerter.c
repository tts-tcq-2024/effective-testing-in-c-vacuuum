#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius)
{
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if (celcius > 200)
    {
        return 500;
    }
    return 200; // OK
}

void alertInCelcius(float farenheit)
{
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200)
    {
        alertFailureCount += 1; // Increment the failure count when the response is not OK
    }
}

int main()
{
    alertInCelcius(400.5);
    alertInCelcius(303.6); 
    assert(alertFailureCount == 1);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
