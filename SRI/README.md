Stemming es un paso importante en el preproceso de documentos, ya que nos permite trabajar con las raíces de las 
palabras y no con sus derivaciones, reduciendo el número de vocablos con el que tenemos que trabajar y al mismo 
tiempo “juntando” palabras que posiblemente tengan alguna relación (como “caminar” y “caminante”) y de esa forma usarlo para crear un índice que nos ayude a encontrar documentos fácilmente.


Si pensamos en libros, un índice nos ayuda a encontrar algo en específico, buscando la página en donde está el tema que
buscamos. Bajo esa premisa, en un libro un índice invertido relaciona palabras con las páginas en las que se encuentra, 
aunque si vemos los índices que hay al final, lo que se muestra ahí son ciertas palabras específicas, o bien temas, junto 
con la(s) página(s) en la(s) que son mencionados. La idea es la misma que en el libro, pero en vez de escribir temas o
palabras clave solamente, en el índice invertido de un motor de búsqueda incluímos todas las palabras del documento, 
filtrando stopwords y aplicando stemming.

Por ejemplo, supongamos que tenemos una colección de 3 documentos, representados aquí con frases:

- El perro corre rápido.
- El niño juega con el perro en el parque.
- El niño nada rápidamente.

Al momento de representarlos en la forma de un motor de búsquda, primero filtramos las stopwords:

- perro corre rápido.
- niño juega perro parque.
- niño nada rápidamente.

Enseguida, aplicamos stemming, obteniendo lso documentos en forma más “aplicable” en motores de búsqueda.

- perr corr rapid
- niñ jug perr parque
- niñ nad rapid

Por último creamos un índice invertido relacionando palabras con los documentos en las que se encuentran:

Palabra	Documento
  
  perr	  1,2
  corr	  1
  rapid	  1,3
  niñ	    2,3
  jug	    2
  parque	2
  nad 	  3
