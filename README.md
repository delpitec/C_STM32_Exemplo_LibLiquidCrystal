# Montagem para teste de utilização da biblioteca LiquidCrystal:

**Descrição do programa:**<br>
Este programa tem como objetivo principal, testar as funcionalidades da biblioteca [LiquidCrystal](https://github.com/delpitec/C_STM32_LibLiquidCrystal), que permite operações em display LCD através do microcontrolador STM32F103C8T6 e ferramenta STM32CubeIDE.<br>
A seguir, temos a foto e o esquema de ligação da montagem teste que está documentada em vídeo [neste link](https://www.youtube.com/watch?v=FuYQdr36oKI):
<br>
<br>
![stm32 and display lcd _ stm32 and liquid crystal display](https://user-images.githubusercontent.com/58537514/151100045-d9c0c72d-9a7d-416b-83bf-2329d887d6be.png)
<br>
<br>

A figura acima, que é a montagem base para este código exemplo, respeita a seguinte sequência de ligação:

| From<br>STM32 Pin | To<br>LCD Pin / Function|
| :---:   | :-: |
| B3 | 4 / RS |
| A15 | 5 / RW |
| A12 | 6 / EN |
| B15 | 11 / D4 |
| B14 | 12 / D5 |
| B13 | 13 / D6 |
| B12 | 14 / D7 |

Para selecionar o teste desejado, basta descomentar a linha que define o teste a ser compilado no arquivo *main.c*.
Cada um dos testes estão resumidamente descritos a seguir:

**AutoScroll:** &nbsp;<br> 
Demonstração das diferenças de utilização do Autoscroll x noAutoScroll

**Blink:** &nbsp;<br> 
Habilita/Desabilita cursor piscante

**Cursor:** &nbsp;<br> 
Habilita/Desabilita cursor *underscore* (_)

**CustomCharacter:** &nbsp;<br> 
Cria caracteres personalizados

**Display:** &nbsp;<br> 
Habilita/Desabilita exibição de mensagem no display

**HelloWorld:** &nbsp;<br> 
Mostra mensagem de helloworld com contador de segundos

**Scroll:** &nbsp;<br> 
Demosntração da função Scroll (nativa do display LCD)

**TextDirection:** &nbsp;<br> 
Demonstração das diferenças de utilização do TextDirection

**SetCursor:** &nbsp;<br> 
Demonstração da função que seleciona posição do cursor

 &nbsp;<br> 
## Contact me:
💼[LinkedIn](https://br.linkedin.com/in/rafaeldelpino)&nbsp;&nbsp;&nbsp;
📹[Youtube](https://www.youtube.com/delpitec)&nbsp;&nbsp;&nbsp;
📸[Instagram](https://www.instagram.com/delpitec_/)&nbsp;&nbsp;&nbsp;
📧[E-mail](delpitec@gmail.com)&nbsp;&nbsp;&nbsp;

