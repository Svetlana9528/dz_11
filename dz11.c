#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

struct Date {
    int day;
    int month;
    int year;
};
struct Motorcycle {
    char brand[30];       // Марка мотоцикла
    int release_year;     // Год выпуска
    struct Date reg_date; // Дата регистрации
    int power;            // Мощность
    int has_damage;       // Наличие повреждений (1 - есть, 0 - нет)
};

int main() {
    setlocale(LC_ALL, ".UTF-8");
    printf("Вариант 20. Запись «Мотоцикл»\n\n");

    struct Motorcycle m1, m2, m3, m, temp;
    for (int i = 1; i <= 3; i++) {
        printf("\nВведите данные для мотоцикла №%d:\n", i);
        printf("Марка: "); scanf("%s", m.brand);
        printf("Год выпуска: "); scanf("%d", &m.release_year);
        printf("Дата регистрации (ДД ММ ГГГГ (через пробел)): ");
        scanf("%d %d %d", &m.reg_date.day, &m.reg_date.month, &m.reg_date.year);
        printf("Мощность (л.с.): "); scanf("%d", &m.power);
        printf("Наличие повреждений (1 - есть, 0 - нет): "); scanf("%d", &m.has_damage);

        // Раскладываем введенные данные из общей переменной m по местам m1, m2, m3
        if (i == 1) m1 = m;
        else if (i == 2) m2 = m;
        else if (i == 3) m3 = m;
    }

    if (m1.power < m2.power) { temp = m1; m1 = m2; m2 = temp; }
    if (m2.power < m3.power) { temp = m2; m2 = m3; m3 = temp; }
    if (m1.power < m2.power) { temp = m1; m1 = m2; m2 = temp; }

    printf("\n--- РЕЗУЛЬТАТ ОБРАБОТКИ (Поврежденные мотоциклы по убыванию мощности) ---\n");
    int found_any = 0;

    if (m1.has_damage == 1) {
        printf("Марка: %s | Мощность: %d л.с. | Год: %d | Регистрация: %02d.%02d.%04d\n",
            m1.brand, m1.power, m1.release_year, m1.reg_date.day, m1.reg_date.month, m1.reg_date.year);
        found_any = 1;
    }
    if (m2.has_damage == 1) {
        printf("Марка: %s | Мощность: %d л.с. | Год: %d | Регистрация: %02d.%02d.%04d\n",
            m2.brand, m2.power, m2.release_year, m2.reg_date.day, m2.reg_date.month, m2.reg_date.year);
        found_any = 1;
    }
    if (m3.has_damage == 1) {
        printf("Марка: %s | Мощность: %d л.с. | Год: %d | Регистрация: %02d.%02d.%04d\n",
            m3.brand, m3.power, m3.release_year, m3.reg_date.day, m3.reg_date.month, m3.reg_date.year);
        found_any = 1;
    }
    if (found_any == 0) {
        printf("Поврежденные мотоциклы не найдены.\n");
    }
    return 0;
}
