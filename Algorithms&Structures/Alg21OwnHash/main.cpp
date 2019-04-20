#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <limits.h>

using namespace std;

using ll= long long int;
ll mod(ll x, ll p);


template<class T>
class HashTable
{
private:
    int m_size;
    const int x=263;
    const long long p = 1000000007;
    std::vector<std::list<T>> m_table;
    ll hash(char i, int exp)
    {
        //cout<<endl<<(int)i<<"*"<<"263^"<<exp<<"="<<ll(i*pow(x,exp))<<endl;
//        if(ll(i*pow(x,exp)) > INT_MAX)
//        {
//            cout<<"mod p="<<mod(i * mod(pow(x,exp),p),p)<<" ";
//            return mod((i*pow(x,exp)),p);
//        }
        return i*pow(x,exp);
    }
    ll bigExp(int x, int exp)
    {
        ll res = x;
        if(exp==0) return 1;
        while(--exp)
        {
            res = mod(res,p)*x;
        }
        return res;
    }
    int hashPolynomFunction(const std::string &str)
    {
        ll sum = 0;
        for(unsigned i=0; i<str.size(); i++)
        {
            ll h = str[i]*bigExp(x,i);//powl(x,i);
            sum+=mod(h, p);
        }
        //cout<< "sum hash ="<<sum_hashs<<endl;
        //cout << "Hash["<<str<<"]="<<mod(mod(sum_hashs,p),m_size)<<endl;
        return mod(mod(sum,p),m_size);
    }


public:
    HashTable() = default;
    HashTable(int size) : m_size(size)
    {
        m_table.resize(m_size);
    }
    void add(const string &str)
    {
        int bucket = hashPolynomFunction(str);
        auto res = std::find(m_table[bucket].begin(), m_table[bucket].end(), str);
        if(res == m_table[bucket].end())
            m_table[bucket].push_front(str);
    }
    void erase(const string &str)
    {
        int bucket = hashPolynomFunction(str);
        auto res = std::find(m_table[bucket].begin(), m_table[bucket].end(), str);
        if(res != m_table[bucket].end())
            m_table[bucket].erase(res);
    }
    void findOut(const string &str)
    {
        int bucket = hashPolynomFunction(str);
        auto res = std::find(m_table[bucket].begin(), m_table[bucket].end(), str);
        if(res != m_table[bucket].end())
            cout<< "yes"<<endl;
        else cout<<"no"<<endl;
    }
    void check(int i)
    {
        if(!m_table[i].empty())
            for(auto var : m_table[i])
                cout<<var<<" ";
        else cout<<endl;
    }
};

int main()
{
    int n, m, idx;
    cin >> n >> m;
    HashTable<string> tab(n);
    string cmd, word;
    for(int i=0;i<m; i++)
    {
        cin >> cmd;
        switch(cmd[0])
        {
        case 'a':
            cin >> word;
            tab.add(word);
            break;
        case 'c':
            cin >> idx;
            tab.check(idx);
            break;
        case 'f':
            cin >> word;
            tab.findOut(word);
            break;
        case 'd':
            cin >> word;
            tab.erase(word);
            break;
        default:
            cout<<"not correct command";
        }
    }
    return 0;
}

ll mod(ll x, ll p)
{
    return (x%p+p)%p;
}
