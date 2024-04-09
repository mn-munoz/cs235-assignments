#include <vector>
#include <functional>
using namespace std;

const size_t INITIAL_CAPACITY = 7;

template <class K ,class V>
class Dictionary {
    public:
        Dictionary() {
            m_size = 0;
            m_dataPos = 0;
            m_capacity = INITIAL_CAPACITY;
            m_data = new vector<pair<K,V>> [m_capacity];
            m_hashtable = new vector<pair<K,size_t>*>[m_capacity * 2 + 1];
            for (size_t i = 0; i < m_capacity * 2 + 1; i++) {
                m_hashtable[i] = nullptr;
            }
            m_deleted = pair(K(), V());
        }

        ~Dictionary() {
            delete [] m_data;
            for (size_t i = 0; i < m_capacity * 2 + 1; i++) {
                if (m_hashtable[i] != nullptr) {
                    delete [] m_hashtable[i];
                }
            }
            delete [] m_hashtable;
        }

        void add(K & key, V & value) {
            m_data[m_dataPos] = pair(key, value);
            size_t index = hash<K>{}(key)% (m_capacity * 2 + 1);
            while (m_hashtable[index] != nullptr || *(m_hashtable[index]) != m_deleted) {
                if(*(m_hashtable[index]) != m_deleted) {
                    if ( m_hashtable[index]-> first == key) {
                        m_data[m_hashtable[index]-> second].second = value;
                    return;
                    }
                }
                index= (index + 1) % (m_capacity * 2 + 1);
            }
            m_hashtable[index] = new pair<K, int>(key, m_dataPos);
            m_dataPos++;
            m_size++;
        }

    private:
        size_t m_capacity;
        vector<pair<K,V>> * m_data; 
        vector<pair<K, size_t> *> * m_hashtable; 
        size_t m_size;
        size_t m_dataPos;
        pair<K, int> m_deleted;
};

int main() {
    Dictionary<int, int> dict;

    return 0;
}