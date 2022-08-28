#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
double h(0.1);
double fx(vector<pair<int, int>> number, double x1)
{
    int i = 0;
    if (number.size() == 3 || number.size() == 2)
    {
        if (number[i].second == 0)
        {
            return number[i].first * pow(x1, number[i + 1].first) + number[i + 2].first;
        }
        else
        {
            return pow(x1, number[i].first) + number[i + 1].first;
        }
    }
    else if (number.size() == 5 || number.size() == 4)
    {
        if (number[i].second == 0)
        {
            return number[i].first * pow(x1, number[i + 1].first) + number[i + 2].first * pow(x1, number[i + 3].first) + number[i + 4].first;
        }
        else
        {
            return pow(x1, number[i].first) + number[i + 1].first * pow(x1, number[i + 2].first) + number[i + 3].first;
        }
    }
    else if (number.size() == 7 || number.size() == 6)
    {
        if (number[i].second == 0)
        {
            return number[i].first * pow(x1, number[i + 1].first) + number[i + 2].first * pow(x1, number[i + 3].first) + number[i + 4].first * pow(x1, number[i + 5].first) + number[i + 6].first;
        }
        else
        {
            return pow(x1, number[i].first) + number[i + 1].first * pow(x1, number[i + 2].first) + number[i + 3].first * pow(x1, number[i + 4].first) + number[i + 5].first;
        }
    }
    else if (number.size() == 9 || number.size() == 8)
    {
        if (number[i].second == 0)
        {
            return number[i].first * pow(x1, number[i + 1].first) + number[i + 2].first * pow(x1, number[i + 3].first) + number[i + 4].first * pow(x1, number[i + 5].first) + number[i + 6].first * pow(x1, number[i + 7].first) + number[i + 8].first;
        }
        else
        {
            return pow(x1, number[i].first) + number[i + 1].first * pow(x1, number[i + 2].first) + number[i + 3].first * pow(x1, number[i + 4].first) + number[i + 5].first * pow(x1, number[i + 6].first) + number[i + 7].first;
        }
    }
    else if (number.size() == 11 || number.size() == 10)
    {
        if (number[i].second == 0)
        {
            return number[i].first * pow(x1, number[i + 1].first) + number[i + 2].first * pow(x1, number[i + 3].first) + number[i + 4].first * pow(x1, number[i + 5].first) + number[i + 6].first * pow(x1, number[i + 7].first) + number[i + 8].first * pow(x1, number[i + 9].first) + number[i + 10].first;
        }
        else
        {
            return pow(x1, number[i].first) + number[i + 1].first * pow(x1, number[i + 2].first) + number[i + 3].first * pow(x1, number[i + 4].first) + number[i + 5].first * pow(x1, number[i + 6].first) + number[i + 7].first * pow(x1, number[i + 8].first) + number[i + 9].first;
        }
    }
    return NULL;
}
double fi(vector<pair<int, int>> number, double x1)
{
    double M=1.01*((fx(number, x1 + h) - fx(number, x1 - h)) / (2 * h));
    return x1 - fx(number, x1) / M;
}
int main()
{
    setlocale(LC_ALL, "rus");
    int chislo(0), Nm(0), Hm(0), Im(0), vibor(0);
    vector<pair<int,int>>number;
    bool bre = false;
    bool hord = true;
    double x1(0), x2(0), fcx1(0), fcx2(0), f2x1(0), f2x2(0), koren_true(0), koren_false(0);
    double Nx1_prib(0), Nx2_prib(0), Hx1_prib(0), Hx2_prib(0), temp(0), Ix1_prib(0), Ix2_prib(0);
    double eps;
    string func;
    cout << "\tПример: 15x3+10x2+5x1+10\n\n";
    cout << "\tВведите функцию: ";
    getline(cin, func);
    cout << "\tВведите эпсилон: ";
    cin >> eps;
    for (int i(0); i < func.size(); i++)
        {
        if (i != 0 && func[i] >= '0' && func[i] <= '9' && func[i + 1] >= '0' && func[i + 1] <= '9' && func[i - 1] == '-')
        {
            switch (func[i])
            {
            case 48:
                chislo = 10 * 0;
                break;
            case 49:
                chislo = 10 * 1;
                break;
            case 50:
                chislo = 10 * 2;
                break;
            case 51:
                chislo = 10 * 3;
                break;
            case 52:
                chislo = 10 * 4;
                break;
            case 53:
                chislo = 10 * 5;
                break;
            case 54:
                chislo = 10 * 6;
                break;
            case 55:
                chislo = 10 * 7;
                break;
            case 56:
                chislo = 10 * 8;
                break;
            case 57:
                chislo = 10 * 9;
                break;
            }
            switch (func[i + 1])
            {
            case 48:
                chislo += 0;
                break;
            case 49:
                chislo += 1;
                break;
            case 50:
                chislo += 2;
                break;
            case 51:
                chislo += 3;
                break;
            case 52:
                chislo += 4;
                break;
            case 53:
                chislo += 5;
                break;
            case 54:
                chislo += 6;
                break;
            case 55:
                chislo += 7;
                break;
            case 56:
                chislo += 8;
                break;
            case 57:
                chislo += 9;
                break;
            }
            chislo *= -1;
            number.push_back(pair<int,int>(chislo,i));
            i += 2;
        }
        else if ( i != 0 && func[i] >= '0' && func[i] <= '9' && func[i - 1] == '-' )
        {
            switch (func[i])
            {
            case 48:
                chislo = 0;
                break;
            case 49:
                chislo = 1;
                break;
            case 50:
                chislo = 2;
                break;
            case 51:
                chislo = 3;
                break;
            case 52:
                chislo = 4;
                break;
            case 53:
                chislo = 5;
                break;
            case 54:
                chislo = 6;
                break;
            case 55:
                chislo = 7;
                break;
            case 56:
                chislo = 8;
                break;
            case 57:
                chislo = 9;
                break;
            }
            i++;
            chislo *= -1;
            number.push_back(pair<int, int>(chislo, i));
        }
        if (func[i] >= '0' && func[i] <= '9' && func[i + 1] >= '0' && func[i + 1] <= '9')
        {
            switch (func[i])
            {
            case 48:
                chislo = 10 * 0;
                break;
            case 49:
                chislo = 10 * 1;
                break;
            case 50:
                chislo = 10 * 2;
                break;
            case 51:
                chislo = 10 * 3;
                break;
            case 52:
                chislo = 10 * 4;
                break;
            case 53:
                chislo = 10 * 5;
                break;
            case 54:
                chislo = 10 * 6;
                break;
            case 55:
                chislo = 10 * 7;
                break;
            case 56:
                chislo = 10 * 8;
                break;
            case 57:
                chislo = 10 * 9;
                break;
            }
            switch (func[i + 1])
            {
            case 48:
                chislo += 0;
                break;
            case 49:
                chislo += 1;
                break;
            case 50:
                chislo += 2;
                break;
            case 51:
                chislo += 3;
                break;
            case 52:
                chislo += 4;
                break;
            case 53:
                chislo += 5;
                break;
            case 54:
                chislo += 6;
                break;
            case 55:
                chislo += 7;
                break;
            case 56:
                chislo += 8;
                break;
            case 57:
                chislo += 9;
                break;
            }
            number.push_back(pair<int, int>(chislo, i));
            i += 2;
        }
        else if (func[i] >= '0' && func[i] <= '9')
        {
            switch (func[i])
            {
            case 48:
                chislo = 0;
                break;
            case 49:
                chislo = 1;
                break;
            case 50:
                chislo = 2;
                break;
            case 51:
                chislo = 3;
                break;
            case 52:
                chislo = 4;
                break;
            case 53:
                chislo = 5;
                break;
            case 54:
                chislo = 6;
                break;
            case 55:
                chislo = 7;
                break;
            case 56:
                chislo = 8;
                break;
            case 57:
                chislo = 9;
                break;
            }
            number.push_back(pair<int, int>(chislo, i));
        }
    }
    cout << "\t1)Автоматический подбор\n\t2)Ручной ввод" << endl;
    cin >> vibor;
    system("clear");
    if (vibor == 1)
    {
        for (double i = -0.5; i < 0.5; i += 0.1)
        {
            for (double j = -0.5; j < i; j += 0.1)
            {
                x1 = i;
                x2 = j;
                double x1_temp = fx(number, x1);
                double x2_temp = fx(number, x2);
                fcx1 = (fx(number, x1 + h) - fx(number, x1 - h)) / (2 * h);
                fcx2 = (fx(number, x2 + h) - fx(number, x2 - h)) / (2 * h);
                f2x1 = (fx(number, x1 + h) - 2 * fx(number, x1) + fx(number, x1 - h)) / (h * h);
                f2x2 = (fx(number, x2 + h) - 2 * fx(number, x2) + fx(number, x2 - h)) / (h * h);
                if ((x1_temp * x2_temp) < 0)
                {
                    if (fcx1 > 0 && fcx2 > 0)
                    {
                        if (f2x1 > 0 && f2x2 > 0)
                        {
                            koren_true = x2;
                            koren_false = x1;
                            bre = true;
                            if (bre)
                            {
                                break;
                            }
                        }
                        else if (f2x1 < 0 && f2x2 < 0)
                        {
                            koren_true = x1;
                            koren_false = x2;
                            bre = true;
                            if (bre)
                            {
                                break;
                            }
                        }
                    }
                    else if (fcx1 < 0 && fcx2 < 0)
                    {
                        if (f2x1 > 0 && f2x2 > 0)
                        {
                            koren_true = x2;
                            koren_false = x1;
                            bre = true;
                            if (bre)
                            {
                                break;
                            }
                        }
                        else if (f2x1 < 0 && f2x2 < 0)
                        {
                            koren_true = x1;
                            koren_false = x2;
                            bre = true;
                            if (bre)
                            {
                                break;
                            }
                        }
                    }
                }
            }
            if (bre)
            {
                break;
            }
        }
        if (!bre)
        {
            cout << "Автоматический подбор не возможен!";
            vibor = 2;
        }
    }
    else if(vibor == 2)
    {
        cout << "Введите x1: ";
        cin>>x1;
        cout << "Введите x2: ";
        cin >> x2;
        double x1_temp = fx(number, x1);
        double x2_temp = fx(number, x2);
        fcx1 = (fx(number, x1 + h) - fx(number, x1 - h)) / (2 * h);
        fcx2 = (fx(number, x2 + h) - fx(number, x2 - h)) / (2 * h);
        f2x1 = (fx(number, x1 + h) - 2 * fx(number, x1) + fx(number, x1 - h)) / (h * h);
        f2x2 = (fx(number, x2 + h) - 2 * fx(number, x2) + fx(number, x2 - h)) / (h * h);
        if ((x1_temp * x2_temp) < 0)
        {
            if (fcx1 > 0 && fcx2 > 0)
            {
                if (f2x1 > 0 && f2x2 > 0)
                {
                    koren_true = x2;
                    koren_false = x1;
                }
                else if (f2x1 < 0 && f2x2 < 0)
                {
                    koren_true = x1;
                    koren_false = x2;
                }
            }
            else if (fcx1 < 0 && fcx2 < 0)
            {
                if (f2x1 > 0 && f2x2 > 0)
                {
                    koren_true = x2;
                    koren_false = x1;
                }
                else if (f2x1 < 0 && f2x2 < 0)
                {
                    koren_true = x1;
                    koren_false = x2;
                }
            }
        }

    }
    else
    {
        cout << "Ввод не правильный!";
        return 0;
    }
    Hx1_prib = koren_false;
    temp = koren_true;
    cout << "\n\n\tХорды приближения: " << endl;
    for (int i = 0; ; i++)
    {
        Hm++;
        Hx2_prib = Hx1_prib - (fx(number, Hx1_prib) / (fx(number, Hx1_prib) - fx(number, temp))) * (Hx1_prib - temp);
        cout << "\n\tX" << i+2 << " приближённое равно: " << Hx2_prib << "\n\tФункция равна: " << fx(number, Hx2_prib);
        if (abs(Hx2_prib - Hx1_prib) < eps)
        {
            break;
        }
        Hx1_prib = Hx2_prib;
        if (i == 50)
        {
            system("cls");
            hord = false;
            break;
        }
    }
    Nx1_prib = koren_true;
    cout << "\n\n\tНьютон приближения: " << endl;
    for (int i = 0; ; i++)
    {
        Nm++;
        Nx2_prib = Nx1_prib - fx(number, Nx1_prib) / ((fx(number, Nx1_prib + h) - fx(number, Nx1_prib - h)) / (2 * h));
        cout << "\n\tX" << i+2 << " приближённое равно: " << Nx2_prib << "\n\tФункция равна: " << fx(number, Nx2_prib);
        if (abs(Nx2_prib - Nx1_prib) < eps)
        {
            break;
        }
        Nx1_prib = Nx2_prib;
        if (i == 50)
        {
            system("cls");
            hord = false;
            break;
        }
    }
    Ix1_prib = koren_true;
    cout << "\n\n\tИтерации приближения: " << endl;
    for (int i = 0; ; i++)
    {
        Im++;
        Ix2_prib = fi(number, Ix1_prib);
        cout << "\n\tX" << i+2 << " приближённое равно: " << Ix2_prib << "\n\tФункция равна: " << fx(number, Ix2_prib);
        if (abs(Ix2_prib - Ix1_prib) < eps)
        {
            break;
        }
        Ix1_prib = Ix2_prib;
        if (i == 50)
        {
            system("cls");
            hord = false;
            break;
        }
    }
    cout << "\n\n\tВаша функция: " << func << endl;
    cout << "\tx1 = " << x1 << "\n";
    cout << "\tЗначение функции x1: " << fx(number, x1) << "\n";
    cout << "\t1 производная x1 = " << fcx1 << "\n";
    cout << "\t2 производная x1 = " << f2x1 << "\n";
    cout << "\tx2 = " << x2 << "\n";
    cout << "\tЗначение функции x2: " << fx(number, x2) << "\n";
    cout << "\t1 производная x2 = " << fcx2 << "\n";
    cout << "\t2 производная x2 = " << f2x2 << "\n";
    cout << "\tКорень выражения = " << koren_true << "\n";
    cout << "\tЭпсилон = " << eps << "\n";
    if (hord)
    {
        cout << "\t\tМетод хорд" << "\n";
        cout << "\tВаше " << Hm << " приближение = " << Hx2_prib << "\n";
    }
    else
    {
        cout << "\t\tМетод хорд невозможен" << "\n";
    }
    cout << "\t\tМетод Ньютона(касательных)" << "\n";
    cout << "\tВаше " << Nm << " приближение = " << Nx2_prib << "\n";
    cout << "\t\tМетод итераций" << "\n";
    cout << "\tВаше " << Im << " приближение = " << Ix2_prib << "\n";
    return 0;
}
