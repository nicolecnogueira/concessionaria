
# Programa

O programa consegue criar concessionárias as quais conseguem armazenar os seguintes tipos de veículos: carros, motos e caminhões. Cada Concessionária possui um `nome`, `CNPJ` e número de veículos no `estoque`; Cada veículo possui `marca`, `preço`, número do `chassi` e ano de `fabricação`; apenas os carros possuem `tipo de motor` (gasolina ou elétrico); apenas as motos possuem  `modelo` (clássico ou esportivo); apenas os caminhões possuem `tipo de carga` (comum ou perigosa).


# Compilação  

* O primeiro passo é compilar o programa com o comando "make" no terminal e , então, executar o comando "./build/programa", também no terminal.
* A partir daí, é possível utilizar os seguintes comandos:
* Para criar uma concessionária:
*      $ create-concessionaria <nome-concessionaria> <CNPJ> <estoque>
*  exemplo:
*      $ create-concessionaria IMD_SA 11.111.111/0001-11 0
*  
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
*  Para aumentar o preço dos veículos de uma concessionária:
*      $ raise-price <nome da concessionária> <taxa de aumento>
*  exemplo:
*      $ raise-price IMD_SA 10
* Para parar a execução do programa:
*      $ quit
