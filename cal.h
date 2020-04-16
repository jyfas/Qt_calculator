#ifndef CAL_H
#define CAL_H

#include <QQueue>
#include <QString>
#include <QStack>

class calculator
{
public:
    calculator();
    QQueue<QString> NumSeparate(const QString &str);            // 分离每个符号及数字
    QQueue<QString> Change(QQueue<QString> &queue);       // 中缀转后缀
    QString GetResult(QQueue<QString> &queue);                  // 由后缀表达式计算结果
};

#endif // CAL_H
