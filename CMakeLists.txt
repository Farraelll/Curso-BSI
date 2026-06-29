cmake_minimum_required(VERSION 3.20)
project(CursoBSI C)

# Busca todos os arquivos main.c dentro de subpastas
file(GLOB_RECURSE MAIN_FILES "*/main.c")

foreach(MAIN_FILE ${MAIN_FILES})
    # Pega o diretório onde o main.c está localizado
    get_filename_component(DIR_PATH ${MAIN_FILE} DIRECTORY)

    # Cria um nome de target baseado no caminho relativo para evitar conflitos
    file(RELATIVE_PATH REL_DIR ${CMAKE_SOURCE_DIR} ${DIR_PATH})
    string(REPLACE "/" "_" TARGET_NAME "${REL_DIR}")
    string(REPLACE " " "_" TARGET_NAME "${TARGET_NAME}")

    # Inclui todos os arquivos .c da mesma pasta do main.c
    file(GLOB TARGET_SOURCES "${DIR_PATH}/*.c")

    # Cria um executável independente para cada exercício
    add_executable(${TARGET_NAME} ${TARGET_SOURCES}  "Estruturas de Dados/")

    # Biblioteca matemática necessária para funções como sqrt no GCC/Clang
    if(UNIX)
        target_link_libraries(${TARGET_NAME} m)
    endif()
endforeach()