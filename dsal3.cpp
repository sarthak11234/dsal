#include <iostream>
using namespace std;

struct node
{
    string name;
    node *B[5]; // Array of 5 pointers to the node structure
};

class book
{
    int c, s, sub;

public:
    node *temp = new node; // Dynamically allocate memory for the root node

    // Function to initialize nodes for title, chapters, sections, and sub-sections
    void Getnewnode()
    {
        for (int i = 0; i < 5; i++)
        {
            temp->B[i] = new node;      // Allocate memory for each chapter node
            temp->B[i]->name = "empty"; // Initialize with "empty"
            for (int j = 0; j < 5; j++)
            {
                temp->B[i]->B[j] = new node;      // Allocate memory for each section
                temp->B[i]->B[j]->name = "empty"; // Initialize section as empty
                for (int k = 0; k < 5; k++)
                {
                    temp->B[i]->B[j]->B[k] = new node;      // Allocate sub-sections
                    temp->B[i]->B[j]->B[k]->name = "empty"; // Initialize sub-section as empty
                }
            }
        }
    }

    // Function to add book title
    void add_title()
    {
        cout << "Enter the title of the book: ";
        cin >> temp->name;
        Getnewnode(); // Initialize nodes after title
    }

    // Function to add chapters to the book
    void add_chapter()
    {
        string cname;
        cout << "Enter the number of chapters in the book: ";
        cin >> c;
        for (int i = 0; i < c; i++)
        {
            cout << endl
                 << "Chapter " << i + 1 << " = ";
            cin >> cname;
            temp->B[i]->name = cname; // Assign chapter name to B[i]
        }
    }

    // Function to add sections to a chapter
    void add_section()
    {
        string sname;
        cout << "Chapter number where you need to add sections = ";
        int chnum;
        cin >> chnum;

        cout << "Enter number of sections = ";
        cin >> s;
        for (int i = 0; i < s; i++)
        {
            cout << endl
                 << "Section " << chnum << "." << i + 1 << " = ";
            cin >> sname;
            temp->B[chnum - 1]->B[i]->name = sname; // Assign section name to B[chnum]
        }
    }

    // Function to add sub-sections to a section
    void add_sub_section()
    {
        string subname;
        cout << "Chapter number where you need to add sub-sections = ";
        int chnum, snum;
        cin >> chnum;

        cout << "Section number where you need to add the sub-sections = ";
        cin >> snum;

        cout << "Enter the number of sub-sections = ";
        cin >> sub;
        for (int i = 0; i < sub; i++)
        {
            cout << endl
                 << "Sub-Section " << chnum << "." << snum << "." << i + 1 << " = ";
            cin >> subname;
            temp->B[chnum - 1]->B[snum - 1]->B[i]->name = subname; // Assign sub-section to B[chnum][snum]
        }
    }

    // Function to display the book structure
    void display()
    {
        cout << endl
             << "=========== INDEX ============" << endl;
        cout << endl
             << "Title: " << temp->name << endl;
        cout << "Chapters: " << endl;

        for (int i = 0; i < c; i++)
        {
            if (temp->B[i]->name != "empty")
            {
                cout << endl
                     << ":" << i + 1 << " : " << temp->B[i]->name;
            }
            for (int j = 0; j < s; j++)
            {
                if (temp->B[i]->B[j]->name != "empty")
                {
                    cout << endl
                         << ":" << i + 1 << "." << j + 1 << " : " << temp->B[i]->B[j]->name;
                }
                for (int k = 0; k < sub; k++)
                {
                    if (temp->B[i]->B[j]->B[k]->name != "empty")
                    {
                        cout << endl
                             << ":" << i + 1 << "." << j + 1 << "." << k + 1 << " : " << temp->B[i]->B[j]->B[k]->name;
                    }
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    book s;
    s.add_title();
    s.add_chapter();
    s.add_section();
    s.add_sub_section();
    s.add_sub_section();
    s.add_section();
    s.add_sub_section();
    s.add_sub_section();
    s.add_section();
    s.add_sub_section();
    s.add_sub_section();
    s.display();
    return 0;
}
