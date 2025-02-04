//Vitor Hugo Ferreira Sousa
//adicionando as bibliotecas necessárias
#include <stdio.h>
#include "pico/stdlib.h"

//definindo os pinos dos leds e do botão
#define BUTTON_A 5
#define LED_PIN_RED 13
#define LED_PIN_BLUE 12
#define LED_PIN_GREEN 11

static bool programa_iniciado = false;
static int estado_semaforo = 0;

//definindo a função de alarme
int64_t alarm_callback(alarm_id_t id, void *user_data) {
    printf("Mudança de Cor\n");
    //desligando todos os leds
    gpio_put(LED_PIN_RED, 0);
    gpio_put(LED_PIN_BLUE, 0);
    gpio_put(LED_PIN_GREEN, 0);

  
    switch (estado_semaforo) { 
        case 0:
        gpio_put(LED_PIN_RED, 1);
        gpio_put(LED_PIN_BLUE, 1);
        gpio_put(LED_PIN_GREEN, 1);
        break;
        case 1:
        gpio_put(LED_PIN_RED, 1);
        gpio_put(LED_PIN_BLUE, 1);
        break;
        case 2:
        gpio_put(LED_PIN_RED, 1);
        break;

    }

    estado_semaforo = (estado_semaforo + 1) % 3; 


if (estado_semaforo == 0) { 
        
        printf("Programa encerrado. Aguardando pressionar o botão...\n");
        programa_iniciado = false;
        return 0; 
    }
    add_alarm_in_ms(3000, alarm_callback, NULL, false); 
    return 0;
}

//função principal
int main(){
    //inicializando os pinos dos leds e o botão
    stdio_init_all();
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);
    gpio_init(LED_PIN_BLUE);
    gpio_set_dir(LED_PIN_BLUE, GPIO_OUT);
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);
   
     printf("Aguardando pressionar o botão...\n");  //mensagem de espera
    //loop infinito
    while (1) {
         if (!gpio_get(BUTTON_A) && !programa_iniciado) {
            sleep_ms(100);
            if(!gpio_get(BUTTON_A)){
                printf("Botão Pressionado, Ligando as LEDs!\n");
                programa_iniciado = true;
                estado_semaforo = 0;
                alarm_callback(0, NULL);
            }
    }
sleep_ms(10);
}
}

