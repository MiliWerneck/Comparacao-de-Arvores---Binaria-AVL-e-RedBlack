# Comparação de Estruturas de Árvores
<p align="left">Marinêz Werneck Magalhães</p>

## Definição do Projeto

<p align="justify"> Até o momento trabalhamos com três modelos de árvore, binária, avl e redblack. Chegou o momento de compararmos tais estruturas, observando seu comportamento sob diferentes volumes de dados. Para tanto, elabore arquivos que contenham 500 , 5000 , 50.000 , 500.000 entradas numéricas do tipo ponto flutuante. Para tanto, tente evitar repetições de valores em grande escala para que possamos ter uma estrutura profunda. Considere produzir os menores a partir dos maiores volumes de forma randômica. Feito a isso, vamos testar os seguintes processos:

1) - Qual o tempo gasto com pesquisa para um arquivo de entrada com 10.000 consultas. Considere como consulta a busca de um determinado número na estrutura escolhida. Para cada pesquisa, é preciso remover o elemento da árvore, retornando esse número para o usuário. Então, considere o processo de remoção como parte final do processo.

2) - Qual o tempo necessário para montar a estrutura em memória.

3) - Qual o ganho dessas estruturas ao compará-las a vetores ordenados e aplicados à pesquisa binária. Qual o tempo gasto com a ordenação do vetor? Foi possível produzi-lo em memória?

4) - Adotando como estrutura o map e unorder_map do C++, há ganhos maiores nesse processo de pesquisa?

Elabore um relatório detalhando a implementação dessas estruturas, funcionamento da aplicação, exemplo de resultado, modo de compilação e conclusões. Considere essa última seção como uma discussão de quando adotar cada estrutura acima citada e o por quê de tal escolha. Para toda essa discussão, apresentar gráficos que demonstrem os resultados obtidos durante o processo de análise. </p>

## Resultados Obtidos

As Árvores foram implementadas, baseadas nos arquivos do professor [Michel](https://github.com/mpiress)

no livro do professor Thomas H. [Cormen](https://www.cs.dartmouth.edu/~thc/)

E a referência de C++ foi obtida no site
[CPlusPlus](https://cplusplus.com/)


- <p align="justify"> O Menu de opções abaixo mostra a impressão dos tempos para criação de cada tipo de árvore, de acordo com a entrada de dados escolhida.

<p align="left">
  <img src="src/images/entrada_500.png" height = "250"></img>
</p>

- <p align="justify"> Impressão dos valores encontrados na Pesquisa e posteriormente removidos.

<p align="left">
  <img src="src/images/impressao_resposta_pesquisa.png" height = "110"></img>
</p>

<p align="justify">Os dados utilizados para pesquisa, estão em um arquivo de entrada "entrada.txt", com 10.000 valores em formato flutuante, com até 8 casas decimais, gerados através de um Gerador (figura abaixo) com 2,2% (220 dados) dos valores não presentes na base de dados que será pesquisada, base esta que também foi gerada pelo mesmo código Gerador, criando assim os arquivos: "500.txt","5000.txt", "50000.txt", "500000.txt"

[Gerador](https://cplusplus.com/reference/random/shuffle_order_engine/seed/)

<p align="left">
  <img src="src/images/gerador.png" height = "110"></img>
</p>

- <p align="justify">A figura abaixo ilustra a saída dos tempos no terminal. Os dados foram coletados em 6 repetições de cada base de dados, esses dados foram armazenados emplanilha eletrônica onde foram tratados, normalizados (entre 0 e 1) e gerados os gráficos correspondentes.

<p align="left">
  <img src="src/images/resposta_pesquisa.png" height = "160"></img>

## Resultados criação de Árvores

 <p align="justify">Para poucos dados (500) não há praticamente diferença entre as formas de criação das árvores, sendo assim a binária é uma excelente opção pela facilidade e simplicidade de implementação.

<p align="left">
  <img src="src/images/criacao_500.png" height = "160"></img>
</p>

<p align="justify">Para poucos dados  (5.000) há pouca diferença entre as formas de criação das árvores, com a RedBlack tendo ligeira vantagem, mas com difícil implementação, sendo assim a binária ainda  é uma excelente opção pela facilidade e simplicidade de implementação.
<p align="left">

  <img src="src/images/criacao_5000.png" height = "160"></img>
</p>
<p align="left">

<p align="justify">Para dados maiores (50.000) há diferença considerável entre as formas de criação das árvores, com a RedBlack  eunordered_map tendo vantagem, sendo assim a a red Black é uma boa opção apesar de ser mais difícil sua implementação.

<p align="left">
  <img src="src/images/criacao_50000.png" height = "160"></img>
</p>
<p align="left">

<p align="justify">Para dados grandes (500.000) há diferença considerável entre as formas de criação das árvores, descartando imediatamente o uso de  map e AVL, com a RedBlack  e unordered_map tendo vantagem, sendo assim a red Black é uma boa opção.

<p align="left">
  <img src="src/images/criacao_500000.png" height = "170"></img>
</p>

## Resultados Pesquisa e Remoção de Árvores

 <p align="justify">Para poucos dados (500) não há praticamente diferença entre as formas de pesquisa e remoção das árvores, sendo assim a binária é uma excelente opção pela facilidade e simplicidade de implementação.

<p align="left">
  <img src="src/images/pesq_rem_500.png" height = "160"></img>
</p>

 <p align="justify">Para poucos dados (5000) há pouca diferença entre as formas de pesquisa e remoção das árvores, com exceção do vector que já pode ser descartado seu uso, sendo que a AVL tem uma ligeira vantagem, tornando assim uma excelente opção.

<p align="left">
  <img src="src/images/pesq_rem_5000.png" height = "160"></img>
</p>

<p align="justify">Para dados maiores (50.000) há diferença considerável entre as formas de pesquisa e remoção nas árvores, com a RedBlack eunordered_map tendo ligeira vantagem, e o vector sendo completamente descartado pelo grande custo de tempo.

<p align="left">
  <img src="src/images/pesq_rem_50000.png" height = "160"></img>

  <p align="justify">Para dados grandes (500.000) há diferença considerável entre as formas de pesquisa e remoção nas árvores, com a RedBlack eunordered_map tendo ligeira vantagem, e o vector sendo completamente descartado pelo altíssimo custo de tempo.
  
</p>
<p align="left">
  <img src="src/images/pesq_rem_500000.png" height = "170"></img>
</p>

## Conclusão: 

<p align="justify"> O programa foi gerado em um notebook, SO Linux Ubuntu, com 8GB de RAM, processador Core I7 10th Gen, placa de vídeo NVidia, sendo que todos os processos conseguiram ser feitos sem grandes problemas.
<p align="justify"> Portanto para pequenos volumes de dados, a Árvore binária é uma ótima opção, mas para grandes volumes de dados a melhor opção será a Árvore Red Black. O uso do vector é muito útil quando vai inserir e ler sequencialmente, mas não quando precisa pesquisar ou remover valores.
  
## Compilação:

| Comando | Função |
|---------| --------|
| `make c` | Limpa tudo, compila e executa |
| `make r` | Compila e executa |


