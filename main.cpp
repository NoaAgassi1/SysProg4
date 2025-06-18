//agassinoa20@gmail.com

#include "MyContainer.hpp"
#include <iostream>

using namespace Container;
using namespace std;

int main()
{
    // Create and populate an integer container
    MyContainer<> container;
    container.add(5);
    container.add(3);
    container.add(-7);
    container.add(10);
    container.add(3);
    container.add(6);

    // Print the container using operator<<
    cout << "Container: " << container << endl;

    // Runs on container using Order iterator, and prints the result
    cout << "Order (insertion order):" << endl;
    for (auto i = container.beginOrder(); i != container.endOrder(); ++i)
        cout << *i << " ";
    cout << endl;

    // Runs on container using AscendingOrder iterator, and prints the result
    cout << "Ascending Order:" << endl;
    for (auto i = container.beginAscending(); i != container.endAscending(); ++i)
        cout << *i << " ";
    cout << endl;

    // Runs on container using DescendingOrder iterator, and prints the result
    cout << "Descending Order:" << endl;
    for (auto i = container.beginDescending(); i != container.endDescending(); ++i)
        cout << *i << " ";
    cout << endl;

    // Runs on container using SideCrossOrder iterator, and prints the result
    cout << "SideCross Order:" << endl;
    for (auto i = container.beginSideCross(); i != container.endSideCross(); ++i)
        cout << *i << " ";
    cout << endl;

    // Runs on container using ReverseOrder iterator, and prints the result
    cout << "Reverse Order: ";
    for (auto it = container.reverse_begin(); it != container.reverse_end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Runs on container using MiddleOutOrder iterator, and prints the result
    cout << "MiddleOut Order: ";
    for (auto it = container.beginMiddleOut(); it != container. endMiddleOut(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << endl;

    // Create and populate a string container
    MyContainer<string> stringsContainer;
    stringsContainer.add("David");
    stringsContainer.add("lior");
    stringsContainer.add("David");
    stringsContainer.add("magi");
    stringsContainer.remove("David");
    stringsContainer.add("didi");
    stringsContainer.add("Eli");
    stringsContainer.add("Bamba");

    // Print the string container using operator<<
    cout << "String Container: " << stringsContainer << endl;

    // Runs on string container using Order iterator
    cout << "Order (insertion order):" << endl;
    for (auto i = stringsContainer.beginOrder(); i != stringsContainer.endOrder(); ++i)
        cout << *i << " ";
    cout << endl;

    // Runs on string container using AscendingOrder iterator
    cout << "Ascending Order:" << endl;
    for (auto i = stringsContainer.beginAscending(); i != stringsContainer.endAscending(); ++i)
        cout << *i << " ";
    cout << endl;

    // Runs on string container using DescendingOrder iterator
    cout << "Descending Order:" << endl;
    for (auto i = stringsContainer.beginDescending(); i != stringsContainer.endDescending(); ++i)
        cout << *i << " ";
    cout << endl;

    // Runs on string container using SideCrossOrder iterator
    cout << "SideCross Order:" << endl;
    for (auto i = stringsContainer.beginSideCross(); i != stringsContainer.endSideCross(); ++i)
        cout << *i << " ";
    cout << endl;

    // Runs on string container using ReverseOrder iterator
    cout << "Reverse Order: ";
    for (auto it = stringsContainer.reverse_begin(); it != stringsContainer.reverse_end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Runs on string container using MiddleOutOrder iterator
    cout << "MiddleOut Order:" << endl;
    for (auto it = stringsContainer.beginMiddleOut(); it != stringsContainer.endMiddleOut(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
