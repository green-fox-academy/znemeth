CREATE DATABASE IF NOT EXISTS property;
USE property;
CREATE table if not exists citta_property (
id int,
name varchar(255),
population int,
area int);

insert into citta_property
VALUES (id, "Bologna", 388367, 140), (id, "Parma", 194417, 261), (id, "Pisa", 89745, 185), (id, "Torino", 886837, 130), (id, "Alessandria", 93867, 204);

SELECT name, population/area
FROM citta_property
WHERE population/area
ORDER BY population/area DESC;

drop database property;