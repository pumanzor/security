##Indice invertido, busqueda booleana y vector de terminos

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

1. El perro corre rápido.
2. El niño juega con el perro en el parque.
3. El niño nada rápidamente.

Al momento de representarlos en la forma de un motor de búsquda, primero filtramos las stopwords:

1. perro corre rápido.
2. niño juega perro parque.
3. niño nada rápidamente.

Enseguida, aplicamos stemming, obteniendo lso documentos en forma más “aplicable” en motores de búsqueda.

1. perr corr rapid
2. niñ jug perr parque
3. niñ nad rapid

Por último creamos un índice invertido relacionando palabras con los documentos en las que se encuentran:

|Palabra	|Documento|
|---------|---------| 
| perr	|  1,2|
| corr	 | 1|
| rapid	|  1,3|
| niñ	   | 2,3|
| jug	   | 2|
| parque	|2|
| nad 	  |3|  
  
  Una vez creado el índice, éste puede ser usado para responder consultas simples, regresando el documento en donde los términos de la consulta están incluídos.

  Algo importante a notar aquí es que la consulta siempre tiene que pasar por el mismo procesamiento aplicado a los documentos. Esto no es solamente aplicable en este caso de búsqueda booleana (si un documento contiene o no un término). Por tanto, si alguien busca “perro”, tenemos que aplicarle filtros y encontrar la raíz de la palabra (stemming) antes de buscarlo en el índice, o de otra forma nunca encontraremos documentos relevantes.

  Si por ejemplo alguien busca “niño perro” (poniendo un ejemplo extremadamente simple para ilustrar), la consulta que un sistema verá es “nin perr”. Ahora bien, es necesario saber si el usuario quiere encontrar los documentos donde ambos términos aparezcan, o bien aquellos en los que cualquiera de los dos términos aparezcan. En el primer caso, necesitamos un operador AND, mientras que en el segundo, requerimos un operador OR.
  
  Buscando en el índice que creamos, si se buscan documentos que tengan los dos términos, necesitamos encontrar la intersección de los documentos en donde “nin” aparece y en donde “perr” aparece. Entonces, obtenemos de nuestro índice la siguiente información:

- niñ = {2,3}
- perr = {1,2}
- niñ \cap perr = {2,3} \cap {1,2} = {2}

Y como resultado tenemos que solamente el documento 2 cumple con los requisitos impuestos por la consulta.

En el caso de que la consulta sea “documentos en los que aparezca cualquiera de los dos términos”, entonces encontramos la unión de los resultados, en este caso todos los documentos.

Ahora, en vez de tener el índice en una tabla como la anterior, podemos crear una columna para cada documento e indicar en ella si una palabra está presente o no. Para ello, en vez de usar un “sí” o “no”, expresamos con 1 si la palabra está contenida en el documento y con 0 en caso contrario.

|Documento1|	Documento 2|	Documento 3|
|----------|-------------|-------------|
|perr|	1|	1|	0|
|corr|1	|0|	0|
|rapid|	1|	0|	1|
|niñ|	0	|1|	1|
|jug|	0	|1|	0|
|parque|	0	|1	|0|
|nad|	0|	0	|1|

Con el índice expresado en esta forma, ahora podemos representar a un documento usando su respectiva columna. Esto es un vector de términos. Si vemos la tabla de arriba, las filas expresan los términos y los documentos en los que se encuentran, mientras que si vemos las columnas nos damos cuenta de los términos que están en cada documento, todo en forma de vectores:

- Vector de “niñ”: [0 1 1]
- Vector del documento 3: [0 0 1 1 0 0 1]

Esta representación nos permite aplicar el  modelo de búsqueda booleano. Con él, podemos responder a búsquedas que usen operadores booleanos (AND, OR, NOT) usando simple lógica booleana. Por ejemplo, para la consulta del ejemplo de arriba “niño perro”, haríamos lo siguiente:

- niñ = [ 0 1 1 ]
- perr = [1 1 0]
- niñ AND perr = [0 1 1] AND [1 1 0] = [0 1 0]

El resultado indica que el único documento que cumple los requisitos es el de la segunda columna (la que tiene el 1), y por tanto, revisando en nuestro índice, es el documento 2.

Como se pude ver, la creación de un índice nos ayuda a encontrar documentos relevantes de forma rápida. Naturalmente, el modelo booleano es simple, y de seguro muchos de ustedes ya notaron sus debilidades. Por ejemplo, si buscamos solamente “perro”, fácilmente obtenemos como resultado los documentos 1 y 2, pero quizá uno sea mucho más relevante respecto a perros y otro vagamente los mencione, en cuyo caso necesitamos ordenar los resultados por relevancia. 
