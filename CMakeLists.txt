cmake_minimum_required(VERSION 3.10)
project(Protogame)

# Definir o padrão C++
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src/player)

# Encontrar todos os arquivos .cpp recursivamente
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Adicionar o executável
add_executable(game ${SOURCES})

# Adiciona o diretório 'src' ao caminho de inclusão
target_include_directories(game PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Linka outras bibliotecas necessárias
target_link_libraries(game PRIVATE raylib GL m pthread dl X11 Xrandr Xi Xcursor player)

# Incluir diretório de cabeçalhos
include_directories(${PROJECT_SOURCE_DIR}/src)
