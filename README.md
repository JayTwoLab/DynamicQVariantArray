# `DynamicQVariantArray` Class: 2D Dynamic Array of `QVariant`

> [English](README.md) , [Korean](README.ko.md)

## Overview

- The `DynamicQVariantArray` class is a **2D dynamic array** capable of storing [**`QVariant`**](https://doc.qt.io/qt-6/qvariant.html) objects.
- The class allows dynamic management and access to data of various types.

- Various data types, such as integers, strings, and floating-point numbers, can be used within a single array.

## Class Definition

`DynamicQVariantArray` internally uses `QVector` to construct a 2D array.

The size of the array can be dynamically set, and the value at each position is stored and retrieved as a `QVariant`.

- **`resize(rows, cols)`**: Dynamically sets the size of the array.
- **`setValue(row, col, value)`**: Sets a `QVariant` value at the specified position.
- **`getValue(row, col)`**: Returns the value at the specified position.
- **`printArray()`**: Prints all the values in the array.

## Usage Example

```cpp
#include <QCoreApplication>
#include "DynamicQVariantArray.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create a 2D Dynamic QVariant Array
    j2::TwoDimensions::DynamicQVariantArray myArray;

    // Set the array size
    myArray.resize(3, 3); // (3 rows, 3 cols)

    // Set and retrieve QVariant values
    myArray.setValue(0, 0, 42);              // Integer
    myArray.setValue(0, 1, "Hello World");   // QString
    myArray.setValue(0, 2, 3.14);            // Double

    // Print specific values
    qDebug() << "Value at (0,0):" << myArray.getValue(0, 0);
    qDebug() << "Value at (0,1):" << myArray.getValue(0, 1);
    qDebug() << "Value at (0,2):" << myArray.getValue(0, 2);
    qDebug() << "---------------------" ;

    // Print the entire array
    myArray.printArray();
    qDebug() << "---------------------" ;

    // Resize the array
    myArray.resize(2, 2);

    myArray.printArray();
    qDebug() << "---------------------" ;
    qDebug() << "Value at (0,2):" << myArray.getValue(0, 2);
    qDebug() << "---------------------" ;

    return 0;
}
```

- Output:

```
Value at (0,0): QVariant(int, 42)
Value at (0,1): QVariant(QString, "Hello World")
Value at (0,2): QVariant(double, 3.14)
---------------------
Value at ( 0 , 0 ):  QVariant(int, 42)
Value at ( 0 , 1 ):  QVariant(QString, "Hello World")
Value at ( 0 , 2 ):  QVariant(double, 3.14)
Value at ( 1 , 0 ):  QVariant(Invalid)
Value at ( 1 , 1 ):  QVariant(Invalid)
Value at ( 1 , 2 ):  QVariant(Invalid)
Value at ( 2 , 0 ):  QVariant(Invalid)
Value at ( 2 , 1 ):  QVariant(Invalid)
Value at ( 2 , 2 ):  QVariant(Invalid)
---------------------
Value at ( 0 , 0 ):  QVariant(int, 42)
Value at ( 0 , 1 ):  QVariant(QString, "Hello World")
Value at ( 1 , 0 ):  QVariant(Invalid)
Value at ( 1 , 1 ):  QVariant(Invalid)
---------------------
Index out of bounds
Value at (0,2): QVariant(Invalid)
---------------------
```
