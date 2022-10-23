#include "CLI.h"


void CLI::Run() {
    Info();

    while(true){
        std::string input;
        std::string res_input;

        while(true){
            if(res_input.empty()){
                std::cout << "> ";
            }
            else{
                std::cout << "... ";
            }

            std::getline(std::cin, input);
            input += '\n';

            if(input.find(';') != std::string::npos){
                res_input += ProcessInput(input);
                break;
            }
            res_input += input;
        }


        Lexer lexer(res_input);

        try{
            Parser parser(&lexer);
            parser.Parse();
        }
        catch (Exception& exception){
            std::cout<< exception.what() << std::endl;
        }
    }
}

std::string CLI::ProcessInput(std::string input) {
    std::string res_string;

    for(auto el: input){
        res_string += el;
        if(el == ';'){
            break;
        }
    }
    return res_string;
}

void CLI::Info() {
    std::cout << "---\tDB based on R-Tree\t---\n\n";
}
