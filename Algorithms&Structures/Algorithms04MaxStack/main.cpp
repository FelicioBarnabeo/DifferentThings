#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
struct stack
{
private:
    int m_maxsize;
    int m_length;
    T * m_data;
    T * m_max_data;
public:
    stack() = default;
    stack(int size) : m_maxsize(size)
    {
        m_data = new T[size];
        m_max_data = new T[size];
    }
    ~stack()
    {
        delete[] m_data;
        m_data = nullptr;
        delete[] m_max_data;
        m_max_data = nullptr;
    }
    void push(T var)
    {
        if(m_length < m_maxsize)
        {

            if(!empty())
            {
                m_max_data[m_length] = std::max(var,m_max_data[m_length-1]) ;

            }
            else
            {
                m_max_data[m_length] = var;

            }
            m_data[m_length++] = var;
        }
        else
        {
            m_maxsize *= 2;
            T * tempdata = new T[m_maxsize];
            std::copy(m_data, m_data+m_length, tempdata);
            delete [] m_data;
            m_data = tempdata;

            T * maxtempdata = new T[m_maxsize];
            std::copy(m_max_data, m_max_data+m_length, maxtempdata);
            delete [] m_max_data;
            m_max_data = maxtempdata;

            m_max_data[m_length] = std::max(var,m_max_data[m_length-1]);
            m_data[m_length++] = var;
        }
    }
    bool empty()
    {
        return m_length==0;
    }
    T pop()
    {
        if(!empty())
        {
            return m_data[--m_length];
        }
    }
    T max()
    {
        return m_max_data[m_length-1];
    }
    T top()
    {
        return m_data[m_length-1];
    }
};

int main()
{
    stack<int> st(64);
    int lines = 0;
    cin >> lines;
    string line;
    int arg;
    for(int i =0; i<lines; i++)
    {
        cin >> line;
        if(line.find("push") != string::npos)
        {
            cin >> arg;
            st.push(arg);
        }
        else if(line.find("pop") != string::npos)
        {
            st.pop();
        }
        else if(line.find("max") != string::npos)
        {
            cout << st.max() << endl;
        }
    }
    return 0;
}
