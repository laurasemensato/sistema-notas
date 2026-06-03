# 📊 Sistema de Notas v4.1

O **Sistema de Notas v4.1** é um programa desenvolvido em **C++** para gerenciar, calcular e armazenar notas de alunos em diversas disciplinas. Ele permite a entrada de dados via console, validação de limites, classificação automática do status acadêmico do aluno e persistência dos dados em arquivos de texto com registro de data e hora.

---

## 🚀 Funcionalidades

* **Menu Interativo:** Navegação simples para gerar novos relatórios, ler dados salvos ou acessar as informações do sistema.
* **Validação Estrita de Entradas:**
    * Limite de **1 a 20 alunos**.
    * Limite de **1 a 5 disciplinas**.
    * Notas validadas estritamente entre **0.0 e 10.0**.
* **Cálculo Automatizado:** Gera a média aritmética das notas informadas para cada aluno por disciplina.
* **Classificação de Status:**
    * 🟢 **Aprovado:** Média igual ou superior a 7.0
    * 🟡 **Recuperação:** Média entre 5.0 e 6.9
    * 🔴 **Reprovado:** Média inferior a 5.0
* **Persistência de Dados (Logs):** Salva automaticamente o relatório gerado e o resumo estatístico em um arquivo chamado `relatorio.txt`, incluindo a data e hora da exportação.
* **Menu "Sobre o Sistema":** Seção dedicada a exibir informações sobre a versão do software e créditos de desenvolvimento.

---

## 📋 Pré-requisitos

Para compilar e executar este projeto, você precisará de:
* Um compilador C++ compatível com o padrão C++11 ou superior (como o `g++` da coleção GCC, Clang ou MSVC).
* Ambiente de linha de comando (Terminal, Prompt de Comando ou PowerShell).

---

## 🛠️ Como Executar o Projeto

Siga os passos abaixo para clonar, compilar e rodar o sistema em sua máquina:

### 1. Clonar o Repositório
```bash
git clone [https://github.com/seu-usuario/nome-do-repositorio.git](https://github.com/seu-usuario/nome-do-repositorio.git)
cd nome-do-repositorio
