#ifndef DYNAMICQVARIANTARRAY_H
#define DYNAMICQVARIANTARRAY_H

#include <QtGlobal>
#include <QVector>
#include <QVariant>
#include <QDebug>

namespace j2 {
namespace TwoDimensions {

// Two-dimensional array class for QVariant
class DynamicQVariantArray {
private:
    QVector<QVector<QVariant>> array;

public:
    // Resizing the dynamic array
    void resize(int rows, int cols) {
        array.resize(rows);
        for (int i = 0; i < rows; ++i) {
            array[i].resize(cols);
        }
    }

    // Set value for (row, col)
    void setValue(int row, int col, const QVariant& value) {
        if (row >= 0 && row < array.size() && col >= 0 && col < array[row].size()) {
            array[row][col] = value;
        } else {
            qWarning() << "Index out of bounds";
        }
    }

    // Get value of (row, col)
    QVariant getValue(int row, int col) const {
        if (row >= 0 && row < array.size() && col >= 0 && col < array[row].size()) {
            return array[row][col];
        } else {
            qWarning() << "Index out of bounds";
            return QVariant();
        }
    }

    // Print all values of the array
    void printArray() const {
        for (int i = 0; i < array.size(); ++i) {
            for (int j = 0; j < array[i].size(); ++j) {
                QVariant value = array[i][j];
                qDebug() << "Value at (" << i << "," << j << "):" << value.toString() << " , " << value.typeName() ;
            }
        }
    }
};

} // namespace TwoDimensions
} // namespace j2

#endif // DYNAMICQVARIANTARRAY_H



