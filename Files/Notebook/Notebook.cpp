#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <stdint.h>
using namespace std;

const string database = "data.bin";
const int pageSize = 5;

struct Contact
{
    uint32_t id;
    char fio[51];
    char tel[13];
    bool active;
};

bool fileExists(const string& filename)
{
    ifstream f(filename);
    if (f.is_open())
    {
        f.close();
        return true;
    }
    return false;
}

void createDatabase()
{
    uint32_t id = 0;
    ofstream f(database, ios::binary);
    if (f)
    {
        f.write((char*)&id, sizeof(id));
        f.close();
    }
}

void addContact()
{
    uint32_t lastId = 0;
    system("cls");
    fstream f(database, ios::in | ios::out | ios::binary);
    if (f.is_open())
    {
        f.read((char*)&lastId, sizeof(uint32_t));
        lastId++;
        f.seekg(0);
        f.write((char*)&lastId, sizeof(uint32_t));
        f.seekg(0, ios::end);
        Contact contact;
        cout << "Введите ФИО контакта (макс. 50 символов): ";
        cin.getline(contact.fio, 50);
        cout << "Введите телефон контакта (макс. 11 символов): ";
        cin.getline(contact.tel, 13);
        contact.active = true;
        contact.id = lastId;
        f.write((char*)&contact, sizeof(Contact));
        f.close();
    }
}

void changeContact()
{
    uint32_t id = 0;
    bool found = false;
    system("cls");
    fstream f(database, ios::in | ios::out | ios::binary);
    if (f.is_open())
    {
        Contact contact;
        cout << "Введите id контакта для редактирования: ";
        cin >> id;
        cin.get();
        f.seekg(sizeof(uint32_t));
        while (f.read((char*)&contact, sizeof(Contact)))
        {
            if (contact.active && contact.id == id)
            {
                char newFio[51];
                char newTel[13];
                found = true;
                cout << "Текущее имя: " << contact.fio <<
                    ". Введите новое имя, или нажмите Enter, если не хотите его менять\n";
                cin.getline(newFio, 50, '\n');
                if (strlen(newFio) > 0)
                    strcpy_s(contact.fio, newFio);
                cout << "Текущей телефон: " << contact.tel <<
                    ". Введите новый телефон, или нажмите Enter, если не хотите его менять\n";
                cin.getline(newTel, 13, '\n');
                if (strlen(newTel) > 0)
                    strcpy_s(contact.tel, newTel);

                if (strlen(newFio) > 0 || strlen(newTel) > 0)
                {
                    f.seekg(-(int)(sizeof(Contact)), ios::cur);
                    f.write((char*)&contact, sizeof(Contact));
                }
                cout << "Успешно обновлен контакт: " << contact.fio << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "Контакт с Ид = " << id << " не найден"
                << endl;
        }
        f.close();
        cout << "Для продолжения нажмите любую клавишу...";
        _getch();
    }
}

void deleteContact()
{
    uint32_t id = 0;
    bool found = false;
    system("cls");
    fstream f(database, ios::in | ios::out | ios::binary);
    if (f.is_open())
    {
        Contact contact;
        cout << "Введите id контакта для удаления: ";
        cin >> id;
        f.seekg(sizeof(uint32_t));
        while (f.read((char*)&contact, sizeof(Contact)))
        {
            if (contact.active && contact.id == id)
            {
                found = true;
                contact.active = false;
                f.seekg(-(int)(sizeof(Contact)), ios::cur);
                f.write((char*)&contact, sizeof(Contact));
                cout << "Успешно удален контакт: " << contact.fio << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "Контакт с Ид = " << id << " не найден"
                << endl;
        }
        f.close();
        cout << "Для продолжения нажмите любую клавишу...";
        _getch();
    }
}

void printContacts()
{
    system("cls");
    ifstream f(database, ios::binary);
    if (f.is_open())
    {
        Contact contact;
        f.seekg(sizeof(uint32_t));
        int contactsCount = 0;
        while (f.read((char*)&contact, sizeof(Contact)))
        {
            if (contact.active)
            {
                cout << "Ид: " << contact.id << "\n";
                cout << "ФИО: " << contact.fio << "\n";
                cout << "Телефон: " << contact.tel << "\n\n";
                contactsCount++;
                if (contactsCount % pageSize == 0)
                {
                    cout << "Для продолжения нажмите любую клавишу\n";
                    if (_getch() == 27) break;
                }
            }
        }
        f.close();
        cout << "Для продолжения нажмите любую клавишу...";
        _getch();
    }
}

void menu()
{
    while (true)
    {
        system("cls");
        cout << "Телефонная книга\n\n";
        cout << "1. Добавить контакт\n";
        cout << "2. Удалить контакт\n";
        cout << "3. Изменить контакт\n";
        cout << "4. Список контактов\n\n";
        cout << "0. Выход\n";

        char choice = _getch();
        switch (choice)
        {
        case '1':
            addContact();
            break;
        case '2':
            deleteContact();
            break;
        case '3':
            changeContact();
            break;
        case '4':
            printContacts();
            break;
        case '0': return;
        }

    }
}

void checkAndCreateDatabase()
{
    bool exists = fileExists(database);
    if (!exists)
        createDatabase();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    checkAndCreateDatabase();
    menu();
}

