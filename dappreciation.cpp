#include <iomanip>
#include <iostream>

/*
 * car_model_year: Takes no parameters and prompts the user to enter
 * the model year of the car they are listing. The model year of the
 * car is returned as an integer (`int`).
 *
 * returns: the model year of the code as entered by the user (`int`).
 */
int car_model_year() {
  int model_year{0};
  std::cout << "What is the model year of the car? ";
  std::cin >> model_year;
  return model_year;
}

/*
 * car_accidents: Takes no parameters and prompts the user to enter
 * the number of accidents the car has been in. The number of accidents
 * is returned as an integer (`int`).
 *
 * returns: the number of accidents as entered by the user (`int`).
 */
int car_accidents() {
  int accidents{0};
  std::cout << "How many accidents has the car been in? ";
  std::cin >> accidents;
  return accidents;
}

/*
 * car_msrp: Takes no parameters and prompts the user to enter
 * the car's MSRP. The car's MSRP is returned as a floating-point
 * number (`double`).
 *
 * returns: the car's MSRP as entered by the user (`double`).
 */
double car_msrp() {
  double msrp{0.0};
  std::cout << "How much did you pay for the car? ";
  std::cin >> msrp;
  return msrp;
}

/*
 * car_has_premium_options: Takes no parameters and prompts the user
 * to enter whether the car has premium options. The presence of premium
 * options on the car is return as a Boolean (`bool`).
 *
 * returns: whether the car has premium option as entered by the user (`bool`).
 */
bool car_has_premium_options() {
  std::string has_options_string{""};
  std::cout << "Does your car have premium options (yes/no)? ";
  std::cin >> has_options_string;
  if (has_options_string == "yes") {
    return true;
  } else {
    return false;
  }
}

/*
 * print_eligible_message: Takes a single parameter (the car's resale value
 * as a floating-point number [`double`]) and prints a nice message telling
 * the user their car is eligible for sale through dappreciation and its price.
 *
 * returns: nothing
 */
void print_eligible_message(double resale_price) {
  std::cout << std::fixed << std::setprecision(2)
            << "dappreciation will list your car for $" << resale_price
            << ".\n";
}

/*
 * print_ineligible_message: Takes no parameters and prints a nice message telling
 * the user their car is ineligible for sale through dappreciation.
 *
 * returns: nothing
 */
void print_ineligible_message() {
  std::cout << "Unfortunately your car is ineligible for the dappreciation "
               "platform.\n";
}

int main()
{
    // Storing all of the functions in a variable, so that they become easire to call and use in the program.
    
    int car_year;
    car_year = car_model_year();
    int car_wrecks;
    car_wrecks = car_accidents();
    int age;
    age = 2022 - car_year;
    bool premium_options_availability;
    /*
    The function car_has_premium_options returns a bool value (true or false) . It asks from the user whether the car has premium options or not
    if the car does, then the function returns true else it returns false by using an if-else statement
     */
    premium_options_availability = car_has_premium_options();
    double car_price = car_msrp();
    bool is_eligible{ true };
    double resale_percent;
    resale_percent = 0.0;
    /*
    A main outer if else loop to determin the car's eligibility
    */
    
    if (age > 10 ||  car_wrecks > 3)
    {

        is_eligible = false;
        print_ineligible_message();

        return 0;
    }
    else
        /*
        Nested if loop to adjust the value of resale percent based on how old the car is
        */
    {
        if (age < 5 && age>=0) {


            resale_percent = 0.85;
        }
        else if (age >= 5 && age <= 8)
        {
            resale_percent = 0.63;
        }
        else if (age >= 9 && age <= 10)
        {
            resale_percent = 0.45;

        }
        // Another nested if loop to decrease the value of the resale percent based on the number of accidents the vehicla has been in

        if (car_wrecks == 1) {

            resale_percent -= 0.02;
        }


        else if (car_wrecks == 2) {

            resale_percent -= 0.1;
        }

        else if (car_wrecks == 3) {

            resale_percent -= 0.2;
        }
        // Check is the car has premium options or not, if it does, this increments the resale percent by 5.
        if (premium_options_availability==true)
        {
            resale_percent += 0.05;
        }
    }
    // Calculate the resale price of the car by multiplying the origginal price of the car by the factor of the resale value(which is stored as a double)
   
    car_price *= resale_percent;
    if (is_eligible) {
        print_eligible_message(car_price);
    }

    


     
    return 0;
}
