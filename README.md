Esse projeto implementa o controle de pinos GPIO através da porta serial UART. Utilizando a ferramenta BitDogLab, que possui como microcontrolador uma Raspberry Pi Pico W, o programa inicializa todos os pinos que serão utilizados, incluindo os necessários para cominucação via UART.

Estão inclusos nos pinos inicializados: GPIO_21, buzzer A da BitDogLab; GPIO_11, 12 13, relativos aos LEDs verde, azul e vermelho, respectivamente; GPIO_0 e 1, relativos aos pinos de TX e RX da UART_0, respectivamente.

Para utilizar este programa, basta realizar o download do repositório e abri-lo através de uma interface que possui um monitor serial.

O Baud Rate (taxa de transmissão) definido foi 115200, e o usuário deve se atentar na configuração de seu monitor serial para selecionar a porta onde sua placa está conectada e colocar sua taxa de envio com o mesmo valor do Baud Rate do programa.

O programa possui 3 funcionalidades principais: Controle de LEDs, acionamento de Buzzer e reboot.
Ao iniciar o programa, o usuário pode digitar os seguintes comandos:

G - Aciona o LED verde
B - Aciona o LED azul
R - Aciona o LED vermelho
C - Aciona os LEDs verde e azul simultaneamente, gerando a cor ciano
Y - Aciona os LEDs LEDs verde e vermelho simultaneamente, gerando a cor amarela
P - Aciona os LEDs azul e vermelho simultaneamente, gerando a cor magenta
W - Aciona todos os LEDs simultaneamente, gerando a cor branca
O - Desliga todos os LEDs
Z - Aciona o buzzer
X - Dá reboot no sistema

Uma demonstração do funcionamento do programa pode ser vista no vídeo disponível no link a seguir:
https://drive.google.com/file/d/1PfA_q2JgKqY5tDNJntALoOgheUWq9hYO/view?usp=sharing

As funcionalidades principais, exigidas pela atividade proposta, são demonstradas, constatando seu total funcionamento.
