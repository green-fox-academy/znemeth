#include <iostream>
#include <fstream>
#include <string>

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
            myfile.open("todo.txt");

            std::string line;

            while (getline(myfile, line)) {
                std::cout << line << '\n';
            }
            myfile.close();
        }

        return 0;
    }
}