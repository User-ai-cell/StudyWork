#include <iostream>
using namespace std;
#include <conio.h>
#include <string.h>
#include <windows.h>
char* filename = "reyisy.txt";
unsigned int n;// хранит кол-во рейсов в списке
//структура - время
struct time
{
    unsigned int hour, minute;
};
//структура - рейс 
struct reyis
{
    unsigned int numreyis, kolmest, svobmest;
    char punktnazn[30];
    struct time tv, tp;
    reyis* next;
};
reyis* head, * current, * tmp;
//функция отображения дополнительного меню
void showDopMenu()
{
    cout << "Что будем изменять?\n";
    cout << "1. Номер рейса\n2. Пункт назначения\n3. Время вылета\n4. Время прибытия\n"
        "5. Кол-во мест в салоне\n6. Кол-во свободных мест в салоне\n7. Ничего не менять!\n";
}
//функция отображения меню
void showMenu()
{
    cout << "Выберете действие:\n";
    cout << "1. Добавить новый рейс в список\n2. Вывести список рейсов на экран\n"
        "3. Отсортировать список рейсов по увеличению времени прибытия\n4. Вывести время отправления в указанный город\n"
        "5. Вывести наличие свободных мест на указанный рейс с указанным временем\n6. Вывести все рейсы за определённый час\n"
        "7. Вывести рейсы с самым большим и наименьшим относительным заполнением\n8. Удалить рейс\n"
        "9. Корректировка информации о определённом рейсе\n0. Выйти\n";
}
//начальная инициализация файла-списка рейсов
void initLib()
{
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp == NULL) //если файл не существует
    {
        n = 0;
        fp = fopen(filename, "w");  //создаем его
        if (fp == NULL)
        {
            cout << "Ошибка создания БД рейсов. Программа будет закрыта!";
            _getch();
            exit(1);
        }
        fwrite(&n, sizeof(int), 1, fp);   //заносим в начало нового файла количество рейсов, сейчас в нем - 0
    }
    else
        fread(&n, sizeof(n), 1, fp); //из существующего файла считываем количество рейсов
    fclose(fp);
}
//функция добовление нового рейса в конец файла
void addreyis()
{
    FILE* fp;
    reyis r;
    char ch;
    fp = fopen(filename, "r+");
    if (fp == NULL)
        cout << "Ошибка чтения данных из файла";
    else
    {
        do
        { //вводим информацию об очередном рейсе
            system("cls");
            cout << "Введите информацию об очередном рейсе\n";
            cout << "Номер рейса: ";
            cin >> r.numreyis;
            cout << "Пункт назначения: ";
            cin.sync();
            cin.getline(r.punktnazn, 29);
            cout << "Время вылета:\n";
            do
            {
                cout << "Чысы(от 0 до 23): ";
                cin >> r.tv.hour;
                if (r.tv.hour < 0 || r.tv.hour>23)
                    cout << "Вы ввели неправильное число!!!\n";
            }         while (r.tv.hour < 0 || r.tv.hour>23);
            do
            {
                cout << "Минуты(от 0 до 59): ";
                cin >> r.tv.minute;
                if (r.tv.minute < 0 || r.tv.minute>59)
                    cout << "Вы ввели неправильное число!!!\n";
            }         while (r.tv.minute < 0 || r.tv.minute>59);
            cout << "Время прибытия:\n";
            do
            {
                cout << "Чысы(от 0 до 23): ";
                cin >> r.tp.hour;
                if (r.tp.hour < 0 || r.tp.hour>23)
                    cout << "Вы ввели неправильное число!!!\n";
            }         while (r.tp.hour < 0 || r.tp.hour>23);
            do
            {
                cout << "Минуты(от 0 до 59): ";
                cin >> r.tp.minute;
                if (r.tp.minute < 0 || r.tp.minute>59)
                    cout << "Вы ввели неправильное число!!!\n";
            }         while (r.tp.minute < 0 || r.tp.minute>59);
            cout << "Общее число мест: ";
            cin >> r.kolmest;
            do
            {
                cout << "Кол-во свободных мест: ";
                cin >> r.svobmest;
                if (r.svobmest > r.kolmest)
                    cout << "Неправильный ввод! Чмсло свободных мест не может быть больше обшего кол-ва мест (" << r.kolmest << ")\n";
            }         while (r.svobmest > r.kolmest);
            n++;
            //заносим информацию об очередном рейсе в конец файла
            fseek(fp, 0, SEEK_END);
            fwrite(&r, sizeof(reyis), 1, fp);
            //заносим информацию о количестве рейсов в начало файла
            fseek(fp, 0, SEEK_SET);
            fwrite(&n, sizeof(int), 1, fp);
            cout << "Ввести данные о еще одном рейсе (д/н)?";
            ch = _getche();
        }     while (ch == 'Д' || ch == 'д'); //можно ввести данные о нескольких книгах
        fclose(fp);
    }
    cout << "\n";
}
//функция очищения списка книг
void clearLib()
{
    current = head;
    while (current)
    {
        tmp = current->next;
        delete current;
        current = tmp;
    }
    head = NULL;
    n = 0;
}
//функция загрузки данных о рейсах из  файла в список
void loadLib()
{
    FILE* fp;
    int i;
    fp = fopen(filename, "r");
    if (fp != NULL)
    {
        clearLib();
        fread(&n, sizeof(int), 1, fp);
        i = n;
        while (i != 0)
        {
            if (head != 0)
            {
                current->next = new reyis;
                current = current->next;
            }
            else
            {
                head = new reyis;
                current = head;
            }
            if (current)
            {
                fread(current, sizeof(reyis), 1, fp);
                current->next = 0;
            }
            i--;
        }
    }
    else
        cout << "Ошибка открытия файла с данными\n";
    fclose(fp);
}
//функция сохранения данных о рейсах из списка в файле 
void saveLib()
{
    FILE* fp;
    fp = fopen(filename, "w+");
    if (fp != NULL)
    {
        tmp = head;
        fwrite(&n, sizeof(int), 1, fp);
        while (tmp)
        {
            fwrite(tmp, sizeof(reyis), 1, fp);
            tmp = tmp->next;
        }
        fclose(fp);
    }
    else
        cout << "Ошибка открытия файла\n";
}
//функция вывода на экран списка рейсов
void showReyis()
{
    loadLib();
    if (n == 0)
        cout << "В списке нет рейсов!!!\n";
    else
    {
        cout << "Список существующих рейсов:\n";
        //вывод списка
        current = head;
        while (current != 0)
        {
            cout << "№ рейса: " << current->numreyis << "\nПункт назначения: " << current->punktnazn << "\nВремя вылета: " << current->tv.hour << " ч. "\
                << current->tv.minute << " минут" << "\nВремя прибытия: " << current->tp.hour << " ч. " << current->tp.minute << " минут"\
                << "\nОбщее число мест: " << current->kolmest << "\nКол-во свободных мест: " << current->svobmest;
            cout << "\n----------------------------------\n";
            current = current->next;
        }
    }
}
//функция сортировки по времени прибытия
void sortTimeP()
{
    unsigned int t1, t2;
    reyis* tek, * start;
    loadLib();
    if (n == 0)
        cout << "В списке нет рейсов!!!\n";
    else
    {
        start = head;        //метод вставки
        while (start->next)  //цикл по отсортированной части
        {
            t1 = start->tp.hour * 60 + start->tp.minute;
            t2 = start->next->tp.hour * 60 + start->next->tp.minute;
            tek = start->next; //следующий за отсортированной частью элемент
            reyis* k = head, * predk = k;
            while (k != tek && t1 < t2)//ищем место (сверху вниз до текущего)
            {
                predk = k; // запоминаем место вставки после predk
                k = k->next;            // перед k
            }
            if (k != tek)       //вставка нужна (если не дошли до текущего)
            {
                start->next = tek->next;//изъяли текущий
                tek->next = k;//втавляем перед k-тым
                if (k == head)
                    head = tek;  //вставляем в начало очереди
                else
                    predk->next = tek;   //вставляем после predk перед k
            }
            start = tek;
        }//конец сортировки списка
        saveLib();
        cout << "Список отсортирован!!!\n";
    }
}
//функция определения времени вылета в определённый город
void timeNazn()
{
    reyis r;
    FILE* fp;
    int k = 0, i;
    char punkt[30];
    if (n == 0)
        cout << "В списке нет рейсов!!!\n";
    else
    {
        cout << "Введите пункт назначения:";
        cin.sync();
        cin.getline(punkt, 29);
        fp = fopen(filename, "r");
        if (fp == NULL)
            cout << "Ошибка чтения данных из файла";
        else
        {
            cout << "В этот город:\n";
            fseek(fp, sizeof(int), SEEK_SET); //пропускаем целое число – количество книг в начале файла
            for (i = 0; i < n; i++) //перебираем все книги из файла
            {
                fread(&r, sizeof(reyis), 1, fp);
                //проверяем считанную из файла книгу на соответствие заданной характеристике поиска
                if (strcmp(punkt, r.punktnazn) == 0)
                {
                    cout << "летит рейс №: " << r.numreyis << " в " << r.tv.hour << " ч. " << r.tv.minute << " минут\n";
                    k = 1;
                }
            }
            if (k == 0)
                cout << "нет рейсов!!!\n";
            fclose(fp);
        }
    }
}
//функция проверки свободных мест на определённый рейс в определённое время
void nalMest()
{
    reyis r;
    FILE* fp;
    int i, k = 0, k1 = 0;
    time tim;
    char punkt[30];
    if (n == 0)
        cout << "В списке нет рейсов!!!\n";
    else
    {
        cout << "Введите пункт назначения:";
        cin.sync();
        cin.getline(punkt, 29);
        cout << "Введите время отправления:\n";
        do
        {
            cout << "Чысы(от 0 до 23): ";
            cin >> tim.hour;
            if (tim.hour < 0 || tim.hour>23)
                cout << "Вы ввели неправильное число!!!\n";
        }         while (tim.hour < 0 || tim.hour>23);
        do
        {
            cout << "Минуты(от 0 до 59): ";
            cin >> tim.minute;
            if (tim.minute < 0 || tim.minute>59)
                cout << "Вы ввели неправильное число!!!\n";
        }         while (tim.minute < 0 || tim.minute>59);
        fp = fopen(filename, "r");
        if (fp == NULL)
            cout << "Ошибка чтения данных из файла";
        else
        {
            fseek(fp, sizeof(int), SEEK_SET); //пропускаем целое число – количество книг в начале файла
            for (i = 0; i < n; i++)
            {
                fread(&r, sizeof(reyis), 1, fp);
                if (strcmp(punkt, r.punktnazn) == 0)
                {
                    if (tim.hour == r.tv.hour && tim.minute == r.tv.minute)
                    {
                        cout << "Рейс №: " << r.numreyis << "-Свободных мест: " << r.svobmest << "\n";
                        k = 1;
                    }
                    k1 = 1;
                }
            }
            if (k == 0 || k1 == 0)
                cout << "Таких рейсов нет!!!\n";
        }
        fclose(fp);
    }
}
//функция поиска всех рейсов за определённый час
void reyisHour()
{
    reyis r, * sort, stemp;
    sort = new reyis[n];
    FILE* fp;
    int i, j = 0, stime1, stime2, k;
    time tim;
    if (n == 0)
        cout << "В списке нет рейсов!!!\n";
    else
    {
        cout << "Введите время, и будут найдены рейсы, отправляющиеся в течении следующего часа:\n";
        do
        {
            cout << "Чысы(от 0 до 23): ";
            cin >> tim.hour;
            if (tim.hour < 0 || tim.hour>23)
                cout << "Вы ввели неправильное число!!!\n";
        }         while (tim.hour < 0 || tim.hour>23);
        do
        {
            cout << "Минуты(от 0 до 59): ";
            cin >> tim.minute;
            if (tim.minute < 0 || tim.minute>59)
                cout << "Вы ввели неправильное число!!!\n";
        }         while (tim.minute < 0 || tim.minute>59);
        fp = fopen(filename, "r");
        if (fp == NULL)
            cout << "Ошибка чтения данных из файла";
        else
        {
            fseek(fp, sizeof(int), SEEK_SET); //пропускаем целое число – количество книг в начале файла
            for (i = 0; i < n; i++)
            {
                fread(&r, sizeof(reyis), 1, fp);
                if (r.tv.hour == tim.hour && r.tv.minute >= tim.minute)
                {
                    sort[j] = r;
                    j++;
                }
                else
                    if (r.tv.hour == tim.hour + 1 && r.tv.minute <= tim.minute)
                    {
                        sort[j] = r;
                        j++;
                    }
            }
            if (j == 1)
            {
                cout << "За время c " << tim.hour << " ч. " << tim.minute << " минут до " << tim.hour + 1 << " ч. " << tim.minute << "минут:\n";
                cout << "№ рейса:" << sort[j - 1].numreyis << "\nПункт назначения:" << sort[j - 1].punktnazn << "\nВремя вылета:"\
                    << sort[j - 1].tv.hour << " ч. " << sort[j - 1].tv.minute << " минут" << "\nВремя прибытия:" << sort[j - 1].tp.hour\
                    << " ч. " << sort[j - 1].tp.minute << " минут" << "\nОбщее число мест:" << sort[j - 1].kolmest << "\nКол-во свободных мест:"\
                    << sort[j - 1].svobmest << "\n";
            }
            else
            {
                for (k = j - 1; k > 0; k--)
                    for (i = 0; i < k; i++)
                    {
                        stime1 = sort[i].tv.hour * 60 + sort[i].tv.minute;
                        stime2 = sort[i + 1].tv.hour * 60 + sort[i + 1].tv.minute;
                        if (stime1 > stime2)
                        {
                            stemp = sort[i + 1];
                            sort[i + 1] = sort[i];
                            sort[i] = stemp;
                        }
                    }
                cout << "За время c " << tim.hour << " ч. " << tim.minute << " минут до " << tim.hour + 1 << " ч. " << tim.minute\
                    << " минут по возростанию времени вылета:\n";
                for (int i = 0; i < j; i++)
                    cout << "№ рейса:" << sort[i].numreyis << "\nПункт назначения:" << sort[i].punktnazn << "\nВремя вылета:"\
                    << sort[i].tv.hour << " ч. " << sort[i].tv.minute << " минут" << "\nВремя прибытия:" << sort[i].tp.hour << " ч. "\
                    << sort[i].tp.minute << " минут" << "\nОбщее число мест:" << sort[i].kolmest << "\nКол-во свободных мест:"\
                    << sort[i].svobmest << "\n";
                delete[]sort;
            }
            fclose(fp);
        }
    }
}
//функция определения относительного заполнения
void otnosZap()
{
    double otnzap = 0, minzap = 1, maxzap = 0;
    int i, min = 0, max = 0;
    FILE* fp;
    reyis r, rmin, rmax;
    if (n == 0)
        cout << "В списке нет рейсов!!!\n";
    else
    {
        fp = fopen(filename, "r");
        if (fp == NULL)
            cout << "Ошибка чтения данных из файла";
        else
        {
            fseek(fp, sizeof(int), SEEK_SET); //пропускаем целое число – количество книг в начале файла
            for (i = 0; i < n; i++)
            {
                fread(&r, sizeof(reyis), 1, fp);
                otnzap = (double)(r.kolmest - r.svobmest) / r.kolmest;
                if (otnzap < minzap)
                {
                    minzap = otnzap;
                    rmin = r;
                }
                if (otnzap > maxzap)
                {
                    maxzap = otnzap;
                    rmax = r;
                }
            }
            cout << "Рейс с самым малым относительным заполнением\n";
            cout << "Номер рейса:" << rmin.numreyis << "\nПункт назначения:" << rmin.punktnazn << "\nВремя вылета:" << rmin.tv.hour << " ч. "\
                << rmin.tv.minute << " минут" << "\nВремя прибытия:" << rmin.tp.hour << " ч. " << rmin.tp.minute << " минут"\
                << "\nОбщее число мест:" << rmin.kolmest << "\nКол-во свободных мест:" << rmin.svobmest << "\nOтносительное заполнение:"\
                << minzap << "\n";
            cout << "Рейс с самым большим относительным заполнением\n";
            cout << "Номер рейса:" << rmax.numreyis << "\nПункт назначения:" << rmax.punktnazn << "\nВремя вылета:" << rmax.tv.hour << " ч. "\
                << rmax.tv.minute << " минут" << "\nВремя прибытия:" << rmax.tp.hour << " ч. " << rmax.tp.minute << " минут"\
                << "\nОбщее число мест:" << rmax.kolmest << "\nКол-во свободных мест:" << rmax.svobmest << "\nOтносительное заполнение:"\
                << maxzap << "\n";
            fclose(fp);
        }
    }
}
//функция удаления информации о рейсе из файла
void delReyis()
{
    int i, numReyis, nNew = 0;
    reyis r;
    FILE* fp, * tmp;
    if (n == 0)
        cout << "В списке нет рейсов!!!\n";
    else
    {
        cout << "Введите номер удаляемого рейса: ";
        cin >> numReyis;
        fp = fopen(filename, "r+");
        tmp = fopen("tmp.dat", "w+");
        fwrite(&nNew, sizeof(int), 1, tmp);
        if (fp == NULL)
            cout << "Ошибка чтения данных из файла";
        else
        {
            fseek(fp, sizeof(int), SEEK_SET);
            for (i = 0; i < n; i++)
            {
                fread(&r, sizeof(reyis), 1, fp);
                if (r.numreyis != numReyis)//если номер рейса не совпадает с заданным - копируем во временный файл
                {
                    fwrite(&r, sizeof(reyis), 1, tmp);
                    nNew++;
                }
            }
            if (nNew < n) //если скопировано рейсов меньше, чем было в исходном 
                //файле - значит какие-то рейсы в новый файл не по
                //пали, т.е. они удалены
            {
                cout << "Рейс(ы) удален(ы)\n";
                n = nNew;
                fseek(tmp, 0, SEEK_SET);
                fwrite(&n, sizeof(int), 1, tmp);
            }
            else
                cout << "Рейсов с таким номером нет в списке\n";
            fclose(fp);
            fclose(tmp);
            remove(filename);    //удаляем исходный файл 
            rename("tmp.dat", filename);
        }
    }
}
//функция корректировки информации о рейсе
void correctReyis()
{
    int i, numReyis, f = 0;
    reyis r;
    char ch = '0', ch2;
    FILE* fp, * tmp;
    if (n == 0)
        cout << "В списке нет рейсов!!!\n";
    else
    {
        fp = fopen(filename, "r+");
        tmp = fopen("tmp.dat", "w+");
        fwrite(&n, sizeof(int), 1, tmp);
        if (fp == NULL)
            cout << "Ошибка чтения данных из файла";
        else
        {
            cout << "Введите номер рейса, с которым мы будем работать: ";
            cin >> numReyis;
            fseek(fp, sizeof(int), SEEK_SET);
            for (i = 0; i < n; i++)
            {
                fread(&r, sizeof(reyis), 1, fp);
                if (r.numreyis != numReyis)
                {
                    fwrite(&r, sizeof(reyis), 1, tmp);
                }
                else
                {
                    cout << "Найден соответствующий рейс\n";
                    showDopMenu();
                    ch = _getch();
                    system("cls");
                    while (ch != '7')
                    {
                        switch (ch)     //в зависимости от выбора пользователя вызываем функцию
                        {
                        case '1':
                        {
                            int newNum;
                            cout << "Введите новый номер для этого рейса:";
                            cin >> newNum;
                            r.numreyis = newNum;
                        }; break;
                        case '2':
                        {
                            char newPunkt[30];
                            cout << "Введите новый пункт назначения для этого рейса:";
                            cin.sync();
                            cin.getline(newPunkt, 29);
                            strcpy(r.punktnazn, newPunkt);
                        }; break;
                        case '3':
                        {
                            time tim;
                            cout << "Введите новое время вылета:\n";
                            do
                            {
                                cout << "Чысы(от 0 до 23): ";
                                cin >> tim.hour;
                                if (tim.hour < 0 || tim.hour>23)
                                    cout << "Вы ввели неправильное число!!!\n";
                            }                                 while (tim.hour < 0 || tim.hour>23);
                            do
                            {
                                cout << "Минуты(от 0 до 59): ";
                                cin >> tim.minute;
                                if (tim.minute < 0 || tim.minute>59)
                                    cout << "Вы ввели неправильное число!!!\n";
                            }                                 while (tim.minute < 0 || tim.minute>59);
                            r.tv.hour = tim.hour;
                            r.tv.minute = tim.minute;
                        }; break;
                        case '4':
                        {
                            time tim;
                            cout << "Введите новое время прибытия:\n";
                            do
                            {
                                cout << "Чысы(от 0 до 23): ";
                                cin >> tim.hour;
                                if (tim.hour < 0 || tim.hour>23)
                                    cout << "Вы ввели неправильное число!!!\n";
                            }                                 while (tim.hour < 0 || tim.hour>23);
                            do
                            {
                                cout << "Минуты(от 0 до 59): ";
                                cin >> tim.minute;
                                if (tim.minute < 0 || tim.minute>59)
                                    cout << "Вы ввели неправильное число!!!\n";
                            }                                 while (tim.minute < 0 || tim.minute>59);
                            r.tp.hour = tim.hour;
                            r.tp.minute = tim.minute;
                        }; break;
                        case '5':
                        {
                            int newColmest;
                            cout << "Введите новое кол-во мест в салоне: ";
                            cin >> newColmest;
                            r.kolmest = newColmest;
                        }; break;
                        case '6':
                        {
                            int newSvobmest;
                            do
                            {
                                cout << "Введите новое кол-во свободных мест в салоне: ";
                                cin >> newSvobmest;
                                if (newSvobmest > r.kolmest)
                                    cout << "Неправильный ввод! Чмсло свободных мест не может быть больше обшего кол-ва мест (" << r.kolmest << ")\n";
                            }                                 while (newSvobmest > r.kolmest);
                            r.svobmest = newSvobmest;
                        }; break;
                        default: cout << "Неверный ввод!!!\n";
                        }
                        f = 1;
                        cout << "Ещё будем что-то изменять (д/н)?";
                        ch2 = _getche();
                        cout << "\n";
                        if (ch2 == 'Д' || ch2 == 'д')
                        {
                            system("cls");
                            showDopMenu();
                            ch = _getch();
                        }
                        else
                            ch = '7';
                    }
                    fwrite(&r, sizeof(reyis), 1, tmp);
                }
            }
            if (f == 0)
                cout << "Рейса с таким номером нет!!!\n";
            fclose(fp);
            fclose(tmp);
            remove(filename);    //удаляем исходный файл 
            rename("tmp.dat", filename);
        }
    }
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    char ch = '10';
    initLib();//сделано
    showMenu();    //выводим меню
    ch = _getch();
    while (ch != '0')
    {
        switch (ch)     //в зависимости от выбора пользователя вызываем функцию
        {
        case '1': addreyis(); break;// проверил
        case '2': showReyis(); break;// проверил
        case '3': sortTimeP(); break;// проверил
        case '4': timeNazn(); break;// проверил
        case '5': nalMest(); break;// проверил
        case '6': reyisHour(); break;// проверил
        case '7': otnosZap(); break;// проверил
        case '8': delReyis(); break;// проверил
        case '9': correctReyis(); break;
        default: cout << "Неверный ввод!!!\n";
        }
        cout << "Нажмите любую клавишу...";
        _getch();
        system("cls");
        showMenu();
        ch = _getch();
    }
    return 0;
}