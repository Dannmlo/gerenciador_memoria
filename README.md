# Gerenciador de Memória RAM em C

Projeto desenvolvido para a disciplina de **Linguagem de Programação I** do curso de **Ciência da Computação** (IFCE).

## 📌 Descrição do Problema
O sistema simula o gerenciamento de blocos de memória RAM através de um menu interativo, permitindo alocar blocos de tamanhos variáveis de forma dinâmica, liberar blocos previamente alocados, consultar o estado da memória simulada e visualizar um resumo dos recursos alocados.

## 🛠️ Conceitos Aplicados
- Alocação e liberação dinâmica de memória (`malloc` e `free`);
- Manipulação de ponteiros e endereços de memória;
- Estruturas de dados (`struct`);
- Vetores de registros;
- Modularização em C (`.c` e `.h`);
- Validação de entradas e prevenção de erros (ex: dupla liberação de blocos).

## 📁 Estrutura do Projeto
```text
gerenciador-memoria/
├── main.c      # Interface com o usuário e controle do menu
├── memoria.c   # Implementação das funções de gerenciamento de memória
└── memoria.h   # Protótipos das funções, estruturas e definições de constantes

## 🚀 Como Compilar e Executar
Via Terminal (GCC):
Bash
# Compilação dos módulos
gcc main.c memoria.c -o gerenciador_memoria

# Execução
./gerenciador_memoria
