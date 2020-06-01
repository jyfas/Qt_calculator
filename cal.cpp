#include "cal.h"


calculator::calculator()
{

}

QQueue<QString> calculator::NumSeparate(const QString &str)             // 分离每个符号及数字
{
    QQueue<QString> l_queue;
    QString num = "";
    int k;

    for(k = 0; k < str.length(); k++)
    {
        if( (str[k] >= '0' && str[k] <= '9') || (str[k] == '.') )         // 如果是数字，数字字符串累加
        {
            num += str[k];
        }
        else if(str[k] == '-')
        {
            if(k == 0)              // 减号处在第一个位置，为符号位，计入数字中
            {
                num += str[k];
            }
            else if(str[k - 1] == '(')      // 减号不在第一个位置，且上一个符号为左括号时，为符号位，计入数字中
            {
                num += str[k];
            }
            else
            {
                if(!num.isEmpty())
                {
                    l_queue.enqueue(num);
                    num.clear();
                }

                l_queue.enqueue(str[k]);
            }
        }
        else if( (str[k] == '+') || (str[k] == '*') || (str[k] == '/')
                 || (str[k] == '(') || (str[k] == ')') )        // 如果是符号，且数字字符串不为空时，数字入栈
        {
            if(!num.isEmpty())
            {
                l_queue.enqueue(num);
                num.clear();
            }

            l_queue.enqueue(str[k]);
        }

    }

    if(!num.isEmpty())          // 若遍历到最后，还有一个数字
    {
        l_queue.enqueue(num);
        num.clear();
    }

    return l_queue;
}

QQueue<QString> calculator::Change(QQueue<QString> &queue)
{
    QQueue<QString> l_result_qqueue;
    QStack<QString> l_symbol_stack;
    QString symbol;
    bool change_flag;

    while(!queue.isEmpty())
    {
        symbol = queue.dequeue();           // 出队列
        symbol.toDouble(&change_flag);      // 将QString转换成Double,并返回结果到change_flag

        if(change_flag)                     // 转换成功，当前队尾元素是数字
        {
            l_result_qqueue.enqueue(symbol);
        }
        else if( (symbol == "+") || (symbol == "-") )       // +-符号优先级最小，入符号栈
        {
            if( (l_symbol_stack.isEmpty()) || (l_symbol_stack.top() == "+")
                    || (l_symbol_stack.top() == "-") || (l_symbol_stack.top() == "(") )         // 若栈不为空或栈顶元素为+-(,则入栈
            {
                l_symbol_stack.push(symbol);
            }
            else if( (l_symbol_stack.top() == "*") || (l_symbol_stack.top() == "/") )            // 直到符号栈为空或者栈顶元素为左括号
            {
                while( (!l_symbol_stack.isEmpty()) && (l_symbol_stack.top() != "(") )
                {
                    l_result_qqueue.enqueue(l_symbol_stack.pop());
                }
                l_symbol_stack.push(symbol);
            }
        }
        else if( (symbol == "*") || (symbol == "/") )       // */直接入栈
        {
            l_symbol_stack.push(symbol);
        }
        else if(symbol == "(")                  // 左括号直接进栈
        {
            l_symbol_stack.push(symbol);
        }
        else if(symbol == ")")                  // 碰到右括号，符号栈顺序出栈，直到碰到第一个左括号
        {
            while(l_symbol_stack.top() != "(")
            {
                l_result_qqueue.enqueue(l_symbol_stack.pop());
            }
            if(l_symbol_stack.top() == "(")             // 舍弃左括号
            {
                l_symbol_stack.pop();
            }
        }
    }
    while(!l_symbol_stack.isEmpty())            // 遍历完成，若符号栈里还有符号未出栈
    {
       l_result_qqueue.enqueue(l_symbol_stack.pop());
    }

    return l_result_qqueue;
}

QString calculator::GetResult(QQueue<QString> &queue)
{
    QStack<QString> l_stack;
    QString symbol;
    QString num;
    QString output;
    QString tmp;
    double num_one, num_two, result;
    bool change_flag;

    while(!queue.isEmpty())
    {
        symbol = queue.dequeue();
        symbol.toDouble(&change_flag);

        if(change_flag)         // 转换成功，是数字
        {
            l_stack.push(symbol);
        }
        else
        {
            num = l_stack.pop();
            num_one = num.toDouble();

            num = l_stack.pop();
            num_two = num.toDouble();

            if(symbol == "+")
            {
               result = num_one + num_two;
            }
            else if(symbol == "-")
            {
                result = num_two - num_one;
            }
            else if(symbol == "*")
            {
                result = num_two * num_one;
            }
             else if(symbol == "/")
            {
                if( (num_one > -0.000000000000001) && (num_one < 0.000000000000001) )       // 判断为除数
                {
                    return "ERROR";
                }
                else
                {
                    result = num_two / num_one;
                }
            }

            num.sprintf("%f",result);
            l_stack.push(num);
        }
    }

    if(l_stack.size() == 1)         // 遍历完成，栈里只有一个元素，即为结果
    {
        output = l_stack.pop();

        /* 去除尾数的0 */
        tmp = output.right(1);

        while( (tmp == "0") && (output.length() != 1) )
        {
            output.chop(1);

            if(output.right(1) == ".")
            {
                output.chop(1);
                break;
            }

            tmp = output.right(1);
        }

        /*
        if(output.length() > 19)
        {
            return "ERROR";
        }
        */
        return output;
    }
    else
    {
        return "ERROR";
    }
}
