add_executable(task3 
	main.cpp
)

target_include_directories(task3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if (ENABLE_PARSER_EXCEPTIONS)
    target_compile_definitions(task3 PRIVATE "ENABLE_PARSER_EXCEPTIONS")
endif()
