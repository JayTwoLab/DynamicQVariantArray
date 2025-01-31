# `DynamicQVariantArray` 클래스 : `QVariant` 2차원 동적 배열

> [English](README.md) , [Korean](README.ko.md)

## 개요

-  `DynamicQVariantArray` 클래스는 **2차원 동적 배열** 로, [**`QVariant`**](https://doc.qt.io/qt-6/qvariant.html) 객체를 저장할 수 있습니다. 
-  클래스를 통해 다양한 타입의 데이터를 동적으로 관리하고 액세스할 수 있습니다. 

- 정수, 문자열, 실수 등 다양한 데이터 형식을 한 배열 내에서 사용할 수 있습니다.

## 클래스 정의

`DynamicQVariantArray`는 `QVector`를 사용하여 내부적으로 2차원 배열을 구성하고 있습니다. 

배열의 크기를 동적으로 설정할 수 있으며, 각 위치에 있는 값을 `QVariant` 타입으로 저장하고 조회할 수 있습니다.

- **`resize(rows, cols)`**: 배열의 크기를 동적으로 설정합니다.
- **`setValue(row, col, value)`**: 특정 위치에 `QVariant` 값을 설정합니다.
- **`getValue(row, col)`**: 특정 위치의 값을 반환합니다.
- **`printArray()`**: 배열의 모든 값을 출력합니다.


## 사용 예제

```cpp
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
```

- Output

```
Value at (0,0): 42
Value at (0,1): "Hello World"
Value at (0,2): 3.14
Value at ( 0 , 0 ): 42  ,  int
Value at ( 0 , 1 ): Hello World  ,  QString
Value at ( 0 , 2 ): 3.14  ,  double
```
