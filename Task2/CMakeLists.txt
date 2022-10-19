add_executable(task2 
    main.cpp

    defines.h

    ParserInput.cpp
    ParserInput.h

    Calculator.cpp
    Calculator.h
)

target_include_directories(task2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(task2 PRIVATE Utils)

if (ENABLE_PARSER_EXCEPTIONS)
    target_compile_definitions(task2 PRIVATE "ENABLE_PARSER_EXCEPTIONS")
endif()
