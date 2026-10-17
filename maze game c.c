
#include <stdio.h>
#include <string.h>

int trials = 3;
char name[50];

void player() {
    printf("Player name: ");
    scanf("%s", name);
    printf("Welcome %s to programming game, you have 3 trials\n", name);
}

void rules() {
    printf("Here are the rules and stages\n");
    printf("*First you have only 3 trials*\n");
    printf("You have three stages:\n");
    printf("stage1: Debug, you gonna detect error in code\n");
    printf("stage2: Syntax, you gonna choose the right syntax\n");
    printf("stage3: Output, you gonna predict output\n");
}

void q1(int trials);
void q2(int trials);
void q3(int trials);
void q4(int trials);
void q5(int trials);

void c1(int trials) {
    printf("*******************************");
    printf("\n**Stage1**\n in this stage you gonna detect error and enter the missing value or the correct one(ex: prin() answer= print() )");
    char y[10];
    printf("#include <stdio.h>\n int main() {\n printf(\"Hello, World!\") \n return 0;}\n *****answer: ");
    scanf("%s", y);
    if (strcmp(y, ";") == 0) {
        q2(trials);
    } else {
        printf("wrong answer\n");
        trials--;
        if (trials == 0) {
            printf("Game over\n");
        } else {
            printf("You have %d trials\n", trials);
            q1(trials);
        }
    }
}

void q1(int trials) {
    printf("*******************************");
    printf("\n**Stage1**\n in this stage you gonna detect error and enter the missing value or the correct one(ex: prin() answer= print() )");
    char y[10];
    printf("#include <stdio.h>\n int main() {\n printf(\"Hello, World!\") \n return 0;}\n *****answer: ");
    scanf("%s", y);
    if (strcmp(y, ";") == 0) {
        q2(trials);
    } else {
        printf("wrong answer\n");
        trials--;
        if (trials == 0) {
            printf("Game over\n");
        } else {
            printf("You have %d trials\n", trials);
            q1(trials);
        }
    }
}

void q2(int trials) {
    printf("*****************************************");
    printf("\n");
    char x[10];
    printf("#include <stdio.h>\nint main() {\n int a = 10.5; \n printf(\"%%d\", a); \n return 0;} \n *****answer: ");
    scanf("%s", x);
    if (strcmp(x, "float") == 0) {
        q3(trials);
    } else {
        printf("wrong answer\n");
        trials--;
        if (trials == 0) {
            printf("Game over\n");
        } else {
            printf("You have %d trials\n", trials);
            q2(trials);
        }
    }
}

void q3(int trials) {
    printf("***********************************************************");
    printf("\n");
    char f[10];
    printf(" #include <stdio.h>\n int main() {\n int x = 3 + 5; \n printf(\"%%d\", x); \n return 1;}\n*****answer: ");
    scanf("%s", f);
    if (strcmp(f, "return 0") == 0 || strcmp(f, "0") == 0) {
        q4(trials);
    } else {
        printf("wrong answer\n");
        trials--;
        if (trials == 0) {
            printf("Game over\n");
        } else {
            printf("You have %d trials\n", trials);
            q3(trials);
        }
    }
}

void q4(int trials) {
    printf("******************************************************");
    printf("\n");
    char z[10];
    printf(" #include <stdio.h>\n void main() {\n printf(\"Hello, World!\"); }\n*****answer: ");
    scanf("%s", z);
    if (strcmp(z, "int main") == 0 || strcmp(z, "int") == 0) {
        q5(trials);
    } else {
        printf("wrong answer\n");
        trials--;
        if (trials == 0) {
            printf("Game over\n");
        } else {
            printf("You have %d trials\n", trials);
            q4(trials);
        }
    }
}

void q5(int trials) {
    printf("********************************************************");
    printf("\n");
    char k[10];
    printf("int main() {\n int arr[3] = {1, 2, 3}; \n printf(\"%%d\", arr[3]);\n return 0;\n*****answer: ");
    scanf("%s", k);
    if (strcmp(k, "arr[0]") == 0 || strcmp(k, "arr[1]") == 0 || strcmp(k, "arr[2]") == 0) {
        printf("congratulation you finished stage one, you have %d trials\n", trials);
    } else {
        printf("wrong answer\n");
        trials--;
        if (trials == 0) {
            printf("Game over\n");
        } else {
            printf("You have %d trials\n", trials);
            q5(trials);
        }
    }
}

void k1(int trials);
void k2(int trials);
void k3(int trials);
void k4(int trials);
void k5(int trials);

void c2(int trials) {
    printf("*******************************");
    printf("\n**Stage2**\n in this stage you gonna choose the right syntax  of c# code(enter choice letter only)");
            k1(trials);
        
}

void k1(int trials) {
    printf("*******************************");
    char y[10];
    printf("1. Which of the following is the correct way to declare a variable in C#?\n A) int x = 10; \n B) int x = \"10\";\nC) x = 10;\nD) declare int x = 10\n*****answer: ");
    scanf("%s", y);
    if (strcmp(y, "a") == 0) {
        k2(trials);
    } else {
        printf("wrong answer\n");
        trials-=1;
        if (trials == 0) {
            printf("Game over\n");
        } else {
            printf("You have %d trials\n", trials);
            k1(trials);
        }
    }
}

void k2(int trials) {
    printf("*****************************************");
    printf("\n");
    char x[10];
    printf("2. What is the correct way to define a method in C#?\n A) method void MyMethod()\nB) public void MyMethod()\nC) public void method MyMethod()\nD) void public MyMethod()\n*****answer: ");
    scanf("%s", x);
    if (strcmp(x, "b") == 0) {
        k3(trials);
    } else {
        printf("wrong answer\n");
        trials-=1;
        if (trials == 0) {
            printf("Game over\n");
        } else {
            printf("You have %d trials\n", trials);
            k2(trials);
        }
    }
}

void k3(int trials) {
    printf("***********************************************************");
    printf("\n");
    char f[10];
    printf(" 3. Which keyword is used to inherit a class in C#?\nA) inherits\nB) extends\nC) base\nD) :\n*****answer: ");
    scanf("%s", f);
    if (strcmp(f, "d") == 0) {
        k4(trials);
    } else {
        printf("wrong answer\n");
        trials-=1;
        if (trials == 0) {
            printf("Game over\n");
        } else {
            printf("You have %d trials\n", trials);
            k3(trials);
        }
    }
}

void k4(int trials) {
    printf("******************************************************");
    printf("\n");
    char z[10];
    printf(" 4. How do you correctly handle exceptions in C#?\nA) try catch\nB) try { } catch { }\nC) attempt { } onFail { }\nD) catch try { }\n*****answer: ");
    scanf("%s", z);
    if (strcmp(z, "b") == 0 ) {
        k5(trials);
    } else {
        printf("wrong answer\n");
        trials-=1;
        if (trials == 0) {
            printf("Game over\n");
        } else {
            printf("You have %d trials\n", trials);
            k4(trials);
        }
    }
}

void k5(int trials) {
    printf("********************************************************");
    printf("\n");
    char k[10];
    printf("5. Which of the following loops is not available in C#?\nA) for\nB) while\nC) do-while\nD) foreach-do\n*****answer:");
    scanf("%s", k);
    if (strcmp(k, "d") == 0 ){
        printf("congratulation you finished stage two, you have %d trials\n", trials);
    } else {
        printf("wrong answer\n");
        trials-=1;
        if (trials == 0) {
            printf("Game over\n");
        } else {
            printf("You have %d trials\n", trials);
            k5(trials);
        }
    }
}
void f1(int trials);
void f2(int trials);
void f3(int trials);
void f4(int trials);
void f5(int trials);

void c3(int trials) {
    printf("*******************************");
    printf("\n**Stage3**\n in this stage you gonna predict the output of code using c++\n");
            f1(trials);
        
}

void f1(int trials) {
    printf("*******************************");
    char y[10];
    printf("#include <iostream>\nint main() {\nint a = 3;\nint b = 4;\nint c = a + b;\nstd::cout << c << std::endl;\nreturn 0;\n*****answer:  ");
    scanf("%s", y);
    if (strcmp(y, "7") == 0) {
        f2(trials);
    } else {
        printf("wrong answer\n");
        trials-=1;
        if (trials == 0) {
            printf("Game over\n");
        } else {
            printf("You have %d trials\n", trials);
            f1(trials);
        }
    }
}

void f2(int trials) {
    printf("*****************************************");
    printf("\n");
    char x[10];
    printf("#include <iostream>\nint main() {\nint x = 10;\nint y = 5;\nint result = x / y;\nstd::cout << result << std::endl;\nreturn 0;}\n*****answer:  ");
    scanf("%s", x);
    if (strcmp(x, "2") == 0) {
        f3(trials);
    } else {
        printf("wrong answer\n");
        trials--;
        if (trials == 0) {
            printf("Game over\n");
        } else {
            printf("You have %d trials\n", trials);
            f2(trials);
        }
    }
}

void f3(int trials) {
    printf("***********************************************************");
    printf("\n");
    char f[10];
    printf(" #include <iostream>\nint main() {\nint a = 1;\nint b = 2;\nint c = 3;\nif (a < b) {\nif (b < c) {\nstd::cout << a << " " << b << " " << c << std::endl;} \nelse {\nstd::cout << c << " " << b << " " << a << std::endl;}} else {\nstd::cout << b << " " << c << " " << a << std::endl;}\nreturn 0;}\n*****answer:");
    scanf("%s", f);
    if (strcmp(f, "123") == 0) {
        f4(trials);
    } else {
        printf("wrong answer\n");
        trials--;
        if (trials == 0) {
            printf("Game over\n");
        } else {
            printf("You have %d trials\n", trials);
            f3(trials);
        }
    }
}

void f4(int trials) {
    printf("******************************************************");
    printf("\n");
    char z[10];
    printf(" #include <iostream>\nint main() {\nint num = 8;\nif (num % 2 == 0) {\nstd::cout << \"Even\" << std::endl;}\n else {std::cout << \"Odd\" << std::endl;}\n return 0;}\n*****answer: ");
    scanf("%s", z);
    if (strcmp(z, "even") == 0 ) {
        f5(trials);
    } else {
        printf("wrong answer\n");
        trials--;
        if (trials == 0) {
            printf("Game over\n");
        } else {
            printf("You have %d trials\n", trials);
            f4(trials);
        }
    }
}

void f5(int trials) {
    printf("********************************************************");
    printf("\n");
    char k[10];
    printf("#include <iostream>\nint main() {\nint i = 0;\nwhile (i < 3) {std::cout << i << " ";\ni++; }\nstd::cout << std::endl;\nreturn 0;}\n*****answer:");
    scanf("%s", k);
    if (strcmp(k, "012") == 0 ){
        printf("congratulation you finished stage three , you won!");} 
        else {
        printf("wrong answer\n");
        trials--;
        if (trials == 0) {
            printf("Game over\n");
        } else {
            printf("You have %d trials\n", trials);
            f5(trials);
        }
    }
}
void start() {
    char y[] = "start";
    char z[] = "exit";
    char x[10];

    printf("Welcome to our programming game, please enter 'start' if you would like to play or 'exit' if you want to quit the game: ");
    scanf("%s", x);

    if (strcmp(x, y) == 0) {
        rules();
        player();
        c1(trials);
        c2(trials);
        c3(trials);
    } else if (strcmp(x, z) == 0) {
        printf("Thanks for playing\n");
    } else {
        printf("Please enter 'start' or 'exit'\n");
        start();
    }
}

int main() {
    start();
    return 0;
}
