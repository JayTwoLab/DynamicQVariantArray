

#include <QCoreApplication>
#include "DynamicQVariantArray.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create a 2D Dynamic QVariant Array
    j2::TwoDimensions::DynamicQVariantArray myArray;

    // Set the array size
    myArray.resize(3, 3);

    // Set and retrieve QVariant values
    myArray.setValue(0, 0, 42);              // Integer
    myArray.setValue(0, 1, "Hello World");   // QString
    myArray.setValue(0, 2, 3.14);            // Double

    // Print specific values
    qDebug() << "Value at (0,0):" << myArray.getValue(0, 0).toInt();
    qDebug() << "Value at (0,1):" << myArray.getValue(0, 1).toString();
    qDebug() << "Value at (0,2):" << myArray.getValue(0, 2).toDouble();

    // Print the entire array
    myArray.printArray();

    return 0;
}

