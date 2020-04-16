#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStack>
#include <QString>
#include "cal.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_0_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_sub_clicked();

    void on_pushButton_multiply_clicked();

    void on_pushButton_divide_clicked();

    void on_pushButton_equal_clicked();

    void on_pushButton_point_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton_right_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_clear_clicked();

private:
    //QStack <QString> buf;
    QString input;                                          // 输入字符串，用于显示
    unsigned int barckets_cnt;                              // 左括号计数器
    calculator my_cal;                                      // 计算类接口
    bool calculate_flag;                                    // 计算完成标志位
    int ReverseLookup(QString &str, const char *ch);        // 反向查找函数
    Ui::Widget *ui;
};

#endif // WIDGET_H
