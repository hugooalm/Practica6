-- Creacion de la tabla
CREATE TABLE agenda(
    id int primary key,
    nombre varchar,
    apes varchar,
    telefono varchar,
    edad int,
    tipo_contacto varchar);

-- Insercion de datos
INSERT INTO agenda(id,nombre,apes,telefono,edad,tipo_contacto) VALUES (1,'Juan','Martin Perez','917897898','25','TRABAJO');
INSERT INTO agenda(id,nombre,apes,telefono,edad,tipo_contacto) VALUES (2,'Ana','Garcia Garcia','699887744','22','TRABAJO');
INSERT INTO agenda(id,nombre,apes,telefono,edad,tipo_contacto) VALUES (3,'Marta','Lopez Perez','677889900','54','FAVORITO');