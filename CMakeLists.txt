cmake_minimum_required(VERSION 3.10)
project(TileTwister)

# On utilise le Standard C++17
set(CMAKE_CXX_STANDARD 17)

# On dit à CMake où trouver les fichiers .hpp (header)
include_directories(include)

# On liste précisément les fichiers sources à compiler
# À chaque fois que je créerais un nouveau fichier .cpp, je l'ajouterais ici.
add_executable(TileTwister 
    src/main.cpp
    src/Grid.cpp
)




