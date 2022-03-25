#ifndef __FORM_H__
#define __FORM_H__

#include <string>
#include "Bureaucrat.hpp"

using std::string;

class Form {
 private:
  const string _name;
  const int _signRequiredGrade;
  const int _executionRequiredGrade;
  bool _isSigned;

  // Disabled Constructor
  Form();

 protected:
  // Methods
  void validateGradeInRange(int grade) const;

 public:
  enum FormGradeRange { HIGHEST_GRADE = 1, LOWEST_GRADE = 150 };
  // Constructors & Destructor
  Form(const string& name, int signGrade, int execGrade);
  Form(const Form& other);
  virtual ~Form();

  // Getters
  const string& getName() const;
  size_t getSignRequiredGrade() const;
  size_t getExecutionRequiredGrade() const;
  bool getIsSigned() const;

  // Methods
  void beSigned(const Bureaucrat& bureaucrat);

  // Exceptions
  class GradeTooHighException;
  class GradeTooLowException;
};

class Form::GradeTooHighException : public std::exception {
 public:
  virtual const char* what() const throw();
};

class Form::GradeTooLowException : public std::exception {
 public:
  virtual const char* what() const throw();
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif  // __FORM_H__