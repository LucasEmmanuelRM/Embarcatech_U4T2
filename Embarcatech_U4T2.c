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
            "C - LEDs verde e azul\nY - LEDs verde e vermelho\nP - LEDs azul e vermelho\n"
            "W - Todos os LEDs\nO - Desligar LEDs\nZ - Acionar buzzer\nX - Reboot\n");

    while (true) {
        // Aguarda comando via UART
            char comando = getchar();
            printf("O comando é: %c",comando);
            switch (comando) {
                case 'G':
                    ligar_LED(LED_G);
                    printf("LED verde ligado!\n");
                    break;
                case 'B':
                    ligar_LED(LED_B);
                    printf("LED azul ligado!\n");
                    break;
                case 'R':
                    ligar_LED(LED_R);
                    printf("LED vermelho ligado!\n");
                    break;
                case 'C':
                    desligar_LEDs();
                    gpio_put(LED_G, 1);
                    gpio_put(LED_B, 1);
                    printf("LEDs verde e azul ligados!\n");
                    break;
                case 'Y':
                    desligar_LEDs();
                    gpio_put(LED_G, 1);
                    gpio_put(LED_R, 1);
                    printf("LEDs verde e vermelho ligados!\n");
                    break;
                case 'M':
                    desligar_LEDs();
                    gpio_put(LED_R, 1);
                    gpio_put(LED_B, 1);
                    printf("LEDs azul e vermelho ligados\n");
                    break;
                case 'W':
                    gpio_put(LED_G, 1);
                    gpio_put(LED_B, 1);
                    gpio_put(LED_R, 1);
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
    return 0;
}

void inicializar_UART(){
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
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
    desligar_LEDs();
    gpio_put(LED_gpio, 1);
}

void desligar_LEDs() {
    gpio_put(LED_G, 0);
    gpio_put(LED_B, 0);
    gpio_put(LED_R, 0);
}

void acionar_buzzer() {
    gpio_put(BUZZER, 1);
    sleep_ms(2000);
    gpio_put(BUZZER, 0);
}

void reboot() {
    printf("Reiniciando o microcontrolador...\n");
    watchdog_reboot(0, 0, 0);
}
