
# Identificação

* Nome: Nicole Carvalho Nogueira

* Matrícula: 20220040038
  
# Compilação  

* a descrição de como compilar e rodar o programa, incluindo um roteiro de entradas e comandos que destaquem as funcionalidades
* O primeiro passo é compilar o programa com o comando "make" no terminal e , então, executar o comando "./build/programa", também no terminal.
* A partir daí, é possível utilizar os seguintes comandos:
* Para criar uma concessionária:
*      $ create-concessionaria <nome-concessionaria> <CNPJ> <estoque>
*  exemplo:
*      $ create-concessionaria IMD_SA 11.111.111/0001-11 0
* Para adicionar um carro:
*      $ add-car <nome-concessionaria> <marca> <chassi> <preço> <ano_de_fabricação> <tipo_de_motor>
*  exemplo:
*      $ add-car IMD_SA Toyota 9BRBLWHEXG0107721 100000 2019 gasolina
* Para adicionar um caminhão:
*      $ add-truck <nome-concessionaria> <marca> <chassi> <preço> <ano_de_fabricação> <tipo_de_carga>
*  exemplo:
*      $ add-truck IMD_SA Scania 7BRBLQHEXG0208811 700000 2010 perigosa
* Para adicionar uma moto:
*      $ add-bike <nome-concessionaria> <marca> <chassi> <preço> <ano_de_fabricação> <modelo>
*  exemplo:
*      $ add-bike IMD_SA Honda 9BRBLQHEXH4208811 50000 2012 esportiva
* Para remover um veículo:
*      $ remove-vehicle <chassi>
*  exemplo:
*      $ remove-vehicle 7BRBLQHEXG0208811
* Para pesquisar um veículo:
*      $ search-vehicle <chassi>
*  exemplo:
*      $ search-vehicle 7BRBLQHEXG0208811
* Para retornar a frota de uma concessionária:
*      $ list-concessionaria <nome-concessionaria>
*  exemplo:
*      $ list-concessionaria IMD_SA
* Para salvar os dados de uma concessionária em um arquivo .txt:
*      $ save-concessionaria <nome-arquivo.txt>
*  exemplo:
*      $ save-concessionaria IMD_SA.txt
* Para retornar os dados salvos em um arquivo .txt:
*      $ load-concessionaria <nome-arquivo.txt>
*  exemplo:
*      $ load-concessionaria IMD_SA.txt
* Para parar a execução do programa:
*      $ quit

# Limitações

* Apesar de todas as funcões terem sido implementadas, quando tentamos adicionar um veículo que já está cadastrado, o programa não reconhece o erro e adiciona o veículo mesmo assim. Assim, a concessionária fica com veículos repetidos.
   
# Autoavaliação

- Modelagem e implementação das classes Concessionária, Veículo, Automóvel, Moto, Caminhão | **10 / 10**
  - 0: sem modelagem e implementação de classes
  - 5: apenas algumas classes modeladas e implementadas; ausência de herança
  - 10: modelagem e implementação completa com uso de herança
  
- Implementação e uso do comando `create-concessionaria` | **10 / 10**
  - 0: não cria concessionária via linha de comando 
  - 5: permite criar apenas uma concessionária
  - 10: permite criar mais do que uma concessionária
  
- Implementação e uso dos comandos para adicionar veículos `add-car/add-bike/add-truck` | **10 / 10**
  - 0: não permite criar veículos via linha de comando
  - 5: permite criar apenas um ou outro veículo em uma única concessionária
  - 10: permite criar qualquer tipo de veículo em qualquer uma das concessionárias disponíveis

- Não permitir adicionar um veículo que já tenha sido anteriormente adicionado | **0 / 10**
  - 0: não realiza o teste
  - 10: realiza o teste e indica o erro  

- Implementação e uso do comando para remover veículos `remove-vehicle` | **10 / 10**
  - 0: comando não implementado
  - 10: comando implementado e funcional

- Implementação e uso do comando para busca de veículos `search-vehicle` | **15 / 15 - Bônus: 0**
  - 0: não implementado
  - 15: implementado e funcional
  - bonus +10: implementado com estratégia de busca diferente da busca exaustiva
  - bonus +10: uso de métodos virtuais para impressão na tela
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `list-concessionaria` | **10 / 10 - Bônus: 0**
  - 0: não implementado
  - 10: implementado e funcional   
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `raise-price` | **10 / 10 - Bônus: 0**
  - 0: não implementado
  - 10: implementado e funcional 
  - bonus +10: implementado com uso de método virtual

- Implementação e uso do comando `save-concessionaria` e `load-concessionaria` | **30 / 30**
  - 0: não implementado
  - 15: ambos os comandos implementados e funcionais
  
- Implementação eficiente através do uso de referencias e contêineres da STL | **0 / 10**
  - 0: não usou contêiner da STL nem fez uso eficiente dos recursos computacionais
  - 5: usou contêiner da STL mas não otimizou uso dos recursos computacionais
  - 10: usou contêiner da STL junto a algoritmos e práticas de bom uso de recursos computacionais
  
- Organização do código em src, include, data | **5 / 5**
  - 0: não organizou o código
  - 5: organizou o código 
  
- Documentação do código | **5 / 5**
  - 0: não documentou o código
  - 5: documentou o código 
  
- Implementação e documentação de arquivos e procedimentos de compilação e teste | **15 / 15**
  - 0: não implementou arquivos e procedimentos de compilação e teste
  - 5: implementou alguns arquivos e procedimentos de compilação e teste (com alguma documentação) 
  - 15: Ampla implementação e documentação de arquivos e procedimentos de compilação e teste (com exemplos)
 
 # Total
 
 **130 / 150 ** pontos (sem bônus)
 
 **130 / 200 ** pontos (com bônus)
