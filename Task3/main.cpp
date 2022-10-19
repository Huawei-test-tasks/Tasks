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

        for (auto i : calc.results())
            std::cout << i << std::endl;

    }  catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what();
        return 1;
    }


    return 0;
}
