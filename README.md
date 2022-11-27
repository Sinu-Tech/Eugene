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

Até o momento, não existe uma solução se quer parecida o projeto. Pois não existem projetos referentes a posição do aluno dentro da escola.  


<br><br>
<h2 id="#SolucaoProposta">3. Solucao Proposta</h2>


<br><br>
<h3 id="#Arquitetura">3.1 Arquitetura da solução</h3>
A solução é composta por cinco módulos, são eles: O Beacon, o dispositivo que será conectado ao Beacon, o ponto de acesso, a aplicação desktop o dispositivo onde será armazenada a aplicação para realizar o monitoramento. O Beacon realiza a leitura dos dispositivos e logo em seguida, já associa o id de cada dispositivo a um nome de aluno. Dessa forma, ele envia dados contendo a localidade de cada aluno para a aplicação por meio da rede local, onde estará armazenado o desktop para monitoramento.
<br>

![Arquitetura](https://user-images.githubusercontent.com/68467958/204149145-50ca6a79-6814-4bd8-bf14-95f3bc1dcdf9.png)








<br><br>
<h2 id="#MateriaisMetodos"> Materiais e Metodos</h2>


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
