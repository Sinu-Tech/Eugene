#  Eugene - Sistema de identificação e segurança de estudantes

<br>
<h2 id="#Introdução">1. Introdução</h2>

Monitorar escolas pode se tornar uma tarefa complexa quando trata-se de uma possível fuga das aulas por parte dos alunos. Isso pode acontecer por vários fatores e ocasionam diversos problemas no ensino escolar do Brasil. Um dos problemas que podem ser ocasionados é a super lotação na sala de aula ou de muitas matrículas cadastradas, mas só uma pequena parte da turma aparece na sala de aula, retirando o direito de quem realemente merecia estar estudando. 

Outro fator determinante para o monitoramento é o acompanhamento de presença por meio do check feito em sala de aula, pois é normal que o aluno por padrão precise pelo menos ter quantidade de presença maior ou igual a 70% de presença na sala de aula. Com isso, muitas vezes a falta ocorre com o aluno estando dentro da escola, mas fora da sala de aula e nenhuma entidade associada a escola tem conhecimento sobre esse fator.

Uma alternativa para diminuir ou até mesmo cessar esse problema, seria contratar pessoas auxiliares para vigiar pátios, corredores, banheiros e mesmo assim ainda pode existir uma margem de erro a depender do tamanho da infraestrutura da escola.

Portanto, a melhor solução seria aplicada por meio de tecnologias conhecidas como Beacons que estariam fixos em pontos importantes da escola e distribuidos de maneira que o seu sinal fosse captado em cada lugar da escola. Essa proposta será desenvolvida melhor nas próximas seções com maiores detalhes.



<br><br>
<h2 id="#ObjetivoGeral"> Objetivo Geral</h2>

Nosso projeto foi iniciado a partir do incentivo do professor André, durante a matéria optativa da Universidade Federal de Sergipe, Tópicos Especiais de Hardware. O projeto Eugene trata-se de uma tecnologia precisa que atua em tempo real para  **monitorar e identificar alunos**.  O uso da tecnologia traz o detalhamento sobre a posição dos alunos e com isso, seria possível identificar problemas recorrentes com os alunos.

<br><br>
<h2 id="#ObjetivoEspecifico"> Objetivo Especifico</h2>


Com o Eugene o objetivo principal é:
- Impedir a fuga de escolas.
- Identificar o motivo da baixa presença nas aulas.
- Garantir a segurança dos alunos.


<br><br>
<h2 id="#Trabalhos relacionados">2. Trabalhos Relacionados</h2>

Até o momento, não existe uma solução se quer parecida com projeto Eugene. Pois não existem projetos referentes a posição do aluno dentro de uma escola.  


<br><br>
<h2 id="#SolucaoProposta">3. Solucao Proposta</h2>


<br><br>
<h3 id="#Arquitetura">3.1 Arquitetura da solução</h3>
A solução é composta por cinco módulos, são eles: O Beacon, o dispositivo que será conectado ao Beacon, o ponto de acesso, a aplicação desktop o dispositivo onde será armazenada a aplicação para realizar o monitoramento. O Beacon realiza a leitura dos dispositivos e logo em seguida, já associa o id de cada dispositivo a um nome de aluno. Dessa forma, ele envia dados contendo a localidade de cada aluno para a aplicação por meio da rede local, onde estará armazenado o desktop para monitoramento.
<br><br>

![Arquiteture](https://user-images.githubusercontent.com/68467958/204153992-d3c1ef9e-ccdd-483f-8a57-3fed736cd832.png)



O projeto foi desenvolvido em distribuição Windows 10 PRO. O código no microcontrolador foi escrito na linguagem C/C++ por meio do Arduino IDE, sendo que as blibliotecas utilizadas realizam a comunicação do ESP32 através de Wi-Fi e a leitura e conexão com dispositivos BLE. 



<br><br>
<h2 id="#MateriaisMetodos">3.2 Materiais e Metodos</h2>
<h3 id="#Módulo de hardware">3.2.1 O Módulo de hardware</h3>
Conforme visto nas seções anteriores, o hardware adotado para fazer a leitura de dispositivos BLE foi o ESP32, com isso, está evidenciado na imagem abaixo as bibliotecas utilizadas, como: "BLEDevice.h","BLEUtils.h", "BLEScan.h", "BLEAdvertisedDevice.h", "BluetoothSerial.h" e "Wifi.h".
<br><br>

![Bibliotecas](https://user-images.githubusercontent.com/68467958/204156469-40502146-18f3-4b43-bb5b-ac0b0e367592.png)

<br><br>


<br><br>
A biblioteca "Wifi.h" é responsável por conectar o ESP32 à rede Wi-Fi. Ela utiliza duas variáveis necessárias para conexão, o ssid (nome da rede) e o password da rede (senha da rede).
<br><br>

<br><br>

![ConexãoWifi](https://user-images.githubusercontent.com/68467958/204155181-d6ccb203-887a-40fa-a185-2d5e5bb27d0a.png)

<br><br>

Abaixo é definido uma lista com todos os dispositivos BLEs que devem ser reconhecido e monitorados.
<br><br>

![listadress](https://user-images.githubusercontent.com/68467958/204156345-729a05ce-6abc-42bd-a1c9-0a7d564dc90b.png)

<br><br>


<br><br>
Já ná imagem abaixo, é possível escanear endereços bluetooths.
<br><br>

<br><br>
![Scanning](https://user-images.githubusercontent.com/68467958/204155711-6afd7f19-3bbe-4952-84e1-1736807edff0.png)
<br><br>

Por último, após validar se algum dos endereços que estava na lista foi reconhecido, então o led ficará aceso.
<br><br>
![Ifscanning](https://user-images.githubusercontent.com/68467958/204155971-5f9f59cc-a838-445a-be3a-ff7f2b76fe3f.png)
<br><br>

<br><br>
<h2 id="#Testes">3.3. Testes</h2>
<br><br>
![teste1](https://user-images.githubusercontent.com/68467958/204180063-782a336d-f3f6-41d1-87ab-f4cb6aa00af7.png)


<br><br>
<h2 id="#Conclusao">4. Conclusões e trabalhos futuros</h2>
<br><br>

Com base na problemática sobre os alunos negligenciarem aula, o presente trabalho se propôs a desenvolver uma solução para ambientes escolares. De acordo com as seções anteriores, o aluno será monitorado de forma que sua localização seja mostrada, a fim de evitar furos de aula e aplicar as medidas cabíveis pela escola.
<br>
Para atingir o objetivo de monitoramento, foi utilizado alguns smarts watchs para validar os endereços bluetooths presentes na lista. Com isso, foi possível ver que os endereços estavam de fato sendo encontrados e com isso para questão de debug, os RSSIs eram printados na tela.
<br>
Para simular testes, foi colocado na lista apenas um endereço bluetooth de um smart watch e ao realizar a verificação, foi encontrado diversos endereços, mas só printado um que estava evidenciado na lista definida.
<br>
As perspectivas de trabalhos futuros incluem criar uma interface gráfica para melhor visualizar os dispositivos BLEs encontrados e construir um "ambiente" com base na planta de uma escola. Com isso, seria possível simular colocando pelo menos dois Esps32 em cantos diferentes para verificar melhor a distância e validar a precisão das coordenadas enviadas pelos Esps.
<br><br>

<br><br>
<h2 id="#Referencias">Referências</h2>
<br><br>

Tutorial - Enviando um JSON com ESP32. 2020.https://pettec.unifei.edu.br/wp-content/uploads/2021/01/Tutorial-Enviando-um-JSON-com-ESP32.pdf. Online; Acessado em 26 de Novembro de 2022.

BLE based Proximity Control using ESP32 – Detect Presence of BLE Devices.2020. https://circuitdigest.com/microcontroller-projects/ble-based-proximity-control-using-esp32. Online; Acessado em 02 de Novembro de 2022.

Beacon Technology – Como eles funcionam e como podem ser usados.2020.https://www.mokosmart.com/pt/beacon-technology/. Online; Acessado em 07 de Setembro de 2022.

ESP32 WIFI: COMUNICAÇÃO COM A INTERNET.2019.https://www.usinainfo.com.br/blog/esp32-wifi-comunicacao-com-a-internet/. Online; Acessado em 17 de Novembro de 2022.

Como configurar um servidor de testes local.2022.https://developer.mozilla.org/pt-BR/docs/Learn/Common_questions/set_up_a_local_testing_server. Online; Acessado em 26 de Novembro de 2022.

Localização Usando Beacons em Ambientes Internos para Monitoramento Remoto de Pacientes.2022.https://docplayer.com.br/108508909-Localizacao-usando-beacons-em-ambientes-internos-para-monitoramento-remoto-de-pacientes.html. Online; Acessado em 07 de Setembro de 2022.


<br><br>
<table border="1" >
    <tr>
        <th>Material</th>
        <th>Figura</th>
        <th>Sobre</th>
    </tr>
    <tr>
        <td>ESP32</td>
        <td><img src="https://www.filipeflop.com/wp-content/uploads/2017/11/6WL55_1.jpg" alt="drawing" width="1000"/></td>
        <td>ESP32 é uma série de microcontroladores de baixo custo e baixo consumo de energia. Também é um sistema-em-um-chip com microcontrolador integrado, Wi-Fi e Bluetooth.</td>
    </tr>
    <tr>
        <td>Arduino</td>
        <td><img src="https://cdn.discordapp.com/attachments/1036750972598374460/1045878181552476180/unknown.png" alt="drawing"/></td>
        <td>A placa Arduino MEGA 2560 é uma ótima opção para expandir seus projetos, quando há a necessidade de mais pinos ou quantidade de memória FLASH. Possui desempenho parecido com a placa Arduino UNO, porém possibilitando maior quantidades de recursos, como mais entradas analógicas e saídas PWM.</td>
    </tr>
    <tr>
        <td>Led</td>
        <td><img src="https://cdn.discordapp.com/attachments/1036750972598374460/1045878510243303434/unknown.png" alt="drawing"/></td>
        <td>Led difuso é um led onde o encapsulamento plástico é fosco, assim vc consegue visualizar ele facilmente na liz do dia. geralmente é utilizado apenas para vc saber que algo está ligado e tal. Os outros tipos são "cristalinos", onde a luz é direcionada pra frente.</td>
    </tr>
    <tr>
        <td>Resistencia</td>
        <td><img src="https://cdn.discordapp.com/attachments/1036750972598374460/1045878818440740904/unknown.png" alt="drawing"/></td>
        <td>A resistência elétrica é definida como a capacidade que um corpo tem de opor-se à passagem da corrente elétrica. A unidade de medida da resistência no SI é o Ohm (Ω), em homenagem ao físico alemão George Simon Ohm, e representa a razão volt/Ampére. Quando um condutor é submetido a uma diferença de potencial, ele passa a ser percorrido por uma corrente elétrica, que é constituída pelo movimento de elétrons livres no interior do condutor. Quando esses elétrons livres entram em movimento, começam a colidir entre si e com os átomos do condutor. Quanto maior o número de colisões, maior a dificuldade encontrada pela corrente elétrica em “atravessar” o condutor. Essa dificuldade de movimento das cargas é que caracteriza a resistência elétrica. A resistência elétrica varia conforme o comprimento, a largura e a natureza do material do condutor, além da temperatura a que ele é submetido.</td>
    </tr>
    <tr>
        <td>Protoboard</td>
        <td><img src="https://cdn.discordapp.com/attachments/1036750972598374460/1045879184087593030/unknown.png" alt="drawing" /></td>
        <td>Protoboard ou matriz de contato é uma placa com diversos furos e conexões condutoras verticais e horizontais para a montagem de circuitos elétricos experimentais. Seu uso tem a vantagem de dispensar a soldagem. As placas variam entre 830 e 6000 furos. Uma protoboard possui orifícios dispostos em colunas e linhas.
        </td>
    </tr>
        <tr>
        <td>Jumpers</td>
        <td><img src="https://cdn.discordapp.com/attachments/1036750972598374460/1045879647801462878/unknown.png" alt="drawing" />
        </td>
        <td>Os Jumpers são pequenos fios condutores que podem ser conectados a uma protoboard para interligar dois pontos do circuito em projetos eletrônicos, geralmente utilizados em conexões com Arduino, Raspberry Pi, entre outros.
        </td>
    </tr>
</table>

<br><br>
<h2 id="#Conclusoes"> Conclusões</h2>

<br><br>
<h2 id="#Colaboradores"> Colaboradores</h2>

<table border="1px">
  <tr>
    <td >
      <a href="https://github.com/joannestephany" target="_blank">
        <img src="https://avatars.githubusercontent.com/u/58868281?v=4"  width="100px;" alt="Foto de Joanne Stephany no GitHub"/><br>
        <sub>
          <b>JOANNE STEPHANY</b>
          <p>Desenvolvedora</p>
        </sub>
      </a>
    </td>
    <td >
      <a href="https://github.com/Kendy619" target="_blank">
        <img  src="https://avatars.githubusercontent.com/u/68467958?v=4" target="_blank"  width="100px;" alt="Foto de Kendy Ferreira no GitHub"/><br>
        <sub>
          <b >KENDY FERREIRA</b>
          <p>Desenvolvedor</p>
        </sub>
      </a>
    </td>
    <td >
      <a href="https://github.com/XxthiagoboyXx" target="_blank">
        <img src="https://avatars.githubusercontent.com/u/72053163?v=4" width="100px;" alt="Foto de Thiago Santos no GitHub"/><br>
        <sub>
          <b>THIAGO SANTOS</b>
          <p>Desenvolvedor</p>
        </sub>
      </a>
    </td>
  </tr>
</table>
