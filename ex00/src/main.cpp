#include <iostream>
#include "Bureaucrat.hpp"
#include "color.hpp"

using std::cerr;
using std::cout;
using std::string;

enum gradeActionType { INCREASE, DECREASE, NONE };

struct gradeAction {
  gradeActionType type;
  int amount;
};

void testGradeAction(Bureaucrat& testPerson, gradeAction action) {
  try {
    cout << (action.type == INCREASE ? CYN "Increasing" : MAG "Decreasing")
         << " grade of " << testPerson.getName() << " by " << action.amount
         << ".\n" END;
    if (action.type == INCREASE)
      testPerson.increaseGrade(action.amount);
    else if (action.type == DECREASE)
      testPerson.decreaseGrade(action.amount);
    cout << testPerson << std::endl;
  } catch (std::exception& e) {
    cerr << RED "[Exception On grading] " << e.what() << "\n" END;
  }
}

void test(const string& header,
          const string& name,
          int initialGrade,
          gradeAction action) {
  cout << HYEL "[[Testing " << header << CYN "(" << initialGrade << ")" HYEL
       << "]]\n" END;
  try {
    Bureaucrat testPerson(name + " person", initialGrade);
    cout << testPerson << std::endl;
    if (action.type != NONE)
      testGradeAction(testPerson, action);
  } catch (std::exception& e) {
    cerr << RED "[Exception On Creation] " << e.what() << "\n" END;
  }
  cout << "\n";
}

int main() {
  test("Grade low", "worst grade", 150, (gradeAction){NONE, 0});
  test("Grade Decrease", "some", 120, (gradeAction){DECREASE, 15});
  test("Grade too low", "wor?st grade", 200, (gradeAction){NONE, 0});
  test("Grade Decrease too low", "bad grade", 120,
       (gradeAction){DECREASE, 100});

  test("Grade high", "best grade", 1, (gradeAction){NONE, 0});
  test("Grade Increase", "some", 30, (gradeAction){INCREASE, 15});
  test("Grade too high", "b?est grade", -123, (gradeAction){NONE, 0});
  test("Grade Increase too high", "good grade", 30,
       (gradeAction){INCREASE, 100});

  Bureaucrat testPerson("testPerson", 1);
  cout << YEL "grade of " << testPerson.getName() << " is "
       << testPerson.getGrade() << "/" << Bureaucrat::LOWEST_GRADE << "\n" END;
}