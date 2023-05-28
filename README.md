# Игра "Змейка" на C++ для курсовой работы в МИРЭА
____
# Запуск
  ## Готовый вариант:
  1. Скачайте [последний релиз](https://github.com/VeiTrr/tipkr/releases/download/v2.1/snake.zip)
  2. Распакуйте архив
  3. Проверьте файл FAQ
  4. Запустите файл Snake.exe
  
  ## Используя исходный код и Cmake:
  1. Скопируйте проект используя гит в пустую папку ```gh repo clone VeiTrr/tipkr```
  2. Скачайте [библиотеку SFML](https://www.sfml-dev.org/download/sfml/2.5.1/)
  3. Исправьте [строку 14 в файле CMakeLists.txt](https://github.com/VeiTrr/tipkr/blob/a19097092797cd39c45842fb18278535ecf991d7/CMakeLists.txt#L14)

  Пример:
    ```
    set(SFML_DIR "путь до папки с SFML/lib/cmake/SFML")
    ```
    
  4. Запустите сборку проекта используя Cmake
