# File

Написать программу для слежения за состоянием выбранного файла.

Ограничимся  двумя характеристиками:
1. Существует файл или нет;
2. Каков размер файла.

Программа будет выводить на консоль уведомление о произошедших изменениях в файле.
Существует несколько ситуаций для наблюдаемого файла

1. Файл существует , файл не  пустой - на экран выводится факт существования файла и его  размер.
2. Файл существует, файл был изменен - на экран выводится факт существования файла, сообщение о том что файл был изменен и его размер.  
3. Файл не существует - на экран выводится информация о том что файл не существует.

В главной программе создаем объект для отслеживания состояния конкретного файла/файлов,
Можно использовать бесконечный цикл, в котором будем обновлять состояние объекта/объектов  каждые 100 миллисекунд
(например так  std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );).

![uml](https://github.com/Alexksksss/File/blob/singleton/photo_2023-05-02_15-16-29.jpg)
