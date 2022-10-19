add_executable(task1 
    main.cpp

    defines.h

    ParserInput.cpp
    ParserInput.h

    Calculator.cpp
    Calculator.h

    BigInteger.h
)

target_include_directories(task1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(task1 PRIVATE Utils)

if (ENABLE_PARSER_EXCEPTIONS)
    target_compile_definitions(task1 PRIVATE "ENABLE_PARSER_EXCEPTIONS")
endif()
