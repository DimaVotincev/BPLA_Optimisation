cmake_minimum_required(VERSION 3.10)

# Название проекта
project(BPLA_Optimisation VERSION 1.0 LANGUAGES CXX)

# Устанавливаем стандарт C++ (например, 17 или 20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем папку include, чтобы в main.cpp можно было писать #include "module1.h" 
# без указания полного пути
include_directories(include)

# Поиск всех исходных файлов (если их много)
# Если программисты добавляют свои .cpp, эта команда их подхватит
file(GLOB_RECURSIVE SOURCES "src/*.cpp" "main.cpp")

# Создаем исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCES})

# Если нужны сторонние библиотеки (например, Math или Threads), добавляем их тут
# find_package(Threads REQUIRED)
# target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)
