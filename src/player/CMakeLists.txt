add_library(player STATIC src/player.cpp)

# Adiciona o diretório 'include' ao caminho de inclusão
target_include_directories(player PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
