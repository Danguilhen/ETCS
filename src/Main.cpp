
#include <cstdlib>
#include <iostream>
#include <thread>
#include <math.h>
#include <string>
#include <ctime>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include "Fixed_Value_Data.hpp" //Ne pas oublier
#include "National_Value_Data.hpp" //Ne pas oublier

using namespace std;
int main()
{
  Fixed_Value_Data fixe_value_data;
  fixe_value_data.Afficher_Fixed_value_data();
  National_Value_Data national_value_data;
  national_value_data.Afficher_National_value_data();

  return 0;
}