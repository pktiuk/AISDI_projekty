#ifndef TREE
#define TREE

#include <iostream>
#include <chrono>
#include <utility>

using namespace std;
/*!
 *  Narzedzie do zliczania czasu
 *
 *  Sposob uzycia:
 *
 *  {
 *    Benchmark<std::chrono::nanoseconds> b;
 *    // kod do zbadania
 *    size_t elapsed = b.elapsed();
 *  }
 *
 *  lub
 *
 *  {
 *    Benchmark<std::chrono::milliseconds> b(true);
 *    // kod do zbadania
 *  } // obiekt wypisze wartosc czasu w podanych jednostkach na stderr
 */
template<typename D = std::chrono::microseconds>
class Benchmark {
public:

    Benchmark(bool printOnExit = false) : m_print(printOnExit) {
        start = std::chrono::high_resolution_clock::now();
    }
    typename D::rep elapsed() const {
        auto end = std::chrono::high_resolution_clock::now();
        auto result = std::chrono::duration_cast<D>(end-start);
        return result.count();
    }
    ~Benchmark() {
        auto result = elapsed();
        if (m_print)
        {
            std::cerr << "Czas: " << result << "\n";
        }
    }
private:
    std::chrono::high_resolution_clock::time_point start;
    bool m_print = true;
};


template<typename KeyType, typename ValueType>
struct element
{
    KeyType key;
    ValueType value;
    element* leftChild;
    element* rightChild;
    element* parent;
    int height = 0;
};


/*
 * Slownik
 */
template<typename KeyType, typename ValueType>
class TreeMap
{
  public:
    using key_type = KeyType;
    using mapped_type = ValueType;
    using value_type = std::pair<const key_type, mapped_type>;

    element<key_type, mapped_type>* root = NULL;

    void clear(element<key_type, mapped_type>* x)
    {
        if(x==NULL)
        {
            return;
        }
        else
        {
            clear(x->leftChild);
            clear(x->rightChild);
        }
        x->leftChild = NULL;
        x->rightChild = NULL;
        x->parent = NULL;
        delete x;

    }
    
    TreeMap() = default;    // konstruktor trywialny
    ~TreeMap()
    {
        clear(root);
    }

    

    /*!
     * true jezeli slownik jest pusty
     */
    bool isEmpty() const
    {
        //throw std::runtime_error("TODO: isEmpty");
        if( root == NULL )
            return true;
        else
            return false;
        
    }

    void updateBalancell(element<key_type, mapped_type>* x, element<key_type, mapped_type>* y)
    {
        if(x->balance == 1)
        {
            x->balance = 0;
            y->balance = 0;
        }
        else
        {
            y->balance = 1;
            x->balance = -1;
        }
    }

    void updateBalancerr(element<key_type, mapped_type>* x, element<key_type, mapped_type>* y)
    {
        if(x->balance == -1)
        {
            x->balance = 0;
            y->balance = 0;
        }
        else
        {
            y->balance = -1;
            x->balance = 1;
        }
    }

    void leftRotation(element<key_type, mapped_type>* a)
    {

        //cout << "left\n" << a->key <<"\n";
        element<key_type, mapped_type>* b = a->rightChild;
        element<key_type, mapped_type>* b1;
        if( b == NULL )
            b1 = NULL;
        else
            b1 = b->leftChild;
        

        //cout<<(b==NULL?"-1":b->key) << "!" << (b1==NULL?"-1":b1->key)<< "\n";
        if(a->parent != NULL)
        {
            if(a->parent->leftChild == a)
                a->parent->leftChild = b;
            else
                a->parent->rightChild = b;
            
        }
        if( b != NULL )
            b->parent = a->parent;
        a->parent = b;
        if( b!= NULL )
            b->leftChild = a;
        a->rightChild = b1;
        a->height = getHeight(a);
        if( b != NULL)
            b->height = getHeight(b);

        //cout<<(b->leftChild==NULL?-1:b->leftChild->key) << "!" <<(b->rightChild==NULL?-1:b->rightChild->key) << "!" << (b1==NULL?-1:b1->key)<< "\n";

        if( a == root )
            root = b;

    }

    void rightRotation(element<key_type, mapped_type>* a)
    {
        //cout << "right\n" << a->key <<"\n";
        element<key_type, mapped_type>* b = a->leftChild;
        element<key_type, mapped_type>* b1;
        if( b == NULL )
            b1 = NULL;
        else
            b1 = b->rightChild;
        
        /*y->leftChild = x->rightChild;
        x->rightChild = y;
        x->parent = y->parent;
        y->parent = x;
        */

        if(a->parent != NULL)
        {
            if(a->parent->leftChild == a)
                a->parent->leftChild = b;
            else
            a->parent->rightChild = b;
            
        }
        if( b != NULL )
            b->parent = a->parent;
        a->parent = b;
        if( b!= NULL )
            b->rightChild = a;
        a->leftChild = b1;
        a->height = getHeight(a);
        if( b != NULL )
            b->height = getHeight(b);

        if( a == root )
            root = b;
    }

    void lr(element<key_type, mapped_type>* b)
    {
        //cout << "lr\n";
        element<key_type, mapped_type>* c = b->rightChild;
        //element<key_type, mapped_type>* a = b->parent;
        rightRotation(c);
        leftRotation(c);

    }

    void rl(element<key_type, mapped_type>* b)
    {
        //cout << "rl\n";
        element<key_type, mapped_type>* c = b->leftChild;
        //element<key_type, mapped_type>* a = b->parent;
        leftRotation(c);
        rightRotation(c);
        
    }

    void avl(element<key_type, mapped_type>* x)
    {
        while( x->parent != NULL )
        {
            if( x->parent->parent == NULL )
            {
                if( x == x->parent->leftChild )
                {
                    rightRotaion(x);
                }
                else
                {
                    leftRotation(x);
                } 
            }
            else
            if( x->parent == x->parent->parent->leftChild && x == x->parent->leftChild )
            {
                rightRotation(x->parent);
                rightRotation(x);
            }
            else
            if( x->parent == x->parent->parent->rightChild && x == x->parent->rightChild )
            {
                leftRotaion(x->parent);
                leftRotaion(x);
            }
            else
            {
                if( x == x->parent->rightChild )
                {
                    leftRotation(x);
                    rightRotaion(x);
                }
                else
                {
                    rightRotaion(x);
                    leftRotation(x);
                }
            }
        }
    }

    int getHeight(element<key_type, mapped_type>* x)
    {
        if( x == NULL )
            return 0;
        int l, r;
        if(x->leftChild == NULL)
            l = 0;
        else
            l = x->leftChild->height;
        
        if(x->rightChild == NULL)
            r = 0;
        else
            r = x->rightChild->height;

        return max(r, l) + 1;        
        
    }

    int getBalance(element<key_type, mapped_type>* x)
    {
        return getHeight(x->leftChild) - getHeight(x->rightChild);
    }

    /*!
     * dodaje wpis do slownika
     */
    void insert(const key_type& key, const mapped_type &value)
    {
        if( isEmpty() )
        {
            root = new element<key_type, mapped_type>;
            root->key = key;
            root->value = value;
            root->leftChild = NULL;
            root->rightChild = NULL;
            root->parent = NULL;
            root->height = 1;
        }
        else
        {
            insert(key, value, root);
        
        }

        /*
        element<key_type, mapped_type>* prev;
        if(isEmpty())
        {
            root = new element<key_type, mapped_type>;
            root->key = key;
            root->value = value;
            root->leftChild = NULL;
            root->rightChild = NULL;
            root->parent = NULL;
        }
        else
        {
            element<key_type, mapped_type>* currEl=root;
            while(true)
            {
                
                if(currEl->key==key)
                    return;
                if(currEl->key<key)
                {
                    if(currEl->rightChild==NULL)
                    {
                        currEl->rightChild=new element<key_type, mapped_type>;
                        currEl->rightChild->key=key;
                        currEl->rightChild->value=value;
                        currEl->rightChild->parent=currEl;
                        currEl->rightChild->rightChild = NULL;
                        currEl->rightChild->leftChild = NULL;

                        currEl->balance -= 1;
                        prev = currEl->rightChild;
                        break;
                    }else
                    {
                        currEl=currEl->rightChild;
                    }
                    
                }else if(currEl->key>key)
                {
                    if(currEl->leftChild==NULL){
                        currEl->leftChild=new element<key_type, mapped_type>;
                        currEl->leftChild->key=key;
                        currEl->leftChild->value=value;
                        currEl->leftChild->parent=currEl;
                        currEl->leftChild->rightChild = NULL;
                        currEl->leftChild->leftChild = NULL;

                        currEl->balance += 1;
                        prev = currEl->leftChild;
                        break;
                    }else
                    {
                        currEl=currEl->leftChild;
                    }
                    
                }
            }
        
            
            while(currEl!=NULL)
            {
                if(currEl->balance != 0)
                    break;
                if(currEl->leftChild == prev)
                {
                    currEl->balance = 1;
                }
                else
                    currEl->balance = -1;
                prev = currEl;
                currEl = currEl->parent;
            }
            if(currEl == NULL)
            {
                return;
            }
            */
            /*
            if(currEl->balance == -1)
            {
                if(currEl->leftChild == prev)
                {
                    currEl->balance = 0;
                }
                else
                if(prev->balance == 1)
                {
                    rl(prev);
                }
                else
                {
                    rightRotataion(prev);
                }
                
            }
            else
            {
                if(currEl->rightChild == prev)
                {
                    currEl->balance = 0;
                    return;
                }
                if(currEl->balance == -1)
                {
                    lr(prev); //????????? moze currEl
                }
                else
                {
                    leftRotation(prev);
                }
            }
            

            

            //Update Heights
        }
        */
    }

    void insert(const key_type& key, const mapped_type &value, element<key_type, mapped_type>* x)
    {
        if(key < x->key)
        {
            if( x->leftChild == NULL )
            {
                x->leftChild=new element<key_type, mapped_type>;
                x->leftChild->key=key;
                x->leftChild->value=value;
                x->leftChild->parent=x;
                x->leftChild->rightChild = NULL;
                x->leftChild->leftChild = NULL;
                x->leftChild->height = 1;
            }
            else
            {
                insert(key, value, x->leftChild);
            }
        }
        else
        if(key > x->key)
        {
            if(x->rightChild == NULL)
            {
                x->rightChild=new element<key_type, mapped_type>;
                x->rightChild->key=key;
                x->rightChild->value=value;
                x->rightChild->parent=x;
                x->rightChild->rightChild = NULL;
                x->rightChild->leftChild = NULL;
                x->rightChild->height = 1;
            }
            else
            {
                insert(key, value, x->rightChild);
            }
        }
        else
            return;
        x->height = getHeight(x);

        int balance = getBalance(x);

        if (balance > 1 && key < x->leftChild->key)  
            rightRotation(x);  
  
        // Right Right Case  
        else
        if (balance < -1 && key > x->rightChild->key)  
            leftRotation(x);  
        // Left Right Case  
        else
        if (balance > 1 && key > x->leftChild->key)  
        {  
            leftRotation(x->leftChild);  
            rightRotation(x);
        }  
    
        // Right Left Case  
        else
        if (balance < -1 && key < x->rightChild->key)  
        {  
            rightRotation(x->rightChild);  
            leftRotation(x);
        }  
    }
    /*!
     * dodaje wpis do slownika przez podanie pary klucz-wartosc
     */
    void insert(const value_type *key_value)
    {
        throw std::runtime_error("TODO: insert");
    }

    /*!
     * zwraca referencje na wartosc dla podanego klucza
     *
     * jezeli elementu nie ma w slowniku, dodaje go
     */
    mapped_type& operator[](const key_type& key)
    {
        throw std::runtime_error("TODO: operator[]");
    }

    /*!
     * zwraca wartosc dla podanego klucza
     * jesli go nie znajdzie zwraca NULL
     */
    const mapped_type& value(const key_type& key) const
    {
        //throw std::runtime_error("TODO: value");
        element<key_type, mapped_type>* tmp = root;
        while( tmp != NULL )
        {
            if(tmp->key == key)
            {
                return tmp->value;
            }
            else
            if(key < tmp->key)
                tmp = tmp->leftChild;
            else
                tmp = tmp->rightChild;
        }
        return NULL;
    }

    /*!
     * zwraca informacje, czy istnieje w slowniku podany klucz
     */
    bool contains(const key_type& key) const {
        throw std::runtime_error("TODO: contains");
    }

    /*!
     * zwraca liczbe wpisow w slowniku
     */
    size_t size() const {
        throw std::runtime_error("TODO: size");
    }

    void write(element<key_type, mapped_type>* x)
    {
        if(x == NULL)
        {
            cout << "\n";
            return;
        }
        //cout << x->key << endl<<" l:" << x->leftChild->key <<endl << " r:" << x->rightChild->key << endl;   
        cout << x->key << " ";
        write(x->leftChild);
        write(x->rightChild);
    }
    
private:

};



#endif
