# Editor de Fotos 

<p> Editor de fotos desenvolvido usando c++ como projeto final da disciplina de Linguagem de Programação da UFRN. Ele funciona apenas com arquivos do formato ".ppm" e tem as seguintes opções de edição:</p>

- Binarizar
- Refletir
- Borrar
- Cortar

## Funcionamento:
<p> O script ao ser executado ele pergunta qual tipo de edição você deseja realizar e pede que seja passado o nome do arquivo que deve ser editado. Feito isso, ele irá pegar o arquivo, ler a matriz proveniente da imagem em questão e em cima disso, trabalhar com os valores dos pixels das imagens. Sendo pra cada tipo de edição, uma função diferente é chamada e uma lógica diferente é aplicada para manipular o valor dos pixels. </p>

<img src="imagens/lena.PNG" alt="lena.ppm" width="30%"> &nbsp;&nbsp;&nbsp;&nbsp;  <img src="imagens/Matriz dos pixels da imagem.PNG" alt="matriz com os pixels" width="65%"> 
<p align="center"> (Imagem usada para testar o código e a matriz dos pixels correspondente ao arquivo de imagem ".ppm")</p>

## Efeitos do Editor:

### Binarizar:
<img src="imagens/lena_binarizada.PNG" alt="lena.ppm" width="30%" align="center">
<p>Passando um limiar de 70</p>

### Refletir:
<img src="imagens/lena_refletida.PNG" alt="lena.ppm" width="30%" align="center">

### Borrar:
<img src="imagens/lena_borrada.PNG" alt="lena.ppm" width="30%" align="center">

### Cortar:
<img src="imagens/lena_cortada.PNG" alt="lena.ppm" width="30%" align="center">
<p>Passando os seguintes valores (linha inicial, linha final, coluna inicial e coluna final): 30 50 100 120 </p>
