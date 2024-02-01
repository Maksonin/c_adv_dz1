#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void task1 ();
void task2 ();
void task3 ();
void task4 ();

int main () {
    task3();
}

/* На стандартном потоке ввода задается натуральное число N (N > 0), после которого следует
последовательность из N целых чисел.
На стандартный поток вывода напечатайте, сколько раз в этой последовательности встречается максимум.
Указание: использовать массивы запрещается.
 */
void task1 () {
    int n = 0;
    scanf("%d", &n);

    int tmp = 0;
    int max = 0;
    int colMax = 0;
    
    while(n){
        scanf("%d", &tmp);
        if(tmp == max)
            colMax++;
        else if (tmp > max) {
            max = tmp;
            if(colMax > 0)
                colMax = 0 + 1;
            else
                colMax++;
        }

        n--;
    }

    printf("\nmax = %d, colMax = %d\n", max, colMax);
}

// функция для вывода двоичного вида числа number в количестве бит равным bite
void printBin(uint64_t number, uint8_t bite){
    for(int i = 0; i < bite; i++){
        printf("%d", (number >> i) & 1);
    }
}

/*
На вход программе подается беззнаковое 32-битное целое число N. Требуется изменить значения всех
битов старшего байта числа на противоположные и вывести полученное таким образом число.
*/
void task2(){
    union
    {
        uint64_t f;
        struct
        {
            uint8_t r1;
            uint8_t r2;
            uint8_t r3;
            uint8_t r4;
        } fields;
    } number;

    printf("32bit number - ");
    scanf("%lld", &number.f);

    printf("%lld\n", number.f);
    printf("1 byte - %d\n", number.fields.r1);
    printf("2 byte - %d\n", number.fields.r2);
    printf("3 byte - %d\n", number.fields.r3);
    printf("4 byte - %d\n", number.fields.r4);

    printBin(number.f, 32);

    number.fields.r4 = ~ number.fields.r4;

    printf("\n%lld\n", number.f);
    printf("1 byte - %d\n", number.fields.r1);
    printf("2 byte - %d\n", number.fields.r2);
    printf("3 byte - %d\n", number.fields.r3);
    printf("4 byte - %d\n", number.fields.r4);

    printBin(number.f, 32);
}

/*
Преподаватели Geek Brains создали набор, содержащий N (1 ≤ N ≤ 1 000 000) натуральных чисел, не
превосходящих 1 000 000. Известно, что ровно одно число в этом наборе встречается один раз, а остальные
— ровно по два раза. Помогите им найти это число. Входные данные: в первой входной строке вводится
число N, затем по одному числу в строке вводятся N натуральных чисел, не превосходящих 2 000 000 000.
Выходные данные: ваша программа должна определить число, встречающееся один раз, и вывести его на
экран. Использовать массивы запрещается
*/
void task3(){
    int n = 0;
    printf("n = ");
    scanf("%d", &n);

    int tmp = 0;
    int single = 0;
    int GBcollection[n];
    int i = 0;
    
    while(i < n){
        printf("str[%d] = ",i);
        scanf(" %d", &GBcollection[i]);

        i++;
    }

    for(int i = 0; i < n; i++){
        for(int i1 = 0; i1 < n; i1++){
            if((GBcollection[i] == GBcollection[i1]) && (i1 != i)){
                break;
            }
            if((i1 == i) && (i1 != n-1)){
                continue;
            }
            if(i1 == n-1)
                single = GBcollection[i];
        }
    }

    printf("\n-> %d\n", single);
}

/*
На стандартном потоке ввода задается целое неотрицательное число N и последовательность допустимых
символов в кодировке ASCII, оканчивающаяся точкой. Допустимые символы – латинские буквы 'a' ... 'z', 'A' ... 'Z' и
пробел. Требуется закодировать латинские буквы ('a' ... 'z', 'A' ... 'Z') шифром Цезаря, пробелы вывести без
изменения. Число N задает сдвиг в шифре. Шифр Цезаря заключается в следующем преобразовании. Пусть
буквы алфавита пронумерованы от 0 до K - 1, где K - число символов в алфавите. Тогда символ с номером n
кодируется символом с номером p = (n + N) mod K (mod - операция взятия остатка). На стандартном потоке
вывода напечатать зашифрованное сообщение, оканчивающееся точкой. Преобразование требуется выполнять
независимо для заглавных и строчных латинских букв.
*/
void task4(){
    printf("Put key - ");
    int n = 0;
    scanf("%d", &n);

    printf("Put string!\n");
    char tmp = 0;
    int len = 1;
    char *cezar = malloc(sizeof(char) * len);
    int i = 0;

    while(tmp != '.'){
        scanf("%c", &tmp);

        if(tmp != '.')
            cezar[i] = (tmp + n) % 126; // 126 - число символов в кодировке ASCII - 1
        else
            cezar[i] = tmp;

        len++;
        cezar = realloc(cezar, sizeof(char) * len);
        i++;
    }

    printf("\n%s\n", cezar);
}