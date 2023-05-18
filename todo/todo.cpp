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
};
Task createTask(vector <Task> list_all) {
    int Choice = 0;
    system("cls");
    cout << "\nХотите создать/изменить задачу?\n 1-Создать или изменить 2-выйти из программы\n";
    cin >> Choice;
    if (Choice == 1)
    {
        My_Time New_Time;
        Task new_task;
        int priority;
        string title;
        string description;
        int month;
        int day;
        int hours;
        int minutes;
        system("cls");
        cout << "Вы вошли в меню создания задач!\n Задайте название -> ";
        cin >> title;

        cout << "\nЗадайте Приоритет 1-Срочное\n 2-Важное \n 3-Неважное\n 4-Необязательное или можно отказаться\n";
        cin >> priority;
        if (priority < 0 || priority>4)
        {
            while (priority < 0 || priority>4)
            {
                system("cls");
                cout << "\nЗадайте Приоритет 1-Срочное\n 2-Важное \n 3-Неважное\n 4-Необязательное или можно отказаться\n";
                cin >> priority;
                if (priority > 0 || priority<4)
                {
                    break;
                }
            }
        }
        cout << "\n Введите дату выполнения задания: в формате Месяц День\n";

        cin >> month; //месяц   
        cin.ignore();
        cin >> day; //день

        cout << "\nВведите время выполнения задачи в формате(с пробелом) ЧЧ ММ\n";
        cin >> setw(2) >> hours;
        cin.ignore();
        cin >> setw(2) >> minutes;

        if (hours<=24 && hours>=0 && minutes<=60 && minutes>=0)
        {
            New_Time.create(day, month, 2023, hours, minutes);
        }else{
            // валидация
            bool isValid = false;
            while (!isValid) {
                cout << "\nНеверно!\nВведите время выполнения задачи с пробелом в формате \nЧасы_Минуты в 24 часовой системе\n";
                cin >> setw(2) >> hours;
                cin.ignore();
                cin >> setw(2) >> minutes;
                if (hours <= 24 && hours >= 0 && minutes <= 60 && minutes >= 0)
                {
                    New_Time.create(day, month, 2023, hours, minutes);
                    break;
                }
            }
        }
        new_task.set(priority, list_all.size(), title, New_Time);
        return new_task; 
    }
    if (Choice == 2)
    {exit(0);}
}
vector <Task> deleteTask(vector <Task> list_all) {
    for (int i = 0; i < list_all.size(); i++)
    {
        list_all[i].print(i);
    }
    cout << "Введите номер задачи для удаления\n";
    int toDel;
    cin >> toDel;
    // validation
    
    if (toDel >= 0 && toDel <= list_all.size())
    {
        vector<Task>::iterator it;
        
        it = list_all.begin() + toDel;
        list_all.erase(it);
        cout << "Задача под номером " << toDel << " удалена\n";
    }
    return list_all;
}
int getCurrentDay() {
    // https://unetway.com/tutorial/c-data-i-vrema?ysclid=lht5soms2m264956071
    time_t now = time(0);
    tm* ltm = localtime(&now);

    return ltm->tm_mday;
    
}
int main()
{
    setlocale(LC_ALL, "Russian");
    vector <Task> list_all;

    for (int i = 0; i < 3; i++)
    {
        My_Time New_Time;
        Task nTask;
        New_Time.create(15+i, 5, 2023, 15+i, 40+i*3);
        nTask.set(3-i, list_all.size(), "title", New_Time);
        list_all.push_back(nTask);
    }
    
    cout << "Привет!";
    int Choice=1;
        while (Choice != 0)
        {
            
            if (list_all.empty())
            {
              cout << "\nВаш список пуст!\n";
              list_all.push_back(createTask(list_all));
            }
            else {
                cout << "\t Отрисовать по: 1-приоритету 2-по дате исполнения";
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
                        cout << " Пострарайтесь выполнить все! \nВсе ваши дела:\n";
                        for (int i = 0; i < list_all.size(); i++)
                        {
                            list_all[i].print(i);
                        }
                }
                else {
                    cout << " Пострарайтесь выполнить все! \nВсе ваши дела:\n";
                    for (int i = 0; i < list_all.size(); i++)
                    {
                        list_all[i].print(i);
                    }
                }

               
                cout << "\nВыберите действие: 1-создать задачу 2-удалить задачу 3-редактировать задачу 0-выход из программы\n";
                cin >> Choice;
                if (Choice == 1)
                {
                    system("cls");
                    list_all.push_back(createTask(list_all));
                }if (Choice == 2)
                {
                    system("cls");
                    list_all = deleteTask(list_all);
                }
                if (Choice == 3)
                {
                    system("cls");
                    int toRewrite = 0;
                    cout << "\nВы вошли в меню редактирования. Введите номер задачи для редактирования!";
                    cin >> toRewrite;
                    // валидация
                    if (toRewrite<0|| toRewrite > list_all.size())
                    {
                        cout << "\n номер задачи неправильный! введите правильное значение";
                        cin >> toRewrite;
                        while (toRewrite<0 || toRewrite > list_all.size())
                        {
                            cout << "\n номер задачи неправильный! введите правильное значение";
                            cin >> toRewrite;
                            if (toRewrite<0 || toRewrite > list_all.size())
                            {
                                break;
                            }
                        }
                    }
                    list_all[toRewrite] = createTask(list_all);
                }
            }
    }
}

