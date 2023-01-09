#include <fstream>
#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
class teacher
{
public:
    int TID, age;
    float BS, Tax, GS;
    char TName[20];
    char TEmail[30];
    char FName[20];
    char MName[20];
    char Address[40];
    char City[20];
    char Qua[20];
    char Sex[10];
    char Subjects[20];
    char Branch[20];
    char Dofjoin[20];
};
class process // container class
{
    teacher t; // composition
public:
    void write1()
    {
        ofstream fout;                   // to write in file
        fout.open("tech.txt", ios::app); // opened the file in append mode
        cout << "\nEnter the teacher's ide:";
        cin >> t.TID;
        cin.getline(t.TName, 20);
        cout << "\nEnter teacher name:";
        cin.getline(t.TName, 20);
        cout << "\nEnter teacher email:";
        cin.getline(t.TEmail, 30);
        cout << "\nEnter teacher father's name:";
        cin.getline(t.FName, 20);
        cout << "\nEnter teacher mother's name:";
        cin.getline(t.MName, 20);
        cout << "\nEnter the age of teacher:";
        cin >> t.age;
        cin.getline(t.Address, 20);
        cout << "\nEnter the address of teacher:";
        cin.getline(t.Address, 40);
        cout << "\nEnter the city of teacher:";
        cin.getline(t.City, 20);
        cout << "\nEnter the qualification of teacher:";
        cin.getline(t.Qua, 20);
        cout << "\nEnter the sex of teacher:";
        cin.getline(t.Sex, 10);
        cout << "\nEnter the subjects of teacher:";
        cin.getline(t.Subjects, 20);
        cout << "\nEnter the branch of teacher:";
        cin.getline(t.Branch, 20);
        cout << "\nEnter the date of joining:";
        cin.getline(t.Dofjoin, 20);
        cout << "\nenter the Basic sellary of teacher:";
        cin >> t.BS;
        t.Tax = t.BS * 10 / 100;
        t.GS = t.BS - t.Tax;
        fout.write((char *)&t, sizeof(t)); // binary mode
        fout.close();                      // file closed
        cout << "\n\n************** Record Saved ***************\n";
    }
    void format()
    {
        ofstream fout;                   // to write in file
        fout.open("tech.txt", ios::out); // opened the file in non append mode
        fout.close();                    // file closed//nosound();
        cout << "\n\tFile Format....";
    }
    void read1()
    {
        ifstream fin;
        int countt = 0;
        fin.open("tech.txt");
        while (1) // infin.loop
        {
            fin.read((char *)&t, sizeof(t)); // binary mode
            if (fin.eof())
                break;
            else
            {
                cout << "\n\n\tTeacher's IDE=" << t.TID << "\n\n\tTeacher's Name=" << t.TName << "\n\n\tTeacher's Email Address=" << t.TEmail << "\n\n\tFather's Name of Teacher=" << t.FName << "\n\n\tMother's Name of Teacher=" << t.MName << "\n\n\tTeacher's Address=" << t.Address << "\n\n\tBelong is City of Teacher=" << t.City << "\n\n\tQualification of Teacher=" << t.Qua << "\n\n\tSex of Teacher=" << t.Sex << "\n\n\tSubjects of teaching=" << t.Subjects << "\n\n\tBranch of Teacher=" << t.Branch << "\n\n\tAge of Teacher=" << t.age << "\n\n\tDate of joining=" << t.Dofjoin << "\n\n\tBasic Sellary=" << t.BS << "\n\n\tTax=" << t.Tax << "\n\n\tGross sellary=" << t.GS;
                countt++; // getch();
            }
            getch();
        }
        cout << "\n\n************** " << countt << " Records Read ***************\n";
        fin.close();
    }
    void search()
    {
        int wantedTID, jasus = 0;
        cout << "\nenter the TID to search=";
        cin >> wantedTID; // 102
        ifstream fin("tech.txt");
        while (1)
        {
            fin.read((char *)&t, sizeof(t)); // binary mode
            if (fin.eof())
                break;
            else if (t.TID == wantedTID)
            {
                cout << "\n\n\tTeacher's IDE=" << t.TID << "\n\n\tTeacher's Name=" << t.TName << "\n\n\tTeacher's Email Address=" << t.TEmail << "\n\n\tFather's Name of Teacher=" << t.FName << "\n\n\tMother's Name of Teacher=" << t.MName << "\n\n\tTeacher's Address=" << t.Address << "\n\n\tBelong is City of Teacher=" << t.City << "\n\n\tQualification of Teacher=" << t.Qua << "\n\n\tSex of Teacher=" << t.Sex << "\n\n\tSubjects of teaching=" << t.Subjects << "\n\n\tBranch of Teacher=" << t.Branch << "\n\n\tAge of Teacher=" << t.age << "\n\n\tDate of joining=" << t.Dofjoin << "\n\n\tBasic Sellary=" << t.BS << "\n\n\tTax=" << t.Tax << "\n\n\tGross sellary=" << t.GS;
                jasus = 1;
                break;
            } // if closed
        }     // while loop closed
        if (jasus == 0)
            cout << "\n\n*****Not Found*****\n\n";
        else
            cout << "\n\n\n\t\trecord found";
        fin.close();
    }
    void del()
    {
        int wantedTID, found = 0;
        cout << "\nenter the TID to delete=";
        cin >> wantedTID;          // 102
        ifstream fin("tech.txt");  // reading
        ofstream fout("temp.txt"); // wrt.
        while (1)
        {
            fin.read((char *)&t, sizeof(t)); // binary mode
            if (fin.eof())
                break;
            if (t.TID != wantedTID)
            {
                fout.write((char *)&t, sizeof(t));
            } // if closed
            else
            {
                found = 1;
            }
        } // while loop closed
        if (found == 0)
            cout << "\n\n*****Not Found*****\n\n";
        else
            cout << "\n Recod delete.....";
        fin.close();
        fout.close();
        remove("tech.txt");
        rename("temp.txt", "tech.txt");
    }
    void update()
    {
        int wantedTID, found = 0;
        cout << "\nenter the TID to update=";
        cin >> wantedTID; // 103
        ifstream fin("tech.txt");
        ofstream fout("temp.txt");
        while (1)
        {
            fin.read((char *)&t, sizeof(t)); // binary mode
            if (fin.eof())
                break;
            if (t.TID != wantedTID)
            {
                fout.write((char *)&t, sizeof(t));
            } // if closed
            else
            {
                // t.TID=wantedTID;
                cout << "\nEnter the teacher's ide:";
                cin >> t.TID;
                cin.getline(t.TName, 20);
                cout << "\nEnter teacher name:";
                cin.getline(t.TName, 20);
                cout << "\nEnter teacher email:";
                cin.getline(t.TEmail, 30);
                cout << "\nEnter teacher father's name:";
                cin.getline(t.FName, 20);
                cout << "\nEnter teacher mother's name:";
                cin.getline(t.MName, 20);
                cout << "\nEnter the age of teacher:";
                cin >> t.age;
                cin.getline(t.Address, 20);
                cout << "\nEnter the address of teacher:";
                cin.getline(t.Address, 40);
                cout << "\nEnter the city of teacher:";
                cin.getline(t.City, 20);
                cout << "\nEnter the qualification of teacher:";
                cin.getline(t.Qua, 20);
                cout << "\nEnter the sex of teacher:";
                cin.getline(t.Sex, 10);
                cout << "\nEnter the subjects of teacher:";
                cin.getline(t.Subjects, 20);
                cout << "\nEnter the branch of teacher:";
                cin.getline(t.Branch, 20);
                cout << "\nEnter the date of joining:";
                cin.getline(t.Dofjoin, 20);
                cout << "\nenter the Basic sellary of teacher:";
                cin >> t.BS;
                t.Tax = t.BS * 10 / 100;
                t.GS = t.BS - t.Tax;
                fout.write((char *)&t, sizeof(t)); // binary mode
                found = 1;
            }
        } // while loop closed
        if (found == 0)
            cout << "\n\n*****Not Found*****\n\n";
        else
            cout << "\nRecord Updated....";
        fin.close();
        fout.close();
        remove("tech.txt");
        rename("temp.txt", "tech.txt");
    }
    int security()
    {
        char uid[30], pass[30];
        cout << "\n\n\n\n\t\t===========Login Panel================";
        cout << "\n\n\n\t\tUser ID:";
        cin >> uid;
        cout << "\n\t\tEnter Password:";
        cin >> pass;
        cout << "\n\t\t======================================";

        if (!(strcmp("Gourav", uid) == 0 && strcmp(pass, "123456") == 0))

        {
            cout << "\n\n\n\n\t\t\tInvalid uid/Password";
            return 0;
        }
        else
        {
            return 1;
        }
    }
}; // class closed
int main()
{
    char choice;
    process obj;
    if (obj.security() == 0)
        return 0;
    do
    {
        // clrscr();
        cout << "\n\n\n\n\t\t===========******================";
        cout << "\n\t\t===========Main Menu==============";
        cout << "\n\t\t===========*******================";
        cout << "\n\n\n\t\t\tPress [ w ] to write";
        cout << "\n\t\t\t.......................";
        cout << "\n\t\t\tPress [ r ] to read";
        cout << "\n\t\t\t.......................";
        cout << "\n\t\t\tPress [ s ] to search";
        cout << "\n\t\t\t.......................";
        cout << "\n\t\t\tPress [ d ] to delete";
        cout << "\n\t\t\t.......................";
        cout << "\n\t\t\tPress [ u ] to update";
        cout << "\n\t\t\t.......................";
        cout << "\n\t\t\tPress [ c ] to format file";
        cout << "\n\t\t\t.......................";
        cout << "\n\n\t\t===========******================";
        cout << "\n\n\t\t\tPress [ x ] to exit:";
        cout << "\n\t\t===========*******================";
        choice = getch(); // w
        switch (choice)
        {
        case 'w':
            obj.write1();
            break;
        case 'r':
            obj.read1();
            break;
        case 's':
            obj.search();
            break;
        case 'd':
            obj.del();
            break;
        case 'u':
            obj.update();
            break;
        case 'c':
            obj.format();
            break;
        }
        cout << "\n\n\t\t************** ***************\n";
        // fflush(stdin);//to clear the memory in buffer
    } while (choice != 'x');
}
