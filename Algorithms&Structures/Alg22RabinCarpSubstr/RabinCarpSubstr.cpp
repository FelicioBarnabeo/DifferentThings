/*Find indexes of substring entries in text  with Rabin Karp algorithm realization
 * Tsaruev Felix 30.06.18
*/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cstring>
#include <array>

using namespace std;


using ll= long long int;
ll mod(ll x, ll p);
ll bin_pow(ll base, ll p);

const int x=263;
const long long MOD = 1e9 + 7;

namespace HashFunctions {
    ll hash(char i, int exp)
    {
        return mod(i*bin_pow(::x,exp),MOD);
    }

    int hashPolynomFunction(const std::string &str)
    {
        ll sum = 0;
        for(unsigned i=0; i<str.size(); i++)
        {
            ll h = hash(str[i],i);
            sum+=mod(h, MOD);
        }
        return (mod(sum,MOD));
    }
}

template<class T>
class HashTable
{
private:
    int m_size;
    std::vector<std::list<T>> m_table;

public:
    HashTable() = default;
    HashTable(int size) : m_size(size)
    {
        m_table.resize(m_size);
    }
    void add(const string &str)
    {
        int bucket = bucketNumber(str);
        auto res = std::find(m_table[bucket].begin(), m_table[bucket].end(), str);
        if(res == m_table[bucket].end())
            m_table[bucket].push_front(str);
    }
    void erase(const string &str)
    {
        int bucket = bucketNumber(str);
        auto res = std::find(m_table[bucket].begin(), m_table[bucket].end(), str);
        if(res != m_table[bucket].end())
            m_table[bucket].erase(res);
    }
    void findOut(const string &str)
    {
        int bucket = bucketNumber(str);
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
    int bucketNumber(const std::string &str)
    {
        return mod(HashFunctions::hashPolynomFunction(str),m_size);
    }
};

int main()
{
    string text, pattern;
    cin >> pattern >> text;
    int P = pattern.size();
    long long hashPattern  = HashFunctions::hashPolynomFunction(pattern);
    int entries = text.size()-P+1;
    std::vector<int> hash_entries(entries);
    int hashLastEntry = HashFunctions::hashPolynomFunction(text.substr(entries-1));
    hash_entries[entries-1] = hashLastEntry;
    for(int i=entries-2; i>=0; i--)
    {
        long long h = (hash_entries[i+1] + MOD - HashFunctions::hash(text[i+P],P-1))%MOD ;
        h =  mod(h*x + text[i],MOD);
        hash_entries[i] = h;
    }
    for(unsigned i=0;i<hash_entries.size();i++)
    {
        if(hash_entries[i]==hashPattern)
        {
            auto pit = pattern.begin();
            auto tit = text.begin()+i;
            while(*pit && *pit++ == *tit++);
            if(pit==pattern.end()) cout<< i<<" ";
        }
    }
    return 0;
}

ll mod(ll x, ll p)
{
    return (x%p+p)%p;
}

ll bin_pow(ll base, ll p)
{
    if(p==0) return 1;
    if(p == 1) return base;
    if(p%2 == 0)
    {
        ll t = bin_pow(base , p/2);
        return t * t%MOD;
    }
    else{
        return bin_pow(base, p-1)*base%MOD;
    }
}
