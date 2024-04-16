#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class literature
{
    int id;
    string title;

public:
    void l_getdata()
    {
        cout << "ID :";
        cin >> id;
       
        cin.ignore();
        cout << "Title :";
        
        getline(cin,title);
        
    }
    
    void l_putdata()
    {
        cout << left << setw(7) << id ;
        cout << left << setw(20) << title ;
    }
};

class e_literature : public virtual literature
{
    string doi;

public:
    void e_getdata()
    {
        cout << "Doi :";
        cin >> doi;
    }

    void e_putadata()
    {
        cout << left << setw(15) << doi ;
    }
};

class hardbound : public virtual literature
{
    int nu_of_copies;

public:
    void H_getdata()
    {
        cout << "IN Stock Copies :";
        cin >> nu_of_copies;
    }

    void H_putdata()
    {
        cout << left << setw(10) << nu_of_copies << " copies" ;
    }
};

class book : public e_literature, public hardbound
{
    int isbn;
    char TB;

public:
    void B_getdata()
    {
        l_getdata();
         cin.ignore();
        
        cout << "ISBN :";
        fflush(stdin);
        cin >> isbn;
         cin.ignore();

        cout << "(E) copy or (H)ardbound :";
        cin >> TB;
        fflush(stdin);
         cin.ignore();
        if (TB == 'E')
        {
            e_getdata();
        }

        else if (TB == 'H')
        {
            H_getdata();
        }
    }

    void b_putdata()
    {
        l_putdata();
        cout << left << setw(7) << isbn ;
        if (TB == 'E')
        {
            e_putadata();
        }

        else if (TB == 'H')
        {
            H_putdata();
        }
    }
};

class magazine : public e_literature, public hardbound
{
    int issn;
    char TM;

public:
    void M_getdata()
    {
        l_getdata();
        cin.ignore();    
        cout << "ISSN :";
        cin >> issn;
        fflush(stdin);
        cout << "(E) copy or (H)ardbound :";
        cin >> TM;
        fflush(stdin);
        if (TM == 'E')
        {
            e_getdata();
        }

        else if (TM == 'H')
        {
            H_getdata();
        }
    }

    void m_putdata()
    {
        l_putdata();
        cout << left << setw(7) << issn ;

        if (TM == 'E')
        {
            e_putadata();
        }

        else if (TM == 'H')
        {
            H_putdata();
        }
    }
};

int main()
{
    int bcount = 0, mcount = 0;
    char s;
    book b[100];
    magazine m[100];

    while (1)
    {

        cout << endl
             << "Enter 1: Add book data" << endl;
        cout << "Enter 2: Add magazine data" << endl;
        cout << "Enter 3:List all books" << endl;
        cout << "Enter 4:List all magazines" << endl;

        cout << "Enter your choice :";
        int x;
        cin >> x;
        switch (x)
        {
        case 1:
        {
            b[bcount].B_getdata();
            bcount++;

            cout << "Enter M to goto new Menu. Press any key to exit :";
            cin >> s;

            if (s != 'M')
            {
                return 0;
            }
            break;
        }    

        case 2:
        {
            m[mcount].M_getdata();
            mcount++;

            cout << "Enter M to goto new Menu. Press any key to exit :";
            cin >> s;

            if (s != 'M')
            {

                return 0;
            }
            break;
        }    

        case 3:
        {
            for (int i = 0; i < bcount; i++)
            {
                b[i].b_putdata();
                cout<<endl;
            }
            cout << "Enter M to goto new Menu. Press any key to exit :";
            cin >> s;

            if (s != 'M')
            {
                return 0;
            }
            break;
        }

        case 4:
        {

            for (int i = 0; i < mcount; i++)
            {
                m[i].m_putdata();
                cout<<endl;
            }
            cout << "Enter M to goto new Menu. Press any key to exit :";
            cin >> s;

            if (s != 'M')
            {
                return 0;
            }
            break;
        }
        }

        
    }
}