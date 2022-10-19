
#include "ParserInput.h"
#include "Calculator.h"

int main(int argc, char *argv[])
{
    std::cout << std::unitbuf;

    try
    {
        ParserInputPtr parser = argc <= 1
                ? ParserInput::create(std::cin)
                : ParserInput::create(argv[1]);

        Calculator calc(parser->cases());

        for (size_t i = 0; i < calc.results().size(); ++i)
        {
            std::cout << "Case " << i + 1 << ":" << std::endl;
            std::cout << parser->cases()[i].A << " + " << parser->cases()[i].B << " = ";
            std::cout << calc.results()[i] << std::endl;

            std::cout << std::endl;
        }

    }  catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what();
        return 1;
    }


    return 0;
}
