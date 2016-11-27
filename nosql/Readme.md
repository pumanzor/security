##NoSQL

NoSQL – "not only SQL” es una categoría general de sistemas de gestión de bases de datos que difiere de los Sistemas Manejadores 
de Bases de Datos – RDBMS, en aspectos como:

    No tienen schemas, no permiten JOINs, no intentan garantizar ACID y escalan horizontalmente.
    Tanto las bases de datos NoSQL como las relacionales son tipos de Almacenamiento Estructurado. 
    
    
El 95% de la información que se está generando actualmente en la red se corresponde con información no estructurada y las bases de datos relacionales tradicionales no son adecuadas para el manejo de esta información. Los nuevos sistemas de gestión de datos desarrollados para su manejo, que utilizan infraestructuras de supercomputación altamente distribuidas, reciben habitualmente el nombre de NoSQL. Este curso explorará algunos ejemplos significativos de las principales taxonomías de los almacenes de datos NoSQL: de clave-valor (Cassandra), orientados a documentos (CouchDB) o grafos (Neo4j). 


    
La principal diferencia radica en cómo guardan los datos (por ejemplo, almacenamiento de un recibo):

- En una RDBMS, la información a persistir se tendría que partir en diferentes tablas y luego, en la capa de aplicación, usar un lenguaje de programación que realice el respectivo mapeo para transformar estos datos en objetos de la vida real [2].
- En NoSQL, simplemente se guarda el recibo. Dado que NoSQL es libre de schemas, no se debe diseñar tablas y su estructura por adelantado. 

De igual forma, identifica algunas características principales, tales como:

- Fáciles de usar en clústeres de balanceo de carga convencionales, debido a que facilitan escalabilidad horizontal.
- Guardan datos persistentes (no sólo cachés).
- No tienen esquemas fijos y permite la migración del esquema sin tener que ser reiniciadas o paradas.
- Suelen tener un sistema de consultas propio en vez de usar un lenguaje de consultas estándar.
- Tienen propiedades ACID en un nodo del clúster y son “eventualmente consistentes” en el clúster. 

Por otro lado, los sistemas relacionales operan bajo las Propiedades ACID definidas para las transacciones. En su defecto, las bases de datos NoSQL son repositorios de almacenamiento más optimistas, y siguen el Modelo BASE:

* Basic Availability: el almacén funciona la mayoría del tiempo incluso ante fallos gracias al almacenamiento distribuido y replicado.
* Soft-sate: los almacenes no tienen porque ser consistentes ni sus réplicas en todo momento.
* Eventual consistency: la consistencia se da eventualmente. 

Hace años atras en un primer intento para conceptualizar el término NoSQL se definió como una nueva generación de sistemas de bases de datos que tenía al menos una de las siguientes propiedades:

- El modelo de datos subyacente no es relacional.
- Los sistemas están diseñados desde el principio como escalable horizontalmente y verticalmente.
- El sistema es de código abierto.
- El sistema es esquema-libre o sólo tiene restricciones de esquema suaves.
- Debido a la arquitectura distribuida, el sistema admite un método de replicación de datos simple.
- El sistema proporciona una API sencilla.
- El sistema generalmente utiliza un modelo de consistencia diferente. 

El término NoSQL se debe enfocar como un conjunto de características para diferentes almacenes de datos, sin un dominio homogéneo. Actualmente existen diferentes categorías de frameworks NoSQL, dentro de los cuales se identifican:

- Llave/ Valor: almacena datos en pares llave / valor. Son muy eficientes por su desempeño y alta escalabilidad, pero son difíciles de consultar y de implementar problemas del mundo real-
- Columnas: almacenan datos en estructuras tabulares, pero las columnas pueden variar en el tiempo y cada fila puede tener solamente un subconjunto de columnas. 
- Orientado a Documentos: tal como llave / valor, pero permiten almacenar mas valores por cada llave. Un valor tipo documento podría ser por ejemplo un XML o un fragmento JSON. Este es un buen paradigma para programadores dado su facilidad, especialmente por el uso de lenguajes de script, implementa mapeo uno a uno para relaciones entre los objetos de código y los objetos (documentos) en el sistema. 
- Grafos: almacena objetos y relaciones en nodos y vértices de un grafo. Para situaciones que se ajusten a este modelo, como datos jerárquicos, esta solución podría ser más rápida que las otras.

En la actualidad las bases de datos NoSQL se emplean para el almacenamiento de datos que manejan un gran volumen, no estructurados, sobre aplicaciones web, y ya se encuentran implementaciones en sistemas de búsquedas como Amazon, Google, Yahoo o Facebook.
