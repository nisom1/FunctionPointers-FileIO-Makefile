#include <stdio.h>
#include <stdbool.h>
#include "pa04.h"

// must enclose the function by #ifdef TEST_INTEGRATE 
// and #endif to enable partial credits
#ifdef TEST_INTEGRATE
void integrate(Integration * intrg)
{
  // integrate the function stored in intrg's func
  // store the result in intrg's answer
  
  
  double lower = intrg.lowerlimit;
  double upper = intrg.upperlimit;
  int intvl = intrg.intervals;
  double intvlwidth = (upper - lower) / intvl;
  double sum = 0;
  for (int cnt = 0; cnt < intvl; cnt ++)
    {
      sum += func(lower);
      lower += intvlwidth;
    }
  sum *= intvlwidth;
  return sum;


}
 #endif // TEST_INTEGRATE

// must enclose the function by #ifdef RUN_INTEGRATE
// and #endif to enable particial credits

#ifdef RUN_INTEGRATE
bool  runIntegrate(char * infilename, char * outfilename)
// return true if it can successfully open and read the input 
// and open and write the output
// return false when encountering any problem
{
  // open the input file name for reading



  // if fopen fails, return false



  // read one double from the input file and store it in 
  // intrg's lowerlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false








  // read one double from the input file and store it in 
  // intrg's upperlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false











  // read one int from the input file and store it in 
  // intrg's intervals
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false








  // close the input file







  // open the output file for writing
  // if fopen fails, return false








  // create an array of funcptr called funcs with five elements:
  // func1, func2, ..., func5




  // go through the elements in funcs 
  // for each element, call integrate for that function
  // write the result (stored in intrg's answer to 
  // the output file. each answer occupies one line (add "\n")
  // use fprintf





  // check the return value of fprintf. 
  // If it is less one one, close the output
  // file and return false







  // after going through all functions in funcs
  // close the output file







  // if the function reaches here, return true





}
#endif // RUN_INTEGRATE
