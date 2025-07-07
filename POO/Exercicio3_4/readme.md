Utilizando a classe MyDate da última atividade:
Sobrecarregue o operador de soma para somar dois objetos do tipo
MyDate e um MyDate e um inteiro (em qualquer ordem - int+MyDate
e MyDate+int!). Para a soma entre dois objetos, some todos os valores
(dia, mês e ano); para a soma com um inteiro, o inteiro é um número de
dias. Lembre-se de garantir que após a soma a nova data é válida.
Sobrecarregue o operador « para permitir que MyDate seja impresso
diretamente usando cout (cout « data). Lembre-se de respeitar a
configuração de data longa ou curta (dica: já existe uma função que
retorna a data como string...)
Submeta um arquivo zip contendo apenas os arquivos .cpp e .h da classe
alterada

Crie uma nova classe, RelatorioErro, que vai utilizar a classe MyDate
A classe RelatorioErro deve possuir um atributo CodigoErro (um
inteiro), um atributo MsgErro (uma string) e um atributo constante
DataErro do tipo MyDate. Ou seja, um const MyDate DataErro.
Deve também haver um atributo de classe (ou seja, variável estática)
NumeroErros
A classe RelatorioErro deve ter uma construtora que incrementa o
número de erros e uma destrutora que decrementa e salva as
informações (data, código e mensagem) no final de um arquivo de log
Submeta um arquivo zip contendo apenas os arquivos .cpp e .h da classe
