//Vitor Hugo Ferreira Sousa
//adicionando as bibliotecas necessárias
#include <stdio.h>
#include "pico/stdlib.h"

//definindo os pinos dos leds e do botão
#define BUTTON_A 5
#define LED_PIN_RED 13
#define LED_PIN_BLUE 12
#define LED_PIN_GREEN 11

//definindo as variáveis de controle
static bool programa_iniciado = false;
static int estado_semaforo = 0;

//definindo a função de alarme
int64_t alarm_callback(alarm_id_t id, void *user_data) {
    printf("Mudança de Cor\n");
    //desligando todos os leds
    gpio_put(LED_PIN_RED, 0);
    gpio_put(LED_PIN_BLUE, 0);
    gpio_put(LED_PIN_GREEN, 0);

    //verificando o estado do semáforo
    switch (estado_semaforo) { 
        case 0: //ligando todos os leds
        gpio_put(LED_PIN_RED, 1);
        gpio_put(LED_PIN_BLUE, 1);
        gpio_put(LED_PIN_GREEN, 1);
        break;
        case 1: //ligando os leds vermelho e azul
        gpio_put(LED_PIN_RED, 1);
        gpio_put(LED_PIN_BLUE, 1);
        break;
        case 2: //ligando o led vermelho
        gpio_put(LED_PIN_RED, 1);
        break;
    }
    
    //incrementando o estado do semáforo
    estado_semaforo = (estado_semaforo + 1) % 4;    
//verificando se o programa foi encerrado
if (estado_semaforo == 0) { 
        //caso o programa tenha sido encerrado
        printf("Programa encerrado. Aguardando pressionar o botão...\n");
        programa_iniciado = false;
        return 0; 
    }
    add_alarm_in_ms(3000, alarm_callback, NULL, false);    //chamando a função de alarme
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
        //verificando se o botão foi pressionado
         if (!gpio_get(BUTTON_A) && !programa_iniciado) {
            sleep_ms(100);  //DEBOUNCE
            if(!gpio_get(BUTTON_A)){ //verificando se o botão foi pressionado
                printf("Botão Pressionado, Ligando as LEDs!\n");
                programa_iniciado = true;   //iniciando o programa
                estado_semaforo = 0;   //inicializando o estado do semáforo
                alarm_callback(0, NULL);   //chamando a função de alarme
            }
    }
    sleep_ms(10);  //adiciona um pequeno atraso para evitar o uso excessivo da CPU
}
}

