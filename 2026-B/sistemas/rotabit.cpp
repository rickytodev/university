#include <iostream>

int LEDS = 6;

void parpadear() {
    for (int i = 0; i < 3; i++) {
        // parpadean los leds al mismo tiempo
    }
}

void left_to_right() {
    for (int i = 0; i < LEDS; i++) {
        // enciende los leds de izquierda a derecha
    }
    // agregamos un tiempo de espera
    parpadear();
}

void right_to_left() {
    for (int i = LEDS - 1; i >= 0; i--) {
        // enciende los leds de derecha a izquierda
    }
    // agregamos un tiempo de espera
    parpadear();
}

int main() {
    while (true) {
        left_to_right();
        right_to_left();
    }
    return 0;
}
