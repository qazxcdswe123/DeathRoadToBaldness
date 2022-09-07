// enum bool
// {
//     false,
//     true
// };

template <class T>
class linearList
{
public:
    linearList();
    virtual ~linearList() = default;

    virtual int Size() const = 0;             // return the maximum number of elements in the list
    virtual int Length() const = 0;           // return the number of elements in the list
    virtual int Search(const T &x) const = 0; // return the position of x
    virtual int Locate(int i) const = 0;      // return the position of the ith element
    virtual T *getData(int i) const = 0;      // return a pointer to the ith element
    virtual void setData(int i, T &x) = 0;    // set the ith element to x
    virtual bool Insert(int i, T &x) = 0;     // insert x just after the ith element
    virtual bool Remove(int i, T &x) = 0;     // remove the ith element and return it in x
    virtual bool IsEmpty() const = 0;         // return true if the list is empty, otherwise return false
    virtual bool IsFull() const = 0;          // return true if the list is full, otherwise return false
    virtual void Sort() = 0;                  // sort the elements in the list
    virtual void Input() = 0;                 // input the elements from the keyboard
    virtual void Output() = 0;                // output the elements to the screen

    virtual linearList<T> &operator=(const linearList<T> &L) = 0; // copy the elements of L to this list
};