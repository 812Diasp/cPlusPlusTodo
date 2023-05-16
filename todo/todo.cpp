// todo.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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
        {
            mName = "Января";
        }
        else if (month == 2)
        {
            mName = "Февраля";
        }
        else if (month == 3)
        {
            mName = "Марта";
        }
        else if (month == 4)
        {
            mName = "Апреля";
        }
        else if (month == 5)
        {
            mName = "Мая";
        }
        else if (month == 6)
        {
            mName = "Июня";
        }
        else if (month == 7)
        {
            mName = "Июля";
        }
        else if (month == 8)
        {
            mName = "Августа";
        }
        else if (month == 9)
        {
            mName = "Сентября";
        }
        else if (month == 10)
        {
            mName = "Октября";
        }else if (month == 11)
        {
            mName = "Ноября";
        }
        else if (month == 12)
        {
            mName = "Декабря";
        }

        cout << "\n " << day << " " << mName << " " << year <<"\n "<<hour<<":"<<minutes<< "\n-------\n";
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
    
    void set(int priority,int id,string title,My_Time deadline) {
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
    void print() {
        cout << "\n---"<<id<<"----\n" << title << "\n-------\n"<<"Выполнить до: ";
        deadline.print_time();
    }
};

Task createTask(vector <Task> list_all) {
    int Choice = 0;
    system("cls");
    cout << "\nХотите создать задачу?\n 1-Создать 2-выйти из программы\n";
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
        cout << "\nЗадайте Приоритет 1-Срочное\n 2-Важное \n 3-Неважное\n 4-Необязательное или можно отказаться\n";
        cin >> priority;
        if (priority < 0 || priority>4)
        {

            while (priority < 0 || priority>4)
            {
                system("cls");
                cout << "\nЗадайте Приоритет 1-Срочное\n 2-Важное \n 3-Неважное\n 4-Необязательное или можно отказаться\n";
                cin >> priority;
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
    {
        exit(0);
    }
}
vector <Task> deleteTask(vector <Task> list_all) {
    cout << "Введите номер задачи для удаления\n";
    int toDel;
    cin >> toDel;
    if (toDel>=0)
    {
        vector<Task>::iterator it;

        it = list_all.begin() + toDel;
        list_all.erase(it);
        cout << "Задача под номером " << toDel << " удалена\n";
    }
    else {
        while (toDel<0)
        {
            cout << "\nНеверно! Введите номер задачи для удаления\n";
            cin >> toDel;
            if (toDel >= 0)
            {
                vector<Task>::iterator it;

                it = list_all.begin() + toDel;
                list_all.erase(it);
                cout << "Задача под номером " << toDel << " удалена\n";
                break;
            }
            
        }
    }

    return list_all;
}





int main()
{
    setlocale(LC_ALL, "Russian");

    
    vector <Task> list_all;

    My_Time New_Time;
    Task new_task;
    
    
    
    cout << "Привет!";
    int Choice=1;
   
        while (Choice != 0)
        {
            system("cls");
            if (list_all.empty())
            {
              list_all.push_back(createTask(list_all));
                
                
            }
            else {

                cout << " Пострарайтесь выполнить все! \nВсе ваши дела:\n";
                for (int i = 0; i < list_all.size(); i++)
                {
                    list_all[i].print();
                }
                cout << "\nВыберите действие: 1-создать задачу 2-удалить задачу 0-выход из программы\n";
                cin >> Choice;
                if (Choice == 1)
                {
                    list_all.push_back(createTask(list_all));
                }if (Choice == 2)
                {
                    list_all = deleteTask(list_all);
                }
            }
        
    }
    

    
}

