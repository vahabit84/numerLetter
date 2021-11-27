#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;
//task1
template<typename T>
void Swap(T *A, T *B)
{
    T C;
    C=*A;
    *A=*B;
    *B=C;
}
//task2
template<typename T>
void SortPointer(vector<T*> vec)
{
    sort( vec.begin(), vec.end(), [](T* pt1, T* pt2)
                                    {return *pt1 < *pt2;} );
}
size_t ForFor(ifstream& m_file)
{
     vector<char> VowelLetters {'a', 'e', 'i', 'o', 'u', 'y'};
     size_t quantity = 0;
     char letter;
   	 while(!m_file.eof())
     {
            m_file.get(letter);
            for (char lit:VowelLetters )
            {
                if(letter == lit) quantity++;
            };
   	 };
   	 return quantity;
}
bool perd (char symbol)
{
    vector<char> VowelLetters {'a', 'e', 'i', 'o', 'u', 'y'};
    for (char lit:VowelLetters )
            {
                if(symbol == lit) return true;
            };
    return false;
}
size_t CountFor(ifstream& m_file)
{
     vector<char> VowelLetters {'a', 'e', 'i', 'o', 'u', 'y'};
     size_t quantity = 0;
     char letter;
     //count_if (m_file.seekg(0,std::ios_base::beg),m_file.eof(), perd(m_file.get())) ;
   	 while(!m_file.eof()){
            m_file.get(letter);
            for (char lit:VowelLetters )
            {
                if(letter == lit) ++quantity;
            };
   	 };
   	 return quantity;
}

int main()
{
    cout << "----------task1 function swap----------" << endl;
    int a=10, b=20;
    int *ptr1, *ptr2;
    ptr1 = &a;
    ptr2 = &b;
    std::cout << "a=" << a << " " << "ptra:" << ptr1 << std::endl;
    std::cout << "b=" << b << " " << "ptrb:" << ptr2 << std::endl;
    Swap(ptr1, ptr2);
    std::cout << "a=" << a << " " << "ptra:" << ptr1 << std::endl;
    std::cout << "b=" << b << " " << "ptrb:" << ptr2 << std::endl;
    //task2
    cout << "----------task2 vector pointers----------" << endl;
    int *p1, *p2, *p3, *p4, *p5;
    int a1, b1, c1, d1, e1;
    a1 = rand()%10;
    p1=&a1;
    b1 = rand()%10;
    p2=&b1;
    c1 = rand()%10;
    p3=&c1;
    d1 = rand()%10;
    p4=&d1;
    e1 = rand()%10;
    p5=&e1;
    vector<int*> numers{p1, p2, p3, p4, p5};
    for(size_t i=0; i< 5; ++i){
        cout << *numers[i] <<":" << numers[i] << endl;
    }
    SortPointer(numers);
    for(int* iter: numers)
    {
        cout << *iter <<":" << iter << endl;
    }
//task
    cout << "----------task2 vector pointers----------" << endl;
    ifstream file("book.txt");
    cout << ForFor(file) << endl;
    file.close();


    return 0;
}
