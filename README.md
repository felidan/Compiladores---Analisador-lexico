Reconhecedor léxico (Transdutor)
===================================================

Este programa foi desenvolvido no intuito de simular um analisador léxico baseado na utilização de transdutores e autômatos. Este processo é utilizado como uma das fases de um compilador para diferenciar números, variáveis e palavras reservadas.

## Requisitos

* **(Recomendado)** Compilador - **GCC 4.9.2** igual ou superior (esta versão já está disponível na versão 5.11 ou superior do Dev C++).

Este programa poderia ser utilizado como o compilador de uma certa linguagem.

## Exemplo de utilização (P(i) palavra reservada na posição i, V representa um Array de variáveis e N(x) representa o número 'x'):

Considerando a linguagem abaixo:
   0 - IF
   1 - ELSE
   2 - END
   3 - GO
   4 - TO
   5 - OF
   6 - PRINT
   7 - READ
   8 - LET

* **Entrada**: LET A := 10 IF A <= 5 : PRINT menor ELSE : PRINT maior END
* **Saída**: P(**8**)V(**0**):=N(**10**)P(**0**)V(**0**)<=N(**5**):P(**6**)V(**1**)P(**1**):P(**6**)V(**2**)P(**2**)