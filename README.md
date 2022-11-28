#  Eugene - Sistema de identificação e segurança de estudantes

## Sumário

<img align="right" width="250" src="https://www.pop-se.rnp.br/wp-content/uploads/2018/12/ufs_principal_positiva.png" alt="Logo UFS">


-   [1. Introdução](#1-introdução)
    -   [1.1 Objetivo Geral](#-11-objetivo-geral)
    -   [1.2 Objetivo Especifico](#-12-objetivo-especifico)
-   [2. Trabalhos Relacionados](#2-trabalhos-relacionados)
-   [3. Solucao Proposta](#3-solucao-proposta)
    -   [3.1 Arquitetura da solução](#31-arquitetura-da-solução)
    -   [3.2 Materiais e Metodos](#32-materiais-e-metodos)
        -   [3.2.1 O Módulo de hardware](#321-o-módulo-de-hardware)
    -   [3.3. Testes](#33-testes)
-   [4. Conclusões e trabalhos futuros](#4-conclusões-e-trabalhos-futuros)
-   [5.Referências](#5-referências)
    -   [5.1. Equipamentos](#51-equipamentos)
-   [6. Colaboradores](#6-colaboradores)

<br>

# Introdução

<h2 id="#Introducao">1. Introdução</h2>

Monitorar escolas pode se tornar uma tarefa complexa quando trata-se de uma possível fuga das aulas por parte dos alunos. Isso pode acontecer por vários fatores e ocasionam diversos problemas no ensino escolar do Brasil. Um dos problemas que podem ser ocasionados é a super lotação na sala de aula ou de muitas matrículas cadastradas, mas só uma pequena parte da turma aparece na sala de aula, retirando o direito de quem realemente merecia estar estudando. 

Outro fator determinante para o monitoramento é o acompanhamento de presença por meio do check feito em sala de aula, pois é normal que o aluno por padrão precise pelo menos ter quantidade de presença maior ou igual a 70% de presença na sala de aula. Com isso, muitas vezes a falta ocorre com o aluno estando dentro da escola, mas fora da sala de aula e nenhuma entidade associada a escola tem conhecimento sobre esse fator.

Uma alternativa para diminuir ou até mesmo cessar esse problema, seria contratar pessoas auxiliares para vigiar pátios, corredores, banheiros e mesmo assim ainda pode existir uma margem de erro a depender do tamanho da infraestrutura da escola.

Portanto, a melhor solução seria aplicada por meio de tecnologias conhecidas como Beacons que estariam fixos em pontos importantes da escola e distribuidos de maneira que o seu sinal fosse captado em cada lugar da escola. Essa proposta será desenvolvida melhor nas próximas seções com maiores detalhes.

<br>
<h2 id="#ObjetivoGeral"> 1.1 Objetivo Geral</h2>

Nosso projeto foi iniciado a partir do incentivo do professor André, durante a matéria optativa da Universidade Federal de Sergipe, Tópicos Especiais de Hardware. O projeto Eugene trata-se de uma tecnologia precisa que atua em tempo real para  **monitorar e identificar alunos**.  O uso da tecnologia traz o detalhamento sobre a posição dos alunos e com isso, seria possível identificar problemas recorrentes com os alunos.

<br>
<h2 id="#ObjetivoEspecifico"> 1.2 Objetivo Especifico</h2>

Com o Eugene o objetivo principal é:
- Impedir a fuga de escolas.
- Identificar o motivo da baixa presença nas aulas.
- Garantir a segurança dos alunos.

<br>
<h2 id="#Trabalhos relacionados">2. Trabalhos Relacionados</h2>

Até o momento, não existe uma solução se quer parecida com projeto Eugene. Pois não existem projetos referentes a posição do aluno dentro de uma escola.  

<br>
<h2 id="#SolucaoProposta">3. Solucao Proposta</h2>
<h3 id="#Arquitetura">3.1 Arquitetura da solução</h3>
A solução é composta por cinco módulos, são eles: O Beacon, o dispositivo que será conectado ao Beacon, o ponto de acesso, a aplicação desktop o dispositivo onde será armazenada a aplicação para realizar o monitoramento. O Beacon realiza a leitura dos dispositivos e logo em seguida, já associa o id de cada dispositivo a um nome de aluno. Dessa forma, ele envia dados contendo a localidade de cada aluno para a aplicação por meio da rede local, onde estará armazenado o desktop para monitoramento.
<br>
<br>

![Arquiteture](https://user-images.githubusercontent.com/68467958/204153992-d3c1ef9e-ccdd-483f-8a57-3fed736cd832.png)[FIGURA 1]


O projeto foi desenvolvido em distribuição Windows 10 PRO. O código no microcontrolador foi escrito na linguagem C/C++ por meio do Arduino IDE, sendo que as blibliotecas utilizadas realizam a comunicação do ESP32 através de Wi-Fi e a leitura e conexão com dispositivos BLE. 

<br>
<h3 id="#MateriaisMetodos">3.2 Materiais e Metodos</h2>
<h4 id="#Módulo de hardware">3.2.1 O Módulo de hardware</h3>
Conforme visto nas seções anteriores, o hardware adotado para fazer a leitura de dispositivos BLE foi o ESP32, com isso, está evidenciado na imagem abaixo as bibliotecas utilizadas, como: "BLEDevice.h","BLEUtils.h", "BLEScan.h", "BLEAdvertisedDevice.h", "BluetoothSerial.h" e "Wifi.h".
<br><br>

![Bibliotecas](https://user-images.githubusercontent.com/68467958/204156469-40502146-18f3-4b43-bb5b-ac0b0e367592.png)[FIGURA 2]

<br>

A biblioteca "Wifi.h" é responsável por conectar o ESP32 à rede Wi-Fi. Ela utiliza duas variáveis necessárias para conexão, o ssid (nome da rede) e o password da rede (senha da rede).

<br>

![ConexãoWifi](https://user-images.githubusercontent.com/68467958/204155181-d6ccb203-887a-40fa-a185-2d5e5bb27d0a.png)[FIGURA 3]

<br>

Na _FIGURA 4_ é definido uma lista com todos os dispositivos BLEs que devem ser reconhecido e monitorados.
<br>

![Listadress](https://user-images.githubusercontent.com/68467958/204156345-729a05ce-6abc-42bd-a1c9-0a7d564dc90b.png)[FIGURA 4]

<br>
Já ná imagem abaixo [FIGURA 5], é possível escanear endereços bluetooths.

<br>

![Scanning](https://user-images.githubusercontent.com/68467958/204155711-6afd7f19-3bbe-4952-84e1-1736807edff0.png)[FIGURA 5]
<br>

Por último [FIGURA 6], após validar se algum dos endereços que estava na lista foi reconhecido, então o led ficará aceso.
<br>

![Ifscanning](https://user-images.githubusercontent.com/68467958/204155971-5f9f59cc-a838-445a-be3a-ff7f2b76fe3f.png)[FIGURA 6]

<br>
<h2 id="#Testes">3.3. Testes</h2>
<br>
Nessa etapa, foram realizados alguns testes a fim de comprovar o funcionamento do projeto proposto. Para tal, foram utilizados os equipamentos listados em <a id="Equipamentos">5.1 Equipamentos</a>. Além disso foi utilizado a Arduino IDE para formulação do código C/C++.
<br><br>
O primeiro objetivo pretendido, foi a listagem de dispositivos que suportem BLE próximos ao microcontrolador. Na imagem abaixo é possível observar que o microcontrolador está buscando dispositivos compatives com BLE. Ele fará uma listagem de todos BLEs que conseguir encontrar durante a verificação.
<br> 

![teste1](https://user-images.githubusercontent.com/68467958/204180063-782a336d-f3f6-41d1-87ab-f4cb6aa00af7.png)[FIGURA 7]
<br><br>

Tendo conseguido listar todos os dispositivos da região, foi necessário criar um filtro para verificar apenas equipamentos pré-cadastrados, estes, simulam os dispositivos dos alunos registrados no sistema. Através disso, é possível verificar se os alunos estão presentes em sala durante o horário escolar.
<br><br>
Na imagem a seguir, é possivel observar que foram reconhecidos dois aparelhos com os seguintes endereços bluetooth: "d4:55:bb:5b:16:a6" e "f0:a5:93:7c:ec:89". Esses endereços correspondem a dois celulares que estavam ligados próximos do esp32. Com isso, a leitura já está sendo realizada corretamente. 
<br><br>

![Teste2](https://user-images.githubusercontent.com/68467958/204191370-608a5707-ec61-498e-9ba3-bf9125238b9c.png)[FIGURA 8]
<br><br>


<h2 id="#Conclusao">4. Conclusões e trabalhos futuros</h2>
<br><br>
Com base na problemática sobre os alunos negligenciarem aula, o presente trabalho se propôs a desenvolver uma solução para ambientes escolares. De acordo com as seções anteriores, o aluno será monitorado de forma que sua localização seja mostrada, a fim de evitar furos de aula e aplicar as medidas cabíveis pela escola.
<br><br>
Para atingir o objetivo de monitoramento, foi utilizado alguns smarts watchs para validar os endereços bluetooths presentes na lista. Com isso, foi possível ver que os endereços estavam de fato sendo encontrados e com isso para questão de debug, os RSSIs eram printados na tela.
<br><br>
Para simular testes, foi colocado na lista apenas um endereço bluetooth de um smart watch e ao realizar a verificação, foi encontrado diversos endereços, mas só printado um que estava evidenciado na lista definida.
<br><br>
As perspectivas de trabalhos futuros incluem criar uma interface gráfica para melhor visualizar os dispositivos BLEs encontrados e construir um "ambiente" com base na planta de uma escola. Com isso, seria possível simular colocando pelo menos dois Esps32 em cantos diferentes para verificar melhor a distância e validar a precisão das coordenadas enviadas pelos Esps.
<br><br>

<h2 id="#Referencias">5. Referências</h2>
<br>

- Tutorial - Enviando um JSON com ESP32. 2020.https://pettec.unifei.edu.br/wp-content/uploads/2021/01/Tutorial-Enviando-um-JSON-com-ESP32.pdf. Online; Acessado em 26 de Novembro de 2022.

- BLE based Proximity Control using ESP32 – Detect Presence of BLE Devices.2020. https://circuitdigest.com/microcontroller-projects/ble-based-proximity-control-using-esp32. Online; Acessado em 02 de Novembro de 2022.

- Beacon Technology – Como eles funcionam e como podem ser usados.2020.https://www.mokosmart.com/pt/beacon-technology/. Online; Acessado em 07 de Setembro de 2022.

- ESP32 WIFI: COMUNICAÇÃO COM A INTERNET.2019.https://www.usinainfo.com.br/blog/esp32-wifi-comunicacao-com-a-internet/. Online; Acessado em 17 de Novembro de 2022.

- Como configurar um servidor de testes local.2022.https://developer.mozilla.org/pt-BR/docs/Learn/Common_questions/set_up_a_local_testing_server. Online; Acessado em 26 de Novembro de 2022.

- Localização Usando Beacons em Ambientes Internos para Monitoramento Remoto de Pacientes.2022.https://docplayer.com.br/108508909-Localizacao-usando-beacons-em-ambientes-internos-para-monitoramento-remoto-de-pacientes.html. Online; Acessado em 07 de Setembro de 2022.

<h3 id="#Equipamentos">5.1. Equipamentos</h2>
<br>

<table border="1" >
    <tr>
        <th>Material</th>
        <th>Figura</th>
        <th>Sobre</th>
    </tr>
    <tr>
        <td>ESP32</td>
        <td><img src="https://www.filipeflop.com/wp-content/uploads/2017/11/6WL55_1.jpg" alt="ESP32" width="1000"/></td>
        <td>ESP32 é uma série de microcontroladores de baixo custo e baixo consumo de energia. Também é um sistema-em-um-chip com microcontrolador integrado, Wi-Fi e Bluetooth.</td>
    </tr>
    <tr>
        <td>Arduino</td>
        <td><img src="https://images.tcdn.com.br/img/img_prod/650361/placa_uno_smd_r3_atmega328_sem_cabo_compativel_para_arduino_773_1_20200818190844.jpg" alt="Arduino"/></td>
        <td>A placa básica do Arduino possui uma série de sensores, o que permite a integração com outros dispositivos e a interação com outros aparelhos. Ou seja, ele pode funcionar através da sua própria interface ou interagir com outros aplicativos instalados no computador.</td>
    </tr>
    <tr>
        <td>Led</td>
        <td><img src="https://cdn.discordapp.com/attachments/1036750972598374460/1045878510243303434/unknown.png" alt="Led"/></td>
        <td>Led difuso é um led onde o encapsulamento plástico é fosco, assim vc consegue visualizar ele facilmente na liz do dia. Os LEDs (Light Emitting Diode) são diodos com capacidade de emitir luz quando polarizados diretamente. Geralmente é utilizado apenas para vc saber que algo está ligado. É necessário observar a corrente e a tensão direta do LED na hora de utilizá-lo no circuito, sendo indicado uso de resistores para limitar a corrente.</td>
    </tr>
    <tr>
        <td>Resistores</td>
        <td><img src="https://cdn.discordapp.com/attachments/1036750972598374460/1045878818440740904/unknown.png" alt="Resistor"/></td>
        <td>Um resistor ou uma resistência é um dispositivo elétrico muito utilizado em eletrônica, ora com a finalidade de transformar energia elétrica em energia térmica por meio do efeito joule, ora com a finalidade de limitar a corrente elétrica em um circuito.</td>
    </tr>
    <tr>
        <td>Protoboard</td>
        <td><img src="https://cdn.discordapp.com/attachments/1036750972598374460/1045879184087593030/unknown.png" alt="Protoboard" /></td>
        <td>Protoboard ou matriz de contato é uma placa de base plástica com diversos orifícios e conexões condutoras verticais e horizontais para a montagem de circuitos elétricos experimentais. Utilizada para fazer montagens provisórias, teste de projetos, além de inúmeras outras aplicações. 
        </td>
    </tr>
        <tr>
        <td>Jumpers</td>
        <td><img src="https://cdn.discordapp.com/attachments/1036750972598374460/1045879647801462878/unknown.png" alt="Jumpers" />
        </td>
        <td>Os Jumpers são pequenos fios condutores que podem ser conectados a uma protoboard para interligar dois pontos do circuito em projetos eletrônicos, geralmente utilizados em conexões com Arduino, Raspberry Pi, entre outros.
        </td>
    </tr>
    <tr>
        <td>Dispositivo com suporte ao BLE</td>
        <td><img src="https://cdn.discordapp.com/attachments/671467728330162193/1046783505566281788/128bd6a8-30ba-4519-adb4-30bb0dd0538b.f5285458e9fcb681e0cf8dcff8151b4a.webp" alt="Smart Watch" />
        </td>
        <td>É necessário utilizar um dispositivo que suporte BLE para que este seja cadastrado e possa ser listado pela aplicação do ESP32.
        </td>
    </tr>
</table>

<br><br>
<h2 id="#Colaboradores">6. Colaboradores</h2>

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
