#include "splashkit.h"
#include "terminal_user_input.h"

#include <string>
using namespace std;

#include <vector>
using std::vector;

int total_length(vector<string> names)
{
    int result = 0;

    for(int i = 0; i < names.size(); i++)
    {
        string name = names[i];
        result += name.length();
    }
    return result;
}
int index_of(vector<string> names, string name)
{
    for (int i = 0; i < names.size(); i++)
    {
        if( (to_lowercase(names[i])) == (to_lowercase(name)))
        {
            return i;
        }
    }
    return -1;
}
bool contains(vector<string> names, string name)
{
    return index_of(names, name) != -1;
}
string shortest_name(vector<string> names)
{
    string min;

    min = names[0];

    for (int i = 1;  i < names.size(); i++)
    {
        if(min.length() > names[i].length())
        {
            min = names[i];
        }
    }
    return min;
}
void print_summary(const vector<string> &names)
{
    write_line("---PRINT SUMMARY---");
    
    for(int i = 0; i < names.size(); i++)
    {
        write_line(names[i]);
    }

    write_line("The total length of characters in this array is: ");
    write_line(total_length(names));

    bool has_oliver;
    has_oliver = contains(names, "oliver");

    if( has_oliver )
    {
    write_line("The name 'Oliver' is found at index: " + to_string(index_of(names, "Oliver")));
    }
    write("The shortest name in this array is: ");
    write_line(shortest_name(names));
}
void add_names(vector<string> &names)
{
    int size;
    size = read_integer("How many names would you like to enter?");
    for (int i = 0; i < size; i++)
    {
    names.push_back(read_string("Enter a name: "));
    }
}
int main()
{
    vector<string> names;

    add_names(names);
    print_summary(names);

    return 0;
}