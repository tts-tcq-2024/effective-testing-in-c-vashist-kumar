#include <stdio.h>
#include <assert.h>
#include <string.h>

int alertFailureCount = 0;

void printMsg(float temperature) {
    printf("ALERT: Temperature is %.1f celcius.\n", temperature);
}

void (*printMessage)(float message) = printMsg;

int networkAlertStub(float celcius) {
    printMessage(celcius);
    return 200;
}

bool alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
        return true;
    }
    return false;
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    assert(alertFailureCount==1);
    assert(alertInCelcius(350) == false);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
