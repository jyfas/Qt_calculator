#include "widget.h"
#include "ui_widget.h"


int Widget::ReverseLookup(QString &str, const char *ch)
{
    int k, m;

    for(k = str.length(); k > -1; k--)
    {
        for(m = 0; m < strlen(ch); m++)
        {
            if(str[k] == ch[m])
            {
                return k;
            }
        }
    }

    return -1;
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);                                              // 创建界面

    this->input = "";                                               // 初始化输入字符串
    this->barckets_cnt = 0;                                         // 初始化括号计数器
    this->calculate_flag = false;                                   // 初始化计算完成标志位

    ui->lineEdit->setReadOnly(true);                                // 设置成只读
    ui->lineEdit->setFont(QFont("system",32,QFont::Normal));        // 设置显示字体
    ui->lineEdit->setAlignment( Qt::AlignRight);                    // 设置文本对齐方式

    ui->lineEdit->setText("0");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_0_clicked()
{
    QString tmp = this->input.right(2);

    if(tmp.length() && tmp[1] == ')')       // 数字前面不能为右括号
    {
        return;
    }

    if(tmp.length() && tmp[1] == '0' &&
            (tmp[0] == '+' || tmp[0] == '-' || tmp[0] == '*' || tmp[0] == '/' || tmp[0] == '('))           // 小数点前不能输入多个0
    {
        return;
    }

    if( ReverseLookup(this->input, ".") - ReverseLookup(this->input,"+-*/(") > 0)         // 判断小数位和整数位是否超过10位
    {
        if( this->input.length() - ReverseLookup(this->input, ".") > 10 ||
                ReverseLookup(this->input,".") - ReverseLookup(this->input, "+-*/(") > 10)
        {
            return;
        }
    }
    else
    {
        if(this->input.length() - ReverseLookup(this->input, "+-*/(") > 10)
        {
            return;
        }
    }

    if(this->calculate_flag)                // 若计算完成后按下数字键，则清除输入字符串
    {
        this->input.clear();
        this->calculate_flag = false;
    }

    if(this->input != "0")
    {
        this->input += "0";
        ui->lineEdit->setText(this->input);
    }
}

void Widget::on_pushButton_1_clicked()
{
    QString tmp = this->input.right(1);

    if(tmp.length() && tmp[0] == ')')
    {
        return;
    }

    if(this->calculate_flag)
    {
        this->input.clear();
        this->calculate_flag = false;
    }

    if( ReverseLookup(this->input, ".") - ReverseLookup(this->input,"+-*/(") > 0)         // 判断小数位和整数位是否超过10位
    {
        if( this->input.length() - ReverseLookup(this->input, ".") > 10 ||
                ReverseLookup(this->input,".") - ReverseLookup(this->input, "+-*/(") > 10)
        {
            return;
        }
    }
    else
    {
        if(this->input.length() - ReverseLookup(this->input, "+-*/(") > 10)
        {
            return;
        }
    }

    if(this->input == "0")                  // 第一个按下0后，再次按下数字键，需清除显示
    {
       this->input.clear();
    }

    this->input += "1";
    ui->lineEdit->setText(this->input);
}

void Widget::on_pushButton_2_clicked()
{
    QString tmp = this->input.right(1);

    if(tmp.length() && tmp[0] == ')')
    {
        return;
    }

    if(this->calculate_flag)
    {
        this->input.clear();
        this->calculate_flag = false;
    }

    if( this->input.length() - ReverseLookup(this->input,"+-*/(") > 16)
    {
        return;
    }

    if(this->input == "0")
    {
       this->input.clear();
    }

    this->input += "2";
    ui->lineEdit->setText(this->input);
}

void Widget::on_pushButton_3_clicked()
{
    QString tmp = this->input.right(1);

    if(tmp.length() && tmp[0] == ')')
    {
        return;
    }

    if(this->calculate_flag)
    {
        this->input.clear();
        this->calculate_flag = false;
    }

    if( this->input.length() - ReverseLookup(this->input,"+-*/(") > 16)
    {
        return;
    }

    if(this->input == "0")
    {
       this->input.clear();
    }

    this->input += "3";
    ui->lineEdit->setText(this->input);
}

void Widget::on_pushButton_4_clicked()
{
    QString tmp = this->input.right(1);

    if(tmp.length() && tmp[0] == ')')
    {
        return;
    }

    if(this->calculate_flag)
    {
        this->input.clear();
        this->calculate_flag = false;
    }

    if( this->input.length() - ReverseLookup(this->input,"+-*/(") > 16)
    {
        return;
    }

    if(this->input == "0")
    {
       this->input.clear();
    }

    this->input += "4";
    ui->lineEdit->setText(this->input);
}

void Widget::on_pushButton_5_clicked()
{
    QString tmp = this->input.right(1);

    if(tmp.length() && tmp[0] == ')')
    {
        return;
    }

    if(this->calculate_flag)
    {
        this->input.clear();
        this->calculate_flag = false;
    }

    if( this->input.length() - ReverseLookup(this->input,"+-*/(") > 16)
    {
        return;
    }

    if(this->input == "0")
    {
       this->input.clear();
    }

    this->input += "5";
    ui->lineEdit->setText(this->input);
}

void Widget::on_pushButton_6_clicked()
{
    QString tmp = this->input.right(1);

    if(tmp.length() && tmp[0] == ')')
    {
        return;
    }

    if(this->calculate_flag)
    {
        this->input.clear();
        this->calculate_flag = false;
    }

    if( this->input.length() - ReverseLookup(this->input,"+-*/(") > 16)
    {
        return;
    }
    if(this->input == "0")
    {
       this->input.clear();
    }

    this->input += "6";
    ui->lineEdit->setText(this->input);
}

void Widget::on_pushButton_7_clicked()
{
    QString tmp = this->input.right(1);

    if(tmp.length() && tmp[0] == ')')
    {
        return;
    }

    if(this->calculate_flag)
    {
        this->input.clear();
        this->calculate_flag = false;
    }

    if( this->input.length() - ReverseLookup(this->input,"+-*/(") > 16)
    {
        return;
    }

    if(this->input == "0")
    {
       this->input.clear();
    }

    this->input += "7";
    ui->lineEdit->setText(this->input);
}

void Widget::on_pushButton_8_clicked()
{
    QString tmp = this->input.right(1);

    if(tmp.length() && tmp[0] == ')')
    {
        return;
    }

    if(this->calculate_flag)
    {
        this->input.clear();
        this->calculate_flag = false;
    }

    if( this->input.length() - ReverseLookup(this->input,"+-*/(") > 16)
    {
        return;
    }

    if(this->input == "0")
    {
       this->input.clear();
    }

    this->input += "8";
    ui->lineEdit->setText(this->input);
}

void Widget::on_pushButton_9_clicked()
{
    QString tmp = this->input.right(1);

    if(tmp.length() && tmp[0] == ')')
    {
        return;
    }

    if(this->calculate_flag)
    {
        this->input.clear();
        this->calculate_flag = false;
    }

    if( (this->input.length() - ReverseLookup(this->input,"+-*/(")) > 16)
    {
        return;
    }

    if(this->input == "0")
    {
       this->input.clear();
    }

    this->input += "9";
    ui->lineEdit->setText(this->input);
}

void Widget::on_pushButton_add_clicked()
{
    QString tmp = this->input.right(1);

    if( (this->input.isEmpty()) && (!this->calculate_flag) )           // 不接受+6形式整数r
    {
       return;
    }
    if( (tmp[0] == '.') || (tmp[0] == '(') )               // +前面不能为.，且不接受+符号位
    {
        return;
    }
    if( (tmp[0] == '+') ||  (tmp[0] == '-') || (tmp[0] == '*') || (tmp[0] == '/')  )        // 加减乘除不能连续出现
    {
        return;
    }

    if(this->calculate_flag)
    {
        this->calculate_flag = false;
    }

    this->input += "+";
    ui->lineEdit->setText(this->input);
}

void Widget::on_pushButton_sub_clicked()
{
    QString tmp = this->input.right(1);

    if(tmp[0] == '.')               // -前面不能为.
    {
        return;
    }

    if( (tmp[0] == '+') ||  (tmp[0] == '-') || (tmp[0] == '*') || (tmp[0] == '/')  )        // 加减乘除不能连续出现
    {
        return;
    }

    if(this->calculate_flag)
    {
        this->calculate_flag = false;
    }

    this->input += "-";
    ui->lineEdit->setText(this->input);
}

void Widget::on_pushButton_multiply_clicked()
{
    QString tmp = this->input.right(1);

    if(this->input.isEmpty())           // ×前面不能为空
    {
        return;
    }

    if( (tmp[0] == '+') || (tmp[0] == '-') || (tmp[0] == '*') ||
            (tmp[0] == '/') || (tmp[0] == '.') || (tmp[0] == '(') )         // ×前面不能为加减乘除、.、（
    {
       return;
    }

    if(this->calculate_flag)
    {
        this->calculate_flag = false;
    }

    this->input += "*";
    ui->lineEdit->setText(this->input);
}

void Widget::on_pushButton_divide_clicked()
{
    QString tmp = this->input.right(1);

    if(this->input.isEmpty())           // ×前面不能为空
    {
        return;
    }

    if( (tmp[0] == '+') || (tmp[0] == '-') || (tmp[0] == '*')
            || (tmp[0] == '/') || (tmp[0] == '.') || (tmp[0] == '('))         // ×前面不能为加减乘除、.、（
    {
       return;
    }

    if(this->calculate_flag)
    {
        this->calculate_flag = false;
    }

    this->input  += "/";
    ui->lineEdit->setText(this->input);
}

void Widget::on_pushButton_equal_clicked()
{
    QQueue<QString> queue;
    QString result;

    result = this->input.right(1);

    if(result == ".")
    {
        this->input.chop(1);
        result = this->input;
    }
    else if( (result == "+") || (result == "-") || (result == "*")
             || (result == "/") || (result == "(") || (this->barckets_cnt > 0) )        // 不接受+-×/
    {
        return;
    }

    ui->lineEdit->clear();

    /* 压栈，中缀表达式转后缀表达式，并计算 */
    queue = my_cal.NumSeparate(this->input);
    queue = my_cal.Change(queue);
    result = my_cal.GetResult(queue);

    /* 判断计算结果 */
    if(result == "ERROR")
    {
        ui->lineEdit->setText("ERROR");
        result.clear();
    }
    else
    {
        ui->lineEdit->setText("=" + result);
        this->calculate_flag = true;
    }

    this->input = result;
    this->barckets_cnt = 0;
}

void Widget::on_pushButton_point_clicked()
{
    QString tmp = this->input.right(1);
    int index;

    if( (this->input.length() - ReverseLookup(this->input,"+-*/(")) > 16 && (!this->calculate_flag) )
    {
        return;
    }
    if( (ui->lineEdit->text() == "0" && this->input.isEmpty()) || (this->calculate_flag))
    {
        this->input.clear();
        this->input += "0.";
        this->calculate_flag = false;
        ui->lineEdit->setText(this->input);
    }
    else
    {
        if( (tmp[0] == '+') || (tmp[0] == '-') || (tmp[0] == '*') || (tmp[0] == '/')
                || (tmp[0] == '(') || (tmp[0] == ')'))          // 小数点前面不能为加减乘除、左括号、右括号
        {
            return;
        }

        index = this->ReverseLookup(this->input, "+-*/.");      // 反向查找一串数字，直到碰到加减乘除小数点

        if(index >= 0 && this->input[index] == '.')             // 找到加减乘除小数点，且相应位置上为小数点
        {
            return;
        }

        if(this->calculate_flag)
        {
            this->input.clear();
            this->calculate_flag = false;
        }

        this->input += ".";
        ui->lineEdit->setText(this->input);
    }

}

void Widget::on_pushButton_left_clicked()
{
    QString tmp = this->input.right(1);

    if(this->calculate_flag)
    {
        this->calculate_flag = false;

        this->input.clear();
    }
    if(tmp.length())
    {
        if( (tmp[0] == '.') || (tmp[0] == ')') )     // 左括号前面不能为.或）
        {
            return;
        }
        if( (tmp[0] > '0') && (tmp[0] < '9') )       // 左括号前面不能为数字
        {
            return;
        }
    }

    this->barckets_cnt += 1;                         // 碰到有效的左括号，计数器加1
    this->input += "(";
    ui->lineEdit->setText(this->input);
}

void Widget::on_pushButton_right_clicked()
{
    QString tmp = this->input.right(1);

    if(this->input.isEmpty())                       // 右括号前面不能为空
    {
        return;
    }
    if(tmp.length())
    {
        if( (tmp[0] == '.') || (tmp[0] == '+') || (tmp[0] == '-')
                || (tmp[0] == '*') || (tmp[0] == '/') || (tmp[0] == '(') )       // 右括号前面不能有小数点、加减乘除、左括号
        {
            return;
        }
    }
    if(this->barckets_cnt == 0)                     // 输入字符串中没有相应匹配的左括号
    {
        return;
    }

    this->barckets_cnt -= 1;                        // 碰到有效的右括号，计数器减1
    this->input += ")";
    ui->lineEdit->setText(this->input);
}

void Widget::on_pushButton_del_clicked()
{
    QString tmp = this->input.right(1);

    this->input.chop(1);

    if(this->calculate_flag)
    {
        return;
    }

    if(this->input.isEmpty())                       // 若删除字符后，输入字符串为空，则显示0
    {
        ui->lineEdit->setText("0");
    }
    else
    {
        if(tmp[0] == ')')                           // 若删除字符为），括号计数器+1
        {
            this->barckets_cnt += 1;
        }
        else if(tmp[0] == '(')                      // 若删除字符为（，括号计数器-1
        {
            this->barckets_cnt -=1;
        }

        ui->lineEdit->setText(this->input);
    }
}

void Widget::on_pushButton_clear_clicked()
{
    /* 清除输入字符串，并显示0 */
    this->input.clear();
    this->barckets_cnt = 0;
    ui->lineEdit->setText("0");
}
