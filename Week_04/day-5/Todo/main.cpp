#include <iostream>
#include <fstream>
#include <string>
//#include std::is_empty

int main(int argc, char *argv[])
{

    if (argc == 1) {
        std::cout << "Command Line Todo application\n"
                     "=============================\n"
                     "\n"
                     "Command line arguments:\n"
                     " -l   Lists all the tasks\n"
                     " -a   Adds a new task\n"
                     " -r   Removes a task\n"
                     " -c   Completes a task" << std::endl;
    } else if (argc == 2) {

        std::string firstarg(argv[1]);

        if (firstarg == "-l") {

            std::ifstream myfile;
            myfile.open("todo_empty.txt");

            std::string line;

            int numberOfLines = 0;
            while (getline(myfile, line)) {
                numberOfLines = numberOfLines + 1;
                std::cout << numberOfLines << " - " << line << '\n';
            }
            myfile.close();

            if (numberOfLines == 0) {
                std::cout << "No todos for today! :)" << std::endl;
            }
        }
    } else if (argc == 3) {

        std::string secondarg(argv[2]);
        std::string thirdarg(argv[3]);
        if (secondarg == "-a") {

        }

        return 0;
    }
}