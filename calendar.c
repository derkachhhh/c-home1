#include <stdio.h>

int days_in_month(int m, int y) {
    if (m == 2) {
        return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28;
    }
    return (m == 4 || m == 6 || m == 9 || m == 11) ? 30 : 31;
}

int first_day_of_month(int m, int y) {
    int adjust = (14 - m) / 12;
    y -= adjust;
    m += 12 * adjust - 2;
    return (1 + (31 * m) / 12 + y + (y / 4) - (y / 100) + (y / 400)) % 7;
}

void display_calendar(int m, int y) {
    printf("Календар на %02d/%d\n", m, y);
    printf("Нд Пн Вт Ср Чт Пт Сб Нд\n");

    int days = days_in_month(m, y);
    int start_day = first_day_of_month(m, y);

    for (int i = 0; i < start_day; i++) {
        printf("   "); // Відступи
    }
    
    for (int day = 1; day <= days; day++) {
        printf("%2d ", day);
        if ((day + start_day) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int month, year;
    printf("Введіть місяць (1-12): ");
    scanf("%d", &month);
    if (month < 1 || month > 12) {
        printf("Неправильний місяць. Спробуйте ще раз.\n");
        return 1;
    }
    printf("Введіть рік: ");
    scanf("%d", &year);
    display_calendar(month, year);
    return 0;
}
