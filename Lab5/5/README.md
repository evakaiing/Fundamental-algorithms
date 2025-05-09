Необходимо реализовать функцию cdecl_translate, которая принимает строку (std::string) с кодом
объявления переменной на языке C и возвращает его текстовое описание на английском языке (std::string).
1. Входные и выходные данные:
● Функция принимает один аргумент — объект класса std::string, содержащий строку с объявлением
переменной на языке Cи (например, “char* b;”).
● Функция возвращает объект класса std::string, представляющий описание данного типа на
английском языке (в данном случае результат должен быть: “declare b as pointer to char”).
2. Требования к переводу:
● Функция должна распознавать стандартные типы данных, такие как int, char, float, double и
производные типы, такие как указатели (*), массивы ([]), функции (например, int f()), и типы со
скобками для группировки.
● Функция должна корректно переводить вложенные и комбинированные типы, например:
○ “char* a;” -> “declare a as pointer to char”
○ “int** b;” -> “declare b as pointer to pointer to int”
○ “float d[10];” -> “declare d as array of 10 elements of float”
○ “int (*func)();” -> “declare func as pointer to function returning int”
3. Проверка на корректность ввода:
● Функция должна проверять синтаксическую корректность строки объявления.
● Типы и идентификаторы переменных должны соответствовать правилам объявления для языка С:
○ Тип данных должен быть допустимым.
○ Название переменной может быть любым подходящим именем, начинающимся с буквы или
подчеркивания (_) и содержащим буквы, цифры, и подчеркивания.
● Если обнаружен некорректный ввод, функция должна вернуть строку с описанием ошибки и
указанием её позиции (например, Syntax error at position 4).
● Для разбора строки и проверки корректности лексем (типа данных, имени переменной, операторов
*, [], () и т.д.) допускается использование регулярных выражений.
Также реализуйте интерпретатор для тестирования функции cdecl_translate. Он должен получать путь к
файлу в качестве аргумента командной строки. Файл должен содержать тестовые строки — каждое
объявление переменной в новой строке. Ответы на запросы, в том числе описание ошибок также
необходимо печатать в стандартный поток вывода.
