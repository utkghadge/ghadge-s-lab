#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class String{
    private:
    char * data;
    size_t length;

    public:
    //defualt ctor
    String() : data(nullptr), length(0) {}

    String(const char * str)
    {
        length = strlen(str);
        data = new char[length+1]; //allocate memory for string + null terminator
        strcpy(data , str); //copy contents of the string 
    }

    //copy constructor
    String(const String & other)
    {
        length = other.length;
        data = new char[length+1];
        strcpy(data, other.data);
    }
    
    // Move constructor
    String(String&& other) noexcept : data(nullptr), length(0) {
        // Transfer ownership of resources
        data = other.data;
        length = other.length;

        // Nullify the other's data pointer
        other.data = nullptr;
        other.length = 0;
    }

    ~String(){
        delete[] data;

    }

    //copy assignment operator
    String& operator= (const String& other)
    {
        if (this == &other) {
            return *this; // Handle self-assignment
        }

        delete[] data; // Deallocate existing memory

        length = other.length;
        data = new char[length+1];
        data = other.data;
        return *this;
    }

     // Move assignment operator
    String& operator=(String&& other) noexcept {
        if (this == &other) {
            return *this; // Handle self-assignment
        }

        delete[] data; // Deallocate existing memory

        // Transfer ownership of resources
        data = other.data;
        length = other.length;

        // Nullify the other's data pointer
        other.data = nullptr;
        other.length = 0;

        return *this;
    }

    // Concatenate two strings
    String operator+(const String& other) const {
        String result;
        result.length = length + other.length;
        result.data = new char[result.length + 1];

        strcpy(result.data, data);
        strcat(result.data, other.data);

        return result;
    }

    char& operator[] (size_t index){
        return data[index];
    }

    friend std::ostream& operator<<(std::ostream& os,const String& str)
    {
        if(str.data )
        {
            os<< str.data;
        }
        return os;
    }

};

int main()
{
    String s1("Hello");
    String s2("World");
    String s3 = s1 + s2; // Concatenate s1 and s2

    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3: " << s3 << std::endl;


    return 0;

}