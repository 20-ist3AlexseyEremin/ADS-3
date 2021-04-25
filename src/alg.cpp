// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"


int priority(char sym) {
	if (sym == '(')
		return 0;
	else if (sym == ')')
		return 1;
	else if ((sym == '+') || (sym == '-'))
		return 2;
	else
		return 3;
}

std::string infx2pstfx(std::string inf) {
        TStack<char> stack;
        std::string result;
        for (int i = 0; i < inf.length(); ++i) {
                if (isdigit(inf[i]) ) {
                        while (isdigit(inf[i])) {
                                result += inf[i];
                                i++;
                        }
                        i--;
                        result += ' ';
                }
        }
        else if ((inf[i] == '(') || (stack.isEmpty()) || (priority(inf[i]) > priority(stack.get()))) {
                stack.push(inf[i]);
        }
        else if (inf[i] == ')') {
                char l = stack.get();
                stack.pop();
        while (l!= '(') {
                result += l;
                result = ' ';
                l = stack.get();
                stack.pop();
        }
        }
        else {
                while (!stack.isEmpty() && (priority(stack.get()) >= priority(inf[i]))) {
        result += stack.get();
        result += ' ';
        stack.pop();
        }
        stack.push(inf[i]);
        }
        }
                while (!stack.isEmpty()) {
                result += stack.get();
                result += ' ';
                stack.pop();
        }
        result.pop_back();
        return result;
        }

int eval(std::string pst) {
        std::string str2;
        TStack<int> stack;
        for (int i = 0; i < pst.length(); i++) {
                if (isdigit(pst[i])) {
                        while (isdigit(pst[i])) {
                                str2 += pst[i];
                                i++;
                        }
                stack.push( stoi(str2) );
                str2.clear();
                }
        else if (pst[i] != ' ') {
                int num2 = stack.get();
                stack.pop();
                int num1 = stack.get();
                stack.pop();
        if (pst[i] == '*') stack.push(num1 * num2);
        else if (pst[i] == '/') stack.push(num1 / num2);
        else if (pst[i] == '+') stack.push(num1 + num2);
        else if (pst[i] == '-') stack.push(num1 - num2);
        }
        }
                return stack.get();
        }
      
