#include "database_digit_reading.h"

void databaseDigitReading(std::string imagePath, int digitValue)
{
	sqlite3 *database;
	char *errorMessage = 0;
	int errorCode;
	const char *sql;

	errorCode = sqlite3_open("digit_reading.db", &database);

	if (errorCode) {
		std::cout << "Can't open database!" << std::endl;
		std::cin.get();

		return;
	}
	
	sql = "CREATE TABLE DIGIT_READING("  \
		"IMAGE_PATH	TEXT	PRIMARY KEY	NOT NULL,"	\
		"DIGIT_NUMBER	INT	NOT NULL);";

	sqlite3_exec(database, sql, 0, 0, &errorMessage);

	std::string command;
	command = "INSERT INTO DIGIT_READING (IMAGE_PATH, DIGIT_NUMBER) "  \
		"VALUES ('" + imagePath + "', " + std::to_string(digitValue) + ");";

	sql = command.c_str();
	errorCode = sqlite3_exec(database, sql, 0, 0, &errorMessage);

	if (errorCode) {
		std::cout << "The data can't be saved or already exist!" << std::endl;
		std::cout << errorMessage << std::endl;
		std::cin.get();
	}
	
	sqlite3_close(database);
}
