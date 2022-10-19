add_executable(task2
	main.cpp
)

target_include_directories(task2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if (ENABLE_PARSER_EXCEPTIONS)
    target_compile_definitions(task2 PRIVATE "ENABLE_PARSER_EXCEPTIONS")
endif()
