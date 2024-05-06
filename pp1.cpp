#include <iostream>
#define size1 10
#define size2 10
using namespace std;

class tele_book
{
private:
    int arr1[size1];
    int arr2[size2];

public:
    tele_book();
    int gen_key(int);
    void linear_prob(int, int);
    void quadratic_prob(int, int);
    void display1();
    void display2();
    int search1(int num);
    int search2(int num);
};

tele_book::tele_book()
{
    for (int i = 0; i < size1; i++)
    {
        arr1[i] = -1;
    }

    for (int i = 0; i < size2; i++)
    {
        arr2[i] = -1;
    }
}

int tele_book::gen_key(int num)
{
    int key;
    key = num % 10;
    return key;
}

void tele_book::display1()
{
    cout << "Hash Table for linear probing " << endl;
    cout << endl;
    cout << "index"
         << "    "
         << "number" << endl;
    cout << endl;
    for (int i = 0; i < size1; i++)
    {

        cout << i << " --> " << arr1[i] << endl;
    }
}

void tele_book::display2()
{
    cout << "Hash Table " << endl;
    cout << endl;
    cout << "index"
         << "    "
         << "number" << endl;
    cout << endl;
    for (int i = 0; i < size2; i++)
    {

        cout << i << " --> " << arr2[i] << endl;
    }
}

void tele_book::linear_prob(int num, int key)
{

    int count = 0;

    if (arr1[key] == -1)

    {
        arr1[key] = num;
    }

    else
    {
        
        while (count < size1)
        {
            key = (key + 1) % size1; 

            if (arr1[key] == -1)
            {
                arr1[key] = num;
                return; 
            }
            count = count + 1;
        }

        cout << "Hash Table is Full" << endl;
        display1();
    }
}

void tele_book::quadratic_prob(int num, int key)
{
    int i = 0;
    int count = 0;

    if (arr2[key] == -1)
    {
        arr2[key] = num;
    }   
    else
    {
        while (count < size2)
        {
            int probe = (key + i * i) % size2; 
            if (arr2[probe] == -1)
            {
                arr2[probe] = num;
                return; 
            }
            count++;
            i = i + 1;
        }

        
        cout << "Hash Table is Full" << endl;
        display2();
        exit(1);
    }
}

int tele_book::search1(int num)
{
    int key = num % 10;
    int count = 0;
    int ok = key;

    while (true)
    {
        count++;
        if (arr1[key] == num)
        {
            return count; 
        }
        key = (key + 1) % 10; 
        if (key == ok)
        {
            break; 
        }
    }
    return -1;
}

int tele_book::search2(int num)
{
    int flag = 0;
    int count = 0;
    for (int i = 0; i < size2; i++)
    {
        count++;
        if (num == arr2[i])
        {
            cout << "Key found " << endl;
            flag = 1;
            break;
        }
        
    }
   
    cout << "Comparisons rquired " << count << endl;

    if (flag == 0)
    {
        cout << "Key not found " << endl;
    }
    return count;
}

int main()
{
    int num, key, count;
    char ans;

    tele_book obj1;
    cout << "Collision handling by linear probing " << endl;
    do
    {
        cout << "Enter number" << endl;
        cin >> num;

        key = obj1.gen_key(num);
        cout << "--> key = " << key << endl;
        obj1.linear_prob(num, key);

        cout << "Add more numbers(y/n)?";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    cout << "Enter the key to search " << endl;
    cin >> key;
    cout << "For Linear probing " << endl;
    count = obj1.search1(key);
    cout << "count = " << count << endl;

    obj1.display1();

    cout << "Collision handling by quadratic probing " << endl;
    do
    {
        cout << "Enter number" << endl;
        cin >> num;

        key = obj1.gen_key(num);
        cout << "--> key = " << key << endl;
        obj1.quadratic_prob(num, key);

        cout << "Add more numbers(y/n)?";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    cout << "Enter the key to search " << endl;
    cin >> key;
    cout << "For Quadratic probing " << endl;
    obj1.search2(key);

    obj1.display2();

    return 0;
}