# Desktop-приложение на ***С++***
## :hammer: *Стек технологий*
+ **Язык программирования:** С++
+ **Фреймворк:** Qt 5.15.3 (Widgets, Core, Gui)
+ **Сборка:** qmake / Qt Creator
+ **Компилятор:** GCC 4.2
+ **Формат данных:** JSON
______ 
## :rocket: *Как запустить проект*
### 1. Сборка через терминал (для Linux)
Для корректной работы приложения требуется настроенное окружение с указанными версиями инструментов.
1. Клонирование репозитория:
```bash
     git clone https://github.com/DashaKuracheva/Test_task.git Test_task_project
     cd Test_task_project
```
2. Создание директории сборки и переход в нее:
   Исходный код лежит в папке Test_Task, поэтому создавать папку сборк нужно там же:
```bash
     cd Test_Task
     mkdir build && cd build
```
3. Генерация файла сборки (Makefile) с помощью qmake:
```
     qmake ../Test_Task.pro CONFIG+=c++11
```  
4. Сборка проекта:
```
     make -j$(nproc)
```
5. Запуск приложения:
```
     ./Test_Task
``` 
### 2. Сборка через командную строку Windows (cmd)
Важное условие: qmake и mingw32-make должны быть прописаны в системных переменных (PATH), либо команды нужно выполнять в Qt Command Prompt.
1. Клонирование репозитория:
```bash
     git clone https://github.com/DashaKuracheva/Test_task.git Test_task_project
     cd Test_task_project
```
2. Создание директории сборки и переход в нее:
   Исходный код лежит в папке Test_Task, поэтому создавать папку сборк нужно там же:
```bash
     cd Test_Task
     mkdir build
     cd build
```
3. Генерация файла сборки (Makefile) с помощью qmake:
```
     qmake ../Test_Task.pro CONFIG+=release
```  
4. Сборка проекта:
```
     mingw32-make -j4
```
5. Сборка всех нужных .dll библиотек для запуска
```
     windeployqt release\Test_Task.exe
```
6. Запуск приложения:
```
     release\Test_Task.exe
```
#### :warning: *Примечание*
Если вы используете систему, где GCC 4.2 не является компилятором по умолчанию, добавьте следующие строки в ваш .pro файл перед сборкой:
```bash
     QMAKE_CXX = g++-4.2
     QMAKE_CC  = gcc-4.2
     CONFIG += c++11
```
