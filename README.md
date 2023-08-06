# Trabalho Prático 2 - AED1
**Nome:** Juliano de Castro Lorenzato
<br>
**Matrícula:** 22101249
<br>
**Turma:** M2

## Sobre o problema do Leetcode
Eram dados alguns tipos de sanduiches (0 para circular e 1 para quadrado) e também era dada 
a mesma quantidade de estudantes que preferiam um dos dois tipos (0 preferem circular, 1 preferem quadrados).
Os sanduiches são empilhados e os estudantes enfileirados, se o primeiro estudnte da fila preferir o sanduiche 
do topo da pilha ele pega o sanduiche e sai da fila, se ele não gostar ele deixa o sanduiche e vai para o final
da fila, por mim deve-se retornar a quantidade de estudantes que ficaram sem comer, podendo ser 0 ou a quantidade 
total de estudantes.

## Casos que testaram com sucesso

| Input                                                | Output |
|------------------------------------------------------|--------|
| students = [1,0]; sandwiches = [0,0]               | 1      |
| students = [1,1,0,0]; sandwiches = [0,1,0,1]         | 0      |
| students = [1,1,1,0,0,1]; sandwiches = [1,0,0,0,1,1] | 3      |

## O que funciona
Creio que todos os algoritmos usados funcionem para qualquer caso. Todos os casos do Leetcode passaram.