##Temas das equipes

### 1) Agro - Desafio IoT ok

Uma cooperativa de agricultores está enfrentando problemas quanto a performance da safra de soja no interior do Paraná. Eles possuem smartphones como ferramenta para uso no campo e os índices de luminosidade e pluviométrico (chuva e luminosidade) são essenciais para tomada de decisão. Além disso, o gestor da cooperativa precisa destas informações como relatório para poder negociar com os bancos de crédito rural o risco de crédito com os produtores.  
Para chuva , considerar choveu ou não (modo digital) 
Para luminosidade, considerar a quantidade de LUX

Como converter o valor do sensor em LUX:
http://www.nadielcomercio.com.br/blog/2015/09/09/medicao-da-luz-com-um-arduino-e-ldr/

##### Light Requirements of "High Energy" Plants
| State   |      Range      | 
|----------|:-------------:|
| Min. necessary for life | 1000 - 5000 lux|
| Min. necessary for consistent but sparse growth|10000 - 15000 lux |
| Min. necessary for robust growth | 20000 - 25000 lux |
| Max. Efficiency for Sub Tropical varieties |25000 - 30000 lux|
| Max. Efficiency for Equatorial varieties |25000 - 50000 lux |
| Min. necessary for robust growth | 20000 - 25000 lux |

*Plants need 25000-50000 lux too grow fast.*


### 2) Casa conectada - Desafio IoT ok

Você é uma startup que decidiu empreender na área de casa conectada (smart home) e através de ter rodado alguns pivots , observou que a área de segurança é um negócio interessante e atrativo. Sua solução possui sensores de presença e de ruído que são capazes de detectar se existem pessoas em áreas da casa para assim evitar roubos e onde a solução de câmera é muito cara. Os seus usuários desejam ser alertados pelo celular e em qual ambiente há risco de intrusos. Além disso o serviço que a sua startup deve oferecer, conta com uma central de segurança que via analytics (com dashboard feito pela sua startup) consegue mapear quais bairros sofrem mais com esse tipo de problema para poder alocar a frota de profissionais de rua de maneira dinâmica e eficiente.


### 3) Carro conectado ok

Você faz parte da área de produto de uma multinacional fabricante de automóveis que está iniciando um projeto de desenvolvimento para ensaio de amortecedores. A equipe engenharia especificou dois dados extremamente relevantes: Aceleração e distância de parada de um objeto. Os engenheiros tem interesse em saber em tempo real o nível de aceleração em cada ensaio, além da distância a um objeto especificado, através de um dashboard via web.

Para distância, considerar unidade de medida em centímetro
Para aceleração , considerar apenas o eixo Y

### 4) Smart Cities - Desafio IoT ok

A prefeitura de São Paulo está com um projeto de smart cities com foco em 2 problemas: 1) mapear a poluição sonora produzido pelo trânsito e 2) informar a população o nível de temperatura e umidade das regiões da cidade para alertar quanto as pancadas de chuvas isoladas que causam transtornos para a população. Além do app que deverá ser disponibilizado para a população, deverá ser oferecido para a defesa civil um dashboard para que os gestores sejam capaz de tomar decisões e análises quanto aos principais pontos de risco da cidade (quanto a chuva).

Para fins de análise, o ruído será calculado com a seguinte fórmula: 
double db = 16.801 * log (sensorValue/1023) + 9.872;


### 5) Varejo - Desafio IoT ok

Você foi contactado por uma grande rede de varejo (supermercado) que está com grandes problemas de reposição de produtos nas gôndolas de supermercado. Por diversas vezes, o cliente não encontra o produto na prateleira e assim o supermercado perde a venda para um concorrente. O tempo de reposição é longo e manual além do espaço ser muito grande para ter diversas pessoas fiscalizando as prateleiras o que ainda implica em um custo de pessoal maior. O seu desafio é controlar em tempo real o nível de ruptura de produto nas gôndolas em tempo real , onde através de um app, um funcionário saberá exatamente quando e onde repor o produto. Ao mesmo tempo , os fabricantes dos produtos tem interesse em saber em tempo real o nível de ruptura em cada ponto de venda além através de um dashboard via web.

Considerar uma gôndola de 30cmx20cm

### 6) Supply chain - Desafio IoT ok (testar)

A área de negócios da empresa que você trabalha (uma grande multinacional de logística) está perdendo dinheiro com o rastreio de produtos e paletes que são transportados em caminhões da sua frota. A solução alinhada com o usuário é o uso de uma app que faça um check dentro do caminhão quando o mesmo for abastecido e uma interface web que apresente em tempo real o status das cargas que estão transportadas por todo o país. Assim , os gestores podem ser capazes de entender quais os centros de distribuição apresentam melhor e pior performance para que isso possa alimentar o planejamento da cadeia .


### 7) Chat Bot - Desafio IoT ok

Com a popularização dos Bots e o Messenger do Facebook como um dos precursores desta tecnologia, você e sua equipe definiram que a próxima geração da internet das Coisas é ser mais social, usando interfaces como o Messenger para interagir com objetos tais como a cafeteira, lâmpadas, geladeiras etc. Para provar que faz sentido a visão de vocês, vocês foram convidados para apresentar um protótipo que usando o messenger do facebook , você são capazes de interagir com um um objeto ( no caso uma lâmpada) que não possui conectividade nativa com a internet.  A aplicação web deverá armazenar o status dos objetos para futuras análises quanto ao comportamento do usuário em casa.

### 8) E-Health -Desafio IoT ok (contato e chave/led)

A área de marketing de uma indústria farmacêutica enfrenta hoje um grande problema de mercado: A adesão à medicamentos para doenças crônicas. O paciente muitas vezes se esquece de tomar o medicamento na hora certa e isso reduz o efeito da droga o que consequentemente aumenta as chances de agravar o quadro clínico do paciente. A empresa de soluções de e-health que você trabalha foi contratada para resolver esse cenário e terá que criar uma solução que seja capaz alertar o paciente que está na hora de tomar o medicamento além de disponibilizar para o médico que acompanha o paciente um dashboard com o analytics do comportamento de adesão ao tratamento prescrito. Além disso, um webapp deve ser disponibilizado para que alguém da família possa acompanhar se o paciente está tomando o medicamento e caso contrário poderá entrar em contato e lembrá-lo.
