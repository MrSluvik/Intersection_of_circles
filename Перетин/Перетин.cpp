// Визначити в скількох точках перетинаються два кола.
//Єдиною умовою є зчитування даних з файлу і запис даних в файл
#include <iostream>
#include <math.h>
#include<fstream>
using namespace std;
int main() 
{
    double x1, y1, r1, x2, y2, r2;
    double d = 0;
    ifstream fileIn;
    fileIn.open("D:/Users8/Я/Desktop/text.txt");//відкриття файлу за шляхом до нього
    fileIn >> x1>> y1>> r1>> x2>> y2>> r2;//запис в зміну с число з файлу "D:/Users8/Я/Desktop/text.txt"
    
    if ((x1 <= 1000000000 )and (y1 <= 1000000000)and (r1 <= 1000000000) and( x2 <= 1000000000) and (y2 <= 1000000000) and (r2 <= 1000000000)) {
        d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));//знаходим відстань між центрами кіл

        if (x1 == x2 && y1 == y2 && r1 == r2) {//перевірка чи кола мають одакові координати та однакові радіуси
            cout << "-1" << endl;
            ofstream fileOut;
            fileOut.open("D:/Users8/Я/Desktop/text.txt", fstream::app);//відкриття файлу  за шляхом до нього  
            fileOut << "\nКола мають безліч точок перетину -1 "; //запис в файл кількіст точок перетину кіл
            fileOut.close();//закриття файлу
        }
        else if ((r1 + r2 == d) || (r1 - r2 == d)) {//за формулою визначаєм чи кола дотикаються(перетинаються в 1 точці)
            cout << "1" << endl;
            ofstream fileOut;
            fileOut.open("D:/Users8/Я/Desktop/text.txt", fstream::app);//відкриття файлу  за шляхом до нього  
            fileOut << "\nКількість точок перетину = 1 " ; //запис в файл кількіст точок перетину кіл
            fileOut.close();//закриття файлу            
        }
        else if ((r1 + r2 < d) || (r1 - r2 > d)) {//за формулою визачаємо чи кола не мають спільних точок
            cout << "0" << endl;
            ofstream fileOut;
            fileOut.open("D:/Users8/Я/Desktop/text.txt", fstream::app);//відкриття файлу  за шляхом до нього  
            fileOut << "\nКількість точок перетину = 0, кола не перетинаються"; //запис в файл кількіст точок перетину кіл
            fileOut.close();//закриття файлу
        }
        else if ((r1 + r2 > d) || (r1 - r2 < d)) {//за формулою визначаємо чи кола перетинаються в двох точках
            cout << "2" << endl;
            ofstream fileOut;
            fileOut.open("D:/Users8/Я/Desktop/text.txt", fstream::app);//відкриття файлу  за шляхом до нього  
            fileOut << "\nКількість точок перетину = 2 "; //запис в файл кількіст точок перетину кіл
            fileOut.close();//закриття файлу
        }
    }
    fileIn.close();//закриття файла
   
}

