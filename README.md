# MATA40-T1-202402

Este é um repositório com as estruturas de dados e algoritmos vistos em sala durante as aulas de MATA40 - ESTRUTURAS DE DADOS com o Professor Sergio Gorender.

Todos os algoritmos se encontram dentro da pasta `src/lib/` divididos em seus respectivos tópicos. Com exceção do algoritmo de notação polonesa, que se encontra em meio ao código de lista linear, os outros algoritmos são arquivos header.

# Uso

Para utilizar os arquivos basta movê-los uma pasta acima, para `src/lib/`, importá-los no código através de `#include "estrutura.h"` e utilizar as suas funções.

# Execução

```bash
# Criar exectutável
make

# Utilizar os arquivos de entrada e saída na execução
bin/main < src/inputf.in > outputf.out

# Em apenas uma linha
make && bin/main < src/inputf.in > outputf.out
```

_Para aqueles que utilizam Sublime Text como editor de código, eu possuo um `build system` para executar essas tarefas e estaria feliz em compartilhar, basta entrar em contato comigo pelo email (limahenriquec@gmail.com)._