# Atividade Clock e temporizadores - One Shot
### Atividade 2 - U4C5 - Embarca Tech 
Atividade relacionada ao capítulo 5 da unidade 4 do programa de Capacitação Cepedi - Embarca Tech
Esse programa tem como objetivo principal aplicar tecnicas de controle de clock e temporização em microcontroladores utilizando a placa BitDogLab, controlando leds em uma temporização a partir do acionamento de um botão que aciona um sequência de leds.

# Requisitos e Instruções de Execução
 Para a execução desse código serão necessários os seguintes equipamentos equipamentos:

#### Hardware
* Um Microcontrolador modelo __Raspbery Pi Pico W__
* Um __PushButton__
* Um led na cor __Vermelha__
* Um led na cor __Azul__
* Um led na cor __Verde__
* Três Resistores de __330 Ohms Ω__

#### Software
* Instale o __Visual Studio Code IDE__
* Instale e configure o __Pico SDK__
* Instale __GNU Toolchain__
* Certifique-se de ter o __Git__ Instalado
* Instale as seguintes extensões no Visual Studio Code: __C/C++, C/C++ COMPILE RUN, Pi Pico W, Cmake e Cmake Tools__

#### Para realização da simulação
* Clone o repositório
  ```bash
   git clone https://github.com/SEU_REPOSITORI.git](https://github.com/Vitorhugofsousa/EbTech-U4C5_02.git

* Faça a compilação do projeto
* Selecione o arquivo __diagram.json__
* Encontre e selecione o botão __"Run"__ no canto superior esquerdo
 Em seguida o código entrará no modo de simulação e poderá ver o programa funcionando.

 ###### Caso realize a execução do programa diretamente na placa de desenvolvimento BitDogLab, ao pressionar o botão A (botão esquerdo) ela exibirá o led principal primeiramente na cor branca (devido a mistura das três cores: Vermelho, Azul e verde) em seguida exibirá a cor roxa (correspondente a mistura das cores Vermelho e Azul) e em seguida exibirá somente a led vermelha. 
###### Cada uma dessas é cores é exibida por 3 segundos em sequencia até que o programa finalize não podendo ser interrompida ou reiniciada até que seja finalizada.

 # Contribuições
<img src="one_shot.png">
