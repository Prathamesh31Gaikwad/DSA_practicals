#include <iostream>
#include <string.h>
using namespace std;

class hashing
{
    struct hasht
    {
        char name[10];
        long key;
        int chain;
    };
    hasht h[10];

public:
    hashing()
    {

        for (int i = 0; i < 10; i++)
        {
            h[i].key = -1;
            strcpy(h[i].name, "NULL");
            h[i].chain = -1;
        }
    }

    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << h[i].key << " " << h[i].name << " " << h[i].chain << endl;
        }
    }

    void insert()
    {
        int num;
        char n[50];
        cout << "Enter the name" << endl;
        cin >> n;
        cout << "Enter the telephone number" << endl;
        cin >> num;

        int hf = num % 10;
        if (h[hf].key == -1)
        {
            h[hf].key = num;
            strcpy(h[hf].name, n);
        }
        else if (h[hf].key != -1 && h[hf].chain == -1)
        {
            int flag = 1;
            for (int i = hf + 1; i < 10; i++)
            {
                if (h[i].key == -1)
                {
                    h[i].key = num;
                    strcpy(h[i].name, n);
                    h[hf].chain = i;
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                for (int i = 0; i < hf; i++)
                {
                    if (h[i].key == -1)
                    {
                        h[i].key = num;
                        strcpy(h[i].name, n);
                        h[hf].chain = i;
                        break;
                    }
                }
            }   
        }
        else
        {

            int flag2 = 1;
            int ch = h[hf].chain;
            while (h[ch].chain != -1)
            {
                ch = h[ch].chain;
            }
            for (int i = ch + 1; i < 10; i++)
            {
                if (h[i].key == -1)
                {
                    h[i].key = num;
                    strcpy(h[i].name, n);
                    h[ch].chain = i;
                    flag2 = 0;
                    break;
                }
            }
            if (flag2 == 1)
            {
                for (int i = 0; i < ch; i++)
                {
                    if (h[i].key == -1)
                    {
                        h[i].key = num;
                        strcpy(h[i].name, n);
                        h[ch].chain = i;
                        break;
                    }
                }
            }
        }
    }

    void search(int val)
    {
        int hf = val % 10;
        int i;
        for (i = hf; i < 10; i++)
        {
            if (h[i].key == val)
            {
                cout << "Key found at index " << i << endl;
                return;
            }
        }
        for (i = 0; i < hf; i++)
        {
            if (h[i].key == val)
            {
                cout << "key found at index " << i << endl;
                return;
            }
        }
        cout<<"key not found"<<endl;
        return;
    }

    void deletee(int val)
    {
        int hf = val % 10;
        if (h[hf].key == val)
        {
            h[hf].key = -1;
            strcpy(h[hf].name, " ");
            h[hf].chain = -1;
        }
        else
        {
            int prev = hf;
            int ch = h[hf].chain;
            while (ch != -1 && h[ch].key != val)
            {
                prev = ch;
                ch = h[ch].chain;
            }
            if (ch != -1)
            {
                h[prev].chain = h[ch].chain;
                h[ch].key = -1;
                strcpy(h[ch].name, " ");
                h[ch].chain = -1;
            }
            else
            {
                cout << "Element not found" << endl;
            }
        }
    }
};

int main()
{
    hashing ha;
    int x, f = 1;
    do
    {
        cout << "menu" << endl;
        cout << "1.create  2.search  3.delete  4.display  5.exit" << endl;
        cout << "enter choice ";
        cin >> x;
        switch (x)
        {
        case 1:
        {
            char a = 'y';
            do
            {
                ha.insert();
                cout << "do u wish to enter more (y/n) ";
                cin >> a;
            } while (a == 'y');
        }
        break;

        case 2:
        {
            int num;
            cout << "enter telephone no to be searched ";
            cin >> num;
            ha.search(num);
        }
        break;

        case 3:
        {
            int num1;
            cout << "enter telephone no to be deleted ";
            cin >> num1;
            ha.deletee(num1);
        }
        break;

        case 4:
        {
            ha.display();
        }
        break;

        case 5:
        {
            cout << "thanks";
            f = 0;
        }
        break;
        }
    } while (f == 1);
    return 0;
}