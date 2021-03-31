# romanos-cpp
Números romanos

# Identificação
João Tito do Nascimento Silva - 18/0123301

# Etapas do desenvolvimento com TDD
1. Inicialmente, foi criado o arquivo testa_romanos.cpp sem nenhum teste, para tentar fazer a execução de uma build com make
e deixar preparado para começar outros códigos. Quando a build estava funcionando, foi criado o primeiro teste de validação.
2. O primeiro teste, de validação, foi escrito para testar o caso de a string dada como número ter mais que 30 caracteres. Assim,
O teste foi escrito e, logo depois, o código. Ao ser concluído o código, foi testado e funcionou corretamente, o que significou
que strings com mais de 30 caracteres retornariam o valor esperado (negativo).
3. O próximo teste envolvia decidir se todos os caracteres na string eram numerais romanos válidos. 
Nesse caso, o teste não foi escrito primeiro, mas sim a enum que continha os valores de cada caractere. 
Após esta enum, foi escrito o teste ShouldReturnNegative_WhenANumeralIsUnknown, e o código foi desenvolvido 
pensando em passar nesse teste. Inicialmente, as mudanças quebraram o teste anterior, de tamanho da string, pois este utilizava caracteres como "A", e mesmo assim funcionou pois, de início não havia a checagem dos caracteres, mas apenas do tamanho das strings.
Assim, foi necessário reescrever esse teste. Depois dos devidos ajustes, o teste passou e prossegui para o próximo teste.
4. O próximo teste envolvia calcular strings de um caractere só. Esse teste foi útil pois garantia que strings mais 
simples funcionariam antes de trabalhar com strings mais complexas. O código é recursivo, então o caso mais simples é este. 
Passar neste caso significaria que temos o funcionamento básico para seguir para os próximos casos, de strings maiores. Assim, 
foi escrito o teste, e o código foi escrito em seguida, sendo ajustado aos poucos para passar em todos os testes já escritos.
5. Na última etapa, era necessário escrever um teste para verificar se strings maiores eram calculadas corretamente. Assim, escrever o teste
foi bem simples, e envolveu somente colocar alguns casos de teste com asserts. Daí em diante, foi adicionada a recursividade do código
e o final do desenvolvimento, quando o último teste também passou, juntamente com todos os outros.