# EDA_T1_2023
primero hay que crear las carpetas data y build, en data van los archivos enviados con la info a ordenar.
Para comnpilar usamos Cmake, por temas orden, se ejecuta en la carpeta build.
Luego usando make compilamos los archivos del programa.
el ejecutable requiere 2 argumentos: el archivo txt y que algoritmo usar, de la siguiente forma.
./sort_ruts ruts_xxxx.txt [primera letra en mayuscula del algoritmo] ; ejemplo: ./sort_ruts ruts_100.txt I //
finalmente los resultados se encuentran en la carpeta build con todos con sorted al final del nombre.
