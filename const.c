#include <stdio.h>
#include <string.h>

class Person
{
private:
    char* m_szName;
public:
    Person(char* szNewName)
    {
        m_szName = strdup(szNewName);
    };
    ~Person() {delete[] m_szName; };
};

int main()
{
    Person p("Fred Jones");
}