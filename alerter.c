#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "printMessage.h"

int alertFailureCount = 0;

int networkAlertMock(float celcius) {
    printMessage(celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}



int main() {
    alertInCelcius(400.5,networkAlerter);
    alertInCelcius(303.6,networkAlerter);
    assert(alertFailureCount==1);
    assert(alertFailureCount==0);
    assert(alertInCelcius(350) == false);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
