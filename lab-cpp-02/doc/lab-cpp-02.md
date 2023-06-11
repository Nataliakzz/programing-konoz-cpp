# Лабораторна робота № 2

**Тема:** Потоки

## ВИМОГИ

**Розробник:** Коноз Наталія

**Завдання:** 

* використання функцій printf/scanf замінити на використання cin/cout;
* усі конкатенації рядків замінити на використання stringstream;
* усі строки типу char * замінити на std::string;
* замінити метод виводу інформації про об’єкт на метод, що повертає рядок-інформацію про об’єкт, який далі можна виводити на екран;

## Опис програми

### Функціональне призначення

Програма потрібна для визначення шкіл із безкоштовним навчанням та перегляду списків усіх шкіл.
Також можна дізнатися різну інформацію про дані школи та порівняти їх за кількістю студентів
###	Призначення та опис структури розроблених методів констант та змінних:

**Опис функцій** :

`int main ()`

Точка входу в програму. Демонстрація рішення. Повертає: код помилки (0)

`enum The_beginning_of_the_school_day`

Коли починається навчання standard (8:00), later_than_standard (8:30), second_shift (14:30)

**Аргументи:**

* standard            - 8:00
* later_than_standard - 8:30
* second_shift        - 14:30

`struct Head_of_the_institution`

Голова інституту

**Аргументи:**

* last_name - Прізвище         
* name      - Ім'я             
* mail      - Електронна пошта 

`struct School`

Список шкіл

**Аргументи:**

* IsEducationFree                       - Безкоштовне навчання чи ні 
* Name                                  - Назва закладу              
* Amount_of_students                    - Кількість студентів        
* Head_of_the_institution head          - Інформація про голову закладу             
* The_beginning_of_the_school_day Begin - Початок занять

`const List* List::Look_for_school_with_free_education() const;`

Шукає школи з безкоштовним навчанням

**Аргументи:**

Повертає структуру з описом шкіл, які мають безкоштовне навчання та відповідний розмір

`void List :: Sort_by_Amount_of_students();` 

Cортує елементи структури в порядку зростання за полем кількості учнів

`class List* Read_To_File(const char* Name_file);` 

Читає файл

**Аргументи:**

* Name_file        файл, який треба прочитати

Повертає структуру записану з даних файлу

`void List :: Write__File (const char *filename) const;`
Записує масив структур до файлу

`void List :: Print() const;`

Виводить масив структур на екран

`void List :: Add_Element (size_t pos, const School *school);` 
Додає елементи

**Аргументи:**

* pos       позиція
* school    клас полями школи

`void List :: Delete_Element (size_t pos);`
Видаляє елементи

**Аргументи:**

* pos       позиція

### Структура програми

```
.
├── doc
│   └──lab18.md
├── Doxyfile
├── Makefile
├── README.md
├── test
│   └── test.cpp
└── src
    ├── main.cpp
    ├── school.cpp
    ├── school.h
    ├── list.cpp
    └── list.h
```

### Приклад:

```
List schools:
--------------------------------------------------------------------------
 Name of the institution: Gryffindor
 Head of the institution: Godric Gryffindor, school_gryffindor@gmail.com
 Free education: +
 Amount of students:1250
 What time do classes start: 8:30
--------------------------------------------------------------------------

--------------------------------------------------------------------------
 Name of the institution: Slytherin
 Head of the institution: Salvador Slytherin, school_slytherin@gmail.com
 Free education: -
 Amount of students:1330
 What time do classes start: 8:00
--------------------------------------------------------------------------

--------------------------------------------------------------------------
 Name of the institution: Ravenclaw
 Head of the institution: Rowan Ravenclaw, school_ravenclaw@gmail.com
 Free education: +
 Amount of students:360
 What time do classes start: 14:00
--------------------------------------------------------------------------

Output from the read function:

--- Gryffindor, 1, 1250, Godric, Gryffindor, school_gryffindor@gmail.com, 1
Output from the read function:

--- Slytherin, 0, 1330, Salvador, Slytherin, school_slytherin@gmail.com, 0
Output from the read function:

--- Ravenclaw, 1, 360, Rowan, Ravenclaw, school_ravenclaw@gmail.com, 2
Output from the read function:

--- --------------------------------------------------------------------------


Schools with free education in ascending order:
List schools:
--------------------------------------------------------------------------
 Name of the institution: Ravenclaw
 Head of the institution: Rowan Ravenclaw, school_ravenclaw@gmail.com
 Free education: +
 Amount of students:360
 What time do classes start: 14:00
--------------------------------------------------------------------------

--------------------------------------------------------------------------
 Name of the institution: Gryffindor
 Head of the institution: Godric Gryffindor, school_gryffindor@gmail.com
 Free education: +
 Amount of students:1250
 What time do classes start: 8:30
--------------------------------------------------------------------------

```


## ВИСНОВКИ.
Отже, я навчилася перетворювати структури на класи та правильно формувати та викликати їх на мові С++.
