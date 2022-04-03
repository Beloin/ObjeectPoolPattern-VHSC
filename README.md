Projeto simples que representa um Padrão de Projeto de ObjectPool.

Temos a classe `VeryHardAndSlowCreation` (VHSC), uma classe que como o nome já diz, demora bastante para ser instanciada.
Tendo isso em vista, iremos salvar instâncias dessa classe em um VHSCPool, um Pool de objetos que mantém esses objetos para poderem ser reutilizados por diferentes chamadas do sistema.

Nesse Pool podemos fazer as operações mais básicas:

 - setMaxPoolSize -> Modificar o tamanho da Pool.
 - getCurrentSize -> Ver a quantidade de objetos disponíveis dentro da Pool
 - acquire -> Receber um objeto disponível da Pool
 - release -> Retornar um objeto para a Pool depois de ser utilizado.

Cada objeto de `VHSC` possui um id próprio, assim podemos realmente ver que os objetos são mantidos e retornados.
