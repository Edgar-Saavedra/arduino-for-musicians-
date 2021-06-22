#include "./4.5-button-debounce.h"

void buttonDebounce(int button_state, int pushButtonStatus) {
    pushButtonStatus = button_state;
    delay(20);
}