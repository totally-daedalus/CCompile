# include <iostream>
# include <string>

void start(std::string compileCommand, std::string executeCommand) {
    int returnCode = system(compileCommand.c_str());

    if(returnCode == 0) {
        system(executeCommand.c_str());
    }
}

int main(int argc, char** argv) {
    std::string compiler = "g++";
    std::string executableName = "temp";
    std::string executeCommand = "./" + executableName;
    std::string compileCommand = compiler + " ";

    std::string filename;

    for(int i = 1; i < argc; i++) {
        filename = argv[i];
        compileCommand += filename + " ";
    }

    compileCommand = compileCommand +  "-o " + executableName;
    
    start(compileCommand, executeCommand);
    system("rm temp");
}
