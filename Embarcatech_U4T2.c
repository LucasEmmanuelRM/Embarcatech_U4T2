#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

// Definição dos pinos GPIO
#define LED_G 11
#define LED_B 12
#define LED_R 13
#define BUZZER 21

// UART utilizado
#define UART_ID uart0
#define BAUD_RATE 115200
#define UART_TX_PIN 0
#define UART_RX_PIN 1

// Funções auxiliares
void inicializar_UART();
void inicializar_perifericos();
void ligar_LED(uint LED_gpio);
void ligar_todos_LEDs();
void desligar_LEDs();
void acionar_buzzer();
void reboot();

int main() {
    // Inicializa UART e periféricos
    stdio_init_all();
    inicializar_UART();
    inicializar_perifericos();

    printf("Controle de GPIO - BitDogLab\n");
    printf("Comandos:\nG - LED verde\nB - LED azul\nR - LED vermelho\n"
            "W - Todos os LEDs\nO - Desligar LEDs\nZ - Acionar buzzer\nX - Reboot\n");

    while (true) {
        // Aguarda comando via UART
        if (uart_is_readable(UART_ID)) {
            char comando = uart_getc(UART_ID);
            switch (comando) {
                case 'G':
                    ligar_LED(LED_G);
                    printf("LED verde ligado\n");
                    break;
                case 'B':
                    ligar_LED(LED_B);
                    printf("LED azul ligado\n");
                    break;
                case 'R':
                    ligar_LED(LED_R);
                    printf("LED vermelho ligado\n");
                    break;
                case 'W':
                    ligar_todos_LEDs();
                    printf("Todos os LEDs ligados\n");
                    break;
                case 'O':
                    desligar_LEDs();
                    printf("Todos os LEDs desligados\n");
                    break;
                case 'Z':
                    acionar_buzzer();
                    printf("Buzzer acionado\n");
                    break;
                case 'X':
                    reboot();
                    break;
                default:
                    printf("Comando invalido\n");
                    break;
            }
        }
    }
    return 0;
}


void inicializar_UART(){
    
}


void inicializar_perifericos() {
    // Inicializa LEDs
    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_put(LED_G, 0);

    gpio_init(LED_B);
    gpio_set_dir(LED_B, GPIO_OUT);
    gpio_put(LED_B, 0);

    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_put(LED_R, 0);

    // Inicializa buzzer
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
    gpio_put(BUZZER, 0);
}


void ligar_LED(uint LED_gpio) {
    
}


void ligar_todos_LEDs() {
    
}


void desligar_LEDs() {
    
}


void acionar_buzzer() {
    
}


void reboot() {
    
}
