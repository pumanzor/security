##NoSQL

NoSQL – "not only SQL” es una categoría general de sistemas de gestión de bases de datos que difiere de los Sistemas Manejadores 
de Bases de Datos – RDBMS, en aspectos como:

    No tienen schemas, no permiten JOINs, no intentan garantizar ACID y escalan horizontalmente.
    Tanto las bases de datos NoSQL como las relacionales son tipos de Almacenamiento Estructurado. 
    
La principal diferencia radica en cómo guardan los datos (por ejemplo, almacenamiento de un recibo):

- En una RDBMS, la información a persistir se tendría que partir en diferentes tablas y luego, en la capa de aplicación, usar un lenguaje de programación que realice el respectivo mapeo para transformar estos datos en objetos de la vida real [2].
- En NoSQL, simplemente se guarda el recibo. Dado que NoSQL es libre de schemas, no se debe diseñar tablas y su estructura por adelantado. 

De igual forma, identifica algunas características principales, tales como:

- Fáciles de usar en clústeres de balanceo de carga convencionales, debido a que facilitan escalabilidad horizontal.
- Guardan datos persistentes (no sólo cachés).
- No tienen esquemas fijos y permite la migración del esquema sin tener que ser reiniciadas o paradas.
- Suelen tener un sistema de consultas propio en vez de usar un lenguaje de consultas estándar.
- Tienen propiedades ACID en un nodo del clúster y son “eventualmente consistentes” en el clúster. 
