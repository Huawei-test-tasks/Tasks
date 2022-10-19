add_executable(task3 
    main.cpp

    defines.h

    ParserInput.cpp
    ParserInput.h

    Calculator.cpp
    Calculator.h

    Treasure/Map.cpp
    Treasure/Map.h
    Treasure/Piece.cpp
    Treasure/Piece.h
    Treasure/PiecesStorage.cpp
    Treasure/PiecesStorage.h
)

target_include_directories(task3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(task3 PRIVATE Utils)

if (ENABLE_PARSER_EXCEPTIONS)
    target_compile_definitions(task3 PRIVATE "ENABLE_PARSER_EXCEPTIONS")
endif()
