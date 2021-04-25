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
        std::string res;
        for (int i = 0; i < inf.length(); ++i) {
                if (isdigit(inf[i])) {
                res += inf[i];
                res += ' ';
        }
        else if ((inf[i] == '(') || (stack.isEmpty()) || (priority(inf[i]) > priority(stack.get()))) {
                stack.push(inf[i]);
        }
        else if (inf[i] == ')') {
                char x = stack.get();
                stack.pop();
        while (x != '(') {
                res += x;
                res += ' ';
                x = stack.get();
                stack.pop();
        }
        }
        else {
                while (!stack.isEmpty() && (priority(stack.get()) >= priority(inf[i]))) {
        res += stack.get();
        res += ' ';
        stack.pop();
        }
        stack.push(inf[i]);
        }
        }
                while (!stack.isEmpty()) {
                res += stack.get();
                res += ' ';
                stack.pop();
        }
        res.pop_back();
        return res;
        }

int eval(std::string pst) {
        TStack<int> stack;
        for (int i = 0; i < pst.length(); i++) {
                if (isdigit(pst[i])) {
        stack.push( pst[i] - '0' );
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
      
