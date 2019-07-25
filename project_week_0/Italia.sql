/*DROP database ITALIA;*/
CREATE DATABASE Italia;
USE Italia;

CREATE TABLE citta (
ID INT auto_increment,
NAME_CITTA VARCHAR(255),
POPULATION INT,
PRIMARY KEY (ID));

INSERT INTO citta (ID, NAME_CITTA, POPULATION)
VALUES (id, "Padova", 180000), (id,"Bologna", 200000), (id,"Venezia", 300000), (id,"Udine", 100000);

SELECT name_citta, population
FROM citta
WHERE population >= 80000
ORDER BY population DESC;
DROP database ITALIA;