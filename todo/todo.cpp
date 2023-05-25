// todo.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
# include <iomanip> // для даты
// для года и времени
#include <stdio.h>
#include <time.h>
#include <string>
#include "windows.h"



using namespace std;



struct My_Time {
private:
    int day, month, year,hour,minutes;
public:
    void create(int day,int month, int year,int hour,int minutes) {
        this->day = day;
        this->month = month;
        this->year = year;
        this->hour = hour;
        this->minutes = minutes;

    }
    void print_time() {
        string mName = "";
        
        if (month == 1)
        { mName = "Января";}

        else if (month == 2)
        { mName = "Февраля";}

        else if (month == 3)
        { mName = "Марта";}

        else if (month == 4)
        { mName = "Апреля";}

        else if (month == 5)
        {mName = "Мая";}

        else if (month == 6)
        { mName = "Июня";}

        else if (month == 7)
        {mName = "Июля";}

        else if (month == 8)
        {mName = "Августа";}

        else if (month == 9)
        {mName = "Сентября";}

        else if (month == 10)
        {mName = "Октября";

        }else if (month == 11)
        {mName = "Ноября";}

        else if (month == 12)
        {mName = "Декабря";}

        cout << "\n " << day << " " << mName << " " << year <<" "<<hour<<":"<<minutes;
    }
    int getDay() {
        return day;
    }
    int getMonth() {
        return month;
    }
};
struct Task {
private:
    int priority;
    int id;
    string title;
    string desc;
    My_Time deadline;

public:
    void set(int priority, int id, string title, My_Time deadline) {
        this->priority = priority;
        this->id = id;
        this->title = title;
        this->deadline = deadline;
    }
    void setTaskList(int priority, vector <Task> list_all, string title, My_Time deadline) {
        this->priority = priority;
        this->id = list_all.size();
        this->title = title;
        this->deadline = deadline;
    }
    void print(int indexArr) {
        string priorityBadge = "";
        if (priority == 1)
        {
            priorityBadge = "/Срочное/";
        }
        else if (priority == 2)
        {
            priorityBadge = "/Важное/";
        }
        else if (priority == 3)
        {
            priorityBadge = "/Неважное/";
        }else if (priority == 4)
        {
            priorityBadge = "/Необязательное или можно отказаться/";
        }
        else {
            priorityBadge = "/.../";
        }
        cout << "\t\t\n\t" << indexArr << "\t\t\n------------------\n" << title << " " << priorityBadge << "\t\t\n------------------\n" << "Выполнить до: ";
        deadline.print_time();
        cout << "\t\t\n------------------\n";
    }
    int getPriority() {
        return priority;
    }
    My_Time getTaskTime() {
        return deadline;
    }
    int getId() {
        return id;
    }
    string getTitle() {
        return title;
    }
};
Task createTask(vector <Task> list_all) {
    int Choice = 0;
    system("cls");
    if (list_all.empty())
    {
        cout << "\nВаш список пуст!\n";
    }
    cout << "\nХотите создать/изменить задачу?\n 1-Создать или изменить 2-выйти из программы\n";
    cin >> Choice;
    if (Choice == 1)
    {
        My_Time New_Time;
        Task new_task;
        int priority;
        string title;
        
        int month;
        int day;
        int hours;
        int minutes;
        system("cls");
        cout << "Вы вошли в меню создания задач!\n Задайте название -> ";
        cin >> title;

        
        
        
        while (true)
        {
            system("cls");
            cout << "\nЗадайте Приоритет 1-Срочное\n 2-Важное \n 3-Неважное\n 4-Необязательное или можно отказаться\n";
            cin >> priority;
            if (priority > 0 || priority <= 4)
            {
                break;
            }
        }
        while (true)
        {
            system("cls");
            cout << "\nВведите дату выполнения задания: в формате в цифрах Месяц День\n";

            cin >> month; //месяц   
            cin.ignore();
            cin >> day; //день
            if (day <= 31 && day > 0 || month<=12 && month >= 1)
            {
               
                break;
            }
        }

        while (true)
        {
            system("cls");
            cout << "\nВведите время выполнения задачи в формате(с пробелом) ЧЧ ММ\n";
            cin >> setw(2) >> hours;
            cin.ignore();
            cin >> setw(2) >> minutes;

            if (hours <= 24 && hours >= 0 && minutes <= 60 && minutes >= 0)
            {
                New_Time.create(day, month, 2023, hours, minutes);
                break;
            }
            
        }

       
        new_task.set(priority, list_all.size(), title, New_Time);
        cout << "\nЗадача создана!\n";
        return new_task; 
    }
    else if (Choice == 2)
    {
        exit(0);
    }
    else {
        system("cls");
        cout << "\nневерный ввод попробуйте еще раз!\n";
        Sleep(3000); // ждать 2 секунд
        createTask(list_all);
    }
    
}
vector <Task> deleteTask(vector <Task> list_all) {
    for (int i = 0; i < list_all.size(); i++)
    {
        list_all[i].print(i);
    }
    
    int toDel;
    
    // validation
    
        while (true)
        {
            
            cout << "Введите номер задачи для удаления\n";
            
            cin >> toDel;
            if (toDel >= 0 && toDel <= list_all.size())
            {
                break;
            }
        }
    
    
        vector<Task>::iterator it;
        
        it = list_all.begin() + toDel;
        list_all.erase(it);
        cout << "Задача под номером " << toDel << " удалена\n";
    
    return list_all;
}
int getCurrentDay() {
    // https://unetway.com/tutorial/c-data-i-vrema?ysclid=lht5soms2m264956071
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int curDay = ltm->tm_mday;
    return curDay;
}
int getCurrentMonth() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int curMonth = 1 + ltm->tm_mon;
    return curMonth;
}
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    vector <Task> list_all;
    int dayNow = getCurrentDay();
    int monthNow = getCurrentMonth();

    //заполнение вектора задачами
    
    for (int i = 0; i < 4; i++)
    {
        My_Time New_Time;
        Task nTask;
        New_Time.create(25+i, 5+i/2, 2023, 15+i, 40+i*3);
        nTask.set(4-i, list_all.size(), "title", New_Time);
        list_all.push_back(nTask);
    }
    
    cout << "Привет!";
    int Choice=1;
        while (Choice != 0)
        {
            //если пуст
            if (list_all.empty())
            {
              
              list_all.push_back(createTask(list_all));
            }
            else {
               
                cout << "\n\n\n\nОтрисовать все задачи: 1-по приоритету 2-по дате исполнения\n\n\n\n";
                int sort=0;
                cin >> sort;
                if (sort==1)
                {
                        for (int i = 0; i < list_all.size(); i++) {
                            for (int j = 0; j < list_all.size()-1; j++) {
                                if (list_all[j].getPriority() > list_all[j + 1].getPriority()) {
                                    Task b = list_all[j]; // создали дополнительную переменную
                                    list_all[j] = list_all[j + 1]; // меняем местами
                                    list_all[j + 1] = b; // значения элементов
                                }
                            }
                        }
                        cout << "\n\n\n по приоритету\n";
                        cout << "\n\n\n Пострарайтесь выполнить все! \nВсе ваши дела:\n";
                        for (int i = 0; i < list_all.size(); i++)
                        {
                            list_all[i].print(i);
                        }
                }
                // по убыванию дня
                else if (sort == 2) {
                    for (int i = 0; i < list_all.size(); i++) {
                        for (int j = 0; j < list_all.size() - 1; j++) {
                            if (list_all[j].getTaskTime().getDay() > list_all[j + 1].getTaskTime().getDay()) {
                                Task b = list_all[j]; // создали дополнительную переменную
                                list_all[j] = list_all[j + 1]; // меняем местами значения элементов
                                list_all[j + 1] = b; 
                            }
                        }
                    }
                    cout << "\n\n\n по дате\n";
                    cout << " Пострарайтесь выполнить все! \nВсе ваши дела:\n";
                    for (int i = 0; i < list_all.size(); i++)
                    {
                        list_all[i].print(i);
                    }
                }
                // обычно
                else {
                    system("cls");
                    cout << " Пострарайтесь выполнить все! \nВсе ваши дела:\n";
                    for (int i = 0; i < list_all.size(); i++)
                    {
                        list_all[i].print(i);
                    }
                }
                cout << "\n\n\nВыберите действие:\n1-создать задачу\n2-удалить задачу\n3-редактировать задачу\n4-отобразить задачи на день\n5-на неделю\n6-на месяц\n7-поиск задачи\n0-выход из программы\n\n\n";
                cin >> Choice;
                // создаем задачу
                if (Choice == 1)
                {
                    system("cls");
                    list_all.push_back(createTask(list_all));

                }
                // удаляем ее
                else if (Choice == 2)
                {
                    system("cls");
                    list_all = deleteTask(list_all);
                }
                // редактируем ее
                else if (Choice == 3)
                {
                    system("cls");
                    int toRewrite = 0;
                    for (int i = 0; i < list_all.size(); i++)
                    {
                        list_all[i].print(i);
                    }
                    

                    while (true)
                    {

                        
                        cout << "\nВы вошли в меню редактирования. Введите номер задачи для редактирования!\n";
                        cin >> toRewrite;
                        if (toRewrite >= 0 && toRewrite <= list_all.size())
                        {
                            break;
                        }
                    }

                   
                    list_all[toRewrite] = createTask(list_all);
                }
                // отображаем задачи на день
                else if (Choice == 4)
                {
                    
                    vector <Task> list_day;
                    system("cls");
                    
                    
                    for (int i = 0; i < list_all.size(); i++)
                    {
                       int taskDay =  list_all[i].getTaskTime().getDay();

                       if (taskDay == dayNow)
                       {
                           Task task = list_all[i];
                           list_day.push_back(task);
                       }
                    }
                    cout << "\nЗАДАЧИ НА ДЕНЬ:\n";
                    if (list_day.empty())
                    {
                        cout << "\nнет задач подходящих по условию\n";
                    }
                    else {
                        
                        for (int i = 0; i < list_day.size(); i++)
                        {
                            list_day[i].print(i);
                        }
                    }
                    
                    
                    
                }

                // отображаем задачи на неделю
                else if (Choice == 5)
                {
                    system("cls");
                    vector <Task> list_by_week;
                    
                    for (int i = 0; i < list_all.size(); i++)
                    {
                        int taskDay = list_all[i].getTaskTime().getDay();
                        int taskMonth = list_all[i].getTaskTime().getMonth();
                        int week = dayNow + 7;

                        if (taskDay <= week && taskMonth==monthNow)
                        {
                            list_by_week.push_back(list_all[i]);
                        }
                    }

                    cout << "\nЗАДАЧИ НА НЕДЕЛЮ:\n";
                    if (list_by_week.empty())
                    {
                        cout << "\nнет задач подходящих по условию\n";
                    }
                    for (int i = 0; i < list_by_week.size(); i++)
                    {
                        list_by_week[i].print(i);
                    }
                }
                // месяц
                else if (Choice == 6)
                {
                    system("cls");
                    vector <Task> list_by_month;

                    for (int i = 0; i < list_all.size(); i++)
                    {
                        // проверяем текуший месяц и месяц задачи
                        int taskMonth = list_all[i].getTaskTime().getMonth();
                        if (taskMonth == monthNow)
                        {
                            list_by_month.push_back(list_all[i]);
                        }
                    }
                    cout << "\nЗАДАЧИ НА МЕСЯЦ:\n";
                    
                    if (list_by_month.empty())
                    {
                        cout << "\nнет задач подходящих по условию\n";
                    }
                    for (int i = 0; i < list_by_month.size(); i++)
                    {
                        list_by_month[i].print(i);
                    }
                }
                // поиск задачи
                else if (Choice == 7) {
                    
                    
                    int ch = 0;
                    
                    while (true)
                    {
                        cout << "Выберите критерий поиска:\n1-по названию\n2-по дате\n3-по приоритету\n";
                        cin >> ch;
                        if (ch==1||ch==2||ch==3)
                        {
                            break;
                        }
                    }
                    //tilte
                    if (ch==1)
                    {
                        cout << "\nвведите название задачи для поиска\n";
                        string title;
                        cin >> title;
                        for (int i = 0; i < list_all.size(); i++)
                        {
                            if (list_all[i].getTitle()==title)
                            {
                                list_all[i].print(i);
                            }
                        }
                    }
                    //дата
                    else if (ch == 2)
                    {
                        int month, day;
                        while (true)
                        {
                           
                            system("cls");
                            cout << "\nВведите дату для поиска задания: в формате в цифрах Месяц_День\n";

                            cin >> month; //месяц   
                            cin.ignore();
                            cin >> day; //день
                            if (day <= 31 && day > 0 || month <= 12 && month >= 1)
                            {
                                break;
                            }
                        }
                        for (int i = 0; i < list_all.size(); i++)
                        {
                            if (list_all[i].getTaskTime().getDay() == day && list_all[i].getTaskTime().getMonth() == month)
                            {
                                list_all[i].print(i);
                            }
                        }
                    }
                    // приоритет
                    if (ch == 3) {
                        int prio=0;
                        
                        while (true)
                        {
                            system("cls");
                            cout << "\nвведите приоритет задачи:\n\n1-Срочное\n2-Важное\n3-Неважное\n4-Необязательное или можно отказаться";
                            cin >> prio;
                            if (prio == 1 || prio == 2 || prio == 3 || prio == 4)
                            {
                                break;
                            }
                        }
                        for (int i = 0; i < list_all.size(); i++)
                        {
                            if (list_all[i].getPriority() == prio)
                            {
                                list_all[i].print(i);
                            }
                        }
                    }
                }

            }
    }
    return 0;
}

